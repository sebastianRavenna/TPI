#include"rlutil.h"
#include<iostream>
#include"DadosObjetivos.h"
using namespace std;

void dibujarDadoObjetivo(int numero, int posc, int posf)
{
    dibujarCuadrado(posc, posf);

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::locate(posc+3, posf+1);
    cout<<numero;
}

void dibujarCuadrado(int posc, int posf)
{
    rlutil::setColor(rlutil::GREY);

    for(int c=posc; c<=posc+6; c++)
    {
        for(int f=posf; f<=posf+2; f++)
        {
            rlutil::locate(c, f);
            cout<<(char) 219;
        }
    }
}
