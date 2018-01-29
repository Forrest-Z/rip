#ifndef PLANNER_INTERFACE_HPP
#define PLANNER_INTERFACE_HPP

#include <vector>

#include "pose.hpp"
#include "velocity_pose.hpp"

namespace rip
{
    namespace navigation
    {
        class PlannerBase
        {
        public:
            PlannerBase() = default;

            virtual ~PlannerBase() = default;
#ifdef ZERO
            /**
             * Plan a trajectory
             *
             * @param initial_plan List of poses
             * @param start_velocity Starting velocity
             */
            virtual void plan(const std::vector<Pose> initial_plan, const VelocityPose& start_velocity) = 0;
#endif
            virtual void plan(const Pose& start, const Pose& goal, const VelocityPose& start_velocity) = 0;

            virtual void clear() = 0;

            /**
             * Checks whether the trajectory is collision free
             */
            //virtual bool isTrajectoryFeasible() = 0;

            virtual bool isHorizonReductionAppropriate(const std::vector<Pose>& poses)
            {
                return false;
            }
        };
    }
}

#endif // PLANNER_INTERFACE_HPP
