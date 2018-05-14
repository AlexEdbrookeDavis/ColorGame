#include "triangle.h"
#include "window.h"

namespace Engine {
		
    Triangle::Triangle(Window* window) {
        //ctor
		this->window = window;
    }

    Triangle::~Triangle() {
        //dtor
    }
	
	void Triangle::draw(bool direction) {


		//while (!glfwWindowShouldClose(window)) {
			float ratio;
			int width, height;
			//glfwGetFramebufferSize(window, &width, &height);
			width = this->window->getWidth();
			height = this->window->getHeight();
			ratio = width / (float) height;
			glViewport(0, 0, width, height);
			glClear(GL_COLOR_BUFFER_BIT);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			if(direction == false)
				glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
			else
				glRotatef((float) glfwGetTime() * -50.f, 0.f, 0.f, 1.f);
			glBegin(GL_TRIANGLES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-0.6f, -0.4f, 0.f);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.6f, -0.4f, 0.f);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(0.f, 0.6f, 0.f);
			glEnd();
		//}
		//glfwDestroyWindow(window);
		//glfwTerminate();
		//exit(EXIT_SUCCESS);
	}
} //namespace Engine