#include "AppWindow.h"

AppWindow::AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	//fprintf(stderr, "On Create \n");

	glGenVertexArrays(4, this->VAO);
	glGenBuffers(4, this->VBO);
	glGenBuffers(4, this->colorVBO);

	this->sample1 = new Triangle(this->VAO[0], this->VBO[0], this->colorVBO[0]);
	this->sample2 = new Triangle2(this->VAO[1], this->VBO[1], this->colorVBO[1]);
	this->sample3 = new Triangle3(this->VAO[2], this->VBO[2], this->colorVBO[2]);
	this->sample4 = new Rectangle(this->VAO[3], this->VBO[3], this->colorVBO[3]);

	VertexShader* vertexShader = new VertexShader();
	FragmentShader* fragmentShader = new FragmentShader();

	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	vertexShader->AttachShaderProgram(shaderProgram);
	fragmentShader->AttachShaderProgram(shaderProgram);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	vertexShader->Destroy(shaderProgram);
	
	
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	//fprintf(stderr, "On Update \n");
	this->sample1->Draw();
	this->sample2->Draw();
	this->sample3->Draw();
	this->sample4->Draw();
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	//fprintf(stderr, "On Destroy \n");
}

AppWindow::~AppWindow()
{
}
