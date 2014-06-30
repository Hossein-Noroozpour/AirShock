#ifndef HGE_MATH_HPP
#define HGE_MATH_HPP
#include <cmath>
namespace hge
{
	namespace math
	{
		template<typename element_type=float>
		class Vector3D
		{
		public:
			element_type vec [3];
			Vector3D(element_type x, element_type y, element_type z)
			{
				vec[0] = x;
				vec[1] = y;
				vec[2] = z;
			}
			Vector3D(element_type e)
			{
				vec[0] = e;
				vec[1] = e;
				vec[2] = e;
			}
			element_type dot(const Vector3D &another) const
			{
				return  (vec[0] * another.vec[0]) +
						(vec[1] * another.vec[1]) +
						(vec[2] * another.vec[2]);
			}
			static element_type dot(const Vector3D &a, const Vector3D &b)
			{
				return  (b.vec[0] * a.vec[0]) +
						(b.vec[1] * a.vec[1]) +
						(b.vec[2] * a.vec[2]);
			}
			Vector3D<element_type> cross(const Vector3D<element_type> &a) const
			{
				return Vector3D<element_type>((vec[1] * a.vec[2]) - (vec[2] * a.vec[1]),
					(vec[2] * a.vec[0]) - (vec[0] * a.vec[2]),
					(vec[0] * a.vec[1]) - (vec[1] * a.vec[0]));
			}
			static Vector3D<element_type> cross(const Vector3D<element_type> &a, const Vector3D<element_type> &b)
			{
				return Vector3D<element_type>((a.vec[1] * b.vec[2]) - (a.vec[2] * b.vec[1]),
					(a.vec[2] * b.vec[0]) - (a.vec[0] * b.vec[2]),
					(a.vec[0] * b.vec[1]) - (a.vec[1] * b.vec[0]));
			}
			void normalize()
			{
				element_type len = (element_type)sqrtl((long double)(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
				vec[0] /= len;
				vec[1] /= len;
				vec[2] /= len;
			}
			static Vector3D<element_type> normalize(const Vector3D<element_type> &a)
			{
				element_type len = (element_type)sqrtl((long double)(
						a.vec[0] * a.vec[0] + a.vec[1] * a.vec[1] + a.vec[2] * a.vec[2]));
				return Vector3D<element_type>(a.vec[0] / len, a.vec[1] / len, a.vec[2] / len);
			}
			Vector3D<element_type> operator+(const Vector3D<element_type> &a)
			{
				return Vector3D<element_type>(vec[0] + a.vec[0], vec[1] + a.vec[1], vec[2] + a.vec[2]);
			}
			Vector3D<element_type> operator-(const Vector3D<element_type> &a)
			{
				return Vector3D<element_type>(vec[0] - a.vec[0], vec[1] - a.vec[1], vec[2] - a.vec[2]);
			}
			Vector3D<element_type> operator*(const Vector3D<element_type> &a)
			{
				return Vector3D<element_type>(vec[0] * a.vec[0], vec[1] * a.vec[1], vec[2] * a.vec[2]);
			}
			Vector3D<element_type> operator/(const Vector3D<element_type> &a)
			{
				return Vector3D<element_type>(vec[0] / a.vec[0], vec[1] / a.vec[1], vec[2] / a.vec[2]);
			}
			void operator+=(const Vector3D<element_type> &a)
			{
				vec[0] += a.vec[0];
				vec[1] += a.vec[1];
				vec[2] += a.vec[2];
			}
			void operator-=(const Vector3D<element_type> &a)
			{
				vec[0] -= a.vec[0];
				vec[1] -= a.vec[1];
				vec[2] -= a.vec[2];
			}
			void operator*=(const Vector3D<element_type> &a)
			{
				vec[0] *= a.vec[0];
				vec[1] *= a.vec[1];
				vec[2] *= a.vec[2];
			}
			void operator/=(const Vector3D<element_type> &a)
			{
				vec[0] /= a.vec[0];
				vec[1] /= a.vec[1];
				vec[2] /= a.vec[2];
			}
		};

		template<typename element_type=float>
		class Vector4D
		{
		public:
			element_type vec [4];
			Vector4D(element_type x, element_type y, element_type z,  element_type w)
			{
				vec[0] = x;
				vec[1] = y;
				vec[2] = z;
				vec[3] = w;
			}
			Vector4D(element_type e)
			{
				vec[0] = e;
				vec[1] = e;
				vec[2] = e;
				vec[3] = e;
			}
			element_type dot(const Vector4D &another) const
			{
				return  (vec[0] * another.vec[0]) +
						(vec[1] * another.vec[1]) +
						(vec[2] * another.vec[2]) +
						(vec[3] * another.vec[3]);
			}
			static element_type dot(const Vector4D &a, const Vector4D &b)
			{
				return  (b.vec[0] * a.vec[0]) +
						(b.vec[1] * a.vec[1]) +
						(b.vec[2] * a.vec[2]) +
						(b.vec[3] * a.vec[3]);
			}
			Vector4D<element_type> cross(const Vector4D<element_type> &a) const
			{
				return Vector4D<element_type>((vec[1] * a.vec[2]) - (vec[2] * a.vec[1]),
					(vec[2] * a.vec[0]) - (vec[0] * a.vec[2]),
					(vec[0] * a.vec[1]) - (vec[1] * a.vec[0]),
					vec[3] * a.vec[3]);
			}
			static Vector4D<element_type> cross(const Vector4D<element_type> &a, const Vector4D<element_type> &b)
			{
				return Vector4D<element_type>((a.vec[1] * b.vec[2]) - (a.vec[2] * b.vec[1]),
					(a.vec[2] * b.vec[0]) - (a.vec[0] * b.vec[2]),
					(a.vec[0] * b.vec[1]) - (a.vec[1] * b.vec[0]),
					a.vec[3] * b.vec[3]);
			}
			void normalize()
			{
				element_type len = (element_type)sqrtl((long double)(
						vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2] + vec[3] * vec[3]));
				vec[0] /= len;
				vec[1] /= len;
				vec[2] /= len;
				vec[3] /= len;
			}
			static Vector4D<element_type> normalize(const Vector4D<element_type> &a)
			{
				element_type len = (element_type)sqrtl((long double)(
						a.vec[0] * a.vec[0] + a.vec[1] * a.vec[1] + a.vec[2] * a.vec[2] + a.vec[3] * a.vec[3]));
				return Vector4D<element_type>(a.vec[0] / len, a.vec[1] / len, a.vec[2] / len, a.vec[3] / len);
			}
		};

