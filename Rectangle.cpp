#include "Rectangle.h"

Rectangle::Rectangle(GLfloat VAO, GLfloat VBO, GLfloat colorVBO)
{
	GLfloat vertexBufferData[] = {
			-0.4f, -1.0f, 0.0f,
			0.4f, -1.0f, 0.0f,
			-0.4f, -0.6f, 0.0f,
			0.4f, -0.6f, 0.0f
	};


	GLfloat colorBufferData[] = {
		0.9f, 0.5f, 0.0f,
		0.9f, 0.5f, 0.0f,
		0.9f, 0.5f, 0.0f,
		0.9f, 0.5f, 0.0f,
	};

	this->VAO = VAO;
	this->VBO = VBO;
	this->colorVBO = colorVBO;

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, this->colorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorBufferData), colorBufferData, GL_STATIC_DRAW);
}

void Rectangle::Draw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0, // stride, let opengl handle it
		(void*)0
	);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->colorVBO);
	glVertexAttribPointer(
		1,					// used by vertex shader
		3,                  // size of the vertex attribute, which should be 3 values
		GL_FLOAT,           // type data type used
		GL_FALSE,           // normalized?, used for lighting
		0,                  //stride, we can give 0 to let opengl handle it, we can also give 3 * sizeof(GLfloat).
		(void*)0            // array buffer offset, defines where we start in the buffer
	);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

Rectangle::~Rectangle()
{
}
