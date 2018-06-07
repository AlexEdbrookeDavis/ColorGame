#include "Window.h"
#include "string.h"

namespace Engine {

	Window::Window(char *title) {
		/*
		THIS MAY NEED MORE RESEARCH
		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 
		*/
		strcpy(title, this->curTitle);
		
		glfwSetErrorCallback(this->error_callback);
		if (!glfwInit())
			exit(EXIT_FAILURE);
		this->curWindow = glfwCreateWindow(WIDTH, HEIGHT, "title", NULL, NULL);
		if (!(this->curWindow)) {
			fprintf( stderr, "Failed to open GLFW window\n" );
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(this->curWindow);
		
		
		glewExperimental=true; // Needed in core profile
		if (glewInit() != GLEW_OK) {
			printf("Failed to initialize GLEW\n");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
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
