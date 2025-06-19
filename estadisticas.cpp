#include<iostream>
#include"rlutil.h"
#include"string"
using namespace std;

void estadisticas(int record, string ganador){


    cout<<"El record es del jugador "<<ganador<<" con un puntaje de: "<<record;




    cout << "\nPresiona una tecla para continuar..." << endl;
    rlutil::anykey();

}
