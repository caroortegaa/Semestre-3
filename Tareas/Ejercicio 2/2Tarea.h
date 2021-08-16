#include<iostream>
#include <string>

using namespace std;

class Jugador
{
    private : //características
    string usuario;
    string contraseña;
    int extra;
    int cerovidas;
    int jugar;

    public : //acciones
    Jugador(){};
    Jugador(string _usuario, string _contraseña, int _extra,int _cerovidas, int_jugar){
        usuario = _usuario;
        contraseña = _contraseña;
        extra=_extra;
        cerovidas=_cerovidas;
        jugar = 0;
    }
    void SetUsuario(string usuario);
    void SetContraseña(string contraseña);
    void vida_extra(int extra);
    void sin_vidas(int cerovidas);

};

void Jugador::SetUsuario(string usuario){
    cout<< "Elige tu nombre de usuario: " << this->usuario<<endl;
}

void Jugador::SetContraseña(string contraseña){
    cout<< "Elige tu contraseña: " << this->contraseña<<endl;
}

void Jugador::vida_extra(int extra){
    if (extra==true)
        return this->extra+1;
    else
    {
        break;
    }
    
}

void Jugador::sin_vidas(int cerovidas){
    if (cerovidas==0)
        return "GAME OVER!"
}

int main()
{
    Jugador * a = new Jugador("Caro" , "abc", 0 ,0,0);
    Jugador * b = new Jugador("Alw" , "abcd", 0,0,0);
    Jugador * c = new Jugador("Cars" , "hola", 0,0,0);

    delete a;
    delete b;
    delete c;
}
