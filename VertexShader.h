#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class VertexShader
{
public:
	const char* vertexShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"layout(location = 1) in vec3 aColor;\n"
		"out vec3 vertexColor;"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"vertexColor = aColor;\n"
		"}\0";
	VertexShader();
	void Destroy(GLuint shaderProgram);
	void AttachShaderProgram(GLuint shaderProgram);
	~VertexShader();

private:
	GLuint vertexShader;;
};

