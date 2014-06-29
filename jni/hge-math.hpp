#ifndef HGE_MATH_HPP
#define HGE_MATH_HPP
namespace hge
{
	namespace math
	{
		template<typename element_type=float>
		class Vector3D
		{
		private:
			element_type vec [3];
		public:
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
		};

		template<typename element_type=float>
		class Vector4D
		{
		private:
			element_type vec [4];
		public:
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
		};

		template<typename element_type=float>
		class Matrix4D
		{
		private:
			element_type mat [16];
		public:
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
		};
	}
}
#endif
