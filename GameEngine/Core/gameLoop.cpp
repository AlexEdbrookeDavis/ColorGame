/**
 * The Game Loop acts as the central processor for a running game.
 * This implementation is currently kept simple for the sake of readability,
 * and currently runs the game logic and renderer both at a constant FPS
 */
 
#include <gameLoop.h>
#include <renderer.h>
#include <inputHandler.h>
#include <app.h>

#include <time.h>

//placeholder timer library (replace with Boost?)
#include <Windows.h>
 
 namespace Engine {
	InputHandler *input;
	Renderer *rend;
	Game::App *gameLogic;
	 

	
	 
	GameLoop::GameLoop() {
		//ctor
		this->gameState = new GameState;
		this->gameState->shouldRun = true;
		
		rend = new Renderer();
		
		input = new InputHandler(rend);

		gameLogic = new Game::App(input->getState(), rend->getState(), gameState);
		
	}
	 
	GameLoop::~GameLoop() {
        //dtor
    } 
	 
	void GameLoop::run() {
		while(this->gameState->shouldRun == true) {
			clock_t loopStart = clock();

			input->readInputs();
			gameLogic->update();
			rend->render();
			
			Sleep( float( clock () + MS_PER_FRAME - loopStart ));
		}
	}
 }