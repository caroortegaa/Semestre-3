#include<iostream>
#include<string>

using namespace std;
#pragma once

class Video
{
    protected:
    int ID;
    string nombre;
    int tiempo;
    string genero;

    public:
    Video(){};
    Video(int ID , string nombre , int tiempo , string genero)
    :ID(ID),nombre(nombre),tiempo(tiempo),genero(genero){}

    virtual void mostrarVideo()=0; //contructor puro 

    int getID();
    string getNombre();
    int getTiempo();
    string getGenero();
};

int Video::getID(){
    return ID;
}

string Video::getNombre(){
    return nombre;
}

int Video::getTiempo(){
    return tiempo;
}

string Video::getGenero(){
    return this->genero;
}