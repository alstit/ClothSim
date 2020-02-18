#pragma once
#include "Mass.h"


class Springf
{
	public:
		int link1x, link1y, link2x, link2y;
		float elasticity, dampening, link1xreal, link1yreal, link2xreal, link2yreal;
		Mass *masse;
		Mass* input;
		SDL_Renderer* renderer = NULL;
		
		Springf(Mass * input, float elasticity, float damp, Mass* aMass);
		void update(float h);
		~Springf();
};

