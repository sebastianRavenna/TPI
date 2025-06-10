#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"Inicio.h"
#include"rlutil.h"
#include"estadisticas.h"
void juego(){
string jugadorA, jugadorB, nombreJugador;

    cout<<"Ingresa el nombre del jugador A: ";
    cin>>jugadorA;

    cout<<"Ingresa el nombre del jugador B: ";
    cin>>jugadorB;

    bool empiezaA = turnoInicial(jugadorA, jugadorB);

    int stockDados=1;
    int stockDadosA = 6;
    int stockDadosB = 6;
    int puntajeTotalA=0;
    int puntajeTotalB=0;
    int ronda=0;

    while (ronda<6 && stockDadosA!=0 &&  stockDadosB!=0 ){
            ronda++;

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
                            cout<<endl;
                            cout<<"Ya elegiste este dado, selecciona otro."<<endl;
                    }

                }

            }else{cout<<"Opcion INCORRECTA, ingresa un numero entre 1 y "<<stockDados<<" para seguir jugando, o 0 para rendirte."<<endl;
            }

            cout<<"cant de dados: "<<cantDadosElegidos<<endl;
            cout<<"suma seleccionada: "<<sumaSeleccionada<<endl;
            cout<<"numeroObjetivo: "<<numeroObjetivo<<endl;
            cout<<endl;
        }


        puntajeRonda = sumaSeleccionada*cantDadosElegidos;
        cout<<"La suma total de los dados elegidos es de "<<sumaSeleccionada<<endl;

        if(sumaSeleccionada==numeroObjetivo){
            cout<<"Lograste igualar el N£mero Objetivo, tu puntaje en esta ronda es "<<puntajeRonda<<" y le pasas "<<cantDadosElegidos<<" dados a tu rival."<<endl;
            cout<<endl;
        }else{
            cout<<"No lograste el N£mero Objetivo, recibis 1 dado de tu rival."<<endl;
            puntajeRonda=0;

            if((empiezaA && stockDadosB!=1) || (!empiezaA && stockDadosA!=1)){
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

            stockDadosA-=cantDadosElegidos;
            stockDadosB+=cantDadosElegidos;
            puntajeTotalA+=puntajeRonda;
            cout<<endl;

            cout<<"Presiona una tecla para continuar."<<endl;
            rlutil::anykey();

            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::cls();

            if(cantDadosElegidos==-1){
                cantDadosElegidos=0;}

            cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalA<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();



        }else{
            empiezaA=true;


            stockDadosB-=cantDadosElegidos;
            stockDadosA+=cantDadosElegidos;
            puntajeTotalB+=puntajeRonda;

            cout<<"Presiona una tecla para continuar."<<endl;
            rlutil::anykey();

            rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::cls();

            if(cantDadosElegidos==-1){
                cantDadosElegidos=0;}

            cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalB<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();



        }
}


rlutil::cls();


            if(puntajeTotalA>puntajeTotalB){

                cout<<"jugadorA gano el juego"<<endl;
            }else {
                cout<<"jugadorB gano el juego"<<endl;
            }
}


