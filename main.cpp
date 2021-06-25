#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "AppWindow.h"

int main() {

	AppWindow app; // AppWindow extends the Window class. The Window class is responsible for initializing the window 
	while (app.isRunning());
}
