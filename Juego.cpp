#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"Inicio.h"
#include"rlutil.h"

int juego(){
string jugadorA, jugadorB, nombreJugador;

    cout<<"Ingresa el nombre del jugador A: ";
    cin>>jugadorA;

    cout<<"Ingresa el nombre del jugador B: ";
    cin>>jugadorB;

    bool empiezaA = turnoInicial(jugadorA, jugadorB);

    int stockDados;
    int stockDadosA = 6;
    int stockDadosB = 6;

    for (int ronda=1; ronda<7; ronda++){

        int vecDadosElegidos[12]={};

        if (empiezaA){
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::cls();
            stockDados = stockDadosA;
            nombreJugador = jugadorA;
        }else{
            rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::cls();
            stockDados = stockDadosB;
            nombreJugador = jugadorB;
        }
        cout<<"Turno de "<<nombreJugador<<endl;
        cout<<"Presiona una tecla para lanzar los dados que te indican el N£mero Objetivo "<<endl<<endl;
        rlutil::anykey();


        int dadosObjetivo[2]={};
        int numeroObjetivo=0;
        srand(time(0));
        for (int i=0;i<2;i++){
            dadosObjetivo[i] = rand() % 12 + 1;
            numeroObjetivo+=dadosObjetivo[i];
        }

        cout<<"Los dados objetivos son: \nDado 1: "<<dadosObjetivo[0]<<"\t"<<"Dado 2: " <<dadosObjetivo[1]<<endl;
        cout<<"Tu NUMERO OBJETIVO es: "<<numeroObjetivo<<endl;
        cout<<endl;
        cout<<"Presiona una tecla para lanzar los dados en tu stock: "<<endl;

        rlutil::anykey();

        int dados[12]={};
        int dadosElegidos=-1, sumaSeleccionada=0, cantDadosElegidos=0, puntajeRonda=0;

        srand(time(0));
        cout<<"Numero de ronda: "<<(ronda+1)/2<<endl;
        cout<<"Es el turno de: "<<nombreJugador<<endl;
        cout<<"Stock de dados: "<<stockDados<<endl;

        for (int i=0;i<stockDados;i++){
            dados[i] = rand() % 6 + 1;
            cout<<" "<<dados[i]<<"\t";
        }
        cout<<endl;
        for (int i=0;i<stockDados;i++){
            cout<<"("<<i+1<<")"<<"\t";
        }
        cout<<endl;
        cout<<"Selecciona los dados que quer‚s sumar, si crees que no podes lograr la suma presiona 0"<<endl;
        cout<<endl;

        /*cout<<"Dado Nø ";
        cin>>dadosElegidos;
        sumaSeleccionada += dados[dadosElegidos-1];
        cantDadosElegidos++;*/


        while(dadosElegidos!=0 && sumaSeleccionada<numeroObjetivo){
            cout<<"Dado Nø ";
            cin>>dadosElegidos;

            if(dadosElegidos>=0 && dadosElegidos<=stockDados){
                if(dadosElegidos!=0){
                    if(vecDadosElegidos[dadosElegidos-1]==0){
                        sumaSeleccionada += dados[dadosElegidos-1];
                        cantDadosElegidos++;
                        vecDadosElegidos[dadosElegidos-1]=dados[dadosElegidos-1];
                    }else{
                    cout<<"Ya elegiste este dado, selecciona otro"<<endl;
                    }

                }

            }else{cout<<"Opcion incorrecta, ingresa un numero entre 1 y "<<stockDados<<" para seguir jugando, o 0 para rendirte."<<endl;
            }

            cout<<"cant de dados: "<<cantDadosElegidos<<endl;
            cout<<"suma seleccionada: "<<sumaSeleccionada<<endl;
            cout<<"numeroObjetivo: "<<numeroObjetivo<<endl;
            cout<<endl;
        }


        puntajeRonda = sumaSeleccionada*cantDadosElegidos;
        cout<<"La suma total de los dados elegidos es de "<<sumaSeleccionada<<endl;

        if(sumaSeleccionada==numeroObjetivo){
            cout<<"Lograste igualar el N£mero Objetivo, tu puntaje en esta ronda es "<<puntajeRonda<<" y le pasas "<<cantDadosElegidos<<" dados a tu rival"<<endl;
        }else{
            cout<<"No lograste el N£mero Objetivo, recibis 1 dado de tu rival"<<endl;

            if(empiezaA  && stockDadosB!=1 || !empiezaA && stockDadosA!=1){
                cantDadosElegidos=-1;
            }else{cantDadosElegidos=0;
            }

}

            /*if(stockDadosA!=1 && stockDadosB!=1){
                cantDadosElegidos=-1;
            }else{cantDadosElegidos=0;
            }*/

        cout<<endl;

        if(empiezaA){
            empiezaA=false;
            cout<<"Ahora le toca a: "<<jugadorB<<endl;
            cout<<"Presiona una tecla para continuar"<<endl;
            rlutil::anykey();
            stockDadosA-=cantDadosElegidos;
            stockDadosB+=cantDadosElegidos;

        }else{
            empiezaA=true;
            cout<<"Ahora le toca a: "<<jugadorA<<endl;
            cout<<"Presiona una tecla para continuar"<<endl;
            rlutil::anykey();
            stockDadosB-=cantDadosElegidos;
            stockDadosA+=cantDadosElegidos;
        }
}
}


