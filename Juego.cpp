#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"Inicio.h"
#include"rlutil.h"

int juego(){
string jugadorA, jugadorB, nombreJugador;

    cout<<"ingrese el nombre del jugador A: ";
    cin>>jugadorA;

    cout<<"ingrese el nombre del jugador B: ";
    cin>>jugadorB;

    bool empiezaA = turnoInicial(jugadorA, jugadorB);

    int stockDados, ronda=0;
    int stockDadosA = 6;
    int stockDadosB = 11;


    for (int ronda=1; ronda<4; ronda++){
        if (empiezaA){
            stockDados = stockDadosA;
            nombreJugador = jugadorA;
            rlutil::cls();
            rlutil::setBackgroundColor(rlutil::BLUE);
        }else{
            stockDados = stockDadosB;
            nombreJugador = jugadorB;
            rlutil::cls();
            rlutil::setBackgroundColor(rlutil::GREEN);
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
        int dadosElegidos, sumaSeleccionada=0, cantDadosElegidos=0, puntajeRonda=0;

        srand(time(0));

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
        cout<<"Dado Nø ";
        cin>>dadosElegidos;
        sumaSeleccionada += dados[dadosElegidos-1];
        cantDadosElegidos++;

        while(dadosElegidos!=0 && sumaSeleccionada<numeroObjetivo){
            cout<<"cant de dados: "<<cantDadosElegidos<<endl;
            cout<<"suma seleccionada: "<<sumaSeleccionada<<endl;
            cout<<"numeroObjetivo: "<<numeroObjetivo<<endl;
            cout<<"Dado Nø ";
            cin>>dadosElegidos;
            sumaSeleccionada += dados[dadosElegidos-1];
            cantDadosElegidos++;
        }

        puntajeRonda = sumaSeleccionada*cantDadosElegidos;
        cout<<"La suma total de los dados elegidos es de "<<sumaSeleccionada<<endl;

        if(sumaSeleccionada==numeroObjetivo){
            cout<<"Lograste igualar el N£mero Objetivo, tu puntaje en esta ronda es "<<puntajeRonda<<" y le pasas "<<cantDadosElegidos<<" dados a tu rival"<<endl;
        }else{
            cout<<"No lograste el N£mero Objetivo, recibis 1 dado de tu rival"<<endl;
        }
        cout<<endl;

        if(empiezaA){
            empiezaA=false;
            cout<<"Ahora le toca a: "<<jugadorB<<endl;
            cout<<"Presiona una tecla para continuar"<<endl;
            rlutil::anykey();
        }else{
            empiezaA=true;
            cout<<"Ahora le toca a: "<<jugadorA<<endl;
            cout<<"Presiona una tecla para continuar"<<endl;
            rlutil::anykey();
        }
}
}

void volverAlMenu(){
    int volverAtras=-1;
    cout<<"Presione 1 para volver al Men£ principal"<<endl;
    cout<<"Presione 0 para salir del Juego"<<endl;
    cout<<"Numero Elegido: ";
    cin>>volverAtras;

        while(volverAtras<0||volverAtras>1){
            cout<<"Numero Incorrecto: ";
            cout<<"Presione 1 para volver al Men£ principal"<<endl;
            cout<<"Presione 0 para salir del Juego"<<endl;
            cout<<"Numero Elegido: ";
            cin>>volverAtras;
        }
    switch (volverAtras){
                case 1:
                    system("cls");
                    mostrarMenu();
                    break;
                case 0:
                    break;
            }
}

