#include "Mass.h"
#ifndef DRAWUTILITY_H
#include "DrawUtility.h"
#endif // !1




void Mass::X(float x) 
{
	this->x = x*SCALE;
	this->r.x = x*SCALE;
	this->xreal = x;
}

void Mass::Y(float y) 
{
	this->y = y * SCALE;
	this->r.y = y * SCALE;
	this->yreal = y;
}




void Mass::draw()
{
	drawSquare(this->r, this->renderer);
}

Mass::Mass(float x, float y, int size, float mass, SDL_Renderer* renderer)
{
	this->x = x*SCALE;
	this->y = y*SCALE;
	this->xreal = x;
	this->yreal = y;
	this->renderer = renderer;
	this->mass = mass;
	this->vx = 0;
	this->vy = 0;
	this->size = size;
	this->r.x = this->x;
	this->r.y = this->y;
	this->r.h = size;
	this->r.w = size;
}

Mass::Mass()
{
}


Mass::~Mass()
{
}
