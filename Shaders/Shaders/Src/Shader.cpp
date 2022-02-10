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
	CompileError(vertexShader, "Vertex");

	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	glCompileShader(fragmentShader);
	CompileError(fragmentShader, "Fragment");

	// Create shader program
	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	// Link shader program
	glLinkProgram(ID);

	// Check for shader linking 
	CompileError(ID, "Program");

	// Delete shader program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate() const
{
	glUseProgram(ID);
}

void Shader::Delete() const 
{
	glDeleteProgram(ID);
}

void Shader::CompileError(unsigned int shader, const char* type)
{
	GLint compiled;

	char infoLog[1024];

	if (type != "Program")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

		if (compiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, nullptr, infoLog);

			std::cout << "Error shader compilation: " << type << "\n" << infoLog << std::endl;
		}
		else
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

			if (compiled == GL_FALSE)
			{
				glGetShaderInfoLog(shader, 1024, nullptr, infoLog);

				std::cout << "Shader linking error: " << type << "\n" << infoLog << std::endl;
			}
		}
	}
}