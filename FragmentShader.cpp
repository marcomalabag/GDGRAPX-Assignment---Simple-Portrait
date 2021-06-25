#include "FragmentShader.h"

FragmentShader::FragmentShader()
{
	this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->fragmentShader, 1, &this->fragmentShaderSource, NULL);
	glCompileShader(this->fragmentShader);
}

void FragmentShader::Destroy()
{
}

void FragmentShader::AttachShaderProgram(GLuint shaderProgram)
{
	glAttachShader(shaderProgram, this->fragmentShader);
}

FragmentShader::~FragmentShader()
{
}
