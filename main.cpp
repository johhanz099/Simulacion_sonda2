#include "declarations.h"

int main(){
    double ms = 333000.0;

    //Datos tierra
    double mt = 1.0;
    double rt = 1.0;
    double v0t = sqrt(G*ms*pow(rt, -3))*rt;
    //
    double mj = 317.81;
    double rj = 5.205;
    double v0j = sqrt(G*ms*pow(rj, -3))*rj;

    //---(x0,y0,z0,Vx0,Vy0,Vz0,m)
    Cuerpo Sol(0,0,0,0,0,0,ms);
    Cuerpo Tierra(rt,0,0,0,v0t,0,mt);
    Cuerpo Jupiter(rj,0,0,0,v0j,0,mj);
    Cuerpo Sonda(50.2,0,0,0,20*sqrt(6)/3,0, 0.0001);

    cuerpos N = {Sol, Jupiter, Tierra};
    //Fuerza inicial
    uptade(N);
    Sol.start_leap_frog(DT);
    Tierra.start_leap_frog(DT);
    Jupiter.start_leap_frog(DT);
    Sonda.start_leap_frog(DT);
    trans_galileo(N);
    print(N);

    for(int ii = 0; ii < NSTEPS; ++ii){
        uptade(N);
        // Sol.leap_frog(DT);
        // Tierra.leap_frog(DT);
        // Jupiter.leap_frog(DT);
        trans_galileo(N);
        print(N);
    }
}