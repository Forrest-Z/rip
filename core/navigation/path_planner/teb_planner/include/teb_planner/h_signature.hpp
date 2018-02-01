/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2017,
 *  TU Dortmund - Institute of Control Theory and Systems Engineering.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the institute nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Christoph Rösmann, Franz Albers
 *
 * Modified by: Andrew Messing
 * - Removed all aspects that required ROS or boost and added in RIP
 *   elements
 *********************************************************************/

#ifndef H_SIGNATURE_HPP
#define H_SIGNATURE_HPP

#include <teb_planner/equivalence_relations.hpp>
#include <teb_planner/misc.hpp>
#include <teb_planner/obstacles.hpp>
#include <teb_planner/teb_config.hpp>
#include <teb_planner/timed_elastic_band.hpp>

#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

#include <optional.hpp>


namespace rip
{
    namespace navigation
    {

        namespace tebplanner
        {

            template <typename T> inline constexpr
            int signum(T x, std::false_type is_signed) {
                return T(0) < x;
            }

            template <typename T> inline constexpr
            int signum(T x, std::true_type is_signed) {
                return (T(0) < x) - (x < T(0));
            }

            template <typename T> inline constexpr
            int signum(T x) {
                return signum(x, std::is_signed<T>());
            }

            /**
             * @brief The H-signature defines an equivalence relation based on homology in terms of complex calculus.
             *
             * The H-Signature depends on the obstacle configuration and can be utilized
             * to check whether two trajectores belong to the same homology class.
             * Refer to: \n
             *  - S. Bhattacharya et al.: Search-based Path Planning with Homotopy Class Constraints, AAAI, 2010
             */
            class HSignature : public EquivalenceClass
            {

            public:

                /**
                * @brief Constructor accepting a TebConfig
                * @param cfg TebConfig storing some user configuration options
                */
                HSignature(std::shared_ptr<TebConfig> cfg)
                    : m_config(cfg)
                {}


