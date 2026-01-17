#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "src/graphics/Shader.h"
#include "src/graphics/Renderer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

float vertices[] = {
	// Positions         // Normals
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  // Bottom-left
	 0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  // Bottom-right
	 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top-center
};

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
glm::vec3 viewPos(0.0f, 0.0f, 3.0f);
glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
glm::vec3 objectColor(1.0f, 0.5f, 0.31f);

int main()
{
	//Window creation
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	
	// Generate and bind a Vertex Array Object (VAO)
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Generate and bind a Vertex Buffer Object (VBO)
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Copy the vertex data into the VBO
	   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	   // Configure the vertex attribute pointers
	   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	   glEnableVertexAttribArray(0);
	   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	   glEnableVertexAttribArray(1);

	   // Unbind the VAO (optional, for safety)
	   glBindVertexArray(0);

	// Create shader program
	Shader shader("shaders/main.vert", "shaders/main.frag");
	shader.use();

	shader.setVec3("lightPos", lightPos);
	shader.setVec3("viewPos", viewPos);
	shader.setVec3("lightColor", lightColor);
	shader.setVec3("objectColor", objectColor);

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f);

	shader.setMat4("model", model);
	shader.setMat4("view", view);
	shader.setMat4("projection", projection);

	// Initialize renderer
	Renderer renderer;
	renderer.initialize(vertices, sizeof(vertices));		

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Animate the light position
		float time = glfwGetTime(); // Get the elapsed time
		lightPos.x = 1.2f * cos(time); // Rotate around the origin
		lightPos.z = 1.2f * sin(time);

		// Use the shader program
		shader.use();

		// Update the light position in the shader
		shader.setVec3("lightPos", lightPos);

		glm::mat4 model = glm::mat4(1.0f);
		renderer.draw(shader, model);

		// Swap buffers and poll events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}