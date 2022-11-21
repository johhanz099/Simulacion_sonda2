#pragma once // avoids multiple inclusions

struct Vec3D
{
    double x, y, z;
    //Constructor
    Vec3D(){
        x = 0.0; y = 0.0; z = 0.0;
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

struct Cuerpo
{
    //Ratio
    double rad = 0.0;
    //Mass
    double mass = 0.0;
    //Energy
    double E = 0.0;
    //Position, Velocity and Force
    Vec3D R, V, F;
    //Constructor - Initial conditions
    Cuerpo(double x0, double y0, double z0, double Vx0, double Vy0, double Vz0, double m){
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
};
