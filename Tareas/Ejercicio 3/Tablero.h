#include<iostream>
#include <string>

using namespace std;
#pragma once 

class Tablero
{
    private:
    int num_casilla;
    string figura;
    string nombre;

    public:
    Tablero(){};
    Tablero(int elnum_casilla, string _figura , string _nombre){
        num_casilla=elnum_casilla;
        figura=_figura;
        nombre=_nombre;
    }
    void buscarcasilla(string nombre , int num_casilla ,int nollenar);
    void llenarcasilla(string nombre);
    void loteria();

};

void Tablero::buscarcasilla(string nombre , int num_casilla,int nollenar){
    nollenar=0;
    if(this-> nombre == this->figura)
        return this->num_casilla;
    else
        return nollenar;
}

void Tablero::llenarcasilla(string nombre){
    this->nombre=this->figura
    cout << "Llenar casilla : " << num_casilla << "que se llama " << nombre << endl;
}

void Tablero::loteria(){
    cout << "¡¡¡¡¡Loteriiiiaaaaa!!!!!" << endl;
}

int main (){
    Tablero* carta1= new Tablero(12,grande,catrina);
    delete carta1;
    return 0;
}