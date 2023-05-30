#include "bird.h"
#include <iostream>  
#include <SDL.h>

Bird::Bird(float _x, float _y, float _v, float _g) {
	this->x = _x;
	this->y = _y;
	this->v = _v;
	this->g = _g;
	this->BirdRect = new SDL_Rect();
	this->BirdRect->x = _x;
	this->BirdRect->y = _y;
	this->BirdRect->h = 32;
	this->BirdRect->w = 32;

}


void Bird::flyUp() {
	// this->y = this->y - this->v;
	
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDLK_SPACE)
		{
			this->BirdRect->y = this->BirdRect->y - this->v;
			std::cout << "Spacebar touched" << std::endl;
		}
	}

}


void Bird::flyDown() {
	//this->y = this->y + this->g;
	this->BirdRect->y = this->BirdRect->y + this->g;

}




