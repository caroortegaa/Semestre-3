#include<iostream>
#include<string>

using namespace std;
#pragma once

class Rating
{
    protected:
    int estrellas;

    public:

    Rating(){
        estrellas = 0;
    }

    void setEstrellas(int calificacion){
        estrellas=calificacion;
    }

    int getEstrellas(){
        return this->estrellas;
    }
};