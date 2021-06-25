#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class FragmentShader
{
public:
	const char* fragmentShaderSource = "#version 330 core\n"
		"in vec3 vertexColor;\n"
		"out vec3 FragColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = vertexColor;\n"
		"}\0";
	FragmentShader();
	void Destroy();
	void AttachShaderProgram(GLuint shaderProgram);
	~FragmentShader();

private:
	GLuint fragmentShader;
};

