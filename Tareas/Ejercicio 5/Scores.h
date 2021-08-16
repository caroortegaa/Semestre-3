#include<iostream>
#include <string>

using namespace std;
#pragma once

class Scores
{
    string equipo;
    int puntos;
    //bool canasta;

    public:
    Scores(string _equipo , int _puntos){
        equipo=_equipo;
        puntos=_puntos;
        //canasta= _canasta;
    }
    void nombre_equipo(string equipo);
    void puntos(int puntos);
};

void Scores::nombre_equipo(string equipo){
    cout << "Este equipo es: " << this-> equipo << endl;
}

void Scores::puntos(int puntos){ //boolcanasta
    //bool canasta= true;
    cout<<"Los puntos de este equipo son: " << this->puntos<< endl;
}


int main(){
   Scores* unequipo= new Scores("Lakers");
   Scores* lospuntos= new Scores(5);

   delete unequipo;
   delete lospuntos;
}
