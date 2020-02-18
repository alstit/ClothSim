
#include"CONSTANT.h"
#include "DrawUtility.h"
#include <cmath>

void drawLine(int x1, int y1, int x2, int y2,SDL_Renderer* renderer) 
{

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	// Render rect
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	
	//SDL_RenderPresent(renderer);


}

void screenflip(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	//SDL_Delay(1000);
}

void drawSquare(SDL_Rect rect,SDL_Renderer* renderer)
{
	
	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	// Render rect
	SDL_RenderFillRect(renderer, &rect);
	// Render the rect to the screen
	//SDL_RenderPresent(renderer);
}

float springEquationy(Springf aspring ,float k,float damp,float x, float y)
{
	float elasticity, mass;
	elasticity = k;

	mass = aspring.masse->mass;

	return 	(-elasticity * x - damp * y + 10 * mass) / mass;
}


float springEquationx(Springf aspring, float k,float damp, float x, float y)
{
	float elasticity, mass;
	elasticity = k;

	mass = aspring.masse->mass;

	return 	(-elasticity * x - damp * y ) / mass;
}


void RK4(Springf aspring, float h,float* X,float *Y) 
{
	Springf spring = aspring;
	float direction,speed,dirPosition,speedTotal,kx,ky,dampx,dampy;
	float k1, k2, k3, k4;
	
	Y[0]= aspring.link2yreal - aspring.link1yreal;
	Y[1] = aspring.masse->vy;

	X[0] = aspring.link2xreal-spring.link1xreal;
	X[1] =aspring.masse->vx;
	



	direction=atan(Y[0]/X[0]);
	/*
	dirPosition = sqrt(abs(pow(Y[0], 2) + pow(X[0], 2)));
	if (X[0] < 0 || Y[0] < 0) 
	{
		dirPosition = -dirPosition;
	}
	speed = atan(Y[1] / X[1]);
	speedTotal = sqrt(abs(pow(Y[1], 2) + pow(X[1], 2)));
	if (X[1] < 0 || Y[1] < 0) 
	{
		speedTotal = - speedTotal;
	}*/

	dampx = abs(cos(direction)*aspring.dampening);
	dampy = abs(sin(direction)*aspring.dampening);


	kx = abs(cos(direction)*aspring.elasticity);
	ky = abs(sin(direction)*aspring.elasticity);

	
	k1 = springEquationx(spring,kx,dampx, X[0], X[1]);
	k2 = springEquationx(spring,kx, dampx, X[0] + (h / 2)*X[1], X[1] + h / 2 * k1);
	k3 = springEquationx(spring,kx, dampx, X[0] + (h / 2)*X[1] + k1 * (h*h) / 4, X[1] + h / 2 * k2);
	k4 = springEquationx(spring,kx, dampx,X[0] + h * X[1] + k2 * (h*h) / 2, X[1] + h * k3);
	X[0] = X[0] + spring.link1xreal;
	X[0] = X[0] + h * X[1] + (h*h / 6)*(k1 + k2 + k3);
	X[1] = X[1] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	
	
	k1 = springEquationy(spring,ky,dampy,Y[0],Y[1]);
	k2 = springEquationy(spring,ky, dampy,Y[0]+(h/2)*Y[1],Y[1]+h/2*k1);
	k3 = springEquationy(spring,ky, dampy, Y[0] + (h / 2)*Y[1] + k1*(h*h) / 4, Y[1] + h / 2 * k2);
	k4 = springEquationy(spring,ky, dampy,Y[0] + h * Y[1] + k2 * (h*h) / 2, Y[1] + h  * k3);
	
	Y[0] = Y[0] + spring.link1yreal;
	
	Y[0] = Y[0] + h * Y[1] + (h*h / 6)*(k1 + k2 + k3);
	Y[1] = Y[1] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);


	

	//return X;

}