#pragma once
#include "Window.h"
#include "Triangle.h"
#include "Triangle2.h"
#include "Triangle3.h"
#include "Rectangle.h"
#include "VertexShader.h"
#include "FragmentShader.h"

class AppWindow : public Window
{
public:
	AppWindow();
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
	~AppWindow();

private:
	Triangle* sample1;
	Triangle2* sample2;
	Triangle3* sample3;
	Rectangle* sample4;
	GLuint VAO[4];
	GLuint VBO[4];
	GLuint colorVBO[4];
	
};

