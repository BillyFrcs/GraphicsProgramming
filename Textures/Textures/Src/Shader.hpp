#pragma once

#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Shader
{
public:
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate() const;
	void Delete() const;

private:
	static void CompileError(unsigned int shader, const char* type);

	static std::string GetFile(const char* fileName);

public:
	GLuint ID;

};

#endif
