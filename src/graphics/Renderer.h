#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    // vertexSizeBytes = sizeof(vertices), indexSizeBytes = sizeof(indices), indexCount = element count in indices
    void initialize(float* vertices, size_t vertexSizeBytes,
                    unsigned int* indices, size_t indexSizeBytes,
                    GLsizei indexCount);
    void draw(const Shader& shader, const glm::mat4& model);

private:
    GLuint VAO{}, VBO{}, EBO{};
    GLsizei m_indexCount{0};
};

#endif // RENDERER_H