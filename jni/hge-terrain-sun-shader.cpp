#include "hge-terrain-sun-shader.hpp"
#include "hge-shader-engine.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#define HGEPRINTCODELINE std::cout << "Debugging: file:" << __FILE__ << " line:" << __LINE__ << std::endl << std::flush;
#define NUMBEROFBUFFERCOMPONENTS 12
hge::shader::TerrainSunShader::TerrainSunShader():
	shaderProgram(render::ShaderEngine::createProgram())
{
	//const std::string shLoc = "C:\\Users\\Thany\\Documents\\Visual Studio 2012\\Projects\\HGE\\x64\\Release\\shaders\\";
	const std::string shLoc = "shaders/";
	std::string pVS = readShaderFile(shLoc + "hge-terrain-shader-string.vertexShader");
	std::string pGS = readShaderFile(shLoc + "hge-terrain-shader-string.geometryShader");
	std::string pFS = readShaderFile(shLoc + "hge-terrain-shader-string.fragmentShader");
	vertexShaderProgram = render::ShaderEngine::addShaderToProgram(pVS, GL_VERTEX_SHADER, shaderProgram);
#ifdef HGETERRAINSUNSHADERDEBUGMODE
	std::cout << "Vertext shader compiled." << std::endl;
	HGEPRINTCODELINE
#endif
#ifdef ANDROID
#else
	geometryShaderProgram = render::ShaderEngine::addShaderToProgram(pGS, GL_GEOMETRY_SHADER, shaderProgram);
#endif
#ifdef HGETERRAINSUNSHADERDEBUGMODE
	std::cout << "Geometry shader compiled." << std::endl;
	HGEPRINTCODELINE
#endif
	fragmentShaderProgram = render::ShaderEngine::addShaderToProgram(pFS, GL_FRAGMENT_SHADER, shaderProgram);
#ifdef HGETERRAINSUNSHADERDEBUGMODE
	std::cout << "Fragment shader compiled." << std::endl;
	HGEPRINTCODELINE
#endif
	hge::render::ShaderEngine::run(shaderProgram);
	mvpmul = render::ShaderEngine::getUniformLocation(std::string("mvpm"), shaderProgram);
#ifdef HGETERRAINSUNSHADERDEBUGMODE
	assert(mvpmul != 0xFFFFFFFF);
#endif
	glUniformMatrix4fv(mvpmul, 1, GL_FALSE, math::Matrix4D<>(1.0f).mat);
	cprtmul = render::ShaderEngine::getUniformLocation(std::string("cprtm"), shaderProgram);
#ifdef HGETERRAINSUNSHADERDEBUGMODE
	assert(cprtmul != 0xFFFFFFFF);
#endif
	glUniform3fv(cprtmul, 1, math::Vector3D<>(1.0f).vec);
	lodnul = render::ShaderEngine::getUniformLocation(std::string("lodn"), shaderProgram);
#ifdef HGETERRAINSUNSHADERDEBUGMODE
	assert(lodnul != 0xFFFFFFFF);
#endif
	glUniform1i(lodnul, 0);
	for(GLuint i = 0; i < HGETERRAINSUNSHADERNUMBEROFTEXTURES; i++)
	{
		tsl[i] = render::ShaderEngine::getUniformLocation(
				std::string("ts[") + std::to_string(i) + "]", shaderProgram);
#ifdef HGETERRAINSUNSHADERDEBUGMODE
		assert(tsl[i] != 0xFFFFFFFF);
#endif
		glUniform1i(tsl[i], i);
	}
}
hge::shader::TerrainSunShader::~TerrainSunShader()
{
	hge::render::ShaderEngine::endObject(vertexShaderProgram);
	hge::render::ShaderEngine::endObject(geometryShaderProgram);
	hge::render::ShaderEngine::endObject(fragmentShaderProgram);
	hge::render::ShaderEngine::endProgram(shaderProgram);
}
void hge::shader::TerrainSunShader::setModelMatrix(const math::Matrix4D<> &modelMatrix)
{
	glUniformMatrix4fv(mmul, 1, GL_FALSE, modelMatrix.mat);
}
void hge::shader::TerrainSunShader::setModelViewProjectionMatrix(const math::Matrix4D<> &modelViewProjectionMatrix)
{
	glUniformMatrix4fv(mvpmul, 1, GL_FALSE, modelViewProjectionMatrix.mat);
}
void hge::shader::TerrainSunShader::setCameraPositionRelativeToModel(const math::Vector3D<>& p)
{
	glUniform3fv(cprtmul, 1, p.vec);
}
void hge::shader::TerrainSunShader::setLODNumber(const GLuint& lodNumber)
{
	glUniform1i(lodnul, lodNumber);
}
void hge::shader::TerrainSunShader::use()
{
	glUseProgram(shaderProgram);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, NUMBEROFBUFFERCOMPONENTS * sizeof(GLfloat), (void*) 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, NUMBEROFBUFFERCOMPONENTS * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, NUMBEROFBUFFERCOMPONENTS * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, NUMBEROFBUFFERCOMPONENTS * sizeof(GLfloat), (void*)(9 * sizeof(GLfloat)));
}
GLuint hge::shader::TerrainSunShader::getModelViewProjectionMatrixUniformLocation()
{
	return mvpmul;
}
GLuint hge::shader::TerrainSunShader::getModelMatrixUniformLoaction()
{
	return mmul;
}
GLuint hge::shader::TerrainSunShader::getVertexShaderProgram()
{
	return vertexShaderProgram;
}
GLuint hge::shader::TerrainSunShader::getGeometryShaderProgram()
{
	return geometryShaderProgram;
}
GLuint hge::shader::TerrainSunShader::getFragmentShaderProgram()
{
	return fragmentShaderProgram;
}
GLuint hge::shader::TerrainSunShader::getShaderProgram()
{
	return shaderProgram;
}
GLuint* hge::shader::TerrainSunShader::getTextureSamplerLocations()
{
	return tsl;
}
std::string hge::shader::TerrainSunShader::readShaderFile(const std::string &fileName)
{
	std::string result;
	std::ifstream in(fileName, std::ios::in);
	if(in)
	{
		in.seekg(0, std::ios::end);
		result.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&result[0], result.size());
		in.close();
		return result;
	}
	std::terminate();
}
