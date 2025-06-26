#include"rlutil.h"
#include<iostream>
#include"Dados.h"
using namespace std;

void dibujarDado(int numero, int posc, int posf, bool blanco)
{
    dibujarCuadrado(posc,posf, blanco);

    if(blanco){
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLACK);
    } else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
    }

    switch(numero)
    {
    case 1:
        rlutil::locate(posc+3, posf+1);
        cout<<(char) 254;
        break;
    case 2:
        rlutil::locate(posc+1, posf);
        cout<<(char) 220;
        rlutil::locate(posc+5, posf+2);
        cout<<(char) 223;
        break;
    case 3:
        rlutil::locate(posc+1, posf);
        cout<<(char) 220;
        rlutil::locate(posc+3, posf+1);
        cout<<(char) 254;
        rlutil::locate(posc+5, posf+2);
        cout<<(char) 223;
        break;
    case 4:
        rlutil::locate(posc+1, posf);
        cout<<(char) 220;
        rlutil::locate(posc+5, posf);
        cout<<(char) 220;
        rlutil::locate(posc+1, posf+2);
        cout<<(char) 223;
        rlutil::locate(posc+5, posf+2);
        cout<<(char) 223;
        break;
    case 5:
        rlutil::locate(posc+1, posf);
        cout<<(char) 220;
        rlutil::locate(posc+5, posf);
        cout<<(char) 220;
        rlutil::locate(posc+3, posf+1);
        cout<<(char) 254;
        rlutil::locate(posc+1, posf+2);
        cout<<(char) 223;
        rlutil::locate(posc+5, posf+2);
        cout<<(char) 223;
        break;
    case 6:
        rlutil::locate(posc+1, posf);
        cout<<(char) 220;
        rlutil::locate(posc+3, posf);
        cout<<(char) 220;
        rlutil::locate(posc+5, posf);
        cout<<(char) 220;

        rlutil::locate(posc+1, posf+2);
        cout<<(char) 223;
        rlutil::locate(posc+3, posf+2);
        cout<<(char) 223;
        rlutil::locate(posc+5, posf+2);
        cout<<(char) 223;
        break;
    }
}

void dibujarCuadrado(int posc, int posf, bool blanco)
{
    if(blanco){

        rlutil::setColor(rlutil::WHITE);
    } else{
        rlutil::setColor(rlutil::BLACK);
    }
    for(int c=posc; c<=posc+6; c++)
    {
        for(int f=posf; f<=posf+2; f++)
        {
            rlutil::locate(c, f);
            cout<<(char) 219;
        }
    }
}
