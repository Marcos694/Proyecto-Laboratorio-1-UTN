#ifndef JUEGODOSPARTICIPANTES_H_INCLUDED
#define JUEGODOSPARTICIPANTES_H_INCLUDED

#include  "funciones.h"

void dosjugadores(char jugador1[],char jugador2[],int puntalt[]){
        system("cls");
        int i,t,objetivosjugador1[6],objetivosjugador2[6],dados[5],
        finronda1=1,finronda2=1,canttiradas1=0, canttiradas2=0,
        puntos1=0,puntos2=0,turno=0;
        ponercero(objetivosjugador1,6);
        ponercero(objetivosjugador2,6);
        ponercero(puntalt,4);
        objetivosjugador1[5]=5;
        objetivosjugador2[5]=5;

        for(i=1;i<=puntalt[4];i++){
             finronda1=1;
             finronda2=1;
            for(t=1;t<=3;t++){
                 ponercero(dados,6);
                 ponercero(dados,6);
                 //tirada jugador 1
                 if (finronda1==1){
                 titulofijo();
                 gotoxy(30,4);
                 cout <<"TURNO DE " << jugador1;
                 gotoxy(10,6);
                 cout<<"RONDA NUMERO  "<<i;
                 gotoxy(50,6);
                 cout<<"PUNTAJE ACUMULADO "<<puntos1;
                 gotoxy(10,8);
                 cout<<"TIRADA NUMERO "<<t;
                 cargaraleatorio(dados,objetivosjugador1[5],6);
                 gotoxy(50,8);
                 mostrarvector(dados,objetivosjugador1[5]);
                 puntosyobjetivos(objetivosjugador1,dados);
                 //mensajes de objetivos primer jugador
                 mensajeobjetivos(objetivosjugador1);
                 //contador tiradas
                 canttiradas1=canttiradas1+1;

                 system("pause>null");
                 system("cls");
                 //preguntar si quiere continuar
                 if ((objetivosjugador1[2]==1)&&(t!=3)){
                    finronda1=preguntarparcontinuar(objetivosjugador1);
                    finronda2=finronda1;
                 }
                 }
                 //cartel tirada fallida
                 if((t==3)&&(objetivosjugador1[3]==0)&&(finronda1==1)){
                    tiradafallida();
                 }



                // acumulacion de puntos dentro de tirada si no quiere continuar
                 if (finronda1 == 2 ){
                    puntos1 = objetivosjugador1[3];
                  }



                 //pantalla entre turnos
                 turno=1;
                 if((finronda2 == 1 )){
                 menuentreturnos(turno,jugador1,jugador2,i,canttiradas1,canttiradas2,puntos1,puntos2);
                 }

                 //tirada jugador 2
                 if (finronda2==1){
                 titulofijo();
                 gotoxy(30,4);
                 cout<<"TURNO DE "<<jugador2;
                 gotoxy(10,6);
                 cout<<"RONDA NUMERO  "<<i;
                 gotoxy(50,6);
                 cout<<"PUNTAJE ACUMULADO "<<puntos2;
                 gotoxy(10,8);
                 cout<<"TIRADA NUMERO "<<t;
                 cargaraleatorio(dados,objetivosjugador2[5],6);
                 gotoxy(50,8);
                 mostrarvector(dados, objetivosjugador2[5]);
                 puntosyobjetivos(objetivosjugador2,dados);
                  //mensajes de objetivos segundo jugador
                  mensajeobjetivos(objetivosjugador2);
                 //contador de tiradas
                 canttiradas2=canttiradas2+1;
                 system("pause>null");
                 system("cls");
                 //preguntar si quiere continuar
                 if ((objetivosjugador2[2] == 1) && (t!=3)){
                     finronda2=preguntarparcontinuar(objetivosjugador2);
                     finronda1=finronda2;
                 }
                 }


                 //cartel tirada fallida
                 if((t==3) && (objetivosjugador2[3]==0) && (finronda2==1)){
                    tiradafallida();
                 }

                 //pantalla entre turnos
                 turno=2;
                 if((!((puntalt[4]==i)&&(t==3))) && (finronda2 == 1 )){
                    menuentreturnos(turno,jugador1,jugador2,i,canttiradas1,canttiradas2,puntos1,puntos2);
                 }

                 }//cierre bucle tirada


             //contadores rondas ganadas
             if(objetivosjugador1[3]>objetivosjugador2[3]){
                   //carga de ronda ganada
                    puntalt[2]=puntalt[2]+1;
              }
              else if(objetivosjugador2[3]>objetivosjugador1[3]){
                  //carga de ronda ganada
                   puntalt[3]=puntalt[3]+1;
              }
             //objetivos pasados a 0 despues de cada ronda
             //se guardan puntos y se vuelve a 5 cantidad de dados
             puntos1=puntos1+objetivosjugador1[3];
             puntos2=puntos2+objetivosjugador2[3];
             ponercero(objetivosjugador1,6);
             ponercero(objetivosjugador2,6);
             objetivosjugador1[5]=5;
             objetivosjugador2[5]=5;
             }//cierre bucle ronda


            //pantalla fin de partida
            if(puntos1>puntos2){
                pantallafindepartida(jugador1,puntos1,canttiradas1);
            }
            else if(puntos2>puntos1){
                pantallafindepartida(jugador2,puntos2,canttiradas2);
            }
            else {
                pantallafinpartidaempate(jugador1,jugador2,canttiradas1,canttiradas2,puntos1,puntos2);
            }
        system("cls");
        //suma de puntos en vector final
        puntalt[0]=puntalt[0]+puntos1;
        puntalt[1]=puntalt[1]+puntos2;
}

