#include <iostream>
#include "Menu.h"
using namespace std;

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
                    cout<<"­GRACIAS POR HABER JUGADO ENFRENDADOS!"<<endl;
                    break;
            }
}
