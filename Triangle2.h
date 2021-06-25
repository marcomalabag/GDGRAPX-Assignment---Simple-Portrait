#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Triangle2
{
public:
	Triangle2(GLfloat VAO, GLfloat VBO, GLfloat colorVBO);
	void Draw();
	~Triangle2();

private:
	GLuint VAO;
	GLuint VBO;
	GLuint colorVBO;
};

