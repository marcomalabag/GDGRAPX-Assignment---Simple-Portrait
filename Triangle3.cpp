#include "Triangle3.h"

Triangle3::Triangle3(GLfloat VAO, GLfloat VBO, GLfloat colorVBO)
{
	GLfloat thirdTriangle[] = {
		0.7f, 0.0f, 0.0f,
		0.2f, 0.0f, 0.0f,
		0.45f, 0.4f, 0.0f
	};

	GLfloat colorBufferData3[] = {
		1.9f, 0.5f, 0.0f,
		1.9f, 0.5f, 0.0f,
		1.9f, 0.5f, 0.0f
	};

	this->VAO = VAO;
	this->VBO = VBO;
	this->colorVBO = colorVBO;

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(thirdTriangle), thirdTriangle, GL_STATIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, this->colorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorBufferData3), colorBufferData3, GL_STATIC_DRAW);

}

void Triangle3::Draw()
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

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

Triangle3::~Triangle3()
{
}