		template<typename element_type=float>
		class Matrix4D
		{
		public:
			element_type mat [16];
			Matrix4D(element_type e)
			{
				mat[0 ] = e;
				mat[1 ] = element_type(0);
				mat[2 ] = element_type(0);
				mat[3 ] = element_type(0);
				mat[4 ] = element_type(0);
				mat[5 ] = e;
				mat[6 ] = element_type(0);
				mat[7 ] = element_type(0);
				mat[8 ] = element_type(0);
				mat[9 ] = element_type(0);
				mat[10] = e;
				mat[11] = element_type(0);
				mat[12] = element_type(0);
				mat[13] = element_type(0);
				mat[14] = element_type(0);
				mat[15] = e;
			}
			Matrix4D()
			{}
			/// WARNING: It is not tested yet!
			static Matrix4D<element_type> lookAt(
					const Vector3D<element_type> &position,
					const Vector3D<element_type> &target,
					const Vector3D<element_type> &up)
			{
				Vector3D<element_type> z = (target - position).normalize();
				Vector3D<element_type> x = up.cross(z).normalize();
				Vector3D<element_type> y = z.cross(x);
				Matrix4D<element_type> m;
				m.mat[0 ] = x.vec[0];
				m.mat[1 ] = x.vec[1];
				m.mat[2 ] = x.vec[2];
				m.mat[3 ] = -x.dot(position);
				m.mat[4 ] = y.vec[0];
				m.mat[5 ] = y.vec[1];
				m.mat[6 ] = y.vec[2];
				m.mat[7 ] = -y.dot(position);
				m.mat[8 ] = z.vec[0];
				m.mat[9 ] = z.vec[1];
				m.mat[10] = z.vec[2];
				m.mat[11] = -z.dot(position);
				m.mat[12] = element_type(0.0);
				m.mat[13] = element_type(0.0);
				m.mat[14] = element_type(0.0);
				m.mat[15] = element_type(1.0);
				return m;
			}
		};
	}
}
#endif
