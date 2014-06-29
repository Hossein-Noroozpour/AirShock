#include "hge-camera-unit.hpp"
namespace hge
{
	namespace math
	{
		CameraMatrix::CameraMatrix():
			cmrX(glm::vec3(1.0f, 0.0f, 0.0f)),
			cmrY(glm::vec3(0.0f, 1.0f, 0.0f)),
			cmrZ(glm::vec3(0.0f, 0.0f, 1.0f)),
			cmrLoc(glm::vec3(0.0f, 0.0f, 1300.0f)),
			viewM(glm::lookAt(glm::vec3(0.0f, 0.0f, 1300.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))),
			rotsclM(glm::mat4(1.0f))
		{
		}
		CameraMatrix::~CameraMatrix()
		{
		}
		void CameraMatrix::translate(const glm::vec3 &vec)
		{
			cmrLoc -= vec;
			viewM = glm::translate(viewM, -vec);
		}
		/// \caution unknown issue maybe exist
		void CameraMatrix::move(const glm::vec3 &vec)
		{
			cmrLoc = vec;
			viewM = glm::translate(rotsclM, vec);
		}
		void CameraMatrix::rotateLocalX(const float &rad)
		{
			cmrY = glm::rotate(cmrY, rad, cmrX);
			cmrZ = glm::rotate(cmrZ, rad, cmrX);
			rotsclM = glm::rotate(rotsclM,-rad, cmrX);//!!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, -cmrLoc);
		}
		void CameraMatrix::rotateLocalY(const float &rad)
		{
			cmrX = glm::rotate(cmrX, rad, cmrY);
			cmrZ = glm::rotate(cmrZ, rad, cmrY);
			rotsclM = glm::rotate(rotsclM, -rad, cmrY);//!!!!!!!!!!!!!!1
			viewM = glm::translate(rotsclM,-cmrLoc);
		}
		void CameraMatrix::rotateLocalZ(const float &rad)
		{
			cmrY = glm::rotate(cmrY, rad, cmrZ);
			cmrX = glm::rotate(cmrX, rad, cmrZ);
			rotsclM = glm::rotate(rotsclM, -rad, cmrZ);//!!!!!!!!!!!!!!1
			viewM = glm::translate(rotsclM,-cmrLoc);
		}
		void CameraMatrix::rotateLocal(const float &rad, const glm::vec3 &vec)
		{
			cmrX = glm::rotate(cmrX,-rad, vec);
			cmrY = glm::rotate(cmrY,-rad, vec);
			cmrZ = glm::rotate(cmrZ,-rad, vec);
			rotsclM = glm::rotate(rotsclM, -rad, vec);//!!!!!!!!!!!!!!!!!11
			viewM = glm::translate(rotsclM, cmrLoc);
		}
		void CameraMatrix::rotateGlobalX(const float &rad)
		{
			cmrX = glm::rotate(cmrX, -rad, Math::globalX);
			cmrY = glm::rotate(cmrY, -rad, Math::globalX);
			cmrZ = glm::rotate(cmrZ, -rad, Math::globalX);
			rotsclM = glm::rotate(rotsclM, rad, Math::globalX);//!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, cmrLoc);
		}
		void CameraMatrix::rotateGlobalY(const float &rad)
		{
			cmrX = glm::rotate(cmrX,-rad, Math::globalY);
			cmrY = glm::rotate(cmrY,-rad, Math::globalY);
			cmrZ = glm::rotate(cmrZ,-rad, Math::globalY);
			rotsclM = glm::rotate(rotsclM, rad, Math::globalY);//!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, cmrLoc);
		}
		void CameraMatrix::rotateGlobalZ(const float &rad)
		{
			cmrX = glm::rotate(cmrX,-rad, Math::globalZ);
			cmrY = glm::rotate(cmrY,-rad, Math::globalZ);
			cmrZ = glm::rotate(cmrZ,-rad, Math::globalZ);
			rotsclM = glm::rotate(rotsclM, rad, Math::globalZ);//!!!!!!!!!!!!
			viewM = glm::translate(rotsclM, -cmrLoc);
		}
		void CameraMatrix::rotateTotal(const float &rad, const glm::vec3 &vec)
		{
			cmrX    = glm::rotate(cmrX   , rad, vec);
			cmrY    = glm::rotate(cmrY   , rad, vec);
			cmrZ    = glm::rotate(cmrZ   , rad, vec);
			cmrLoc  = glm::rotate(cmrLoc , -rad, vec);//!!!!!!!!!!!
			rotsclM = glm::rotate(rotsclM, -rad, vec);//!!!!!!!!!!!!!
			viewM   = glm::rotate(viewM  , -rad, vec);//!!!!!!!!!!
		}
		void CameraMatrix::scaleX(const float &x)
		{
			rotsclM = glm::scale(rotsclM, glm::vec3(x, 0.0f, 0.0f));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		void CameraMatrix::scaleY(const float &y)
		{
			rotsclM = glm::scale(rotsclM, glm::vec3(0.0f, y, 0.0f));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		void CameraMatrix::scaleZ(const float &z)
		{
			rotsclM = glm::scale(rotsclM, glm::vec3(0.0f, 0.0f, z));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		void CameraMatrix::scale(const float &x, const float &y, const float &z)
		{
			rotsclM = glm::scale(rotsclM, glm::vec3(x, y, z));
			viewM   = glm::translate(rotsclM, cmrLoc);
		}
		const glm::mat4 &CameraMatrix::getMatrix()
		{
			return viewM;
		}
		const glm::mat4 &CameraMatrix::getRotateScaleMatrix()
		{
			return rotsclM;
		}
		const glm::vec3 CameraMatrix::getLocation()
		{
			return cmrLoc;
		}
		void CameraMatrix::moveForward(const float &spd)
		{
			auto vec = cmrZ * spd;
			cmrLoc -= vec;
			viewM = glm::translate(viewM, vec);
		}
		void CameraMatrix::moveSideward(const float& spd)
		{
			auto vec = cmrX * spd;
			cmrLoc -= vec;
			viewM = glm::translate(viewM, vec);
		}
	}
}
