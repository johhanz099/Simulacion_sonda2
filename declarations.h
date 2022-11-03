#include <iostream>
#include <cmath>
#include "bodies.h"

//Constante G
const double G = 1;
const int NSTEPS = 100000; //Pasos
const double DT = 0.1; //Intervalo de tiempo

//
void initial_conditions(Planeta & body1, Planeta & body2);
void force(Planeta & body1, Planeta & body2);
void start_leap_frog(Planeta & body, const double & dt);
void leap_frog(Planeta & body, const double & dt);
void print(Planeta & body1, Planeta & body2, double time);
