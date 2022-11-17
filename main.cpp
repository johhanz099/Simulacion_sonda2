#include "declarations.h"

int main(){

    //Trayectoria circular(r=100, w=1/10, T=62.8)
    //-----------(x0,y0,z0,Vx0,Vy0,Vz0,m)
    Cuerpo Sol(0,0,0,0,0,0,10000);
    Cuerpo Tierra(50,0,0,0,10*sqrt(2),0,1);
    Cuerpo Marte(100,0,0,0,10,0,1);

    cuerpos N = {Tierra, Marte, Sol};
    //Fuerza inicial
    uptade(N);
    Sol.start_leap_frog(DT);
    Tierra.start_leap_frog(DT);
    Marte.start_leap_frog(DT);

    for(int ii = 0; ii < NSTEPS; ++ii){
        uptade(N);
    }
}