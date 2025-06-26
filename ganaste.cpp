#include <iostream>
#include"rlutil.h"
using namespace std;

 void ganaste(){

               for(int i=0; i<30; i++){
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
                rlutil::locate(10,5);
                cout<<"­­GANASTE LA PARTIDA!!";

        rlutil::msleep(i*5);

        }}
