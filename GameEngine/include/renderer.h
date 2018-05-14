/**
 * The Renderer handles the generation of graphics in the engine.
 * It must not contain ANY game logic, but rather be able to handle graphical states created from said logic
 */

#ifndef RENDER_H
#define RENDER_H

#include <GLFW/glfw3.h>
#include "window.h"

namespace Engine {

	struct RenderState {
		bool leftTri;
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
    };

} //namespace Engine


#endif // RENDER_H
