#include "declarations.h"

int main(){
    //Datos Sol
    double mS = 333000.0;
    //Datos Tierra
    double mt = 1.0;
    double rt = 1.0;
    double v0t = sqrt(G*mS*pow(rt, -3))*rt;
    //Datos Jupiter
    double mj = 317.81;
    double rj = 5.205;
    double v0j = sqrt(G*mS*pow(rj, -3))*rj;
    //Datos Sonda
    double ms = 4.225E-22;
    double v0s = 0.7;
    double r0s = rt + (4.286E-5);

    //---(x0,y0,z0,Vx0,Vy0,Vz0,m)
    Cuerpo Sol(0,0,0,0,0,0,mS);
    Cuerpo Tierra(rt,0,0,0,v0t,0,mt);
    Cuerpo Jupiter(rj,0,0,0,v0j,0,mj);
    Cuerpo Sonda(r0s,0,0,0,v0s,0, ms);

    cuerpos N = {Sonda, Sol, Jupiter, Tierra};
    //Fuerza inicial
    force(N);
    Sol.start_leap_frog(DT);
    Tierra.start_leap_frog(DT);
    Jupiter.start_leap_frog(DT);
    Sonda.start_leap_frog(DT);
    trans_galileo(N);
    print(N);

    for(int ii = 0; ii < NSTEPS; ++ii){
        force(N);
        trans_galileo(N);
        print(N);
    }
}
