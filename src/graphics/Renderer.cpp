#include "Renderer.h"
#include "Shader.h"

Renderer::Renderer() = default;

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Renderer::initialize(float* vertices, size_t vertexSizeBytes,
                          unsigned int* indices, size_t indexSizeBytes,
                          GLsizei indexCount) {
    m_indexCount = indexCount;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSizeBytes, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSizeBytes, indices, GL_STATIC_DRAW);

    // position attribute: 2 floats per vertex
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Renderer::draw(const Shader& shader, const glm::mat4& model) {
    const_cast<Shader&>(shader).use();
    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}