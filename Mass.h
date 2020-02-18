#pragma once
#ifndef CONSTANT_H
#include "CONSTANT.h"
#endif // !CONSTANT_H


class Mass
{
	public:
		//X and Y in rect
		int x, y, size;
		float xreal, yreal;
		float vx,vy;
		SDL_Renderer* renderer;
		SDL_Rect r;
		float mass;
		void draw();
		Mass(float x, float y, int size, float mass, SDL_Renderer* renderer);
		Mass();
		~Mass();

		void X(float x);
		void Y(float y);


};

