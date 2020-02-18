#include "Spring.h"
#ifndef DRAWUTILITY_H
#include "DrawUtility.h"
#endif 






Springf::Springf(Mass *input,float elasticity ,float damp,Mass *aMass)
{
	this->renderer = aMass->renderer;
	this->input = input;
	this->elasticity = elasticity;
	this->dampening = damp;
	this->masse = aMass;
	this->link1x = (*input).x;
	this->link1y = (*input).y;
	//this->link1x = WIDTH / 2 -10;
	//this->link1y = HEIGHT / 2 -10;
	this->link1xreal = (*input).xreal;
	this->link1yreal = (*input).yreal;
	//this->link1xreal = WIDTH/2/SCALE-10/SCALE;
	//this->link1yreal = HEIGHT/2/SCALE-10/SCALE;

	this->link2xreal = aMass->xreal;
	this->link2yreal = aMass->yreal;
	this->link2x = aMass->x;
	this->link2y = aMass->y;
	this->renderer = aMass->renderer;
}

void Springf::update(float h) 
{

	
	drawLine(link1x, link1y, link2x, link2y, this->renderer);
	masse->draw();
	
	float X[2];
	float Y[2];
	RK4(*this, h,X,Y);
	(*masse).X(X[0]);
	(*masse).Y(Y[0]);
	this->link2xreal = masse->xreal;
	this->link2yreal = masse->yreal;
	this->link2x = masse->x;
	this->link2y = masse->y;
	
	masse->vx = X[1];
	masse->vy = Y[1];
	
	this->link1x = input->x;
	this->link1y = input->y;
	this->link1xreal = input->xreal;
	this->link1yreal = input->yreal;
}



Springf::~Springf()
{
}
