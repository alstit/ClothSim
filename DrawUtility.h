#pragma once
#include "CONSTANT.h"
#ifndef SPRING_H
#include "Spring.h"
#endif // !SPRING_H
#ifndef CONSTANT_H
#include "CONSTANT.h"
#endif

void screenflip(SDL_Renderer* renderer);
void drawSquare( SDL_Rect rect, SDL_Renderer* renderer);
void drawLine(int x1, int y1, int x2, int y2, SDL_Renderer* renderer);
void RK4(Springf aspring,float h,float* X, float *Y);
float springEquation(Springf aspring, float k, float x, float y);
