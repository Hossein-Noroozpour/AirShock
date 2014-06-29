#include "hge-camera-unit.hpp"
namespace hge
{
	namespace math
	{
		CameraUnit::CameraUnit():
			cmrX(Vector3D<>(1.0f, 0.0f, 0.0f)),
			cmrY(Vector3D<>(0.0f, 1.0f, 0.0f)),
			cmrZ(Vector3D<>(0.0f, 0.0f, 1.0f)),
			cmrLoc(Vector3D<>(0.0f, 0.0f, 1300.0f)),
			viewM(glm::lookAt(Vector3D<>(0.0f, 0.0f, 1300.0f), Vector3D<>(0.0f, 0.0f, 0.0f), Vector3D<>(0.0f, 1.0f, 0.0f))),
			rotsclM(Matrix4D<>(1.0f))
		{
		}
		CameraUnit::~CameraUnit()
		{
		}
		void CameraUnit::translate(const Vector3D<> &vec)
		{
			cmrLoc -= vec;
			viewM = glm::translate(viewM, -vec);
		}
		/// \caution unknown issue maybe exist
		void CameraUnit::move(const Vector3D<> &vec)
		{
			cmrLoc = vec;
			viewM = glm::translate(rotsclM, vec);
		}
		void CameraUnit::rotateLocalX(const float &rad)
		{
			cmrY = glm::rotate(cmrY, rad, cmrX);
			cmrZ = glm::rotate(cmrZ, rad, cmrX);
			rotsclM = glm::rotate(rotsclM,-rad, cmrX);//!!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, -cmrLoc);
		}
		void CameraUnit::rotateLocalY(const float &rad)
		{
			cmrX = glm::rotate(cmrX, rad, cmrY);
			cmrZ = glm::rotate(cmrZ, rad, cmrY);
			rotsclM = glm::rotate(rotsclM, -rad, cmrY);//!!!!!!!!!!!!!!1
			viewM = glm::translate(rotsclM,-cmrLoc);
		}
		void CameraUnit::rotateLocalZ(const float &rad)
		{
			cmrY = glm::rotate(cmrY, rad, cmrZ);
			cmrX = glm::rotate(cmrX, rad, cmrZ);
			rotsclM = glm::rotate(rotsclM, -rad, cmrZ);//!!!!!!!!!!!!!!1
			viewM = glm::translate(rotsclM,-cmrLoc);
		}
		void CameraUnit::rotateLocal(const float &rad, const Vector3D<> &vec)
		{
			cmrX = glm::rotate(cmrX,-rad, vec);
			cmrY = glm::rotate(cmrY,-rad, vec);
			cmrZ = glm::rotate(cmrZ,-rad, vec);
			rotsclM = glm::rotate(rotsclM, -rad, vec);//!!!!!!!!!!!!!!!!!11
			viewM = glm::translate(rotsclM, cmrLoc);
		}
		void CameraUnit::rotateGlobalX(const float &rad)
		{
			cmrX = glm::rotate(cmrX, -rad, Vector3D<>(1.0f, 0.0f, 0.0f));
			cmrY = glm::rotate(cmrY, -rad, Vector3D<>(1.0f, 0.0f, 0.0f));
			cmrZ = glm::rotate(cmrZ, -rad, Vector3D<>(1.0f, 0.0f, 0.0f));
			rotsclM = glm::rotate(rotsclM, rad, Vector3D<>(1.0f, 0.0f, 0.0f));//!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, cmrLoc);
		}
		void CameraUnit::rotateGlobalY(const float &rad)
		{
			cmrX = glm::rotate(cmrX,-rad, Vector3D<>(0.0f, 1.0f, 0.0f));
			cmrY = glm::rotate(cmrY,-rad, Vector3D<>(0.0f, 1.0f, 0.0f));
			cmrZ = glm::rotate(cmrZ,-rad, Vector3D<>(0.0f, 1.0f, 0.0f));
			rotsclM = glm::rotate(rotsclM, rad, Vector3D<>(0.0f, 1.0f, 0.0f));//!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, cmrLoc);
		}
		void CameraUnit::rotateGlobalZ(const float &rad)
		{
			cmrX = glm::rotate(cmrX,-rad, Vector3D<>(0.0f, 0.0f, 1.0f));
			cmrY = glm::rotate(cmrY,-rad, Vector3D<>(0.0f, 0.0f, 1.0f));
			cmrZ = glm::rotate(cmrZ,-rad, Vector3D<>(0.0f, 0.0f, 1.0f));
			rotsclM = glm::rotate(rotsclM, rad, Vector3D<>(0.0f, 0.0f, 1.0f));//!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, -cmrLoc);
		}
		void CameraUnit::rotateTotal(const float &rad, const Vector3D<> &vec)
		{
			cmrX    = glm::rotate(cmrX   , rad, vec);
			cmrY    = glm::rotate(cmrY   , rad, vec);
			cmrZ    = glm::rotate(cmrZ   , rad, vec);
			cmrLoc  = glm::rotate(cmrLoc , -rad, vec);//!!!!!!!!!!!
			rotsclM = glm::rotate(rotsclM, -rad, vec);//!!!!!!!!!!!!!
			viewM   = glm::rotate(viewM  , -rad, vec);//!!!!!!!!!!
		}
		void CameraUnit::scaleX(const float &x)
		{
			rotsclM = glm::scale(rotsclM, Vector3D<>(x, 0.0f, 0.0f));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		void CameraUnit::scaleY(const float &y)
		{
			rotsclM = glm::scale(rotsclM, Vector3D<>(0.0f, y, 0.0f));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		void CameraUnit::scaleZ(const float &z)
		{
			rotsclM = glm::scale(rotsclM, Vector3D<>(0.0f, 0.0f, z));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		void CameraUnit::scale(const float &x, const float &y, const float &z)
		{
			rotsclM = glm::scale(rotsclM, Vector3D<>(x, y, z));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		const Matrix4D<> &CameraUnit::getMatrix()
		{
			return viewM;
		}
		const Matrix4D<> &CameraUnit::getRotateScaleMatrix()
		{
			return rotsclM;
		}
		const Vector3D<> CameraUnit::getLocation()
		{
			return cmrLoc;
		}
		void CameraUnit::moveForward(const float &spd)
		{
			auto vec = cmrZ * spd;
			cmrLoc -= vec;
			viewM = glm::translate(viewM, vec);
		}
		void CameraUnit::moveSideward(const float& spd)
		{
			auto vec = cmrX * spd;
			cmrLoc -= vec;
			viewM = glm::translate(viewM, vec);
		}
	}
}
