#include<iostream>
using namespace std;
#include"Juego.h"
#include"rlutil.h"
#include"creditos.h"
#include"volverAlMenu.h"
#include"estadisticas.h"
#include"Dados.h"
#include"Reglamento.h"
#include"titulo.h"



void mostrarMenu()
{   ///Variables de estadisticas, por  referencia
    string ganadorRecord="";
    int record=0;


    int numeroInicio;

    ///usamos do para que entre al menu directo, no forzar al numeroInicio
    do {


    titulo();

    cout<<endl<<endl<<endl;
    cout<<" =========================="<<endl;
    cout<<"||  1 - JUGAR             ||"<<endl;
    cout<<"||                        ||"<<endl;
    cout<<"||  2 - ESTADISTICAS      ||"<<endl;
    cout<<"||                        ||"<<endl;
    cout<<"||  3 - CRDITOS          ||"<<endl;
    cout<<"||                        ||"<<endl;
    cout<<"||  4 - REGLAMENTO        ||"<<endl;
    cout<<"||========================||"<<endl;
    cout<<"||  0 - SALIR             ||"<<endl;
    cout<<" =========================="<<endl<<endl;

    cout<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    ///while de validacion, no usamos default porque se reinicia
    while(numeroInicio>4||numeroInicio<0)
    {
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }


    switch(numeroInicio)
    {
    case 1:

        rlutil::cls();
        ///se trae por referencia  para usar en estadisticas
        juego(record, ganadorRecord);
        volverAlMenu();
        break;

    case 2:

        rlutil::cls();
        ///se utiliza los argumentos por valor
        estadisticas(record, ganadorRecord);
        volverAlMenu();

        break;

    case 3:
        rlutil::cls();
        creditos();
        volverAlMenu();
        break;

    case 4:
        rlutil::cls();
        reglamento();
        volverAlMenu();
        break;


    case 0:
        rlutil::cls();
        ///se trae por referencia
        confirmar(numeroInicio);
        break;
    }
        ///while que te saca del juego
    } while (numeroInicio != 0);
}



