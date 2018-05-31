#include "inputHandler.h"

namespace Engine {

	InputHandler::InputHandler(Renderer* rend) {
		
		this->inState = new InputState;
		this->inState->buttonPress = false;
		rend->setInputs(this->key_callback, inState);
	}

	InputHandler::~InputHandler() {
		//dtor
	}

	void InputHandler::readInputs() {
		//printf("test: %d\n", this->inState->buttonPress);
		glfwPollEvents();
	}

	
	InputState* InputHandler::getState() {
		return this->inState;
	}

	void InputHandler::setState(bool val) {
		this->inState->buttonPress = val;
	}
	
	void InputHandler::key_callback(GLFWwindow* Window, int key, int scancode, int action, int mods) {
		InputState* inState = static_cast<InputState*>(glfwGetWindowUserPointer(Window));
		if (key == GLFW_KEY_E && action == GLFW_PRESS)
			//printf("test\n");
			inState->buttonPress = true;
		if (key == GLFW_KEY_E && action == GLFW_RELEASE)
			inState->buttonPress = false;

			//glfwSetWindowShouldClose(Window, GL_TRUE);
	}
} //namespace Engine
