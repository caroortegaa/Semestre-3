#include"Video.h"
#include"Rating.h"

using namespace std;
#pragma once

class Series : public virtual Video , public virtual Rating
{
    protected:
    int capitulos;
    int temporada;

    public:
    Series(){};
    Series(int ID , string nombre , int tiempo , string genero, int capitulos , int temporada)
    : Video(ID , nombre , tiempo , genero) , capitulos(capitulos), temporada(temporada)
    {}



    void mostrarVideo(){
     cout << ID << endl;
     cout << nombre << endl;
     cout << tiempo << endl;
     cout << genero << endl;
     cout << capitulos << endl;
     cout << temporada << endl;
    }

  int getTemporada()
  {
    return this->temporada;
  }

    int getCapitulo()
  {
    return this->capitulos;
  }

};
