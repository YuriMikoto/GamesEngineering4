#include "SDL.h"
#include <iostream>

#include "Animation.h"

using namespace std;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Event event;

	Animation fsm;
	int i = 0;

	while (1) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_DOWN) {//Down arrow enters idle state.
					fsm.idle();
				}
				if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {//Left or right arrow enters walking state.
					fsm.walking();
				}
				if (event.key.keysym.sym == SDLK_UP) {//Up arrow enters jumping state.
					fsm.jumping();
				}
			}
		}
	}

	return 0;
}