#include "declarations.h"

void initial_conditions(Planeta & body1, Planeta & body2){
    body2.R[0] = 10;
    body2.V[1] = 0;

    body1.mass = 100;
    body2.mass = 1;
}

void force(Planeta & body1, Planeta & body2){
    //Reiniciar fuerza
    body1.F[0] = body1.F[1] = body1.F[2] = 0.0;
    body2.F[0] = body2.F[1] = body2.F[2] = 0.0;

    vec Fdir(3, 0.0);
    // direccion de la fuerza
    for(int ii = 0; ii < 3; ii++){
        Fdir[ii] = body2.R[ii] - body1.R[ii];
    }
    //norma
    double Fdir_norm = std::sqrt(pow(Fdir[0], 2) + pow(Fdir[1], 2) + pow(Fdir[2], 2));
    //vec unitario
    for(int ii = 0; ii < 3; ii++){
        Fdir[ii] = Fdir[ii]/Fdir_norm;
    }

    // Fuerza
    for(int ii = 0; ii < 3; ii++){
        body1.F[ii] = -G*Fdir[ii]*body1.mass*body2.mass/(Fdir_norm*Fdir_norm);
        body2.F[ii] = G*Fdir[ii]*body1.mass*body2.mass/(Fdir_norm*Fdir_norm);
    }
}

void start_leap_frog(Planeta & body, const double & dt){

    for(int ii = 0; ii < 3; ii++){
        body.V[ii] += body.F[0]*dt/(2*body.mass);
    }
}

void leap_frog(Planeta & body, const double & dt){
    for(int ii = 0; ii < 3; ii++){
        body.V[ii] += body.F[ii]*dt/(2*body.mass);
        body.R[ii] += body.V[ii];
    }
}

void print(Planeta & body1, Planeta & body2, double time){
    std::cout << time << " "
        << body1.R[0] << " "
        << body2.R[0] << " "
        << body1.R[1] << " "
        << body2.R[1] << "\n";
}