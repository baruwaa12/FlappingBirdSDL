#include "text.hpp"
#include <SDL.h>

Text::Text(float _x, float _y) {
	this->x = _x;
	this->y = _y;
}

void Text::setX(float value) {
	x = value;
}

void Text::setY(float value) {
	y = value;
}


float Text::getX() {
	return x;
}

float Text::getY() {
	return y;
}