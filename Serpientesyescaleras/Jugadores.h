#include<iostream>
#include <string>

using namespace std;
#pragma once

class Jugadores{
    private:
    int posicion;

    public:

    Jugadores(){
         posicion = 0;
    }
   
   void setposicion(int casilla){
       posicion=casilla;
   }

   int getposicion(){
       return posicion;
   }
};




