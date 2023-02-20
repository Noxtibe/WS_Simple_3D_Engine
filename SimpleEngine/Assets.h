#pragma once
#include <map>
#include <string>
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
using std::map;
using std::string;

// A static singleton Assets class that hosts several
// functions to load resources. Each loaded resource is also 
// stored for future reference by string handles. All functions 
// and resources are static and no public constructor is defined.
class Assets
{
public:
    static std::map<std::string, Texture> textures;
    static std::map<std::string, Shader> shaders;
    static std::map<std::string, Mesh> meshes;

    // Loads a texture from file
    static Texture loadTexture(IRenderer& renderer, const string& filename, const string& name);

    // Retrieves a stored texture
    static Texture& getTexture(const std::string& name);

    // Loads (and generates) a shader program from file loading vertex, fragment (and tessellation control, evaluation,
    // geometry) shader's source code. If tcShaderFile, teShaderFile, gShaderFile are not nullptr, it also loads
    // tessellation and geometry shaders
    static Shader loadShader(const std::string& vShaderFile, const std::string& fShaderFile,
        const std::string& tcShaderFile, const std::string& teShaderFile,
        const std::string& gShaderFile, const std::string& name);

    // Retrieves a stored shader
    static Shader& getShader(const std::string& name);

    // Loads a mesh from file
    static Mesh loadMesh(const string& filename, const string& name);

    // Retrieves a stored mesh
    static Mesh& getMesh(const std::string& name);

    // Properly de-allocates all loaded resources
    static void clear();

private:
    Assets() {}

    // Loads a single texture from file
    static Texture loadTextureFromFile(IRenderer& renderer, const string& filename);

    // Loads and generates a shader from file
    static Shader loadShaderFromFile(const std::string& vShaderFile, const std::string& fShaderFile,
        const std::string& tcShaderFile = "", const std::string& teShaderFile = "",
        const std::string& gShaderFile = "");

    static Mesh loadMeshFromFile(const string& filename);

};