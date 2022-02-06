#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Vertex shader
const char* VERTEX_SHADER_SOURCE = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

// Fragment shader 
const char* FRAGMENT_SHADER_SOURCE = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main(void)
{
    // Initialize the library
    if (!glfwInit())
        return -1;

    // Hint desire value
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] =
    {
        -0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
        0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
        0.0f, 0.5f * static_cast<float>(sqrt(3)) * 2 / 3, 0.0f
    };

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Application", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();

        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error!" << std::endl;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // Gen buffers
    unsigned int value;

    glGenBuffers(1, &value);

    // Vertex shader source
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &VERTEX_SHADER_SOURCE, nullptr);
    glCompileShader(vertexShader);

    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &FRAGMENT_SHADER_SOURCE, nullptr);
    glCompileShader(fragmentShader);

    // Create shader program
    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Link shader program
    glLinkProgram(shaderProgram);

    // Delete shader program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLuint VBO;
    GLuint VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3. * sizeof(float), static_cast<void*>(0));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Render color
    glClearColor(0.5f, 0.3f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.5f, 0.3f, 0.7f, 1.0f); // Render color
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Delete window before ending the program
    glfwDestroyWindow(window);

    glfwTerminate();

    return EXIT_SUCCESS;
}