#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <windows.h>
HANDLE wHnd;
using namespace std;
#include "funciones.h"
#include "juegodosparticipantes.h"


void menudosparticipantes(char jugador1[],char jugador2[],int puntalt[]);

int main(){


    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 100, 20};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);


    char jugador1[25],jugador2[25],opc;
    int puntalt[5];
    ponercero(puntalt,4);
    //Menu principal
    while(true){
        titulofijo();
        gotoxy(10,4);
        cout << "A - Juego Nuevo entre dos participantes";
        gotoxy(10,5);
        cout << "B - Mostrar Puntuacion mas alta";
        gotoxy(10, 6);
        cout << "C - Modo Simulado";
        gotoxy(10, 7);
        cout << "S - Salir";
        gotoxy(10, 9);
        cout << "Ingresar opcion: ";
        cin >> opc;
        switch(opc){
            case 'A':
            case 'a':
                menudosparticipantes(jugador1,jugador2,puntalt);
                dosjugadores(jugador1,jugador2,puntalt);
            break;
            case 'B':
            case 'b':
                puntuacionalta(jugador1,jugador2,puntalt);
            break;
            case 'C':
            case 'c':
                menudosparticipantes(jugador1,jugador2,puntalt);
                modosimulado(jugador1,jugador2,puntalt);
            break;
            case 'S':
            case 's':
                return 0;
            break;
            default:
                gotoxy(12, 15);
                cout << "Opcion de menu invalida";
                system("pause>null");
                system("cls");
            break;
        }
        }
        }
        //Menu de dos participantes
void menudosparticipantes(char jugador1[],char jugador2[],int puntalt[]){
        system("cls");
        titulofijo();
        //Ingreso de nombre primer participante
        gotoxy(10,4);
        cout << "Ingrese Nombre del Primer Jugador"<<endl;
        gotoxy(10,5);
        cargarcadena(jugador1,24);
        //Ingreso nombre segundo participante
        gotoxy(10,6);
        cout << "Ingrese Nombre del Segundo Jugador"<<endl;
        gotoxy(10,7);
        cargarcadena(jugador2,24);
        //Ingreso numero de rondas
        gotoxy(10,8);
        cout << "Ingrese Cantidada de rondas"<<endl;
        gotoxy(10,9);
        cin>>puntalt[4];
        system("cls");
        return;


        }

