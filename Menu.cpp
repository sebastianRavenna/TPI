#include<iostream>
using namespace std;
#include"Juego.h"
#include"rlutil.h"
#include  "creditos.h"
#include "volverAlMenu.h"



void mostrarMenu(){
int numeroInicio;
rlutil::setBackgroundColor(rlutil::MAGENTA);
rlutil::cls();
rlutil::setColor(rlutil::WHITE);


cout<<"      ______   ___________  _______   ______  ___    ____  ____  ____ "<<endl;
cout<<"     / ___/ | / / ___/ __ \\/ ____/ | / / __ \\/   |  / __ \\/ __ \\/ ___/"<<endl;
cout<<"    / __//  |/ / /_ / /_/_/ __/ /  |/ / / / / /| | / / / / / / /\\__ \\ "<<endl;
cout<<"   / /__/ /|  / __// _  \\/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ / "<<endl;
cout<<"  /____/_/ |_/_/  /_/ \\_/_____/_/ |_/_____/_/  |_/_____/\\____//____/  "<<endl<<endl<<endl<<endl<<endl;

cout<<" =========================="<<endl;
cout<<"||  1 - JUGAR             ||"<<endl;
cout<<"||                        ||"<<endl;
cout<<"||  2 - ESTADISTICAS      ||"<<endl;
cout<<"||                        ||"<<endl;
cout<<"||  3 - CRDITOS          ||"<<endl;
cout<<"||========================||"<<endl;
cout<<"||  0 - SALIR             ||"<<endl;
cout<<" =========================="<<endl<<endl;

cout<<"Ingrese la opcion deseada: ";
cin>> numeroInicio;

while(numeroInicio>3||numeroInicio<0){
    cout<<"Numero incorrecto"<<endl;
    cout<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;
}

switch(numeroInicio){
    case 1:

        rlutil::cls();
        juego();
        volverAlMenu();
    break;

    case 2:
        rlutil::cls();
        cout<<"estadisticas.h";
        volverAlMenu();
    break;

    case 3:
        rlutil::cls();
        creditos();
        volverAlMenu();
    break;

    case 0:
        rlutil::cls();
        cout<<"¨Estas seguro que queres salir del juego?"<<endl<<endl;
        volverAlMenu();
        rlutil::anykey();

    return;
}
}



