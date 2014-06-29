#include "hge-scene-unit.hpp"
#include "hge-white-shader.hpp"
#include <iostream>
#ifdef _WIN64
#define HGESCENEUNITDEFAULTTEXTUREFILENAME "C:\\Users\\Thany\\Documents\\Visual Studio 2012\\Projects\\HGE\\x64\\Release\\textures\\hge.jpg"
#elif __unix__
#define HGESCENEUNITDEFAULTTEXTUREFILENAME "textures/hge.jpg"
#endif
hge::render::SceneUnit::SceneUnit():
	occlusionQueryShader(new shader::WhiteShader()),
	defaultShader(new shader::SunShader()),
	defaultTexture(new texture::TextureUnit(GL_TEXTURE_2D, HGESCENEUNITDEFAULTTEXTUREFILENAME)),
	currentCameraIndex(0),
	currentPerspectiveIndex(0),
	hasTerrain(false),
	hasGeometry(false)
{
	cameras.push_back(std::shared_ptr<math::CameraMatrix>(new math::CameraMatrix()));
	perspectives.push_back(std::shared_ptr<math::PerspectiveMatrix>(new math::PerspectiveMatrix()));
}
void hge::render::SceneUnit::addGeometry(const std::shared_ptr<GeometryUnit>& geometry)
{
	hasGeometry = true;
	geometry->setOcclusionQueryShader(occlusionQueryShader);
	geometry->setShader(defaultShader);
	geometry->setTexture(defaultTexture);
	geometry->getModelMatrix()->scale(1000.0f);
	geometry->getModelMatrix()->translate(glm::vec3(0.0f, 0.0f, 10.0f));
	geometries.push_back(geometry);
}
void
hge::render::SceneUnit::draw()
{
	auto vp = perspectives[0]->getMatrix() * cameras[0]->getMatrix();
	auto vp_rot = perspectives[0]->getMatrix() * cameras[0]->getRotateScaleMatrix();
	glDepthMask(GL_FALSE);
	for(unsigned int i = 0; i < skies.size(); i++)
	{
		skies[i]->draw(vp_rot);
	}
	glDepthMask(GL_TRUE);
	if(hasTerrain)
	{
		terrain->draw(vp);
	}
	if(hasGeometry)
	{
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
		glDepthMask(GL_FALSE);
		geometries[0]->occlusionQueryStarter(vp);
		for(unsigned int i = 1; i < geometries.size(); i++)
		{
			geometries[i]->occlusionQuery(vp);
		}
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
		glDepthMask(GL_TRUE);
		for(unsigned int i = 0; i < geometries.size(); i++)
		{
			geometries[i]->draw();
		}
	}
}
std::shared_ptr<hge::render::GeometryUnit> hge::render::SceneUnit::getGeoByID(const std::string& id)
{
	for(unsigned int i = 0; i < geometries.size(); i++)
	{
		if(geometries[i]->isThisYourID(id))
		{
			return geometries[i];
		}
	}
	HGEPRINTCODELINE
	std::cout << "Geo Not found!" << std::endl;
	return nullptr;
}
void hge::render::SceneUnit::setTerrain(const std::shared_ptr<TerrainUnit>& t)
{
	hasTerrain = true;
	terrain = t;
}
std::shared_ptr<hge::math::CameraMatrix>
hge::render::SceneUnit::getCamera(const unsigned int& cameraIndex)
{
	return cameras[cameraIndex];
}
void hge::render::SceneUnit::addSky(const std::shared_ptr<SkyBoxUnit> &sky)
{
	skies.push_back(sky);
}

std::shared_ptr<hge::render::SkyBoxUnit> hge::render::SceneUnit::getSky(const unsigned int &skyIndex)
{
	return skies[skyIndex];
}