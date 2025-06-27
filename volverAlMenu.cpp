#include <iostream>
#include"Menu.h"
#include"rlutil.h"
#include"volverAlMenu.h"
using namespace std;

void volverAlMenu(){
    cout<<endl;
    cout<<"Presiona una tecla para volver al Men£ principal"<<endl<<endl;
    rlutil::anykey();


}

void confirmar(int &numeroInicio)
{
    int finalizar;
    cout<<endl;
    cout<<"¨Estas seguro que queres salir del juego?"<<endl<<endl<<"\t1.Si\t\t2.No"<<endl<<endl;
    cout<<"Numero elegido: ";
    cin>>finalizar;

    while(finalizar>2 || finalizar<1)
    {
        cout<<endl<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> finalizar;
    }

    switch (finalizar){
    case 1:
        rlutil::cls();
        cout<<endl<<endl;
        rlutil::setBackgroundColor(rlutil::GREEN);
        cout<<"­GRACIAS POR HABER JUGADO ENFRENDADOS!"<<endl<<endl;
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        break;
    case 2:
        rlutil::cls();
        numeroInicio=-1;
        break;
    }
}
