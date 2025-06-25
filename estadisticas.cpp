#include<iostream>
#include"rlutil.h"
#include"string"
using namespace std;

void estadisticas(int record, string ganador){




    if(ganador==""){
            cout<<"No hay datos cargados todavia."<<endl;

    }else{cout<<"El record es del jugador "<<ganador<<" con un puntaje de: "<<record<<endl;
    }


    cout << "\nPresiona una tecla para continuar..." << endl<<endl;
    rlutil::anykey();
    rlutil::cls();
}
