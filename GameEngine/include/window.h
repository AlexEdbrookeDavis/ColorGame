/**
 * The Window serves to handle the bare basics of window management.
 * Includes window generation, rendering, and querys.
 */

#ifndef WINDOW_H
#define WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <windows.h>
//#include "GL/wglext.h"
#include "string"

namespace Engine {


	class Window
	{


		public:
			/** Default constructor */
			Window(char *title);
			/** Default destructor */
			virtual ~Window();

			void render();
			
			int getWidth();
			int getHeight();
			char* getTitle();
			GLFWwindow* getGLFWwindow();
			
			void setKeyCallback(GLFWkeyfun func);
			void setInputPointer(void* inState);
		protected:

		private:
			double width;
			double height;
			
			GLFWwindow* curWindow;
			char curTitle[];
			
			static void error_callback(int error, const char* description);
	};
} //namespace Engine

#endif // WINDOW_H
