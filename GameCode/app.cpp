
#include "gameLoop.h"
#include "app.h"

namespace Game {
		
    App::App(Engine::InputState* inState, Engine::RenderState* rendState) {
        //ctor
		this->inState = inState;
		this->rendState = rendState;
    }

    App::~App() {
        //dtor
    }
	
	void App::update() {
		if(this->inState->buttonPress == true) {
			this->rendState->leftTri = true;
		} else {
			this->rendState->leftTri = false;
		}
	}
} //namespace Game