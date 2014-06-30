#ifndef HGETEXTUREUNIT_HPP
#define	HGETEXTUREUNIT_HPP
#ifdef ANDROID
#include <GLES3/gl3.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif
#include <string>
#include <FreeImage.h>
namespace hge
{
	namespace texture
	{
		class TextureUnit
		{
		public:
			TextureUnit(GLenum TextureTarget, const std::string& FileName);
			bool load();
			void bind(GLenum TextureUnit);
		private:
			GLenum m_textureTarget;
			GLuint m_textureObj;
		};
	}
}
#endif	/* TEXTURE_H */
