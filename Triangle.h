#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>



class Triangle
{
public:
	Triangle(GLfloat VAO, GLfloat VBO, GLfloat colorVBO);
	void Draw();
	~Triangle();

private:
	GLuint VAO;
	GLuint VBO;
	GLuint colorVBO;
	
};

