#include<iostream>
#include"rlutil.h"
#include"string"
using namespace std;

void estadisticas(int record, string ganador){

    if(ganador==""){
            cout<<endl;
            cout<<"No hay datos cargados todavia."<<endl;

    }else{cout<<endl<<"El record es de "<<ganador<<" con un puntaje de: "<<record<<endl;
    }

    cout<<endl;

}
