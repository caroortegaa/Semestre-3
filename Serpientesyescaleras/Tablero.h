#include<iostream>
#include <string>
#include "Jugadores.h"

using namespace std;
#pragma once

class Tablero{
    private:
    string S;
    string L;
    string N;
    string juego;

    public:
    Tablero(){
        juego = "NNNNNNLSNNNNNLNSNNNNNNNSNLNNNN";
    }

    char getposicion(int numero){
        return juego[numero];
    }
};


