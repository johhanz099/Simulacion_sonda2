#include <iostream>
#include <cmath>
#include <vector>
#include "bodies.h"

typedef std::vector<Cuerpo> cuerpos; //Nombre para vector

//Constantes globales
const double G = 1; //Constantes G
const double T = 200; //Tiempo
const double DT = 0.001; //Intervalo de tiempo
const int NSTEPS = int(T/DT); //Pasos

// function declaratons
void uptade(cuerpos & Nbody);
void trans_galileo(cuerpos & Nbody);
