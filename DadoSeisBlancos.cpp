#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"rlutil.h"

int sorteo, volverAtras=-1;


void caraDadoSeis(){
    int continuar;
    do{

    int dados[12]={};
    int stockDados, cantDados;

    srand(time(0));

    cout<<"ingresar cant de dados: ";
    cin>>cantDados;

    for (int i=0;i<cantDados;i++){
        dados[i] = rand() % 6 + 1;
        cout<<dados[i]<<"\t";
    }
    cout<<endl;
    cout<<"presione 1 si desea continuar: ";
    cin>> continuar;
}   while(continuar==1);

}

void volverAlMenu(){
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
