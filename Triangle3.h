#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Triangle3
{
public:
	Triangle3(GLfloat VAO, GLfloat VBO, GLfloat colorVBO);
	void Draw();
	~Triangle3();

private:
	GLuint VAO;
	GLuint VBO;
	GLuint colorVBO;
};

