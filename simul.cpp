#include "declarations.h"

void trans_galileo(cuerpos & Nbody){
    int N = Nbody.size();
    for(int ii = 0; ii < N; ++ii){
        Nbody[ii].R = Nbody[ii].R - Nbody[N-1].R;
        Nbody[ii].V = Nbody[ii].V - Nbody[N-1].V;
    }
}

void uptade(cuerpos & Nbody){
    int N = Nbody.size();

    //Reiniciar fuerzas
    for(int ii = 0; ii < N; ii++){
        Nbody[ii].F.x = Nbody[ii].F.y = Nbody[ii].F.z = 0.0;
    }
    //Calcular fuerza
    for(int ii = 0; ii < N; ii++){
        for(int jj = 0; jj < N; jj++){
            if(ii != jj){
                Vec3D r;
                // direccion de la fuerza m1->m2
                r = Nbody[jj].R - Nbody[ii].R;
                //norma
                double r_norm = std::pow((r.x*r.x)+(r.y*r.y)+(r.z*r.z), -1.5);

                // Fuerza
                double esc = G*Nbody[ii].mass*Nbody[jj].mass*r_norm; 
                Nbody[ii].F = Nbody[ii].F + r*esc;
            }
        }
        //Actualizar posicion y velocidad
        Nbody[ii].leap_frog(DT);
    }
}

void print(cuerpos & Nbody){
    int N = Nbody.size();
    //Imprimir resultados
    for(int ii = 0; ii < N; ii++){
        std::cout << Nbody[ii].R.x << "," << Nbody[ii].R.y <<  ",";
    }
    std::cout << "\n";
}