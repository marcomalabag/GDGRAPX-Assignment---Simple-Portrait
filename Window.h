#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
	public:
		Window();
		bool isRunning();
		virtual void onCreate();
		virtual void onUpdate();
		virtual void onDestroy();
		GLFWwindow* getWindow();
		~Window();


	private:
		GLFWwindow* window;
		bool Broadcast();

	protected:
		bool IsInitialized = true;
		bool IsRunning;


};

