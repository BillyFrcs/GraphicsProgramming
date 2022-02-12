#pragma once

#ifndef SHADER_HPP
#define SHADER_HPP

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

	void Activate();
	void Delete();

public:
	GLuint ID;

};

#endif
