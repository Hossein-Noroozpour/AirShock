#include "hge-perspective-matrix.hpp"
hge::math::PerspectiveUnit::PerspectiveUnit():
	persM(glm::perspective(50.0f, 1.778645833f, 0.5f, 900000000000000000000000.0f))
{
}
hge::math::PerspectiveUnit::~PerspectiveUnit()
{
}
const glm::mat4 &hge::math::PerspectiveUnit::getMatrix()
{
	return persM;
}
