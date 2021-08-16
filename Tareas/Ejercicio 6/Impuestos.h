#include<iostream>
#include <string>

using namespace std;
#pragma once

class Impuestos
{
    private:
    int porcentaje;
    int monto;
    int total;

    public:
    Impuestos(){};
    Impuestos(int _porcentaje, int _monto , int _total){
        porcentaje = _porcentaje;
        monto = _monto;
        total = _total;
    }
    void calcular_impuesto(int monto);
    void total_pagar(int total, int montotal);
};

void Impuestos::calcular_impuesto(int monto){
    int montotal = this->monto - 4053;
}

void Impuestos::total_pagar(int total , int montotal){
    this -> total = montotal;
    cout<< "El total de impuestos que debe pagar es de : $ " << this -> total << "pesos" << endl;
}

int main(){
    Impuestos* empleado1 = new Impuestos (20.3 , 20000 , 0);

    delete empleado1;

    return 0;
}