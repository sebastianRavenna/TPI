#include<iostream>
#include<ctime>

using namespace std;

int numeroInicio;

void mostrarMenu(){

cout<<"      ______   ___________  _______   ______  ___    ____  ____  ____ "<<endl;
cout<<"     / ___/ | / / ___/ __ \\/ ____/ | / / __ \\/   |  / __ \\/ __ \\/ ___/"<<endl;
cout<<"    / __//  |/ / /_ / /_/_/ __/ /  |/ / / / / /| | / / / / / / /\\__ \\ "<<endl;
cout<<"   / /__/ /|  / __// _  \\/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ / "<<endl;
cout<<"  /____/_/ |_/_/  /_/ \\_/_____/_/ |_/_____/_/  |_/_____/\\____//____/  "<<endl<<endl<<endl<<endl<<endl;

cout<<" =========================="<<endl;
cout<<"||  1 - JUGAR             ||"<<endl;
cout<<"||                        ||"<<endl;
cout<<"||  2 - ESTADISTICAS      ||"<<endl;
cout<<"||                        ||"<<endl;
cout<<"||  1 - CRDITOS          ||"<<endl;
cout<<"||========================||"<<endl;
cout<<"||  0 - SALIR             ||"<<endl;
cout<<" =========================="<<endl<<endl;

cout<<"Ingrese el numero deseado: ";
cin>> numeroInicio;

while(numeroInicio>2||numeroInicio<0){
    cout<<"Ingrese un n£mero correcto"<<endl;
    cout<<"Ingrese el numero deseado: ";
    cin>> numeroInicio;
}

switch(numeroInicio){
    case 1:
    cout<<"aca va la funcion del juego.h";
    break;

    case 2:
    cout<<"aca va la funcion de las estadisticas.h";
    break;

    case 3:
    cout<<"aca va la funcion de creditos.h";
    break;

    case 0:
    return;
}
}



