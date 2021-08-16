#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
#pragma once

class Dice
{
    public:
    int roll(int caras); 
}; 


int Dice::roll(int caras){
    
    srand(time(NULL));
    int total = rand()%caras+1;
    //cout<< "El numero lanzado es:"<< total << endl;
    return total;
}

//int main(){
//    Dice d;
//    cout << d.roll (8);
//}