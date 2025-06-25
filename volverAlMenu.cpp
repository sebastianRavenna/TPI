#include <iostream>
#include"Menu.h"
#include"rlutil.h"
#include"volverAlMenu.h"
using namespace std;

void volverAlMenu(){
    int volverAtras=-1;
    cout<<"Presione 1 para volver al Men£ principal"<<endl<<endl;
    cout<<"Presione 0 para salir del Juego"<<endl<<endl;
    cout<<"Numero Elegido: ";
    cin>>volverAtras;
    cout<<endl;
        while(volverAtras<0||volverAtras>1){
            cout<<"Numero Incorrecto: "<<endl<<endl;
            cout<<"Presione 1 para volver al Men£ principal"<<endl<<endl;
            cout<<"Presione 0 para salir del Juego"<<endl<<endl;
            cout<<"Numero Elegido: ";
            cin>>volverAtras;
        }
    switch (volverAtras){
                case 1:
                    rlutil::cls();
                    break;
                case 0:
                    confirmar();
                    cout<<"­GRACIAS POR HABER JUGADO ENFRENDADOS!"<<endl;
                    break;
            }
}

void confirmar(int numeroInicio)
{
    int finalizar;
    cout<<"¨Estas seguro que queres salir del juego?"<<endl<<"1.Si\t2.No"<<endl;
    cin>>finalizar;
    switch (finalizar){
    case 1:
        rlutil::cls();
        cout<<"­GRACIAS POR HABER JUGADO ENFRENDADOS!"<<endl;
        return;
    case 2:
        rlutil::cls();
        numeroInicio=-1;

        break;
    }
}
