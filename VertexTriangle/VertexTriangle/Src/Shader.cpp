#include "Shader.h"

std::string GetFile(const char* fileName)
{
	std::ifstream input(fileName, std::ios::binary);

	if (input)
	{
		std::string content;

		input.seekg(0, std::ios::end);

		content.resize(input.tellg());

		input.seekg(0, std::ios::beg);
		input.read(&content[0], content.size());
		input.close();

		return content;
	}

	throw(errno); 
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = GetFile(vertexFile);
	std::string fragmentCode = GetFile(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Vertex shader source
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, nullptr);
	glCompileShader(vertexShader);

	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	glCompileShader(fragmentShader);

	// Create shader program
	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	// Link shader program
	glLinkProgram(ID);

	// Delete shader program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete() 
{
	glDeleteProgram(ID);
}