

#include "window.h"
#include "triangle.h"
#include "renderer.h"
#include "string"

namespace Engine {
	Triangle *tri;
	Window *wind;
	
    Renderer::Renderer() {
        //ctor
		char title[] = "Simple example";
		wind = new Window(title);
		tri = new Triangle(wind);
		
		this->rendState = new RenderState;
		this->rendState->leftTri = false;

    }

    Renderer::~Renderer() {
        //dtor
    }
	
	void Renderer::render() {
		tri->draw(this->rendState->leftTri);
		wind->render();
	}
	
	Window* Renderer::getWindow() {
		return wind;
	}
	
	RenderState* Renderer::getState() {
		return this->rendState;
	}
	
	void Renderer::setInputs(GLFWkeyfun func, void* inState) {
		wind->setKeyCallback(func);
		wind->setInputPointer(inState);
	}
} //namespace Engine