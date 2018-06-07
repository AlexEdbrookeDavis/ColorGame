#include "cube.h"
#include "window.h"



namespace Engine {
	GLuint VertexArrayID;
	
	

	
    Cube::Cube(Window* window) {
		
        //ctor
		this->window = window;
		
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);


    }

    Cube::~Cube() {
        //dtor
    }
	
	void Cube::draw(bool direction, glm::mat4 Projection, glm::mat4 View, int shaderProgram) {
		
	
		//Identity Matrix
		glm::mat4 Model = glm::mat4(1.0f);
		
		//Rotation
		if(direction == false)
			Model = glm::rotate(Model, (float) glfwGetTime() * 1.f, glm::vec3(0.0f, 0.0f, 1.0f));
		else
			Model = glm::rotate(Model, (float) glfwGetTime() * -1.f, glm::vec3(0.0f, 0.0f, 1.0f));
		
		//Final mvp matrix
		glm::mat4 mvp = Projection * View * Model;


		//Load Vertex Data
		GLuint vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(
			0,                  //attribute 0
			3,                  //size
			GL_FLOAT,           //type
			GL_FALSE,           //normalized?
			0,                  //stride
			(void*)0            //array buffer offset
		);
		
		//Load Color Data
		GLuint colorbuffer;
		glGenBuffers(1, &colorbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);
					glVertexAttribPointer(
			1,                  //attribute 0
			3,                  //size
			GL_FLOAT,           //type
			GL_FALSE,           //normalized?
			0,                  //stride
			(void*)0            //array buffer offset
		);
		
		//Enable
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		//Enable Basic Shader
        glUseProgram(shaderProgram);

		//Push mvp to shader
        int vertexMVPLocation = glGetUniformLocation(shaderProgram, "mvp");
        glUniformMatrix4fv(vertexMVPLocation, 1, GL_FALSE, glm::value_ptr(mvp));	
		
		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 12*3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		
		//Remove attribute data
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);	
	}
} //namespace Engine