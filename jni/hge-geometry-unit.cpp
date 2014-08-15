#include "hge-geometry-unit.hpp"
#include <iostream>
#define HGEPRINTCODELINE std::cout << "Debugging: file:" << __FILE__ << " line:" << __LINE__ << std::endl << std::flush;
hge::render::GeometryUnit::GeometryUnit
(const std::string& id, const std::string& name):
id(id), name(name)
#ifdef GL_ES_VERSION_3_0
	,mvp(math::Matrix4D<>(1.0f))
#endif
{
#ifdef GL_ES_VERSION_3_0
	glGenQueries(HGEGEOMETRYNUMBEROFQUERIES, queries);
#endif
}
hge::render::GeometryUnit::~GeometryUnit()
{
#ifdef GL_ES_VERSION_3_0
	glDeleteQueries(HGEGEOMETRYNUMBEROFQUERIES, queries);
#endif
}
void
hge::render::GeometryUnit::setMesh(const std::shared_ptr<hge::render::MeshUnit>& m)
{
	mesh = m;
}
#ifdef GL_ES_VERSION_3_0
void hge::render::GeometryUnit::draw()
{
#else
void hge::render::GeometryUnit::draw(const math::Matrix4D<> &vp)
{
#endif
#ifdef GL_ES_VERSION_3_0
	GLuint query_result = 0;
	glGetQueryObjectuiv(queries[HGEGEOMETRYOCCLUSIONQUERYINDEX], GL_QUERY_RESULT, &query_result);
	if(query_result == 0)
	{
		return;
	}
#elif ! defined(GL_ES_VERSION_2_0)
	glBeginConditionalRender(queries[HGEGEOMETRYOCCLUSIONQUERYINDEX], GL_QUERY_WAIT);
#else
#endif
	mesh->bindVBO();
	shader->use();
	texture->bind(GL_TEXTURE0);
	shader->setModelMatrix(modelMatrix.getConstRotateMatrix());
#ifndef GL_ES_VERSION_3_0
	auto mvp = vp * modelMatrix.getConstRotateScaleTranslateMatrix();
#endif
	shader->setModelViewProjectionMatrix(mvp);
	mesh->bindIBO();
	mesh->draw();
#ifdef GL_ES_VERSION_3_0
#elif ! defined(GL_ES_VERSION_2_0)
	glEndConditionalRender();
#else
#endif
}
#ifdef GL_ES_VERSION_3_0
void
hge::render::GeometryUnit::occlusionQuery(const math::Matrix4D<> &vp)
{
	mvp = vp * modelMatrix.getConstRotateScaleTranslateMatrix();
	glBeginQuery(GL_ANY_SAMPLES_PASSED, queries[HGEGEOMETRYOCCLUSIONQUERYINDEX]);
	occlusionQueryShader->setModelViewProjectionMatrix(mvp);
	occlusionQueryMesh->bindTotal();
	occlusionQueryMesh->draw();
	glEndQuery(GL_ANY_SAMPLES_PASSED);
}
void hge::render::GeometryUnit::occlusionQueryStarter(const math::Matrix4D<> &vp)
{
	mvp = vp * modelMatrix.getConstRotateScaleTranslateMatrix();
	glBeginQuery(GL_ANY_SAMPLES_PASSED, queries[HGEGEOMETRYOCCLUSIONQUERYINDEX]);
	occlusionQueryMesh->bindTotal();
	occlusionQueryShader->use();
	occlusionQueryShader->setModelViewProjectionMatrix(mvp);
	occlusionQueryMesh->draw();
	glEndQuery(GL_ANY_SAMPLES_PASSED);
}
#endif
bool hge::render::GeometryUnit::isThisYourID(const std::string& idstr)
{
	return id == idstr;
}
void hge::render::GeometryUnit::setShader(const std::shared_ptr<shader::ShaderUnit>& sh)
{
	shader = sh;
}
#ifdef GL_ES_VERSION_3_0
void hge::render::GeometryUnit::setOcclusionQueryShader(const std::shared_ptr<shader::ShaderUnit>& sh)
{
	occlusionQueryShader = sh;
}
#endif
void hge::render::GeometryUnit::setTexture(const std::shared_ptr<texture::TextureUnit>& texture)
{
	this->texture = texture;
}
hge::math::ModelUnit*
hge::render::GeometryUnit::getModelMatrix()
{
	return &modelMatrix;
}
std::shared_ptr<hge::render::MeshUnit> hge::render::GeometryUnit::getMesh()
{
	return mesh;
}
#ifdef GL_ES_VERSION_3_0
void
hge::render::GeometryUnit::setOcclusionQueryMesh(const std::shared_ptr<MeshUnit> &m)
{
	occlusionQueryMesh = m;
}
#endif
