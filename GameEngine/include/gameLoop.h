/**
 * The Game Loop acts as the central processor for a running game.
 * This implementation is currently kept simple for the sake of readability,
 * and currently runs the game logic and renderer both at a constant FPS
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include <renderer.h>
#include <inputHandler.h>
#include <app.h>

namespace Engine {
	const float MS_PER_FRAME = 16.667;
	
	class GameLoop {
        public:

		/** Default constructor */
            GameLoop();
            /** Default destructor */
            virtual ~GameLoop();

			void run();
        protected:

        private:
			Game::GameState *gameState;
    };
} //namespace Game
#endif // GAME_LOOP_H
