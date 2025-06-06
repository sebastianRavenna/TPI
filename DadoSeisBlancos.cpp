#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"rlutil.h"



int jugadorA(){
    int dadosObjetivo[2]={};
    int numeroObjetivo=0;
    srand(time(0));

    for (int i=0;i<2;i++){
        dadosObjetivo[i] = rand() % 12 + 1;
        numeroObjetivo+=dadosObjetivo[i];
    }

    cout<<"Los dados objetivos son: "<<dadosObjetivo[0]<<"\t"<<dadosObjetivo[1]<<endl;
    cout<<"La suma de los 2 dados es de "<<numeroObjetivo<<". Ese es tu n£mero objetivo"<<endl;
    cout<<endl;
    cout<<"Presiona una tecla para lanzar los dados en tu stock: "<<endl;
    rlutil::anykey();

    int dados[12]={};
    int stockDados, cantDados, dadosElegidos, sumaSeleccionada=0, cantDadosElegidos=0, puntajeRonda=0;

    srand(time(0));

    cout<<"ingresar cant de dados: ";
    cin>>cantDados;

    for (int i=0;i<cantDados;i++){
        dados[i] = rand() % 6 + 1;
        cout<<" "<<dados[i]<<"\t";
    }
    cout<<endl;
    for (int i=0;i<cantDados;i++){
        cout<<"("<<i+1<<")"<<"\t";
    }
    cout<<endl;
    cout<<"Selecciona los dados que quer‚s sumar, al finalizar presion  0"<<endl;
    cout<<"Dado Nø ";
    cin>>dadosElegidos;

    while(dadosElegidos!=0){
        sumaSeleccionada += dados[dadosElegidos-1];
        cantDadosElegidos++;
        cout<<"Dado Nø ";
        cin>>dadosElegidos;
    }
    puntajeRonda = sumaSeleccionada*cantDadosElegidos;
    cout<<"La suma total de los dados elegidos es de "<<sumaSeleccionada<<endl;
    if(sumaSeleccionada==numeroObjetivo){
        cout<<"Lograste igualar el N£mero Objetivo, tu puntaje en esta ronda es "<<puntajeRonda<<" y le pasas "<<cantDadosElegidos<<" dados a tu rival"<<endl;
    }else{
        cout<<"No lograste el N£mero Objetivo, recibis 1 dado de tu rival"<<endl;
    }
cout<<endl;
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
