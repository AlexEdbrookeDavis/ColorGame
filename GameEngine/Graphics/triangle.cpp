#include "triangle.h"
#include "window.h"

namespace Engine {
	GLuint VertexArrayID;
	static const GLfloat g_vertex_buffer_data[] = {
		-0.6f, -0.4f, 0.f,
		0.6f, -0.4f, 0.f,
		0.f, 0.6f, 0.f,
	};
	
    Triangle::Triangle(Window* window) {
        //ctor
		this->window = window;
		
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);


    }

    Triangle::~Triangle() {
        //dtor
    }
	
	void Triangle::draw(bool direction) {
		    // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
			glClear( GL_COLOR_BUFFER_BIT );

			// Draw nothing, see you in tutorial 2 !
			// This will identify our vertex buffer
			GLuint vertexbuffer;
			// Generate 1 buffer, put the resulting identifier in vertexbuffer
			glGenBuffers(1, &vertexbuffer);
			// The following commands will talk about our 'vertexbuffer' buffer
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			// Give our vertices to OpenGL.
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

			// 1st attribute buffer : vertices
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);
			
			//Make a rotation matrix
			glPushMatrix();
			if(direction == false)
				glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
			else
				glRotatef((float) glfwGetTime() * -50.f, 0.f, 0.f, 1.f);
			
			// Draw the triangle !
			glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
			glDisableVertexAttribArray(0);

			//undo the rotation matrix
			glPopMatrix();
		
	}
} //namespace Engine