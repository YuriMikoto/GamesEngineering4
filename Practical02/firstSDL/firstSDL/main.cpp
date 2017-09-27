#include "SDL.h"
#include <iostream>

#include "Player.h"
#include "InputHandler.h"
#include "Command.h"

using namespace std;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Event event;
	bool running = true; //Determines when to stop running the game loop.

	InputHandler ih;

	JumpCommand* jump = new JumpCommand();
	FireCommand* fire = new FireCommand();
	SwitchCommand* swap = new SwitchCommand();
	EvadeCommand* evade = new EvadeCommand();

	ih.assignButtons(jump, evade, fire, swap);

	while (running) {//Game loop that checks for SDL events.
		while (SDL_PollEvent(&event)) {

			cout << event.key.keysym.sym << endl;

			ih.handleInput(event);
			

			/*if (event.type == SDL_QUIT) {
				//Prepare the program to shut down when the player quits.
				running = false;
			}*/
		}
	}

	return 0;
}