#include<iostream>
using namespace std;
#include<ctime>
#include "rlutil.h"

 bool turnoInicial(string jugadorA, string jugadorB){
    int sorteoInicial[2]={};
    srand(time(0));

    do{
        cout<<"Presiona una tecla para realizar el sorteo inicial"<<endl;
        rlutil::anykey();
        sorteoInicial[0] = rand() % 6 + 1;
        sorteoInicial[1] = rand() % 6 + 1;
        cout <<jugadorA<< ": " << sorteoInicial[0] << "\t"<<jugadorB<< ": " << sorteoInicial[1]<< endl;
        cout << endl;

    } while (sorteoInicial[0]==sorteoInicial[1]);

    if(sorteoInicial[0]>sorteoInicial[1]){
        cout<<jugadorA<<" gana el sorteo. \nApreta una tecla para iniciar el juego";
        rlutil::anykey();
    }else{
    cout<<jugadorA<<" gana el sorteo. Apreta una tecla para iniciar el juego";
        rlutil::anykey();
    }

    return sorteoInicial[0]>sorteoInicial[1];
}
