#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"


int sorteo, volverAtras=-1;
int volverAlMenu();

void caraDadoSeis(){
    srand(time(0));
    sorteo = rand() % 6 + 1;
    switch(sorteo){
        case 1:
            cout<<"+-------+"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|   o   |"<<endl;
            cout<<"|       |"<<endl;
            cout<<"+-------+"<<endl;
            volverAlMenu();
        break;

        case 2:
            cout<<"+-------+"<<endl;
            cout<<"|   o   |"<<endl;
            cout<<"|       |"<<endl;
            cout<<"|   o   |"<<endl;
            cout<<"+-------+"<<endl;
            volverAlMenu();
        break;

        case 3:
            cout<<"+-------+"<<endl;
            cout<<"| o     |"<<endl;
            cout<<"|   o   |"<<endl;
            cout<<"|     o |"<<endl;
            cout<<"+-------+"<<endl;
            volverAlMenu();
        break;

        case 4:
            cout<<"+-------+"<<endl;
            cout<<"| o   o |"<<endl;
            cout<<"|       |"<<endl;
            cout<<"| o   o |"<<endl;
            cout<<"+-------+"<<endl;
            volverAlMenu();
        break;

        case 5:
            cout<<"+-------+"<<endl;
            cout<<"| o   o |"<<endl;
            cout<<"|   o   |"<<endl;
            cout<<"| o   o |"<<endl;
            cout<<"+-------+"<<endl;
            volverAlMenu();
        break;

        case 6:
            cout<<"+-------+"<<endl;
            cout<<"| o o o |"<<endl;
            cout<<"|       |"<<endl;
            cout<<"| o o o |"<<endl;
            cout<<"+-------+"<<endl;
            volverAlMenu();
        break;
    }
}

int volverAlMenu(){
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
