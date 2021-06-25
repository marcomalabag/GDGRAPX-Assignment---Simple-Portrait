#include "Window.h"

Window::Window()
{
	if (glfwInit() != GLFW_TRUE) {
		fprintf(stderr, "Failed to initialized! \n");
		IsInitialized = false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Marco C. Malabag", NULL, NULL);

	if (window == NULL) {
		fprintf(stderr, "Failed to load window! \n");
		IsInitialized = false;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		IsInitialized = false;
	}


	IsRunning = true;

	
}

bool Window::isRunning()
{
	if (IsRunning) {
		Broadcast();
	}

	return IsRunning;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	this->IsRunning = false;
}

GLFWwindow* Window::getWindow()
{
	return this->window;
}

Window::~Window()
{
}

bool Window::Broadcast()
{
	if (this->IsInitialized) {
		this->onCreate();
		glClearColor(0.0f, 0.4f, 0.0f, 0.0f);
		this->IsInitialized = false;

		while (!glfwWindowShouldClose(window)) {
			float ratio;
			int width, height;
			glfwGetFramebufferSize(window, &width, &height);
			ratio = width / (float)height;
			glViewport(0, 0, width, height);
			glClear(GL_COLOR_BUFFER_BIT);
			this->onUpdate();
			

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		this->onDestroy();
		
	}


	IsRunning = false;

	return true;
}

