#include "Window.h"
#include "string.h"

namespace Engine {

	/*bool WGLExtensionSupported(const char *extension_name)
	{
		// this is pointer to function which returns pointer to string with list of all wgl extensions
		PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglGetExtensionsStringEXT = NULL;

		// determine pointer to wglGetExtensionsStringEXT function
		_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) wglGetProcAddress("wglGetExtensionsStringEXT");

		if (strstr(_wglGetExtensionsStringEXT(), extension_name) == NULL)
		{
			// string was not found
			return false;
		}

		// extension is supported
		return true;
	}*/

	Window::Window(char *title) {
		/*
		THIS MAY NEED MORE RESEARCH
		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 
		*/
		
		/*PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
		PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;

		if (WGLExtensionSupported("WGL_EXT_swap_control"))
		{
			// Extension is supported, init pointers.
			wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) wglGetProcAddress("wglSwapIntervalEXT");

			// this is another function from WGL_EXT_swap_control extension
			wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC) wglGetProcAddress("wglGetSwapIntervalEXT");
		}*/
		
		strcpy(title, this->curTitle);
		
		glfwSetErrorCallback(this->error_callback);
		if (!glfwInit())
			exit(EXIT_FAILURE);
		
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		this->width = mode->width;
		this->height = mode->height;

		this->curWindow = glfwCreateWindow(this->width, this->height, "title", glfwGetPrimaryMonitor(), NULL);
		//this->curWindow = glfwCreateWindow(this->width, this->height, "title", NULL, NULL);
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
		
		glfwSetInputMode(this->curWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		
		glfwSwapInterval(1);
	}

	Window::~Window() {
		//dtor
	}

	void Window::render() {
		glfwSwapBuffers(this->curWindow);
	}

	int Window::getWidth() {
		return this->width;
	}

	int Window::getHeight() {
		return this->height;
	}
	
	char* Window::getTitle(){
		return this->curTitle;
	}

	GLFWwindow* Window::getGLFWwindow(){
		return this->curWindow;
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
