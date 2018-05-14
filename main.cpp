/**
 * This will act as the instantiator of the application
 * and will kick off the primary game loop
 */

#include <assert.h>
#include <stddef.h>

#include "gameLoop.h"

int main(int argc, char* argv[])
{
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