void modosimulado(char jugador1[],char jugador2[],int puntalt[]){
        system("cls");
        int i,t,objetivosjugador1[6],objetivosjugador2[6],dados[5],
        finronda1=1,finronda2=1,canttiradas1=0, canttiradas2=0,
        puntos1=0,puntos2=0,turno=1;
        ponercero(objetivosjugador1,6);
        ponercero(objetivosjugador2,6);
        ponercero(puntalt,4);
        objetivosjugador1[5]=5;
        objetivosjugador2[5]=5;

        for(i=1;i<=puntalt[4];i++){
             finronda1=1;
             finronda2=1;
		for(t=1;t<=3;t++){
             ponercero(dados,6);
             ponercero(dados,6);
             //tirada jugador 1
             if (finronda1==1){
             titulofijo();
             gotoxy(30,4);
             cout <<"TURNO DE " << jugador1;
             gotoxy(10,6);
             cout<<"RONDA NUMERO  "<<i;
             gotoxy(50,6);
             cout<<"PUNTAJE ACUMULADO "<<puntos1;
             gotoxy(10,8);
             cout<<"TIRADA NUMERO "<<t;

             ingresodedados(dados,objetivosjugador1[5]);

             puntosyobjetivos(objetivosjugador1,dados);
             //mensajes de objetivos primer jugador
             mensajeobjetivos(objetivosjugador1);
             //contador tiradas
             canttiradas1=canttiradas1+1;
             system("pause>null");
             system("cls");
             //preguntar si quiere continuar
             if ((objetivosjugador1[2]==1)&&(t!=3)){
                finronda1=preguntarparcontinuar(objetivosjugador1);
                finronda2=finronda1;
             }
             }
             //cartel tirada fallida
             if((t==3) && (objetivosjugador1[3]==0) && (finronda2==1)){
                tiradafallida();
             }


             // acumulacion de puntos dentro de tirada si no quiere continuar
                 if (finronda1 == 2 ){
                    puntos1 = objetivosjugador1[3];
                  }


             //pantalla entre turnos
             turno=1;
             if((finronda2 == 1 )){
                 menuentreturnos(turno,jugador1,jugador2,i,canttiradas1,canttiradas2,puntos1,puntos2);
                 }
             //tirada jugador 2
             if (finronda2==1){
             titulofijo();
             gotoxy(30,4);
             cout<<"TURNO DE "<<jugador2;
             gotoxy(10,6);
             cout<<"RONDA NUMERO  "<<i;
             gotoxy(50,6);
             cout<<"PUNTAJE ACUMULADO "<<puntos2;
             gotoxy(10,8);
             cout<<"TIRADA NUMERO "<<t;

             ingresodedados(dados,objetivosjugador2[5]);

             puntosyobjetivos(objetivosjugador2,dados);
              //mensajes de objetivos segundo jugador
              mensajeobjetivos(objetivosjugador2);
             //contador de tiradas
             canttiradas2=canttiradas2+1;
             system("pause>null");
             system("cls");
             //preguntar si quiere continuar
             if (objetivosjugador2[2]==1&&t!=3){
                 finronda2=preguntarparcontinuar(objetivosjugador2);
                 finronda1=finronda2;
             }
             }
             //cartel tirada fallida
             if((t==3)&&(objetivosjugador2[3]==0)&&(finronda2==1)){
                tiradafallida();
             }

              //pantalla entre turnos
             turno=2;
            if((!((puntalt[4]==i)&&(t==3))) && (finronda2 == 1 )){
                    menuentreturnos(turno,jugador1,jugador2,i,canttiradas1,canttiradas2,puntos1,puntos2);
             }



             }//cierre bucle tirada


             //contadores rondas ganadas
             if(objetivosjugador1[3]>objetivosjugador2[3]){
                   //carga de ronda ganada
                    puntalt[2]=puntalt[2]+1;
              }
              else if(objetivosjugador2[3]>objetivosjugador1[3]){
                  //carga de ronda ganada
                   puntalt[3]=puntalt[3]+1;
              }
             //objetivos pasados a 0 despues de cada ronda
             //se guardan puntos y se vuelve a 5 cantidad de dados
             puntos1=puntos1+objetivosjugador1[3];
             puntos2=puntos2+objetivosjugador2[3];
             ponercero(objetivosjugador1,6);
             ponercero(objetivosjugador2,6);
             objetivosjugador1[5]=5;
             objetivosjugador2[5]=5;
              }

              //cierre bucle ronda


        //pantalla fin de partida
            if(puntos1>puntos2){
                pantallafindepartida(jugador1,puntos1,canttiradas1);
                //carga de ronda ganada
                puntalt[2]=puntalt[2]+1;
            }
            else if(puntos2>puntos1){
                pantallafindepartida(jugador2,puntos2,canttiradas2);
                //carga de ronda ganada
                puntalt[3]=puntalt[3]+1;
            }
            else {
                pantallafinpartidaempate(jugador1,jugador2,canttiradas1,canttiradas2,puntos1,puntos2);
            }
        system("cls");
        //suma de puntos en vector final
        puntalt[0]=puntalt[0]+puntos1;
        puntalt[1]=puntalt[1]+puntos2;
}


#endif // JUEGODOSPARTICIPANTES_H_INCLUDED
