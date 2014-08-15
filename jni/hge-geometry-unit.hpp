#ifndef HGE_GEOMETRY_UNIT_HPP_
#define HGE_GEOMETRY_UNIT_HPP_
#include <string.h>
#include "hge-mesh-unit.hpp"
#include "hge-model-unit.hpp"
#include "hge-shader-unit.hpp"
#include "hge-texture-unit.hpp"
#include "hge-math.hpp"
#include <memory>
//#define HGEGEOMETRYDEBUGMVPVALUECHECK
#ifdef GL_ES_VERSION_3_0
#define HGEGEOMETRYNUMBEROFQUERIES 2
#define HGEGEOMETRYOCCLUSIONQUERYINDEX 0
#define HGEGEOMETRYPIXELSPASSED 1
#endif
namespace hge
{
	namespace render
	{
		class GeometryUnit
		{
		public:
			GeometryUnit(const std::string& id, const std::string& name);
			~GeometryUnit();
			void setMesh(const std::shared_ptr<MeshUnit>& m);
#ifdef GL_ES_VERSION_3_0
			void setOcclusionQueryMesh(const std::shared_ptr<MeshUnit>& m);
			void draw();
			void occlusionQuery(const math::Matrix4D<>& vp);
			void occlusionQueryStarter(const math::Matrix4D<>& vp);
			void setOcclusionQueryShader(const std::shared_ptr<shader::ShaderUnit>& shader);
#else
			void draw(const math::Matrix4D<>& vp);
#endif
			bool isThisYourID(const std::string& idstr);
			void setShader(const std::shared_ptr<shader::ShaderUnit>& shader);
			void setTexture(const std::shared_ptr<texture::TextureUnit>& texture);
			math::ModelUnit* getModelMatrix();
			std::shared_ptr<MeshUnit> getMesh();
		private:
#ifdef GL_ES_VERSION_3_0
			GLuint queries[HGEGEOMETRYNUMBEROFQUERIES];
#endif
			std::string id;
			std::string name;
#ifdef GL_ES_VERSION_3_0
			math::Matrix4D<> mvp;
#endif
			math::ModelUnit modelMatrix;
			std::shared_ptr<MeshUnit> mesh;
#ifdef GL_ES_VERSION_3_0
			std::shared_ptr<MeshUnit> occlusionQueryMesh;
#endif
			std::shared_ptr<shader::ShaderUnit> shader;
#ifdef GL_ES_VERSION_3_0
			std::shared_ptr<shader::ShaderUnit> occlusionQueryShader;
#endif
			std::shared_ptr<texture::TextureUnit> texture;
		};
	}
}
#endif
