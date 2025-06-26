using namespace std;
#include<iostream>

void reglamento(){

    cout << "REGLAMENTO DEL JUEGO: ENFRENDADOS"<<endl<<endl;
    cout << "Enfrendados es un juego de dados para 2 jugadores, basado en el azar y las matematicas."<<endl<<endl;
    cout << "El objetivo es sumar la mayor cantidad de puntos en 3 rondas, o ganar automaticamente si te quedas sin dados."<<endl<<endl;

    cout << "DADOS:"<<endl;
    cout << "Cada jugador comienza con 6 dados de 6 caras (dados stock)."<<endl;
    cout << "Ademas, se usan 2 dados de 12 caras que lanzan ambos jugadores entre rondas."<<endl<<endl;

    cout << "INICIO DEL JUEGO:"<<endl;
    cout << "Ambos jugadores tiran un dado. Quien saque el numero mayor empieza."<<endl;
    cout << "- En caso de empate, se repite hasta que haya un ganador."<<endl<<endl;

    cout << "TURNO DE UN JUGADOR:"<<endl;
    cout << "1. Tira los 2 dados de 12 caras --> la suma da el NUMERO OBJETIVO (entre 2 y 24)."<<endl;
    cout << "2. Tira todos sus dados stock."<<endl;
    cout << "3. Intenta elegir una combinacion de dados que sumen el NUMERO OBJETIVO."<<endl<<endl;

    cout << "SI LOGRA IGUALAR (TIRADA EXITOSA):"<<endl;
    cout << "Gana puntos multiplicando el NUMERO OBJETIVO por la cantidad de dados usados."<<endl;
    cout << "Pierde esos dados y se los pasa al rival."<<endl;
    cout << "Si se queda sin dados gana automaticamente +10.000 puntos."<<endl<<endl;

    cout << "SI NO LOGRA IGUALAR (TIRADA NO EXITOSA):"<<endl;
    cout << "El rival le da un dado, si tiene mas de 1 en su stock. De lo contrario, no hay penalizacion."<<endl<<endl;

    cout << "FIN DE LA RONDA:"<<endl;
    cout << "La ronda termina cuando ambos participantes jugaron."<<endl;
    cout << "El juego termina tras 3 rondas o si alguien se queda sin dados stock."<<endl<<endl;



}
