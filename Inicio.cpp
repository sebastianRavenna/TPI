#include<iostream>
using namespace std;
#include<ctime>
#include"Dados.h"
#include "rlutil.h"

 bool turnoInicial(string jugadorA, string jugadorB){
    int sorteoInicial[2]={};
    bool blanco=true;
    do{
        rlutil::hidecursor();
        cout<<"Presiona una tecla para realizar el sorteo inicial"<<endl;
        rlutil::anykey();
        rlutil::saveDefaultColor();
        for (int i=0;i<2;i++){
        sorteoInicial[i] = rand() % 6 + 1;
        dibujarDado(sorteoInicial[i], i*20+5, 6, blanco);
        rlutil::locate(i*20+5, 9);
        rlutil::resetColor();
        if (i==0){
            cout <<jugadorA;
            blanco=false;
        }else {
            cout <<jugadorB;
             blanco=true;
        }
        }
        cout << endl<<endl;
        if(sorteoInicial[0]==sorteoInicial[1]){
            cout<<"Hay empate"<<endl<<endl;
            rlutil::anykey();
            rlutil::cls();
        }

    } while (sorteoInicial[0]==sorteoInicial[1]);

    rlutil::locate(10,11);
    if(sorteoInicial[0]>sorteoInicial[1]){
        cout<<"нн"<<jugadorA<<" GANA EL SORTEO!! \n\nApreta una tecla para iniciar el juego";
        rlutil::anykey();
    }else{
        cout<<"нн"<<jugadorB<<" GANA EL SORTEO!! \n\nApreta una tecla para iniciar el juego";
        rlutil::anykey();
    }

    return sorteoInicial[0]>sorteoInicial[1];
}
