#pragma comment(lib, "./SDL2main.lib")
#pragma comment(lib, "./SDL2.lib")

#ifndef DRAWUTILITY_H
#include "DrawUtility.h"
#endif // !DRAWUTILITY_H
#ifndef MASS_H
#include "Mass.h"
#endif // !1
#ifndef SPRING_H
#include "Spring.h"
#endif // !SPRING_H
#include <vector>




#include <iostream>
using namespace std;



int main(int argc, char* args[])
{


	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
		return -1;
	}

	{
		/* Création de la fenêtre */
		SDL_Window* screen = NULL;
		screen = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_SHOWN);

		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
		/*SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);*/
		
		//screenflip(renderer);

		float mass = .005;
		float K = .01;
		float damp = 0.1;
		//float mass = .2;
		//float K = .5;
		//float damp = 0.1;
		//screenflip(renderer);
		//SDL_Delay(1000);
		//Mass(int x, int y, int size, float mass, SDL_Renderer* renderer)
		/*Mass aMass2((WIDTH-100) / 2 / SCALE, (HEIGHT -20)/ 2 / SCALE, 10, mass, renderer);
		Mass aMass((WIDTH )/ 2/SCALE, HEIGHT / 2/SCALE,10, mass, renderer);
		Mass aMass3(((WIDTH -300)/ 2 / SCALE), ((HEIGHT-300)/ 2 / SCALE), 10, mass, renderer);
		//float x, float y,float elasticity ,float damp,Mass aMass
		Springf aSpring(&aMass2,K,damp, &aMass);
		Springf aSpring2(&aMass3,K, damp, &aMass2);
		*/
		Mass* masses[25];
		vector<Springf> springsV;
		vector<Springf> springsH;

		int size = 5;

		for (int i = 0; i < size+1 ; i++)
		{

			for (int j = 0; j < size+1; j++) 
			{
				Mass* aMass = new Mass((10 * j)+10, (10 * i)+10, 10, mass, renderer);
				masses[i*size+j] = aMass;
				//if (j > 0 && (j!=size && i>0))
				if (j > 0) 
				{
					Springf aspring(masses[i*size + j - 1], K, damp, masses[i*size + j]);
					springsH.push_back(aspring);
				}
				if (i >0)
				{
					Springf aspring(masses[i*size + j -size], K, damp, masses[i*size +j]);
					springsV.push_back(aspring);
				}
			}
		}
		
		//Mass aMass2(100, 3, 10, mass, renderer);
		//Springf aspring1(masses[0], K, damp, &aMass2);
		//springsH.push_back(aspring1);


		
		while(true)
		{
			//cout << aSpring.masse.vx << endl;
			screenflip(renderer);
			for (int i = 0; i < springsV.size(); i++) 
			{
				springsV[i].update(0.001);

						
			}

			for (int i = 0; i < springsH.size(); i++) 
			{
				springsH[i].update(0.001);
			}
			//aSpring.update(0.001);
			//aSpring2.update(0.001);
			SDL_RenderPresent(renderer);
			SDL_Delay(0.1);
		}



			while (true) {}

		if (screen)
		{
			//aSpring.update(1);
			//SDL_Delay(1000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
			//aSpring.update(1);
			//SDL_Delay(1000);

			SDL_DestroyWindow(screen);
		}
		else
		{
			fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
		}
	}

	SDL_Quit();

	return 0;
}





