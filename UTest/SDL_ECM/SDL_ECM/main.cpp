#include "SDL.h"
#include "Entity.h"

#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"

#include "AISystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"

#include <iostream>

#include <assert.h>

using namespace std;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	Entity player(0);
	HealthComponent playerHC;
	PositionComponent playerPC;
	ControlComponent playerCC;
	player.addComponent(playerHC);
	player.addComponent(playerPC);
	player.addComponent(playerCC);

	Entity alien(1);
	HealthComponent alienHC;
	PositionComponent alienPC;
	alien.addComponent(alienHC);
	alien.addComponent(alienPC);

	Entity dog(2);
	HealthComponent dogHC;
	PositionComponent dogPC;
	dog.addComponent(dogHC);
	dog.addComponent(dogPC);

	Entity cat(3);
	HealthComponent catHC;
	PositionComponent catPC;
	cat.addComponent(catHC);
	cat.addComponent(catPC);

	AISystem as;
	as.addEntity(player);
	as.addEntity(alien);
	as.addEntity(dog);
	as.addEntity(cat);

	ControlSystem cs;
	cs.addEntity(player);

	RenderSystem rs;
	rs.addEntity(player);
	rs.addEntity(alien);
	rs.addEntity(dog);
	rs.addEntity(cat);

	assert(dogHC.getHealth() == 100); //Correct. Does not interrupt the program.
	//assert(catPC.getXPosition() == 9); //This will cause a break point. Uncomment if you want to see that. 
	//Alternatively, set Test as startup project and watch it break because of pretty much the exact same thing.

	while (true) {
		as.update();
		cs.update();
		rs.update();
	}

	return 0;
}