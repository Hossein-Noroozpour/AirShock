#ifndef HGE_PERSPECTIVE_UNIT_HPP_
#define HGE_PERSPECTIVE_UNIT_HPP_
#include "glm/glm.hpp"
namespace hge
{
	namespace math
	{
		class PerspectiveMatrix
		{
		private:
			glm::mat4 persM;
		public:
			PerspectiveMatrix();
			~PerspectiveMatrix();
			const glm::mat4 &getMatrix();
		};
	}
}
#endif
