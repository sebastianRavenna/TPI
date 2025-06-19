#include<iostream>
using namespace std;
#include"Juego.h"
#include"rlutil.h"
#include"creditos.h"
#include"volverAlMenu.h"
#include"estadisticas.h"
#include"Dados.h"



void mostrarMenu()
{   string ganadorRecord="";
    int record=0;
    int numeroInicio;

    do {
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::cls();

    for(int i=0; i<30; i++)
    {
        if(i%3==0)
        {
            rlutil::setBackgroundColor(rlutil::YELLOW);
            rlutil::setColor(rlutil::RED);
        }
        else if ((i-1)%3==0)
        {
            rlutil::setBackgroundColor(rlutil::MAGENTA);
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLACK);
        }

        rlutil::locate(20,3);
        cout<<"      ______   ___________  _______   ______  ___    ____  ____  ____   "<<endl;
        rlutil::locate(20,4);
        cout<<"     / ___/ | / / ___/ __ \\/ ____/ | / / __ \\/   |  / __ \\/ __ \\/ ___/  "<<endl;
        rlutil::locate(20,5);
        cout<<"    / __//  |/ / /_ / /_/_/ __/ /  |/ / / / / /| | / / / / / / /\\__ \\   "<<endl;
        rlutil::locate(20,6);
        cout<<"   / /__/ /|  / __// _  \\/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /   "<<endl;
        rlutil::locate(20,7);
        cout<<"  /____/_/ |_/_/  /_/ \\_/_____/_/ |_/_____/_/  |_/_____/\\____//____/    "<<endl;
        rlutil::locate(20,8);
        cout<<"                                                                        "<<endl;

        rlutil::msleep(i*5);
    }

    bool blanco=true;
    for (int i=1; i<=6; i++){
        dibujarDado(i, i*9+20, 10, blanco);
    }
        int ubicacionDados=20;
    for (int i=6; i>=1; i--){
        dibujarDado(i, ubicacionDados+=9, 14, blanco=false);
    }

    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::setColor(rlutil::WHITE);

    cout<<endl<<endl<<endl;
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

    while(numeroInicio>3||numeroInicio<0)
    {
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }


    switch(numeroInicio)
    {
    case 1:

        rlutil::cls();
        juego(record, ganadorRecord);
        volverAlMenu();
        break;

    case 2:

        rlutil::cls();
        estadisticas(record, ganadorRecord);
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
        confirmar();
        volverAlMenu();

        return;
    }

    } while (numeroInicio != 0);
}



