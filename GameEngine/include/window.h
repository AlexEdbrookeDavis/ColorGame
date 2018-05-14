/**
 * The Window serves to handle the bare basics of window management.
 * Includes window generation, rendering, and querys.
 */

#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "string"

namespace Engine {
	class Window
	{


		public:
			const int WIDTH = 640;
			const int HEIGHT = 480;
			/** Default constructor */
			Window(char *title);
			/** Default destructor */
			virtual ~Window();

			void render();
			
			int getWidth();
			int getHeight();
			char* getTitle();
			
			void setKeyCallback(GLFWkeyfun func);
			void setInputPointer(void* inState);
		protected:

		private:
		
			GLFWwindow* curWindow;
			char curTitle[];
			
			static void error_callback(int error, const char* description);
	};
} //namespace Engine

#endif // WINDOW_H
