#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Rectangle
{
public:
	Rectangle(GLfloat VAO, GLfloat VBO, GLfloat colorVBO);
	void Draw();
	~Rectangle();

private:
	GLuint VAO;
	GLuint VBO;
	GLuint colorVBO;
};

