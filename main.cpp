/**
 * This will act as the instantiator of the application
 * and will kick off the primary game loop
 */

#include <assert.h>
#include <stddef.h>

#include "gameLoop.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	
	// Initialise GLFW
	glewExperimental = true; // Needed for core profile
	if( !glfwInit() ) {
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}



    //Default Exit Status
    //int FinalStatusCode = Engine::StatusCodeSafeExit;

    //Setup logger destination
    //Engine::FileLogger gameLog("gameLog.txt");

    //generate game Application
    Engine::GameLoop *application = new Engine::GameLoop();
    assert(application != NULL);

    //Pass command line to application
    //application->ProccessCommandLine(argc, argv);

    //Initialize Game-loop
    //FinalStatusCode = application->run();
	application->run();
	
    //cleanup
    delete application;
	
    //remove pointer
    application = NULL;

    //Return final status
    //return FinalStatusCode;
	return 0;
}
