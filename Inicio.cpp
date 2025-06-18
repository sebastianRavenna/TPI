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
        dibujarDado(sorteoInicial[i], i*20+5, 5, blanco);
        rlutil::locate(i*20+5, 8);
        rlutil::resetColor();
        if (i==0){
            cout <<jugadorA;
        }else cout <<jugadorB;
        }
        //cout <<jugadorA<< ": " << dadoInicial[0] << "\t"<<jugadorB<< ": " << sorteoInicial[1]<< endl;
        cout << endl<<endl;
        if(sorteoInicial[0]==sorteoInicial[1]){
            cout<<"Hay empate"<<endl<<endl;
            rlutil::anykey();
            rlutil::cls();
        }

    } while (sorteoInicial[0]==sorteoInicial[1]);

    rlutil::locate(10,10);
    if(sorteoInicial[0]>sorteoInicial[1]){
        cout<<jugadorA<<" gana el sorteo. \n\n\nApreta una tecla para iniciar el juego";
        rlutil::anykey();
    }else{
        cout<<jugadorB<<" gana el sorteo. \n\n\nApreta una tecla para iniciar el juego";
        rlutil::anykey();
    }

    return sorteoInicial[0]>sorteoInicial[1];
}
