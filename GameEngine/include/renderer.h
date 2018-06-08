/**
 * The Renderer handles the generation of graphics in the engine.
 * It must not contain ANY game logic, but rather be able to handle graphical states created from said logic
 */

#ifndef RENDER_H
#define RENDER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "window.h"

namespace Engine {

	struct RenderState {
		bool leftTri;
		float xPos;
		float yPos;		
		float zPos;		
		float xRotate;
		float yRotate;
	};
	
	class Renderer {
        public:
			RenderState* rendState;
			
            /** Default constructor */
            Renderer();
            /** Default destructor */
            virtual ~Renderer();

			void render();
			
			Window* getWindow();
			RenderState* getState();

			void setInputs(GLFWkeyfun func, void* inState);
        protected:

        private:
			int shaderProgram;
    };

} //namespace Engine


#endif // RENDER_H
