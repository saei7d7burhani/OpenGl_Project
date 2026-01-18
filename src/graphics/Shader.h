#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp> // Include GLM for vector types

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void deleteProgram();

    // New method to set a vec3 uniform
    void setVec3(const std::string& name, const glm::vec3& value);

    // Existing method for setting a mat4 uniform
    void setMat4(const std::string& name, const glm::mat4& value) const;

    // Add this method declaration to the Shader class public section
    void setInt(const std::string& name, int value) const;

private:
    std::string get_file_contents(const char* filePath);
    void checkCompileErrors(GLuint shader, const std::string& type);
};

#endif