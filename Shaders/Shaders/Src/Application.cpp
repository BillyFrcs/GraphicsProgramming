#include <cstdlib>
#include <iostream>

// #include <GL/glew.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Buffer.h"

// Window screen
constexpr auto WIDTH = 640;
constexpr auto HEIGHT = 480;

// Vertices coordinates
GLfloat vertices[] =
{
    // Coordinates                                    // Color
    -0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.1f, 0.7f, 0.1f, 0.03f, // Lower left corner  
    0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.1f, 0.7f, 0.1f, 0.03f, // Lower right corner
    0.0f, 0.5f * static_cast<float>(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.12f, // Upper corner
    -0.25f, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f, 0.1f, 0.45f, 0.17f, // Inner left
    0.25, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f, 0.1f, 0.45f, 0.17f, // Inner right
    0.0f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f, 0.1f, 0.3f, 0.02f // Inner down
};

// Vertices indices
GLuint indices[] =
{
    0, 3, 5, // Lower left triangle
    3, 2, 4, // Lower right triangle
    5, 4, 1 // Upper triangle
};

int main(void)
{
    // Initialize the library
    if (!glfwInit())
        return -1;

    // Hint desire value
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Shaders", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();

        throw("Failed to create a Window!");

        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, WIDTH, HEIGHT);

    // Check OpenGL version
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    Shader ShaderProgram("Shaders/Vertex.vert", "Shaders/Fragment.frag");

    auto* VAO = new VertexArray();
    VAO->Bind();

    auto* VBO = new VertexBuffer(vertices, sizeof(vertices));

    Buffer* EBO = new Buffer(indices, sizeof(indices));

    VAO->LinkAttribute(*VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), static_cast<void*>(0));
    VAO->LinkAttribute(*VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    VAO->Unbind();
    VBO->Unbind();
    EBO->Unbind();

    GLuint Uniform = glGetUniformLocation(ShaderProgram.ID, "scale");

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.19f, 0.15f, 0.3f, 1.0f); // Render background color
        glClear(GL_COLOR_BUFFER_BIT);

        ShaderProgram.Activate();
        glUniform1f(Uniform, 0.5f);

        VAO->Bind();

        // Draw the triangle
        // glDrawArrays(GL_TRIANGLES, 0, 3); // Draw default triangle
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0); // Draw triangle with index buffer

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Delete all the objects
    VAO->Delete();
    VBO->Delete();
    EBO->Delete();

    ShaderProgram.Delete();

    // Delete window before ending the program
    glfwDestroyWindow(window);

    glfwTerminate();

    return EXIT_SUCCESS;
}