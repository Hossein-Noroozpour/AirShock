#ifndef HGE_MODEL_UNIT_HPP_
#define HGE_MODEL_UNIT_HPP_
#include "glm/glm.hpp"
namespace hge
{
	namespace math
	{
		class ModelUnit
		{
		private:
			glm::vec3 localX;//object local directionX
			glm::vec3 localY;//object local directionY
			glm::vec3 localZ;//object local directionZ
			glm::vec3 location;//object location
			glm::mat4 rotateScaleTranslateMatrix;//rotation scale translate matrix
			glm::mat4 rotateScaleMatrix;//rotation scale matrix
			glm::mat4 rotateMatrix;	//rotation matrix
		public:
			ModelMatrix();
			void translate(const glm::vec3 &trn);
			void scale(const float &size);
			const glm::mat4 &getConstRotateScaleTranslateMatrix();
			const glm::mat4 &getConstRotateScaleMatrix();
			const glm::mat4 &getConstRotateMatrix();
		};
	}
}
#endif
