#pragma once // avoids multiple inclusions
#include <iostream>
#include <vector>


typedef std::vector<double> vec; //Nombre para vector

struct Planeta
{
    //Radio
    double rad = 0.0;
    //Masa
    double mass = 0.0;
    //Posicion
    vec R = {0, 0 ,0};
    //Velocidad
    vec V = {0, 0 ,0};
    //Fuerza
    vec F = {0, 0 ,0};
    //Vector energia (cenetica, potencial, mecanica)
    vec E = {0, 0 ,0};

};