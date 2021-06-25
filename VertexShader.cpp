#include "VertexShader.h"

VertexShader::VertexShader()
{
	this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->vertexShader, 1, &this->vertexShaderSource, NULL);
	glCompileShader(this->vertexShader);
}

void VertexShader::Destroy(GLuint shaderProgram)
{
	glDetachShader(shaderProgram, this->vertexShader);
	glDeleteShader(this->vertexShader);
}

void VertexShader::AttachShaderProgram(GLuint shaderProgram)
{
	glAttachShader(shaderProgram, this->vertexShader);
}

VertexShader::~VertexShader()
{
}
