#pragma once
#include <stack>
#include "Mesh.hh"
#include "Camera.hh"
#include "glew.h"
#include "DrawBuffer.hh"

#ifdef TINYOBJLOADER
#include "tiny_obj_loader.h"
#elif defined(ALEMBIC)
#include "Alembic/Abc/IObject.h"
#elif defined(ASSIMP)
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#else
#error "You have to define which importer implementation you want"
#endif

class Importer {
    private:
#ifdef TINYOBJLOADER
	void genMesh(const tinyobj::shape_t&, const tinyobj::attrib_t&, int , std::vector<Mesh>&);
#elif defined(ALEMBIC)
	inline glm::mat4 createTransformMatrix(const glm::vec3 &, const glm::vec3 &, const glm::vec3 &);
	inline glm::vec3 AlembicVec3toGlmVec3(Alembic::Abc::V3d const &);
	void getFullPositionScale(Alembic::Abc::IObject const &, glm::vec3 &, glm::vec3 &, glm::vec3 &);
	inline glm::mat4 M44d4x4ToGlm(const Alembic::Abc::M44d&);
	void visitObject(Alembic::Abc::IObject, std::string const &, DrawBuffer&);
#else
	inline glm::mat4 aiMatrix4x4ToGlm(const aiMatrix4x4& from);
	void genMesh(const aiScene* scene_, DrawBuffer&);
#endif
    public:
	Importer(std::string file, DrawBuffer&);
	void load(std::string& file, DrawBuffer&);
};
