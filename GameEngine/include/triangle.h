/**
 * An example object for use by the renderer..
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GLFW/glfw3.h>
#include "window.h"

namespace Engine {	
	class Triangle {
        public:
			Window* window;

            /** Default constructor */
            Triangle(Window* window);
            /** Default destructor */
            virtual ~Triangle();

			void draw(bool direction);
        protected:

        private:
    };
} //namespace Engine
#endif // TRIANGLE_H
