#pragma once // avoids multiple inclusions
#include <iostream>
#include <vector>


typedef std::vector<double> vec; //Nombre para vector

#include<iostream>
struct Vec3D
{
    double x, y, z;
    //Constructor
    Vec3D(){
        x = 0.0; y = 0.0; z = 0.0;
    }
    //Print vector
    void print(){
        std::cout << "(" << x << ", " << y << ", " << z << ")" << "\n";
    }
    //Overloading operator +
    Vec3D operator+(const Vec3D &v){
        Vec3D sum;
        sum.x = x + v.x;
        sum.y = y + v.y;
        sum.z = z + v.z;
        return sum;
    }
    //Overloading operator +
    Vec3D operator-(const Vec3D &v){
        Vec3D sum;
        sum.x = x - v.x;
        sum.y = y - v.y;
        sum.z = z - v.z;
        return sum;
    }
    //Overloading operator *
    Vec3D operator*(const double &c){
        Vec3D esc;
        esc.x = c*x;
        esc.y = c*y;
        esc.z = c*z;
        return esc;
    }
    //Overloading operator /
    Vec3D operator/(const double &c){
        Vec3D esc;
        esc.x = x/c;
        esc.y = y/c;
        esc.z = z/c;
        return esc;
    }
};

struct Planeta
{
    //Radio
    double rad = 0.0;
    //Masa
    double mass = 0.0;
    //Posicion
    Vec3D R;
    //Velocidad
    Vec3D V;
    //Aceleracion auxiliar
    Vec3D Aaux;
    //Fuerza
    Vec3D F;
    //Vector energia (cenetica, potencial, mecanica)
    Vec3D E;

    //Constructor condiciones iniciales
    Planeta(double x0, double y0, double z0, double Vx0, double Vy0, double Vz0, double m){
        this -> mass = m;
        this -> R.x = x0;
        this -> R.y = y0;
        this -> R.z = z0;
        this -> V.x = Vx0;
        this -> V.y = Vy0;
        this -> V.z = Vz0;
    }

    //Leap_Frog algorithm
    void start_leap_frog(const double & dt){
        V = V + F*(dt/(2*mass));
    }

    void leap_frog(const double & dt){
        V = V + F*(dt/(mass));
        R = R + V*dt;
    }

    //Verlet algorithm
    void verlet(const double & dt){
        R = R + V*dt + Aaux*(dt*dt*0.5);
        V = V + (Aaux+(F/mass))*(dt*0.5);
    }

};