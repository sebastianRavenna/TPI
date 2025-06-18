#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"Inicio.h"
#include"rlutil.h"
#include"estadisticas.h"
#include"Dados.h"

void juego()
{
    string jugadorA, jugadorB, nombreJugador;

    cout<<"Ingresa el nombre del jugador A: ";
    cin>>jugadorA;

    cout<<"Ingresa el nombre del jugador B: ";
    cin>>jugadorB;

    bool empiezaA = turnoInicial(jugadorA, jugadorB);
    bool blanco;
    ///bool primeraPartida=false;

    int stockDados=1;
    int stockDadosA = 6;
    int stockDadosB = 6;
    int puntajeTotalA=0;
    int puntajeTotalB=0;
    int ronda=0;

    while (ronda<6 && stockDadosA!=0 && stockDadosB!=0 )
    {
        ronda++;

        int vecDadosElegidos[12]= {};

        if (empiezaA)
        {
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::cls();
            stockDados = stockDadosA;
            nombreJugador = jugadorA;
            blanco = true;
        }
        else
        {
            rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::cls();
            stockDados = stockDadosB;
            nombreJugador = jugadorB;
            blanco = false;
        }

        cout<<"Numero de ronda: "<<(ronda+1)/2<<endl;
        cout<<"Turno de "<<nombreJugador<<endl<<endl;
        cout<<jugadorA<<": "<<puntajeTotalA<<"\t\t"<<jugadorB<<": "<<puntajeTotalB<<endl;
        cout<<"Presiona una tecla para lanzar los dados que te indican el N£mero Objetivo "<<endl<<endl;
        rlutil::anykey();

        int dadosObjetivo[2]= {};
        int numeroObjetivo=0;

        for (int i=0; i<2; i++)
        {
            dadosObjetivo[i] = rand()%12+1;
            numeroObjetivo+=dadosObjetivo[i];
        }

        cout<<"Los dados objetivos son: \nDado 1: "<<dadosObjetivo[0]<<"\t"<<"Dado 2: " <<dadosObjetivo[1]<<endl;
        cout<<"Tu NUMERO OBJETIVO es: "<<numeroObjetivo<<endl;
        cout<<endl;
        cout<<"Tu stock de dados es de: "<<stockDados<<endl;

        cout<<"Presiona una tecla para lanzar tus dados: "<<endl;
        rlutil::anykey();

        int dados[12]= {};
        int dadosElegidos=-1, sumaSeleccionada=0, cantDadosElegidos=0, puntajeRonda=0;


        rlutil::saveDefaultColor();
        for (int i=0;i<stockDados;i++){
            dados[i] = rand()%6+1;
            dibujarDado(dados[i], i*9+3, 14, blanco);
            rlutil::locate(i*9+5, 17);
            if (empiezaA){
            rlutil::setBackgroundColor(rlutil::BLUE);
            }else rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::setColor(rlutil::WHITE);
            cout<<"("<<i+1<<")"<<"\t";
        }
        for (int i=0;i<stockDados;i++){
        }
        cout<<endl<<endl;

        cout<<"Selecciona los dados que quer‚s sumar, si crees que no podes lograr la suma presiona 0"<<endl;
        cout<<endl;

        while(dadosElegidos!=0 && sumaSeleccionada<numeroObjetivo)
        {
            cout<<"Dado Nø ";
            cin>>dadosElegidos;

            if(dadosElegidos>=0 && dadosElegidos<=stockDados)
            {

                if(dadosElegidos!=0)
                {

                    if(vecDadosElegidos[dadosElegidos-1]==0)
                    {
                        sumaSeleccionada += dados[dadosElegidos-1];
                        cantDadosElegidos++;
                        vecDadosElegidos[dadosElegidos-1]=dados[dadosElegidos-1];

                    }
                    else
                    {
                        cout<<endl;
                        cout<<"Ya elegiste este dado, selecciona otro."<<endl;
                    }

                }

            }
            else
            {
                cout<<"Opcion INCORRECTA, ingresa un numero entre 1 y "<<stockDados<<" para seguir jugando, o 0 para rendirte."<<endl;
            }

            cout<<"cant de dados: "<<cantDadosElegidos<<endl;
            cout<<"suma seleccionada: "<<sumaSeleccionada<<endl;
            cout<<endl;
        }


        puntajeRonda = sumaSeleccionada*cantDadosElegidos;
        cout<<"La suma total de los dados elegidos es de "<<sumaSeleccionada<<endl;

        if(sumaSeleccionada==numeroObjetivo)
        {
            cout<<"Lograste igualar el N£mero Objetivo, tu puntaje en esta ronda es "<<puntajeRonda<<" y le pasas "<<cantDadosElegidos<<" dados a tu rival."<<endl;
            cout<<endl;
        }
        else
        {
            cout<<"No lograste el N£mero Objetivo"<<endl;
            puntajeRonda=0;

            if((empiezaA && stockDadosB!=1) || (!empiezaA && stockDadosA!=1))
            {
                cantDadosElegidos=-1;
                cout<<"Recibis un dado de tu rival."<<endl;
            }
            else
            {
                cantDadosElegidos=0;
            }

        }


        cout<<endl;

        if(empiezaA)
        {
            empiezaA=false;
            blanco = false;
 ///              6      -      (-1)=  7
            stockDadosA-=cantDadosElegidos;
 ///              6     +       (-1)=  5
            stockDadosB+=cantDadosElegidos;
            puntajeTotalA+=puntajeRonda;
            cout<<endl;

            cout<<"Presiona una tecla para continuar."<<endl;
            rlutil::anykey();

            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::cls();

            if(cantDadosElegidos==-1)
            {
                cantDadosElegidos=0;
            }
            if(stockDadosA==0)
            {
                puntajeTotalA+=10000;
                cout<<"Ganaste 10000 puntos por quedarte sin dados"<<endl<<endl;
            }
            cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalA<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();


        }
        else
        {
            empiezaA=true;
            blanco = true;


            stockDadosB-=cantDadosElegidos;
            stockDadosA+=cantDadosElegidos;
            puntajeTotalB+=puntajeRonda;

            cout<<"Presiona una tecla para continuar."<<endl;
            rlutil::anykey();

            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::cls();

            if(cantDadosElegidos==-1)
            {
                cantDadosElegidos=0;
            }

            if(stockDadosB==0)
            {
                puntajeTotalB+=10000;
                cout<<"Ganaste 10000 puntos por quedarte sin dados"<<endl<<endl;
            }
            cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalB<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();



        }
    }


    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::cls();

    if(puntajeTotalA>puntajeTotalB)
    {

        cout<<jugadorA<<" gano el juego con "<<puntajeTotalA<<" puntos"<<endl;

    }
    else if(puntajeTotalA<puntajeTotalB)
    {

        cout<<jugadorB<<" gano el juego con "<<puntajeTotalB<<" puntos"<<endl<<endl;

    }
    else
    {
        cout<<"Hubo empate entre el jugador "<<jugadorA<<" y el jugador "<<jugadorB<<" con "<<puntajeTotalA<<" puntos."<<endl<<endl;
    }

    cout<<"Presiona una tecla para continuar."<<endl<<endl;
    rlutil::anykey();


    //if(!primeraPartida){

    // primeraPartida=true;
    //}

}

/*void estadisticas(int puntajeTotalA,int puntajeTotalB, string jugadorA, string jugadorB,bool primeraPartida){

            rlutil::cls();

    if(primeraPartida){



    if (puntajeTotalA==puntajeTotalB){
        cout<<"Hubo un empate entre los jugadores."<<endl;

            }else if(puntajeTotalA>puntajeTotalB){
                    puntajeMax=puntajeTotalA;
                    cout<<jugadorA<<" gano el juego"<<"con "<<puntajeTotalA<<" puntos"<<endl;

            }else {
                    puntajeMax=puntajeTotalB;
                    cout<<jugadorB<<" gano el juego"<<"con "<<puntajeTotalB<<" puntos"<<endl;
            }}

            }*/
