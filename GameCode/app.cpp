
#include "app.h"
#include <cmath>

namespace Game {
		
    App::App(Engine::InputState* inState, Engine::RenderState* rendState, Engine::GameState* gameState) {
        //ctor
		this->inState = inState;
		this->rendState = rendState;
		this->gameState = gameState;
    }

    App::~App() {
        //dtor
    }
	
	void App::update() {
		if(this->inState->ePress == true) {
			this->rendState->leftTri = true;
		} else {
			this->rendState->leftTri = false;
		}
		if(this->inState->wPress == true) {
			this->rendState->xPos += 0.2 * sin(this->rendState->xRotate);
			this->rendState->yPos += 0.2 * cos(this->rendState->xRotate);
		}
		if(this->inState->sPress == true) {
			this->rendState->xPos -= 0.2 * sin(this->rendState->xRotate);
			this->rendState->yPos -= 0.2 * cos(this->rendState->xRotate);
		}
		if(this->inState->aPress == true) {
			this->rendState->xPos += 0.2 * cos(this->rendState->xRotate);
			this->rendState->yPos -= 0.2 * sin(this->rendState->xRotate);
		}
		if(this->inState->dPress == true) {
			this->rendState->xPos -= 0.2 * cos(this->rendState->xRotate);
			this->rendState->yPos += 0.2 * sin(this->rendState->xRotate);
		}	
		if(this->inState->upPress == true) {
			this->rendState->yRotate += 0.025;
		}	
		if(this->inState->downPress == true) {
			this->rendState->yRotate -= 0.025;
		}	
		if(this->inState->leftPress == true) {
			this->rendState->xRotate += 0.025;
		}	
		if(this->inState->rightPress == true) {
			this->rendState->xRotate -= 0.025;
		}	
		if(this->inState->spacePress == true) {
			this->rendState->zPos += 0.2;
		}
		if(this->inState->leftCtrlPress == true) {
			this->rendState->zPos -= 0.2;
		}
		if(this->inState->escPress == true) {
			this->gameState->shouldRun = false;
		}
		
		this->rendState->xRotate += this->inState->mousex * 0.005;
		this->rendState->yRotate += this->inState->mousey * 0.005;
		if(this->rendState->xRotate >= 3.141592 * 2)
			this->rendState->xRotate -= 3.141592 * 2;
		if(this->rendState->xRotate <= -3.141592 * 2)
			this->rendState->xRotate += 3.141592 * 2;
		if(this->rendState->yRotate >= 3.141592 / 2)
			this->rendState->yRotate = 3.141592 / 2;
		if(this->rendState->yRotate <= -3.141592 / 2)
			this->rendState->yRotate = -3.141592 / 2;
	}
} //namespace Game