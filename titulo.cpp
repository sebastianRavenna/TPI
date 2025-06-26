#include <iostream>
#include"rlutil.h"
#include"Dados.h"
using namespace std;

///titulo del juego
void titulo(){
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::cls();

 for(int i=0; i<30; i++)
    {
        if(i%3==0)
        {   rlutil::hidecursor();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);
        }
        else if ((i-1)%3==0)
        {   rlutil::hidecursor();
            rlutil::setBackgroundColor(rlutil::MAGENTA);
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {   rlutil::hidecursor();
            rlutil::setBackgroundColor(rlutil::YELLOW);
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

        ///relentiza
        rlutil::msleep(i*5);
    }

    ///generacion de dados, argumentos por valores
    for (int i=1; i<=6; i++){
        dibujarDado(i, i*9+20, 10, true);
    }
        int ubicacionDados=20;
    for (int i=6; i>=1; i--){
        dibujarDado(i, ubicacionDados+=9, 14, false);
    }
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::setColor(rlutil::WHITE);
}
