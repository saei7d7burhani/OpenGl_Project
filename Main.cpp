#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/graphics/Shader.h"
#include "src/graphics/Renderer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// Vertex positions (x, y)
GLfloat vertices[] = {
    -0.5f,  0.5f,  // Top-left
     0.5f,  0.5f,  // Top-right
    -0.5f, -0.5f,  // Bottom-left
     0.5f, -0.5f   // Bottom-right
};

// Indices for two CCW triangles (square)
GLuint indices[] = {
    0, 2, 1,  // TL, BL, TR
    2, 3, 1   // BL, BR, TR
};

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
glm::vec3 viewPos(0.0f, 0.0f, 3.0f);
glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
glm::vec3 objectColor(1.0f, 0.5f, 0.31f);

int main()
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Square", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, 800, 800);

    // Create shader program
    Shader shader("shaders/main.vert", "shaders/main.frag");
    shader.use();

    shader.setVec3("lightPos", lightPos);
    shader.setVec3("viewPos", viewPos);
    shader.setVec3("lightColor", lightColor);
    shader.setVec3("objectColor", objectColor);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view  = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f);

    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    // Use Renderer with indexed drawing
    Renderer renderer;
    renderer.initialize(vertices, sizeof(vertices), indices, sizeof(indices), 6);

    glDisable(GL_CULL_FACE);
    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Animate the light position (optional)
        float time = glfwGetTime();
        lightPos.x = 1.2f * cos(time);
        lightPos.z = 1.2f * sin(time);

        shader.use();
        shader.setVec3("lightPos", lightPos);

        glm::mat4 model = glm::mat4(1.0f);
        renderer.draw(shader, model);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}