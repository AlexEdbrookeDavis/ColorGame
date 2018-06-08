/**
 * This handles input by the user, placing this input information into a shared struct for use by the game logic.
 * Include keyboard and mouse input.
 */

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "renderer.h"

namespace Engine {

	struct InputState {
		bool ePress;
		bool wPress;
		bool aPress;
		bool sPress;
		bool dPress;
		bool upPress;
		bool leftPress;
		bool rightPress;
		bool downPress;
		bool spacePress;
		bool leftCtrlPress;
		bool escPress;
	};
	
	class InputHandler {
        public:
			InputState* inState;

            /** Default constructor */
            InputHandler(Renderer* rend);
            /** Default destructor */
            virtual ~InputHandler();

			void readInputs();
			
			InputState* getState();
			
			void setState(bool val);
			
			static void key_callback(GLFWwindow* Window, int key, int scancode, int action, int mods);

        protected:

        private:
		
    };
} //namespace Engine
#endif // INPUT_HANDLER_H
