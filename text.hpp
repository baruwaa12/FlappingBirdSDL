#pragma once
#include <SDL.h>

class Text
{
private:
	float x;
	float y;

public:
	Text(float x, float y);
	void setX(float value);
	void setY(float value);
	float getY();
	float getX();
	SDL_Rect* textRect;
};

