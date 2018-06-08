/*
 * This is an example application being run by the game engine.
 * Eventually it will run a pseudo Minecraft game (mutable block world)
 */

#ifndef APP_H
#define APP_H

#include "inputHandler.h"
#include "renderer.h"
#include "gameLoop.h"

namespace Game {

    class App {
        public:
		
			Engine::InputState* inState;
			Engine::RenderState* rendState;
			Engine::GameState* gameState;
		
            /** Default constructor */
            App(Engine::InputState* inState, Engine::RenderState* rendState, Engine::GameState* gameState);
            /** Default destructor */
            virtual ~App();
			
			void update();

        protected:

        private:
    };
} //namespace Game
#endif // APP_H
