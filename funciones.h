#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <windows.h>

void gotoxy(short x, short y){

    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void titulofijo(){

        gotoxy(30,0);
        cout << "--------------------------------"<<endl;
        gotoxy(30,1);
        cout << "JUEGO BARCO CAPITAN TRIPULACION ";
        gotoxy(30,2);
        cout << "--------------------------------"<<endl;
}

void mostrarVector(char v[], int tam){
int i;
for(i=0;i<tam;i++){
cout<<v[i]<<"\t";
}
}

void ponercero(int v[], int tam){
int i;
for(i=0;i<(tam-1);i++){
v[i]=0;
}
}

void cargaraleatorio(int v[], int tam, int limite){
int i;
srand(time(NULL));
for( i=0; i<tam; i++ ){
v[i]=(rand()%limite)+1;
}
}

void mostrarvector(int v[], int tam){
int i;
for(i=0;i<tam;i++){
cout<<v[i]<<"\t";
}
}

int preguntarparcontinuar(int objetivosjugador[]){
     char opc;
     do {
     system("cls");
     titulofijo();
     cout<<"Seleccione si quiere continuar con el juego"<<endl;
     cout<<"Presione s para continuar"<<endl;
     cout<<"Presione n para dejar de tirar"<<endl;
     cin>>opc;
     switch(opc){
            case 'S':
            case 's':
            objetivosjugador[3]=0;
            system("cls");
            return 1;
            break;
            case 'N':
            case 'n':
            system("cls");
            return 2;
            break;
            default:
            gotoxy(12, 15);
            cout << "Opcion de menu invalida";
            system("pause>null");
            break;
        }
        }
    while(opc!='S'||opc!='s'||opc!='N'||opc!='n');
return 0;
}

void menuentreturnos(int numjugador,char jugador1[],char jugador2[],int ronda,
                     int canttiradas1,int canttiradas2,int puntos1,int puntos2){
    if(numjugador==1){
        titulofijo();
        gotoxy(40,6);
        cout<<"Proximo Jugador: "<<jugador2<<endl;
        gotoxy(42,8);
        cout<<"Puntaje "<<puntos2<<endl;
        gotoxy(40,10);
        cout<<"Ronda numero "<<ronda<<endl;
        gotoxy(39,12);
        cout<<"Tiradas totales "<<canttiradas2<<endl;
    }
    else{
        titulofijo();
        gotoxy(40,6);
        cout<<"Proximo Jugador: "<<jugador1<<endl;
        gotoxy(42,8);
        cout<<"Puntaje "<<puntos1<<endl;
        gotoxy(40,10);
        cout<<"Ronda numero "<<ronda<<endl;
        gotoxy(39,12);
        cout<<"Tiradas totales "<<canttiradas1<<endl;
    }
    system("pause");
    system("cls");
    }

void pantallafindepartida(char jugador[], int puntaje, int canttiradas){
        titulofijo();
        cout<<"el jugador ganador es "<<jugador<<endl;
        cout<<"el puntaje es :"<<puntaje<<endl;
        cout<<"la cantidad de tiradas es: "<<canttiradas<<endl;
        system("pause>null");
        system("cls");
}

void pantallafinpartidaempate(char jugador1[],char jugador2[],int canttiradas1,int canttiradas2,int puntos1,int puntos2){
        titulofijo();
        if(puntos1==0&&puntos2==0){
        cout<<"Los jugadores no consiguieron puntos"<<endl;
        }else if(canttiradas1>canttiradas2){
        cout<<"el jugador ganador es "<<jugador1<<endl;
        cout<<"el puntaje es :"<<puntos1<<endl;
        cout<<"la cantidad de tiradas es: "<<canttiradas1<<endl;
        }else if(canttiradas2>canttiradas1){
        cout<<"el jugador ganador es "<<jugador2<<endl;
        cout<<"el puntaje es :"<<puntos2<<endl;
        cout<<"la cantidad de tiradas es: "<<canttiradas2<<endl;
        }else{
        cout<<"Los Jugadores Empataron"<<endl;
                }
}

void puntosyobjetivos(int objetivos[],int dados[]){
    int i;
    //bucle busqueda de barco
    for (i=0;i<=5;i++){
        if (dados[i]==6&&objetivos[0]==0){
            dados[i]=0;
            objetivos[0]=1;
            objetivos[5]=4;
    }
    }
    //buscar capitan
    for (i=0;i<=5;i++){
        if (dados[i]==5&&objetivos[1]==0&&objetivos[0]==1){
            objetivos[1]=1;
            dados[i]=0;
            objetivos[5]=3;
    }
    }
    //buscar tripulacion
    for (i=0;i<=5;i++){
        if (dados[i]==4&&objetivos[2]==0&&objetivos[1]==1&&objetivos[0]==1){
            objetivos[2]=1;
            dados[i]=0;
            objetivos[5]=2;
    }
    }
    //sumar carga
    for (i=0;i<=5;i++)
    {
        if (objetivos[0]==1&&objetivos[1]==1&&objetivos[2]==1){
            objetivos[3]=objetivos[3]+dados[i];
    }
    }
    }

void tiradafallida(){
    titulofijo();
    gotoxy(30,10);
    cout<<"NO SE ACUMULARON PUNTOS EN ESTA TIRADA";
    system("pause>null");
    system("cls");
}

void puntuacionalta(char jugador1[],char jugador2[],int puntalt[]){
        system("cls");
        titulofijo();
    if(puntalt[0]>puntalt[1]){
        gotoxy(30,5);
        cout<<"El Jugador ganador es: "<<jugador1<<endl;
        gotoxy(30,6);
        cout<<"Cantidad de puntos: "<<puntalt[2]<<endl;
    }else if(puntalt[1]>puntalt[0]){
        gotoxy(30,5);
        cout<<"El Jugador ganador es: "<<jugador2<<endl;
        gotoxy(30,6);
        cout<<"Cantidad de puntos: "<<puntalt[3]<<endl;
    }else {
        gotoxy(30,5);
        cout<<"Empataron"<<endl;
    }
        system("pause>null");
        system("cls");
    }

void ingresodedados(int dados[],int cantdados){
        int i;

        gotoxy(50,8);
        cout<<"Ingrese Numero de dado: ";

        for (i=0;i<cantdados;i++){
            bool compro=true;
            while(compro==true){
            gotoxy(50,9+i);
            cin>>dados[i];
            if(dados[i]>0&&dados[i]<7){
                compro=false;
            }else{
                gotoxy(53,9+i);
                cout<<"Ingreso Incorecto Intente Nuevamente"<<endl;
                system("pause>null");
                gotoxy(50,9+i);
                cout<<"                                        "<<endl;
            }
            }
    }
    }

void cargarcadena(char palabra[],int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        palabra[i]=cin.get();
        if(palabra[i]=='\n')break;
    }
    palabra[i]='\0';
    fflush(stdin);
}

void mensajeobjetivos(int objetivosjugador[]){
        if(objetivosjugador[0]==1){
               gotoxy(10,10);
               cout<<"BARCO ENCONTRADO";
            }
        if(objetivosjugador[1]==1){
               gotoxy(10,11);
               cout<<"CAPITAN ENCONTRADO";
           }
        if(objetivosjugador[2]==1){
               gotoxy(10,12);
               cout<<"TRIPULACION ENCONTRADA";
           }
        if(objetivosjugador[3]!=0){
               gotoxy(10,13);
               cout<<"CANTIDAD DE CARGA "<<objetivosjugador[3];
           }
}

#endif // FUNgotoxy(10,15);CIONES_H_INCLUDED
