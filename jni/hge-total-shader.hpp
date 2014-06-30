#ifndef HGETOTALSHADER_HPP
#define	HGETOTALSHADER_HPP
#include "hge-math.hpp"
#include "hge-shader-engine.hpp"
namespace hge
{
	namespace shader
	{
		class TotalShader
		{
		public:

			enum ShadingMode
			{
				fullShadingMode,
				occlusionQueryShadingMode,
				bakeShadowToTextureShadingMode
			};

		private:

			GLuint modelViewProjectionMatrixUniformLocation;
			GLuint modelMatrixUniformLoaction;
			GLuint sunLightDirectionUniformLocation;
			GLuint mainTextureSamplerLocation;
			GLuint shadingModeUniformLocation;

			GLuint vertexShader;
			GLuint fragmentShader;
			GLuint shaderProgram;

			math::Matrix4D<> modelMatrix;
			math::Matrix4D<> modelViewProjectionMatrix;
			math::Vector3D<> sunLightDirection;

			ShadingMode shadingMode;

		public:

			///\note You must have initialized OpenGL before calling this function.
			TotalShader();
			~TotalShader();

			void setModelMatrix(const math::Matrix4D<> &modelMatrix);
			void setModelViewProjectionMatrix(const math::Matrix4D<> &modelViewProjectionMatrix);
			void changeSunLightDirection(const math::Vector3D<> &sun_dir);

			void use();

			GLuint getModelViewProjectionMatrixUniformLocation();
			GLuint getModelMatrixUniformLoaction();
			GLuint getTextureSamplerLocation();
			GLuint getShadingModeUniformLocation();

			GLuint getVertexShader();
			GLuint getFragmentShader();
			GLuint getShaderProgram();

			void goToFullShadingMode();
			void goToOcclusionQueryShadingMode();
			void goToBakeShadowToTextureShadingMode();

			ShadingMode getShadingMode();
		};
	}
}
#endif
