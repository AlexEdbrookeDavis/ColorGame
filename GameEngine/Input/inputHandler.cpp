#include "inputHandler.h"

namespace Engine {

	InputHandler::InputHandler(Renderer* rend, Window* window) {
		this->wind = window;
		
		this->inState = new InputState;
		this->inState->ePress = false;
		this->inState->wPress = false;
		this->inState->aPress = false;
		this->inState->sPress = false;
		this->inState->dPress = false;
		this->inState->upPress = false;
		this->inState->leftPress = false;
		this->inState->downPress = false;
		this->inState->rightPress = false;
		this->inState->spacePress = false;
		this->inState->leftCtrlPress = false;
		this->inState->escPress = false;
		this->inState->mousex = 0;
		this->inState->mousey = 0;
		rend->setInputs(this->key_callback, inState);
	}

	InputHandler::~InputHandler() {
		//dtor
	}

	void InputHandler::readInputs() {
		glfwPollEvents();
		// Get mouse position
		double xpos, ypos;
		glfwGetCursorPos(this->wind->getGLFWwindow(), &xpos, &ypos);
		// Reset mouse position for next frame
		glfwSetCursorPos(this->wind->getGLFWwindow(), 640/2, 480/2);
		this->inState->mousex = double(640/2 - xpos);
		this->inState->mousey = double(480/2 - ypos);
	}

	
	InputState* InputHandler::getState() {
		return this->inState;
	}

	void InputHandler::setState(bool val) {
		this->inState->ePress = val;
	}
	
	void InputHandler::key_callback(GLFWwindow* Window, int key, int scancode, int action, int mods) {
		InputState* inState = static_cast<InputState*>(glfwGetWindowUserPointer(Window));
		bool *pressTarget = NULL;
		switch (key) {
			case GLFW_KEY_E:
				pressTarget = &inState->ePress;
				break;
			case GLFW_KEY_W:
				pressTarget = &inState->wPress;
				break;
			case GLFW_KEY_A:
				pressTarget = &inState->aPress;
				break;
			case GLFW_KEY_S:
				pressTarget = &inState->sPress;
				break;
			case GLFW_KEY_D:
				pressTarget = &inState->dPress;
				break;
			case GLFW_KEY_UP:
				pressTarget = &inState->upPress;
				break;
			case GLFW_KEY_LEFT:
				pressTarget = &inState->leftPress;
				break;
			case GLFW_KEY_DOWN:
				pressTarget = &inState->downPress;
				break;
			case GLFW_KEY_RIGHT:
				pressTarget = &inState->rightPress;
				break;				
			case GLFW_KEY_SPACE:
				pressTarget = &inState->spacePress;
				break;		
			case GLFW_KEY_LEFT_CONTROL:
				pressTarget = &inState->leftCtrlPress;
				break;
			case GLFW_KEY_ESCAPE:
				pressTarget = &inState->escPress;
				break;	
			}
		if (pressTarget != NULL && action == GLFW_PRESS)
			*pressTarget = true;
		if (pressTarget != NULL && action == GLFW_RELEASE)
			*pressTarget = false;
			//glfwSetWindowShouldClose(Window, GL_TRUE);
	}
} //namespace Engine
