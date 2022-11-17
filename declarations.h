#include <iostream>
#include <cmath>
#include <vector>
#include "bodies.h"

typedef std::vector<Cuerpo> cuerpos; //Nombre para vector

//Constantes globales
const double G = 8.2214E-7; //Constantes G
const double T = 85; //Tiempo
const double DT = 0.0001; //Intervalo de tiempo
const int NSTEPS = int(T/DT); //Pasos

// function declaratons
void uptade(cuerpos & Nbody);
void trans_galileo(cuerpos & Nbody);
void print(cuerpos & Nbody);