                /**
                 * @brief Calculate the H-Signature of a path
                 *
                 * The implemented function accepts generic path descriptions that are restricted to the following structure: \n
                 * The path is composed of points T and is represented by a std::vector< T > or similar type (std::list, std::deque, ...). \n
                 * Provide a unary function with the following signature <c> std::complex< long double > (const T& point_type) </c>
                 * that returns a complex value for the position (Re(*)=x, Im(*)=y).
                  *
                 * T could also be a pointer type, if the passed function also accepts a const T* point_Type.
                 *
                 * @param path_start Iterator to the first element in the path
                 * @param path_end Iterator to the last element in the path
                 * @param obstacles obstacle container
                 * @param fun_cplx_point function accepting the dereference iterator type and that returns the position as complex number.
                 * @tparam BidirIter Bidirectional iterator type
                 * @tparam Fun function of the form std::complex< long double > (const T& point_type)
                 */
                template<typename BidirIter, typename Fun >
                void calculateHSignature(BidirIter path_start, BidirIter path_end, Fun fun_cplx_point, const ObstacleContainer* obstacles)
                {
                    if (obstacles->empty())
                    {
                        m_hsignature = std::complex<double>(0, 0);
                        return;
                    }


                    if(m_config->hcp.h_signature_prescaler <= 0.1 ||m_config->hcp.h_signature_prescaler > 1)
                    {
                        misc::Logger::getInstance()->error("Only a prescaler on the interval (0.1,1] ist allowed.");
                        assert(false);
                    }

                    // guess values for f0
                    // paper proposes a+b=N-1 && |a-b|<=1, 1...N obstacles
                    int m = std::max( (int)obstacles->size() - 1, 5 ); // for only a few obstacles we need a min threshold in order to get significantly high H-Signatures

                    int a = (int) std::ceil(double(m) / 2.0);
                    int b = m - a;

                    std::advance(path_end, -1); // reduce path_end by 1 (since we check line segments between those path points

                    typedef std::complex<long double> cplx;
                    // guess map size (only a really really coarse guess is required
                    // use distance from start to goal as distance to each direction
                    // TODO: one could move the map determination outside this function, since it remains constant for the whole planning interval
                    cplx start = fun_cplx_point(*path_start);
                    cplx end = fun_cplx_point(*path_end); // path_end points to the last point now after calling std::advance before
                    cplx delta = end - start;
                    cplx normal(-delta.imag(), delta.real());
                    cplx map_bottom_left;
                    cplx map_top_right;
                    if (std::abs(delta) < 3.0)
                    {
                        // set minimum bound on distance (we do not want to have numerical instabilities) and 3.0 performs fine...
                        map_bottom_left = start + cplx(0, -3);
                        map_top_right = start + cplx(3, 3);
                    }
                    else
                    {
                        map_bottom_left = start - normal;
                        map_top_right = start + delta + normal;
                    }

                    m_hsignature = 0; // reset local signature

                    std::vector<double> imag_proposals(5);

                    // iterate path
                    while (path_start != path_end)
                    {
                        cplx z1 = fun_cplx_point(*path_start);
                        cplx z2 = fun_cplx_point(*(path_start + 1));

                        for (std::size_t l = 0; l < obstacles->size(); ++l) // iterate all obstacles
                        {
                            cplx obst_l = obstacles->at(l)->getCentroidCplx();
                            //cplx f0 = (long double) prescaler * std::pow(obst_l-map_bottom_left,a) * std::pow(obst_l-map_top_right,b);
                            cplx f0 = (long double) m_config->hcp.h_signature_prescaler * (long double)a * (obst_l - map_bottom_left) * (long double)b * (obst_l - map_top_right);

                            // denum contains product with all obstacles exepct j==l
                            cplx Al = f0;
                            for (std::size_t j = 0; j < obstacles->size(); ++j)
                            {
                                if (j == l)
                                {
                                    continue;
                                }
                                cplx obst_j = obstacles->at(j)->getCentroidCplx();
                                cplx diff = obst_l - obst_j;
                                //if (diff.real()!=0 || diff.imag()!=0)
                                if (std::abs(diff) < 0.05) // skip really close obstacles
                                {
                                    Al /= diff;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            // compute log value
                            double diff2 = std::abs(z2 - obst_l);
                            double diff1 = std::abs(z1 - obst_l);
                            if (diff2 == 0 || diff1 == 0)
                            {
                                continue;
                            }
                            double log_real = std::log(diff2) - std::log(diff1);
                            // complex ln has more than one solution -> choose minimum abs angle -> paper
                            double arg_diff = std::arg(z2 - obst_l) - std::arg(z1 - obst_l);
                            imag_proposals.at(0) = arg_diff;
                            imag_proposals.at(1) = arg_diff + 2 * M_PI;
                            imag_proposals.at(2) = arg_diff - 2 * M_PI;
                            imag_proposals.at(3) = arg_diff + 4 * M_PI;
                            imag_proposals.at(4) = arg_diff - 4 * M_PI;
                            double log_imag = *std::min_element(imag_proposals.begin(), imag_proposals.end(), smaller_than_abs);
                            cplx log_value(log_real, log_imag);
                            //cplx log_value = std::log(z2-obst_l)-std::log(z1-obst_l); // the principal solution doesn't seem to work
                            m_hsignature += Al * log_value;
                        }
                        ++path_start;
                    }
                }


                /**
                 * @brief Check if two candidate classes are equivalent
                 * @param other The other equivalence class to test with
                 */
                virtual bool isEqual(const EquivalenceClass& other) const
                {
                    const HSignature* hother = dynamic_cast<const HSignature*>(&other); // TODO: better architecture without dynamic_cast
                    if (hother)
                    {
                        double diff_real = std::abs(hother->m_hsignature.real() - m_hsignature.real());
                        double diff_imag = std::abs(hother->m_hsignature.imag() - m_hsignature.imag());
                        if (diff_real <= m_config->hcp.h_signature_threshold && diff_imag <= m_config->hcp.h_signature_threshold)
                        {
                            return true;    // Found! Homotopy class already exists, therefore nothing added
                        }
                    }
                    else
                    {
                        misc::Logger::getInstance()->error("Cannot compare HSignature equivalence classes with types other than HSignature.");
                    }

                    return false;
                }

                /**
                 * @brief Check if the equivalence value is detected correctly
                 * @return Returns false, if the equivalence class detection failed, e.g. if nan- or inf values occur.
                 */
                virtual bool isValid() const
                {
                    return std::isfinite(m_hsignature.real()) && std::isfinite(m_hsignature.imag());
                }

                /**
                 * @brief Check if the trajectory is non-looping around an obstacle.
                 * @return Returns always true, as this cannot be detected by this kind of H-Signature.
                 */
                virtual bool isReasonable() const
                {
                    return true;
                }

                /**
                 * @brief Get the current value of the h-signature (read-only)
                 * @return h-signature in complex-number format
                 */
                const std::complex<long double>& value() const {return m_hsignature;}


            private:

                std::shared_ptr<TebConfig> m_config;
                std::complex<long double> m_hsignature;
            };





            /**
             * @brief The H-signature in three dimensions (here: x-y-t) defines an equivalence relation based on homology using theorems from electro magnetism.
             *
             * The H-Signature depends on the obstacle configuration and can be utilized
             * to check whether two trajectores belong to the same homology class.
             * Refer to: \n
             *  - S. Bhattacharya et al.: Identification and Representation of Homotopy Classes of Trajectories for Search-based Path Planning in 3D, 2011
             */
            class HSignature3d : public EquivalenceClass
            {
            public:
                /**
                * @brief Constructor accepting a TebConfig
                * @param cfg TebConfig storing some user configuration options
                */
                HSignature3d(std::shared_ptr<TebConfig> cfg)
                    : m_config(cfg)
                {}


                /**
                 * @brief Calculate the H-Signature of a path
                 *
                 * The implemented function accepts generic path descriptions that are restricted to the following structure: \n
                 * The path is composed of points T and is represented by a std::vector< T > or similar type (std::list, std::deque, ...). \n
                 * Provide a unary function with the following signature <c> std::complex< long double > (const T& point_type) </c>
                 * that returns a complex value for the position (Re(*)=x, Im(*)=y).
                 *
                 * T could also be a pointer type, if the passed function also accepts a const T* point_Type.
                 *
                 * @param path_start Iterator to the first element in the path
                 * @param path_end Iterator to the last element in the path
                 * @param obstacles obstacle container
                 * @param fun_cplx_point function accepting the dereference iterator type and that returns the position as complex number.
                 * @tparam BidirIter Bidirectional iterator type
                 * @tparam Fun function of the form std::complex< long double > (const T& point_type)
                 */
                template<typename BidirIter, typename Fun>
                void calculateHSignature(BidirIter path_start, BidirIter path_end, Fun fun_cplx_point, const ObstacleContainer* obstacles,
                                         nonstd::optional<TimeDiffSequence::iterator> timediff_start, nonstd::optional<TimeDiffSequence::iterator> timediff_end)
                {
                    m_hsignature_3d.resize(obstacles->size());

                    std::advance(path_end, -1); // reduce path_end by 1 (since we check line segments between those path points

                    double H = 0;

                    for (std::size_t l = 0; l < obstacles->size(); ++l) // iterate all obstacles
                    {
                        H = 0;
                        double transition_time = 0;
                        double next_transition_time = 0;
                        BidirIter path_iter;
                        TimeDiffSequence::iterator timediff_iter;

                        // iterate path
                        for (path_iter = path_start, timediff_iter = *timediff_start; path_iter != path_end; ++path_iter, ++timediff_iter)
                        {
                            std::complex<long double> z1 = fun_cplx_point(*path_iter);
                            std::complex<long double> z2 = fun_cplx_point(*(path_iter + 1));
                            Eigen::Vector2d pose (z1.real(), z1.imag());
                            Eigen::Vector2d nextpose (z2.real(), z2.imag());

                            transition_time = next_transition_time;
                            if (timediff_start == nonstd::nullopt || timediff_end == nonstd::nullopt) // if no time information is provided yet, approximate transition time
                            {
                                next_transition_time += (nextpose - pose).norm() / m_config->robot.max_vel_x;    // Approximate the time, if no time is known
                            }
                            else // otherwise use the time information from the teb trajectory
                            {
                                if (std::distance(path_iter, path_end) != std::distance(timediff_iter, *timediff_end))
                                {
                                    misc::Logger::getInstance()->error("Size of poses and timediff vectors does not match. This is a bug.");
                                }
                                next_transition_time += (*timediff_iter)->dt();
                            }

                            Eigen::Vector3d pose_with_time (pose(0), pose(1), transition_time);
                            Eigen::Vector3d next_pose_with_time (nextpose(0), nextpose(1), next_transition_time);

                            Eigen::Vector3d direction_vec = next_pose_with_time - pose_with_time;
                            Eigen::Vector3d dl = 0.1 * direction_vec.normalized(); // Integrate with 10 steps between each pose

                            for (Eigen::Vector3d position = pose_with_time; (position - pose_with_time).norm() <= direction_vec.norm(); position += dl)
                            {
                                double t = 120;
                                Eigen::Vector3d s1 (obstacles->at(l)->getCentroid()(0), obstacles->at(l)->getCentroid()(1), 0);
                                Eigen::Vector3d s2;
                                obstacles->at(l)->predictCentroidConstantVelocity(t, s2.head(2));
                                s2[2] = t;
                                Eigen::Vector3d r = position;
                                Eigen::Vector3d p1 = s1 - r;
                                Eigen::Vector3d p2 = s2 - r;
                                Eigen::Vector3d d = ((s2 - s1).cross(p1.cross(p2))) / (s2 - s1).squaredNorm();
                                Eigen::Vector3d phi = 1 / d.squaredNorm() * ((d.cross(p2) / p2.norm()) - (d.cross(p1) / p1.norm()));

                                if (dl.norm() < (next_pose_with_time - position).norm())
                                {
                                    H += phi.dot(dl);
                                }
                                else
                                {
                                    H += phi.dot(next_pose_with_time - position);
                                }
                            }
                        }

                        // normalize to 1
                        m_hsignature_3d.at(l) = H / (4 * M_PI);
                    }
                }

                /**
                 * @brief Check if two candidate classes are equivalent
                 *
                 * If the absolute value of the H-Signature is equal or greater than 1, a loop (in x-y) around the obstacle is indicated.
                 * Positive H-Signature: Obstacle lies on the left hand side of the planned trajectory
                 * Negative H-Signature: Obstacle lies on the right hand side of the planned trajectory
                 * H-Signature equals zero: Obstacle lies in infinity, has no influence on trajectory
                 *
                 * @param other The other equivalence class to test with
                 */
                virtual bool isEqual(const EquivalenceClass& other) const
                {
                    const HSignature3d* hother = dynamic_cast<const HSignature3d*>(&other); // TODO: better architecture without dynamic_cast
                    if (hother)
                    {
                        if (m_hsignature_3d.size() == hother->m_hsignature_3d.size())
                        {
                            for (size_t i = 0; i < m_hsignature_3d.size(); ++i)
                            {
                                // If the H-Signature for one obstacle is below this threshold, that obstacle is far away from the planned trajectory,
                                // and therefore ignored in the homotopy class planning
                                if (std::abs(hother->m_hsignature_3d.at(i)) < m_config->hcp.h_signature_threshold || std::abs(m_hsignature_3d.at(i)) < m_config->hcp.h_signature_threshold)
                                {
                                    continue;
                                }

                                if (signum(hother->m_hsignature_3d.at(i)) != signum(m_hsignature_3d.at(i)))
                                {
                                    return false;    // Signatures are not equal, new homotopy class
                                }
                            }
                            return true; // Found! Homotopy class already exists, therefore nothing added
                        }
                    }
                    else
                    {
                        misc::Logger::getInstance()->error("Cannot compare HSignature3d equivalence classes with types other than HSignature3d.");
                    }

                    return false;
                }

                /**
                 * @brief Check if the equivalence value is detected correctly
                 * @return Returns false, if the equivalence class detection failed, e.g. if nan- or inf values occur.
                 */
                virtual bool isValid() const
                {
                    for (const double& value : m_hsignature_3d)
                    {
                        if (!std::isfinite(value))
                        {
                            return false;
                        }
                    }
                    return true;
                }

                /**
                 * @brief Check if the trajectory is non-looping around any obstacle. Values greater than 1 indicate a looping trajectory.
                 * @return Returns false, if the trajectory loops around an obstacle
                 */
                virtual bool isReasonable() const
                {
                    for (const double& value : m_hsignature_3d)
                    {
                        if (value > 1.0)
                        {
                            return false;
                        }
                    }
                    return true;
                }

                /**
                 * @brief Get the current h-signature (read-only)
                 * @return h-signature in complex-number format
                 */
                const std::vector<double>& values() const {return m_hsignature_3d;}

            private:
                std::shared_ptr<TebConfig> m_config;
                std::vector<double> m_hsignature_3d;
            };
        }
    }
}


#endif // H_SIGNATURE_HPP
