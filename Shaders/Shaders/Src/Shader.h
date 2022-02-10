#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string GetFile(const char* fileName);

class Shader
{
public:
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate() const;
	void Delete() const;

private:
	static void CompileError(unsigned int shader, const char* type);

public:
	GLuint ID;

};

#endif
