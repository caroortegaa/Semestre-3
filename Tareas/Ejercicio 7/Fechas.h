#include<iostream>
#include <string>

using namespace std;
#pragma once

class Fecha
{
    private:
    int dia;
    int mes;
    string letrames;
    int anio;

    public:
    Fecha(){};
    Fecha(int _dia, int _mes , string _letrames , int _anio){
        dia=_dia;
        mes=_mes;
        letrames= _letrames;
        anio=_anio;
    }
    void getDate(int _dia, int _mes , string _letrames , int _anio);
    void getCurrentDate(int _dia, int _mes , string _letrames , int _anio);
    void getDay(int _dia);
    void getMonth(int _mes , string _letrames);
    void getYear(int _anio);
};

void Fecha::getDate(int _dia, int _mes , string _letrames , int _anio){
    cout << "¿Qué formato de fecha desea? 1. 2. 3. 4."<< getDate << endl;
    if getDate==1.
        return this->dia , "-" , this-> mes
    elif getDate==2.
        return this->dia, "-", this-> mes, "-" , this->anio;
    elif getDate==3.
        return this->dia, "/", this-> mes, "/" , this->anio;
    else getDate==4.
        return this->dia, "/", this-> mes;
}

void Fecha::getCurrentDate(int _dia, int _mes , string _letrames , int _anio){
    cin >> "¿Qué fecha desea poner? : ">> this-> getDate;
    cout << "La fecha actual es:" << this->getDate;
}

void Fecha::getDay(int _dia){
    cin >> "¿Qué día es? : " >> *_dia >> endl;
    cout << "Hoy es : " << this->dia << endl;
}

void Fecha::getMonth(int _mes , string _letrames){
    cin >> "¿Qué mes es? : " >> mes >> letrames >> endl;
    cout << "Debe especificar si quiere que el mes sea número(1) o palabra(2) : " << endl;
    if getMonth==1
        return this-> mes;
    else getMonth==2
        return this-> letrames;
}

void Fecha::getYear(int _anio){
    cin >> "¿Qué año es? : " >> *_anio >> endl;
    cout << "Hoy es : " << this->anio << endl;
}

int main(){
    Fecha* opcion1= new Fecha(24 , 05 , mayo , 2020);
    Fecha* opcion2= new Fecha(7 , 12 , diciembre , 2019);
    Fecha* opcion3= new Fecha(31 , 08 , agosto , 2020);

    delete opcion1;
    delete opcion2;
    delete opcion3;

    return 0;
}