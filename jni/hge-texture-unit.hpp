#ifndef HGETEXTUREUNIT_HPP
#define	HGETEXTUREUNIT_HPP
#ifdef ANDROID
#include <GLES2/gl2.h>
#include <png.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#include <FreeImage.h>
#endif
#include <string>
namespace hge
{
	namespace texture
	{
		class TextureUnit
		{
		public:
#ifdef ANDROID
#else
			TextureUnit(GLenum TextureTarget, const std::string& FileName);
			bool load();
#endif
			void bind(GLenum TextureUnit);
		private:
			GLenum m_textureTarget;
			GLuint m_textureObj;
		};
	}
}
#endif
