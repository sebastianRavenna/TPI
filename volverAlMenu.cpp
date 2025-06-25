#include <iostream>
#include"Menu.h"
#include"rlutil.h"
#include"volverAlMenu.h"
using namespace std;

void volverAlMenu(){
//    int numeroInicio, volverAtras=-1;
    /*cout<<"Presione 1 para volver al Men£ principal"<<endl<<endl;
    cout<<"Numero Elegido: ";
    cin>>volverAtras;
    cout<<endl;*/
    //rlutil::cls();

    cout<<"Presione una tecla para volver al Men£ principal"<<endl<<endl;
    rlutil::anykey();


}

void confirmar(int &numeroInicio)
{
    int finalizar;
    cout<<"¨Estas seguro que queres salir del juego?"<<endl<<"1.Si\t2.No"<<endl;
    cin>>finalizar;
    switch (finalizar){
    case 1:
        rlutil::cls();
        cout<<"­GRACIAS POR HABER JUGADO ENFRENDADOS!"<<endl;
        break;
    case 2:
        rlutil::cls();
        numeroInicio=-1;
        break;
    }
}
