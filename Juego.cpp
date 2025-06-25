#include<iostream>
using namespace std;
#include<ctime>
#include"Menu.h"
#include"Inicio.h"
#include"rlutil.h"
#include"estadisticas.h"
#include"Dados.h"

void juego(int &record, string &ganadorRecord)
{
    string jugadorA, jugadorB, nombreJugador, ganador;

    cout<<"Ingresa el nombre del jugador A: ";
    cin>>jugadorA;

    cout<<"Ingresa el nombre del jugador B: ";
    cin>>jugadorB;
    cout<<endl;
    bool empiezaA = turnoInicial(jugadorA, jugadorB);
    bool blanco;
    int puntajeGanador=0;
    int stockDados=1;
    int stockDadosA = 6,stockDadosB = 6;
    int puntajeTotalA=0,puntajeTotalB=0;
    int ronda=0;

    while (ronda<6 && stockDadosA!=0 && stockDadosB!=0)
    {
        ronda++;

        int vecDadosElegidos[12]={};

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

        cout<<"Puntaje de "<<jugadorA<<": "<<puntajeTotalA<<"\t\t\t"<<"RONDA "<<(ronda+1)/2<<"\t\t\t"<<"Puntaje de "<<jugadorB<<": "<<puntajeTotalB<<endl<<endl;
        cout<<"Turno de "<<nombreJugador<<endl<<endl;
        cout<<"Presiona una tecla para lanzar los dados que te indican el NUMERO OBJETIVO "<<endl<<endl;
        rlutil::anykey();

        int dadosObjetivo[2]={};
        int numeroObjetivo=0;

        for (int i=0; i<2; i++)
        {
            dadosObjetivo[i] = rand()%12+1;
            numeroObjetivo+=dadosObjetivo[i];
        }

        cout<<"Los dados objetivos son: \nDado (1): "<<dadosObjetivo[0]<<"\t"<<"Dado (2): " <<dadosObjetivo[1]<<endl<<endl;
        cout<<"Tu NUMERO OBJETIVO es: "<<numeroObjetivo<<endl;
        cout<<endl;
        cout<<"Tu stock de dados es de: "<<stockDados<<endl<<endl;

        cout<<"Presiona una tecla para lanzar tus dados "<<endl;
        rlutil::anykey();

        int dados[12]={};
        int dadosElegidos=-1, sumaSeleccionada=0, cantDadosElegidos=0, puntajeRonda=0;
        int sumaMaxima=0;

        rlutil::saveDefaultColor();
        for (int i=0;i<stockDados;i++){
            dados[i]= rand()%6+1;
            sumaMaxima+=dados[i];
            dibujarDado(dados[i], i*9+3, 16, blanco);
            rlutil::locate(i*9+5, 19);
            if (empiezaA){
            rlutil::setBackgroundColor(rlutil::BLUE);
            }else rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::setColor(rlutil::WHITE);
            cout<<"("<<i+1<<")"<<"\t";
        }
        for (int i=0;i<stockDados;i++){
        }
        cout<<endl<<endl;

        if (sumaMaxima<numeroObjetivo) {

            cout << "No es posible alcanzar el NUMERO OBJETIVO con los dados actuales."<<endl<<endl;
            cout << "Perd‚s esta ronda autom ticamente."<<endl<<endl;}

        else{cout<<"Selecciona los dados que quer‚s sumar, si crees que no podes lograr la suma presiona 0"<<endl;
        cout<<endl;

        while(dadosElegidos!=0 && sumaSeleccionada<numeroObjetivo)
        {
            cout<<"Dado seleccionado Nø ";
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

            cout<<endl;
        }}


        puntajeRonda = sumaSeleccionada*cantDadosElegidos;

        if(sumaSeleccionada==numeroObjetivo)
        {
            cout<<"Lograste igualar el NUMERO OBJETIVO"<<endl;
            cout<<"La suma total de los dados elegidos es de "<<sumaSeleccionada<<endl;
        }
        else
        {
            cout<<"No lograste el NUMERO OBJETIVO"<<endl;
            puntajeRonda=0;

            if((empiezaA && stockDadosB!=1) || (!empiezaA && stockDadosA!=1))
            {
                cantDadosElegidos=-1;

            }
            else
            {
                cantDadosElegidos=0;
            }

        }


            cout<<endl;
            cout<<"Presiona una tecla para continuar."<<endl;
            rlutil::anykey();

        if(empiezaA)
        {
            empiezaA=false;
            blanco = false;
 ///              6      -      (-1)=  7
            stockDadosA-=cantDadosElegidos;
 ///              6     +       (-1)=  5

            puntajeTotalA+=puntajeRonda;

            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::cls();

            if(stockDadosA==0){
                puntajeTotalA+=10000;

                if(puntajeTotalA>record){
                    record=puntajeTotalA;
                    ganadorRecord=puntajeTotalA;
                    }
                cout<<"Obtenes 10000 puntos por quedarte sin dados"<<endl<<endl;
                cout<<"­­GANASTE LA PARTIDA!!"<<endl<<endl;
                cout<<"Tu puntaje final es de "<<puntajeTotalA<<endl<<endl;
                cout<<"Presiona una tecla para continuar."<<endl<<endl;
                rlutil::anykey();


            }else{

             if(puntajeRonda==0){

                if(stockDadosB!=1){

                    cout<<"Recibis 1 dado de tu rival."<<endl<<endl;}

                else{
                    cout<<"Tu rival no puede pasarte el unico dado que le queda."<<endl<<endl;}}

                    stockDadosB+=cantDadosElegidos;

                    cout<<"Tu NUMERO OBJETIVO era "<<numeroObjetivo<<endl<<endl;

            if(sumaSeleccionada==numeroObjetivo){

                int cont = 0;
                for(int i=0; i<12; i++){
                    if (vecDadosElegidos[i]!=0){
                        dibujarDado(vecDadosElegidos[i], cont*9+3, 4, blanco);
                        rlutil::locate(cont*9+5, 7);
                        rlutil::setBackgroundColor(rlutil::BLUE);
                        cout<<"("<<i+1<<")"<<"\t";
                        cont++;
                    }
                }
                cout<<endl<<endl;

                if(cantDadosElegidos==1){
                    cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dado a tu rival"<<endl<<endl;

                }else{
                    cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
                }

            }
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalA<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();}


        }
        else
        {
            empiezaA=true;
            blanco = true;


            stockDadosB-=cantDadosElegidos;

            puntajeTotalB+=puntajeRonda;

            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::cls();



            if(stockDadosB==0)
            {
                puntajeTotalB+=10000;
                if(puntajeTotalB>record){
                    record=puntajeTotalB;
                    ganadorRecord=jugadorB;
                }

                cout<<"Obtenes 10000 puntos por quedarte sin dados"<<endl<<endl;
                cout<<"­­GANASTE LA PARTIDA!!"<<endl<<endl;
                cout<<"Tu puntaje final es de "<<puntajeTotalB<<endl<<endl;
                cout<<"Presiona una tecla para continuar."<<endl<<endl;
                rlutil::anykey();

            }else{
            if(puntajeRonda==0){

                if(stockDadosA!=1){

                    cout<<"Recibis 1 dado de tu rival."<<endl<<endl;}

                else{
                    cout<<"Tu rival no puede pasarte el unico dado que le queda."<<endl<<endl;}}

                    stockDadosA+=cantDadosElegidos;

            cout<<"Tu NUMERO OBJETIVO era "<<numeroObjetivo<<endl<<endl;

            if(sumaSeleccionada==numeroObjetivo){

                int cont = 0;
                for(int i=0; i<12; i++){
                    if (vecDadosElegidos[i]!=0){
                        dibujarDado(vecDadosElegidos[i], cont*9+3, 4, blanco);
                        rlutil::locate(cont*9+5, 7);
                        rlutil::setBackgroundColor(rlutil::GREEN);
                        rlutil::setColor(rlutil::WHITE);
                        cout<<"("<<i+1<<")"<<"\t";
                        cont++;
                    }
                }
                cout<<endl<<endl;

                if(cantDadosElegidos==1){
                    cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dado a tu rival"<<endl<<endl;

                }else{
                    cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
                }

            }
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalB<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();}



        }
    }


    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::cls();

    if(puntajeTotalA<10000 && puntajeTotalB<10000){

        if(puntajeTotalA>puntajeTotalB)
    {

        cout<<jugadorA<<" gano el juego con "<<puntajeTotalA<<" puntos"<<endl;
        ganador=jugadorA;
        puntajeGanador=puntajeTotalA;
    }
    else if(puntajeTotalA<puntajeTotalB)
    {

        cout<<jugadorB<<" gano el juego con "<<puntajeTotalB<<" puntos"<<endl<<endl;
        ganador=jugadorB;
        puntajeGanador=puntajeTotalB;
    }
    else
    {
        cout<<"Hubo empate entre el jugador "<<jugadorA<<" y el jugador "<<jugadorB<<" con "<<puntajeTotalA<<" puntos."<<endl<<endl;
        ganador=jugadorA;
        puntajeGanador=puntajeTotalA;

    }

    if(puntajeGanador>record){
        record=puntajeGanador;
        ganadorRecord=ganador;
    }



     cout<<"Ingrese una tecla para vovler al menu"<<endl;
        rlutil::anykey();
        rlutil::cls();

}}


