#include <iostream>
#include <locale.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h> // aca esta system("cls"); para limpiar pantalla
#include "rlutil.h"
#include "funciones.h"


using namespace std;

int main()
{
    //COMIENZO DE MENU DE OPCIONES
    srand(time(NULL));
    //este Do-While General se repetira hasta que se ingresa la opcion 0,
    //rlutil:: hidecursor();
    int operacion = 1 ;
    char seguroSalir = 'Z';
    int flag = 0;
    const int LARGO = 30;
    const int VEC = 3;
    char nombreGanador[LARGO], nombreMaximoGanador[LARGO];
    int PDVGanador = 0, PDVMaximoGanador = 0;


    while(flag == 0) {

        //primeros nombres ingresados
        char nombre1[LARGO];
        char nombre2[LARGO];
        //despues de definir quien juega primero, contendran los nombres de los jugadores
        char jugador1[LARGO];
        char jugador2[LARGO];
        //variables Generales
        int con3Dados = 0, ronda; // si alguien cae en el barro o si ambos tienen mas de 50 trufas
        //variables Jugador 1
        int maxLanzamientoJ1 = 0, flagMaxLanzJ1 = 0;
        int trufasRtrufasGoinksJ1[VEC] = {}; // indice 0 : trufasRonda, indice 1: trufasGeneral, indice 2: oinks
        //variables jugador 2
        int maxLanzamientoJ2 = 0, flagMaxLanzJ2 = 0;
        int trufasRtrufasGoinksJ2[VEC] = {};// indice 0 : trufasRonda, indice 1: trufasGeneral, indice 2: oinks
        int maxTrufasPorLzGralJ1 = 0, maxTrufasPorLzGralJ2 = 0;

        operacion = mostrarMenu();

    //SWITCH DE SELECCION SEGUN EL MENU
        rlutil::cls();

        switch( operacion ){
           case 0:
                seguroSalir = 'Z';
                while( seguroSalir != 'N' && seguroSalir != 'S' ){
                        printf( "\nESTA SEGURO QUE DESEA SALIR??? (S/N) " );
                        cin >> seguroSalir;
                        cin.ignore();
                    }
                if ( seguroSalir == 'S' ){
                    flag = 1;
                    printf( "\nGRACIAS POR JUGAR GRAN CERDO!!!!" );
                    getchar();
                }else if( seguroSalir == 'N' ){
                    rlutil::cls();
                }
                break;
           case 1:
                //ACA SE DESARROLLA EL JUEGO
               //************************************************************************************************************************************//
                //PRIMERO LLAMAMOS A LA FUNCION QUE DETERMINA QUIEN COMIENZA TIRANDO
               //cin.ignore(); // HACER ESTO SIEMPRE DESPUES DE HACER UN CIN

               //SOLICITAR NOMBRES A LOS JUGADORES
               pedirNombres(nombre1,nombre2, LARGO);
               system("cls");
               //SE DEFINE QUIEN LANZARA PRIMERO EN LAS RONDAS
               seleccionPrimerJugador(nombre1 , nombre2, LARGO, jugador1, jugador2);
               //COMIENZO DE JUEGO
               for (int i = 0; i < 5 ; i ++) {
                    ronda = i+1;
                    //inicializo en cero las trufas de la ronda
                    trufasRtrufasGoinksJ1[0] = 0;
                    trufasRtrufasGoinksJ2[0] = 0;

                    //parametros jugador1- jugador2,
                    system("cls");
                    jugadaRondaJ1(jugador1,jugador2, trufasRtrufasGoinksJ1, trufasRtrufasGoinksJ2, maxLanzamientoJ1,flagMaxLanzJ1, maxLanzamientoJ2,flagMaxLanzJ2, con3Dados, ronda,maxTrufasPorLzGralJ1,maxTrufasPorLzGralJ2 );
                    jugadaRondaJ2(jugador1,jugador2, trufasRtrufasGoinksJ1, trufasRtrufasGoinksJ2, maxLanzamientoJ1,flagMaxLanzJ1, maxLanzamientoJ2,flagMaxLanzJ2, con3Dados, ronda,maxTrufasPorLzGralJ1,maxTrufasPorLzGralJ2 );
               }//fin FOR 5 rondas
               system("cls");
               calculoGanador(jugador1,jugador2, trufasRtrufasGoinksJ1, trufasRtrufasGoinksJ2, maxLanzamientoJ1,maxLanzamientoJ2, nombreGanador, PDVGanador, maxTrufasPorLzGralJ1, maxTrufasPorLzGralJ2);
               maximoGanador(nombreGanador, PDVGanador, nombreMaximoGanador, PDVMaximoGanador);
               //FIN DESARROLLO DEL JUEGO
               //************************************************************************************************************************************//
               break;
           case 2:
               rlutil::cls();
               lasReglas();
               rlutil::cls();
               break;
           case 3:
               rlutil::cls();
               lasEstadisticas(nombreMaximoGanador, PDVMaximoGanador );
               rlutil::cls();
               break;
           case 4:
               rlutil::cls();
               losCreditos();
               rlutil::cls();
               break;
        }//FIN DEL SWITCH DE OPCIONES DEL PROGRAMA
    }//FIN DEL WHILE DE TODO EL PROGRAMA
    return 0;
}
