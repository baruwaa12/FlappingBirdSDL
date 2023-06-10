#include "bird.h"
#include <iostream>  
#include <SDL.h>
#include <chrono>


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
	// timer->exec(everyTwoSecs, flyDown()) 
}

void Bird::StartTimer() { // Create a timer event 

	timerID = SDL_AddTimer(50, [](Uint32 interval, void* param) -> Uint32 { Bird* flappy = static_cast<Bird*>(param);
	flappy->flyDown(); return interval; }, this); if (timerID == 0) { std::cerr << "Failed to create timer: " << SDL_GetError() << std::endl; }

	if (timerID == 0) {
		std::cerr << "Failed to create timer: " << SDL_GetError() << std::endl;
	}
}

void Bird::StopTimer() {

	if (timerID != 0) {
		SDL_RemoveTimer(timerID);
		timerID = 0;
	}
}

void Bird::jump() {
	this->y = this->y - this->v;
	this->BirdRect->y = this->BirdRect->y - this->v;
}

 void Bird::flyDown() {
	this->y = this->y + this->g;
	this->BirdRect->y = this->BirdRect->y + this->g;

 }

// Use a timer to regulate the bird to drop by gravity 





