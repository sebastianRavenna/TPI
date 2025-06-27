#include<iostream>
using namespace std;
#include<ctime>
#include"rlutil.h"
#include"Menu.h"
#include"Inicio.h"
#include"estadisticas.h"
#include"Dados.h"
#include"ganaste.h"
#include"DadosObjetivos.h"

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
    int stockDados;
    int stockDadosA = 6,stockDadosB = 6;
    int puntajeTotalA=0,puntajeTotalB=0;
    int ronda=0;

    while (ronda<6 && stockDadosA!=0 && stockDadosB!=0)
    {
        ronda++;

        ///valida para no elegir el mismo dado, y muestra los elegidos
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

       cout<<"Los dados objetivos son: "<<endl;
        for (int i=0; i<2; i++)
        {
            dadosObjetivo[i]=rand()%12+1;
            dibujarDadoObjetivo(dadosObjetivo[i], i*15+10, 9);
            numeroObjetivo+=dadosObjetivo[i];
            if (empiezaA){
            rlutil::setBackgroundColor(rlutil::BLUE);
            }else {rlutil::setBackgroundColor(rlutil::GREEN);}
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(i*15+10, 12);
            cout<<"Dado ("<<i+1<<")";
        }
        cout<<endl<<endl;
        rlutil::setBackgroundColor(rlutil::YELLOW);
        rlutil::setColor(rlutil::BLACK);
        cout<<"Tu NUMERO OBJETIVO es: "<<numeroObjetivo<<endl;

        if (empiezaA){
            rlutil::setBackgroundColor(rlutil::BLUE);
            }else{rlutil::setBackgroundColor(rlutil::GREEN);}
            rlutil::setColor(rlutil::WHITE);
        cout<<endl;
        cout<<"Tu stock de dados es de: "<<stockDados<<endl<<endl;

        cout<<"Presiona una tecla para lanzar tus dados "<<endl;
        rlutil::anykey();

        int dados[12]={};
        ///inicia en -1 para que entre al while
        int dadosElegidos=-1, sumaSeleccionada=0, cantDadosElegidos=0, puntajeRonda=0;
        int sumaMaxima=0;

        for (int i=0;i<stockDados;i++){
            dados[i]=rand()%6+1;
            sumaMaxima+=dados[i];
            dibujarDado(dados[i], i*9+3, 20, blanco);
            if (empiezaA){
            rlutil::setBackgroundColor(rlutil::BLUE);
            }else {rlutil::setBackgroundColor(rlutil::GREEN);}
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(i*9+5, 23);
            cout<<"("<<i+1<<")"<<"\t";
        }

        cout<<endl<<endl;

        if (sumaMaxima<numeroObjetivo) {

            cout << "No es posible alcanzar el NUMERO OBJETIVO con los dados actuales."<<endl<<endl;
            cout << "Perd‚s esta ronda autom ticamente."<<endl<<endl;}

        else{cout<<"Selecciona los dados que quer‚s sumar, si crees que no podes lograr la suma presiona 0"<<endl<<endl;

        ///ciclo para eleccion de dados
        while(dadosElegidos!=0 && sumaSeleccionada<numeroObjetivo)
        {
            cout<<"Dado seleccionado Nø ";
            cin>>dadosElegidos;

            ///valida que elija un dado  dentro del stock
            if(dadosElegidos>=0 && dadosElegidos<=stockDados)
            {
                if(dadosElegidos!=0)
                {
                    ///valida que no elija el mismo dado
                    ///se resta 1 para equiparar posicion e indice
                    if(vecDadosElegidos[dadosElegidos-1]==0)
                    {
                        sumaSeleccionada += dados[dadosElegidos-1];
                        cantDadosElegidos++;
                        vecDadosElegidos[dadosElegidos-1]=dados[dadosElegidos-1];
                    }
                    else
                    {
                        cout<<endl<<"Ya elegiste este dado, selecciona otro."<<endl;
                    }
                }
            }
            else
            {
                cout<<"Opcion INCORRECTA, ingresa un numero entre 1 y "<<stockDados<<" para seguir jugando, o 0 para rendirte."<<endl;
            }
        cout<<endl;
        }}



        ///tirada exitosa
        if(sumaSeleccionada==numeroObjetivo)
        {
            puntajeRonda = sumaSeleccionada*cantDadosElegidos;
            cout<<"Lograste igualar el NUMERO OBJETIVO"<<endl<<endl;
        }
        ///tirada no exitosa
        else
        {
            cout<<"No lograste el NUMERO OBJETIVO"<<endl<<endl;
            puntajeRonda=0;

            ///para no pasar dado en caso de stock 1
            if((empiezaA && stockDadosB!=1) || (!empiezaA && stockDadosA!=1))
            {
                cantDadosElegidos=-1;
            }
            else
            {
                cantDadosElegidos=0;
            }
        }
            cout<<endl<<"Presiona una tecla para continuar."<<endl;
            rlutil::anykey();

        if(empiezaA)
        {
            empiezaA=false;
            blanco=false;
 ///              6     -      (-1)=  7
            stockDadosA-=cantDadosElegidos;
            puntajeTotalA+=puntajeRonda;
            rlutil::cls();

            if(stockDadosA==0){
                puntajeTotalA+=10000;
                rlutil::setBackgroundColor(rlutil::BROWN);
                cout<<"­­TIRADA EXITOSA!!"<<endl<<endl;
                rlutil::setBackgroundColor(rlutil::BLUE);
                cout<<"Obtenes 10000 puntos por quedarte sin dados"<<endl<<endl;

                ganaste();

                rlutil::setBackgroundColor(rlutil::BLUE);
                rlutil::setColor(rlutil::WHITE);
                cout<<endl<<endl<<"Tu puntaje final es de "<<puntajeTotalA<<endl<<endl;


            }else{

             if(puntajeRonda==0){
                ///informa si recibe dado o no
                if(stockDadosB!=1){
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<<"­­TIRADA NO EXITOSA!!"<<endl<<endl;
                    rlutil::setBackgroundColor(rlutil::BLUE);
                    cout<<"Recibis 1 dado de tu rival."<<endl<<endl;
                    cout<<"Tu NUMERO OBJETIVO era "<<numeroObjetivo<<endl<<endl;}

                else{
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<<"­­TIRADA NO EXITOSA!!"<<endl<<endl;
                    rlutil::setBackgroundColor(rlutil::BLUE);
                    cout<<"Tu rival no puede pasarte el unico dado que le queda."<<endl<<endl;
                    cout<<"Tu NUMERO OBJETIVO era "<<numeroObjetivo<<endl<<endl;}}

                    ///  6     +       (-1)=  5
                    stockDadosB+=cantDadosElegidos;
                    ///esta aca para que no se interfiera para validacion cuando tiene 2 dados


            if(sumaSeleccionada==numeroObjetivo){
                rlutil::setBackgroundColor(rlutil::BROWN);
                cout<<"­­TIRADA EXITOSA!!"<<endl<<endl;
                rlutil::setBackgroundColor(rlutil::BLUE);

            ///validacion para que le cartel sea plural o singular
            if(cantDadosElegidos==1){
                cout<<"El dado que seleccionaste fue: "<<endl<<endl;
            }else{
                cout<<"Los dados que seleccionaste fueron: "<<endl<<endl;
            }

                int cont=0;
                for(int i=0; i<12; i++){
                    if (vecDadosElegidos[i]!=0){
                        dibujarDado(vecDadosElegidos[i], cont*9+3, 5, blanco);
                        rlutil::locate(cont*9+5, 8);
                        rlutil::setBackgroundColor(rlutil::BLUE);
                        cout<<"("<<i+1<<")"<<"\t";
                        cont++;
                    }
                }
                cout<<endl<<endl;

                ///validacion para que le cartel sea plural o singular
                if(cantDadosElegidos==1){
                    cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dado a tu rival"<<endl<<endl;

                }else{
                    cout<<"En esta ronda le pasaste "<<cantDadosElegidos<<" dados a tu rival"<<endl<<endl;
                }
            }
            cout<<"Tu puntaje en esta ronda fue: "<<puntajeRonda<<endl<<endl;
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalA<<endl<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();}

        }
        else
        {
            empiezaA=true;
            blanco = true;

            rlutil::saveDefaultColor();
            stockDadosB-=cantDadosElegidos;
            puntajeTotalB+=puntajeRonda;
            rlutil::cls();

            if(stockDadosB==0)
            {
                puntajeTotalB+=10000;
                rlutil::setBackgroundColor(rlutil::CYAN);
                cout<< "­­TIRADA EXITOSA!!"<<endl<<endl;
                rlutil::setBackgroundColor(rlutil::GREEN);
                cout<<"Obtenes 10000 puntos por quedarte sin dados"<<endl<<endl;
                ganaste();

                rlutil::setBackgroundColor(rlutil::GREEN);
                rlutil::setColor(rlutil::WHITE);
                cout<<endl<<endl<<"Tu puntaje final es de "<<puntajeTotalB<<endl<<endl;


            }else{
            if(puntajeRonda==0){

                if(stockDadosA!=1){
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<< "­­TIRADA NO EXITOSA!!"<<endl<<endl;
                    rlutil::setBackgroundColor(rlutil::GREEN);
                    cout<<"Recibis 1 dado de tu rival."<<endl<<endl;
                    cout<<"Tu NUMERO OBJETIVO era "<<numeroObjetivo<<endl<<endl;}

                else{
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<< "­­TIRADA NO EXITOSA!!"<<endl<<endl;
                    rlutil::setBackgroundColor(rlutil::GREEN);
                    cout<<"Tu rival no puede pasarte el unico dado que le queda."<<endl<<endl;
                    cout<<"Tu NUMERO OBJETIVO era "<<numeroObjetivo<<endl<<endl;}}

                    stockDadosA+=cantDadosElegidos;


            if(sumaSeleccionada==numeroObjetivo){
                rlutil::setBackgroundColor(rlutil::BROWN);
                cout<< "­­TIRADA EXITOSA!!"<<endl<<endl;
                rlutil::setBackgroundColor(rlutil::GREEN);
                if(cantDadosElegidos==1){
                    cout<<"El dado que seleccionaste fue: "<<endl<<endl;
                    }else{
                    cout<<"Los dados que seleccionaste fueron: "<<endl<<endl;
            }

                int cont=0;
                for(int i=0; i<12; i++){
                    if (vecDadosElegidos[i]!=0){
                        dibujarDado(vecDadosElegidos[i], cont*9+3, 5, blanco);
                        rlutil::locate(cont*9+5, 8);
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
            cout<<"Tu puntaje total hasta ahora es: "<<puntajeTotalB<<endl<<endl<<endl;
            cout<<"Presiona una tecla para continuar."<<endl<<endl;
            rlutil::anykey();
            }
        }
    }

    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::cls();

    if(puntajeTotalA>puntajeTotalB){
        cout<<endl<<jugadorA<<" gan¢ el juego con "<<puntajeTotalA<<" puntos"<<endl<<endl;

        ganaste();

        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::setColor(rlutil::WHITE);
        cout<<endl<<endl;
        ganador=jugadorA;
        puntajeGanador=puntajeTotalA;
    }
    else if(puntajeTotalA<puntajeTotalB)
    {
        cout<<endl<<jugadorB<<" gan¢ el juego con "<<puntajeTotalB<<" puntos"<<endl<<endl;

        ganaste();

        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::setColor(rlutil::WHITE);
        cout<<endl<<endl;
        ganador=jugadorB;
        puntajeGanador=puntajeTotalB;
    }
    else
    {   cout<<endl;
        cout<<"Hubo empate entre "<<jugadorA<<" y "<<jugadorB<<" con "<<puntajeTotalA<<" puntos."<<endl<<endl;
        ganador=jugadorA;
        puntajeGanador=puntajeTotalA;

    }

    if(puntajeGanador>record){
        record=puntajeGanador;
        ganadorRecord=ganador;
    }


}


