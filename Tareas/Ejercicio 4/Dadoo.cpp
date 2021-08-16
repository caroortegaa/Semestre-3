#include "Dado.h"

void Dado::contar_caras(int caras){
    cout<< "El número de caras que tiene es: "<< this-> caras << endl;
}

void Dado::resultado(int caras){
    srand(time(NULL));
    int total = rand()%caras+1;
    this->num_lanzado=total;
    cout<< "El numero lanzado es:"<< this-> num_lanzado << endl;
}

int main(){
    Dado* primertiro= new Dado(6,0);
    Dado* segundotiro= new Dado(12,0);
    Dado* tercertiro= new Dado(8,0);

    delete primertiro;
    delete segundotiro;
    delete tercertiro;

    return 0;
}

