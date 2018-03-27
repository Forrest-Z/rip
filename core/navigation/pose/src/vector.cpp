#include "pose/vector.hpp"

namespace rip
{
    namespace navigation
    {
        namespace pose
        {
            Vector::Vector()
            {
            }

            Vector::Vector(std::vector<double> a) : m_a(std::move(a))
            {
            }

            Vector::Vector(const Vector& v) : m_a(v.m_a)
            {
            }

            Vector::Vector(Vector&& v) : m_a(std::move(v.m_a))
            {
            }

            Vector::Vector(std::size_t order) : m_a(order)
            {
            }

            Vector::~Vector()
            {
            }

            double Vector::dot(const Vector& v2) const
            {
                const Vector& v1 = *this;
                double result = 0.0;
                for(std::size_t i = 0; i < v1.order(); i ++)
                {
                    result += v1.m_a[i] * v2.m_a[i];
                }
                return result;

            }

            std::size_t Vector::order() const
            {
                return m_a.size();
            }

            void Vector::set(Vector a)
            {
                if(order() != a.order())
                {
                    throw std::runtime_error("Length of array is different from the Vector expected order.");
                }
                m_a = std::move(a.m_a);
            }

            double& Vector::at(int i)
            {
                return m_a[i];
            }

            double Vector::at(int i) const
            {
                return m_a[i];
            }

            Vector Vector::operator+(const Vector& v2) const
            {
                const Vector& v1 = *this;
                if(v1.order() != v2.order())
                {
                    throw std::runtime_error("Vector sizes are not compatible.");
                }
                Vector result(std::vector<double>(v1.order()));
                std::vector<double>& a = result.m_a;
                for(std::size_t i = 0; i < a.size(); i ++)
                {
                    a[i] = v1.m_a[i] + v2.m_a[i];
                }
                return result;
            }

            Vector Vector::operator-(const Vector& v2) const
            {
                const Vector& v1 = *this;
                if(v1.order() != v2.order())
                {
                    throw std::runtime_error("Vector sizes are not compatible.");
                }
                Vector result(v1.order());
                std::vector<double>& a = result.m_a;
                for(std::size_t i = 0; i < a.size(); i ++)
                {
                    a[i] = v1.m_a[i] - v2.m_a[i];
                }
                return result;
            }

            bool Vector::operator<(const Vector& v2) const
            {
                if(this == &v2)
                    return false;
                const Vector& v1 = *this;
                bool result = v1.order() > 0;
                for(std::size_t i = 0; i < v1.order(); i ++)
                {
                    result = result && v1.m_a[i] < v2.m_a[i];
                }
                return result;
            }

            bool Vector::operator>(const Vector& v2) const
            {
                if(this == &v2)
                    return false;
                const Vector& v1 = *this;
                bool result = v1.order() > 0;
                for(std::size_t i = 0; i < v1.order(); i ++)
                {
                    result = result && v1.m_a[i] > v2.m_a[i];
                }
                return result;
            }

            bool Vector::operator==(const Vector& v) const
            {
                if(this == &v)
                    return true;
                return m_a == v.m_a;
            }

            Vector& Vector::operator=(const Vector& that)
            {
                this->m_a = that.m_a;
                return *this;
            }

            // operator= is implicitly declared as deleted in subclasses
            // because it also defines a move assignment operator.
            void Vector::copyAssign(const Vector& v)
            {
                if(this != &v)
                {
                    m_a = v.m_a;
                }
            }

            void Vector::moveAssign(Vector&& v)
            {
                if(this != &v)
                {
                    m_a = std::move(v.m_a);
                }
            }

            double& Vector::operator[](std::size_t i)
            {
                return m_a[i];
            }

            double Vector::operator[](std::size_t i) const
            {
                return m_a[i];
            }

            Matrix Vector::cross(const Vector& that) const
            {
                std::vector<double> m(order() * that.order());
                int k = 0;
                for(std::size_t i = 0; i < order(); i ++)
                {
                    double a = m_a[i];
                    for(std::size_t j = 0; j < that.order(); j ++)
                    {
                        double b = that[j];
                        m[k] = a * b;
                        k ++;
                    }
                }
                return Matrix(order(), that.order(), m);
            }

            Vector Vector::aliasVector() const
            {
                return Vector(m_a);
            }

            std::ostream& operator<<(std::ostream& os, const Vector& v)
            {
                os << v.order() << ":{";
                for(std::size_t i = 0; i < v.order(); i ++)
                {
                    if(i > 0)
                        os << ", ";
                    os << v[i];
                }
                os << "}";
                return os;
            }

        }
    }
}