#include "Window.h"
#include "string.h"

namespace Engine {

	Window::Window(char *title) {
		strcpy(title, this->curTitle);
		
		glfwSetErrorCallback(this->error_callback);
		if (!glfwInit())
			exit(EXIT_FAILURE);
		this->curWindow = glfwCreateWindow(WIDTH, HEIGHT, "title", NULL, NULL);
		if (!(this->curWindow)) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(this->curWindow);
		//glfwSetKeyCallback(this->curWindow, InputHandler::key_callback);
	}

	Window::~Window() {
		//dtor
	}

	void Window::render() {
		glfwSwapBuffers(this->curWindow);
		glfwPollEvents();
	}

	int Window::getWidth() {
		return this->WIDTH;
	}

	int Window::getHeight() {
		return this->HEIGHT;
	}
	
	char* Window::getTitle(){
		return this->curTitle;
	}

	void Window::setKeyCallback(GLFWkeyfun func){
		glfwSetKeyCallback(this->curWindow, func);
	}
	
	void Window::setInputPointer(void* inState){
		glfwSetWindowUserPointer(this->curWindow, inState);
	}
	
	void Window::error_callback(int error, const char* description) {
		fputs(description, stderr);
	}


} //namespace Engine
