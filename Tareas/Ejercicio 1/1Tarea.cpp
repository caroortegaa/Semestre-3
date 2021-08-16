#include<iostream>
#include <string>

using namespace std;

class Videojuego
{
    private://para que npo me hackeen
    string personajes;
    string fuego; 
    string agua;
    //string nieve;
    int score;
    
    public:
    Videojuego(){};//constructor default
    Videojuego(string _personajes , string _fuego ,string _agua, int _score){
        personajes=_personajes;
        fuego=_fuego;
        agua=_agua;
        score=_score;
    }
    void puntos_juego(int score);
    void user_name(string personajes);
    void atacar(string fuego , string agua,int gota,int llama);
    void ganar(string agua);
    void perder(string fuego);
};

void Videojuego::puntos_juego(int score){
    cout<<"Tu puntaje es: " << this-> score << endl;
}

void Videojuego::user_name(string personajes){
    cout<< "El personaje elegido es:" << this->personajes << endl;
}

void Videojuego::atacar(string fuego , string agua,int gota,int llama){
    if (atacar)
        llama=1;
    else
        gota=2;
}

void Videojuego::ganar(string agua){
    this -> gota = agua;
    cout << agua << "Gnaste el juego" << endl;
}

void Videojuego::perder(string fuego){
    this -> llama = fuego;
    cout << fuego << "Perdiste el juego" << endl;
}

int main(){
    Videojuego * ronda1 = new Videojuego("Browser" , "fuego" , 0);
    Videojuego* ronda2= new Videojuego("Elsa" , "agua" , 0);

    delete ronda1;
    delete ronda2;

    return 0;
}
