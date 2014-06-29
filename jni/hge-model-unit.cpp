#include "hge-model-matrix.hpp"
hge::math::ModelUnit::ModelUnit():
	localX(glm::vec3(1.0f, 0.0f, 0.0f)),
	localY(glm::vec3(0.0f, 1.0f, 0.0f)),
	localZ(glm::vec3(0.0f, 0.0f, 1.0f)),
	location(glm::vec3(0.0f, 0.0f, 0.0f)),
	rotateMatrix(glm::mat4(1.0f)),
	rotateScaleMatrix(glm::mat4(1.0f)),
	rotateScaleTranslateMatrix(glm::mat4(1.0f))
{
}

void hge::math::ModelUnit::ModelUnit::translate (const glm::vec3 &trn)
{
	location += trn;
	rotateScaleTranslateMatrix = glm::translate(rotateScaleTranslateMatrix, trn);
}

void hge::math::ModelUnit::scale(const float &size)
{
	rotateScaleMatrix = glm::scale(rotateScaleMatrix, glm::vec3(size));
	rotateScaleTranslateMatrix = glm::translate(rotateScaleMatrix, location);
}

const glm::mat4 &hge::math::ModelUnit::getConstRotateScaleTranslateMatrix()
{
	return rotateScaleTranslateMatrix;
}

const glm::mat4 &hge::math::ModelUnit::getConstRotateScaleMatrix()
{
	return rotateScaleMatrix;
}

const glm::mat4 &hge::math::ModelUnit::getConstRotateMatrix()
{
	return rotateMatrix;
}
