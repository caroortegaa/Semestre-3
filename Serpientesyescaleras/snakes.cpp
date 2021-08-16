//carolina Ortega Barrios A01025254
#include"Tablero.h"
#include"Dice.h"
#include"Jugadores.h"
#include<stdlib.h>
#include<time.h>

using namespace std;



int main(){
    Tablero t;
    Dice d;
    Jugadores j1;
    Jugadores j2;

    int contador = 0;

    while (contador < 31)
    {
        cout << "Press C to continue next turn, or E to end the game : " ;
        char respuesta;
        cin >> respuesta;
        if (respuesta == 'E')
        {
            cout << "Thanks for playing!!" << endl;
            break;
        }

        else if (respuesta != 'C' )
        {
            cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
        }

        else
        {
            cout << "Es el turno del jugador 1 " << endl;
            int lanzar_numero = d.roll(6);
            cout << "Tiraste el número: " << lanzar_numero << endl;
            int casillap1 = j1.getposicion() + lanzar_numero;
            char tablero=t.getposicion(casillap1);
            if(tablero == 'S')
            {
                cout << "¡OOPS! Caíste en una casilla Serpiente , ahora tu posición es: " << casillap1 << endl;
                j1.setposicion(casillap1- 3);
            }
            else if(tablero == 'L')
            {
                cout << "Caíste en una casilla Escalera , ahora tu posición es: " << casillap1 << endl;
                j1.setposicion(casillap1+ 3);
            }
            else
            {
                cout << "Caíste en una casilla Normal , tu posición es: " << casillap1 << endl;
                j1.setposicion(casillap1);
            }

            if (casillap1>29)
            {
                cout << "---GAME OVER---";
                cout<< "PLAYER 1 IS THE WINNER!!!!";
                break;
            }
            


            cout << "Es el turno del jugador 2 " << endl;
            int lanzar_numero2 = d.roll(6);
            cout << "Tiraste el número: " << lanzar_numero2 << endl;
            int casillap2 = j2.getposicion() + lanzar_numero2;
            char tablero2 = t.getposicion(casillap2);
            if (tablero2 == 'S')
            {
                cout << "¡OOPS! Caíste en una casilla Serpiente , ahora tu posición es: " << casillap2 << endl;
                j2.setposicion(casillap2- 3);
            }
            else if(tablero2 == 'L')
            {
                cout << "Caíste en una casilla Escalera , ahora tu posición es: " << casillap2 << endl;
                j2.setposicion(casillap2- 3);
            }
            else
            {
                cout << "Caíste en una casilla Normal , tu posición es: " << casillap2 << endl;
                j2.setposicion(casillap2- 3);
            }

            if (casillap2>29)
            {
                cout << "---GAME OVER---";
                cout << "PLAYER 2 IS THE WINNER!!!!";
                break;
            }


        }

        contador++;
    }

}







