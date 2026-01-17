#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void initialize(float* vertices, size_t size);
    void draw(const Shader& shader, const glm::mat4& model);

private:
    GLuint VAO, VBO;
};

#endif // RENDERER_H