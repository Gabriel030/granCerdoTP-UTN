
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
#include "funciones.h" //definiciones de las funciones

using namespace std;


void pedirNombres(char n1[], char n2[], int L) {

    printf("\n\n\n\n\t\t\t\t\t Ingrese el nombre del Jugador 1:\n\t\t\t\t\t\t\t");
    cin.getline(n1 , L);
    printf("\n\n\n\n\t\t\t\t\t Ingrese el nombre del Jugador 2:\n\t\t\t\t\t\t\t");
    cin.getline(n2 , L);
    strupr(n1);
    strupr(n2);
}


//FUNCION SELECCION DEL JUGADOR QUE COMIENZA
void seleccionPrimerJugador (char n1[], char n2[], int L, char j1[], char j2[] ){

    int flagInicio = 0;
    int sumaPuntosN1 = 0, sumaPuntosN2 = 0, mayorDadoN1 = 0, mayorDadoN2 = 0;
    while(sumaPuntosN1 == sumaPuntosN2 && flagInicio == 0) {

        int dado1N1 = 0 , dado2N1 = 0, dado1N2 = 0,dado2N2 = 0;
        //PANTALLA PARA NOMBRE 1, O PRIMER LANZADOR
        printf("\t\t\t\t--------------------------------------------------------\n");
        printf("\t\t\t\t\t%s, presiona ENTER para lanzar\n",n1);
        printf("\t\t\t\t--------------------------------------------------------\n");

        getchar();
        dado1N1 = lanzarDado();
        mayorDadoN1 = dado1N1;
        dado2N1 = lanzarDado();
        if(dado2N1>mayorDadoN1) {
                mayorDadoN1 = dado2N1;
        }
        sumaPuntosN1 = dado1N1 + dado2N1;
        printf("\t\t\t\t\t\t+-------------------------+\n");
        printf("\t\t\t\t\t\t|   DADO: %2d              |\n", dado1N1);
        printf("\t\t\t\t\t\t|   DADO: %2d              |\n", dado2N1);
        printf("\t\t\t\t\t\t|   MAYOR DADO: %2d        |\n",mayorDadoN1);
        printf("\t\t\t\t\t\t|   PUNTOS TOTALES: %2d    |\n",sumaPuntosN1);
        printf("\t\t\t\t\t\t+-------------------------+");
        printf("\n");

        //PANTALLA PARA NOMBRE 2, O SEGUNDO LANZADOR
        printf("\t\t\t\t--------------------------------------------------------\n");
        printf("\t\t\t\t\t%s, presiona ENTER para lanzar\n",n2);
        printf("\t\t\t\t--------------------------------------------------------\n");
        getchar();
        dado1N2 = lanzarDado();
        mayorDadoN2 = dado1N2;
        dado2N2 = lanzarDado();
        if(dado2N2>mayorDadoN2) {
                mayorDadoN2 = dado2N2;
        }
        sumaPuntosN2 = dado1N2 + dado2N2;
        printf("\t\t\t\t\t\t+-------------------------+\n");
        printf("\t\t\t\t\t\t|   DADO: %2d              |\n", dado1N2);
        printf("\t\t\t\t\t\t|   DADO: %2d              |\n", dado2N2);
        printf("\t\t\t\t\t\t|   MAYOR DADO: %2d        |\n",mayorDadoN2);
        printf("\t\t\t\t\t\t|   PUNTOS TOTALES: %2d    |\n",sumaPuntosN2);
        printf("\t\t\t\t\t\t+-------------------------+");
        printf("\n");

        //CALCULANDO EL PRIMERO

        if(sumaPuntosN1 > sumaPuntosN2){
            //re asigno los nombres de los jugadores
            //sale del ciclo por q sumaPuntos son diferentes
            strcpy(j1,n1);
            strcpy(j2,n2);
            printf("\n\n\t\t\t\t\t\tINICIA  ** %s ** !!!", j1);
            printf("\n\n");
        }else if(sumaPuntosN2 > sumaPuntosN1){
                strcpy(j1,n2);
                strcpy(j2,n1);
                printf("\n\n\t\t\t\t\t\tINICIA  ** %s ** !!!", j1);
                printf("\n\n");
            }else if( mayorDadoN1 > mayorDadoN2){
                    //si cae aca, tiene igual puntaje, con la flag sale del while
                    flagInicio = 1;
                    strcpy(j1,n1);
                    strcpy(j2,n2);
                    printf("\n\n\t\t\t A igual puntaje, por mayor dado INICIA ** %s **", j1);
                    printf("\n\n");
                }else if( mayorDadoN2 > mayorDadoN1 ){
                    //si cae aca, tiene igual puntaje, con la flag sale del while
                        flagInicio = 1;
                        strcpy(j1,n2);
                        strcpy(j2,n1);
                        printf("\n\n\t\t\t A igual puntaje, por mayor dado INICIA ** %s **", j1);
                        printf("\n\n");
                    }


    }

    printf("\n\n\n\t\t\t\t\t\t ENTER para comenzar JUEGO:");
    getchar();
    rlutil::cls();


}

//FUNCION LANZAR DADO

int lanzarDado( void ){

    int dado = 1+ rand()% 6;

    return dado;


}


int mostrarMenu (void){

    int opcion = 1;
    int y = 0;
    int op;


    do {
        //rlutil::cls();

        rlutil::locate(30,9);
        cout << "----------------------------" << endl;
        rlutil::locate(30,10);
        cout << "         GRAN CERDO" << endl;
        rlutil::locate(30,11);
        cout << "----------------------------" << endl;
        rlutil::locate(30,12);
        cout << " - JUGAR" << endl;
        rlutil::locate(30,13);
        cout << " - REGLAS" << endl;
        rlutil::locate(30,14);
        cout << " - ESTADISTICAS" << endl;
        rlutil::locate(30,15);
        cout << " - CERDITOS" << endl;
        rlutil::locate(30,16);
        cout << " - SALIR" << endl;
        rlutil::locate(30,17);
        //cout << "---INGRESE LA OPCION--------" << endl;
        rlutil::locate(28, 12 + y);
        cout<<(char)175<<endl;


        //CONTROLADOR MOVIMIENTO DEL MENU

        switch( rlutil::getkey() ){
        case 14: //UP
                rlutil::locate( 28 , 12 + y);
                cout << " " << endl;
                y--;
                if( y < 0 ) {
                    y = 0;
                }
                break;
        case 15: //DOWN
                rlutil::locate( 28 , 12 + y);
                cout << " " << endl;
                y++;
                if(y > 4){
                    y = 4;
                }
                break;
        case 1: //ENTER
            //MANEJO DEL VALOR DE ENTER
            //FIN SWITCH MANEJO ENTER
                 if(y == 0){
                    opcion = 0;
                    op = 1;
                    return op;
                 }else if( y == 1){
                        opcion = 0;
                        op = 2;
                        return op;
                    }else if(y == 2){
                            opcion = 0;
                            op = 3;
                            return op;
                        }else if(y == 3){
                                opcion = 0;
                                op = 4;
                                return op;
                            }else if(y == 4){
                                    opcion = 0;
                                    op = 0;
                                    return op;
                                }

                 break;
        }//fin del switch




    }while(opcion != 0 );

    return op;


}


void jugadaRondaJ1(char j1[], char j2[], int trTgOiJ1[], int trTgOiJ2[], int &maxLanzJ1, int &flagLJ1, int &maxLanzJ2,  int &flagLj2, int &dadosX3, int RONDA, int &maxTrufasPorLzJ1, int &maxTrufasPorLzJ2 ){

        int  ceder = 0, barro = 0, ases = 0;
        int lanzamientos = 0;

        //valido antes de entrar a ceder para saber si sigue o no tirando
        while( ceder == 0 && barro == 0){

            int dado1 = 0, dado2 = 0, dado3 = 0 , sumaPuntos = 0;
            char continuar;
            int output = 0;
            //


            //INICIO VALIDACION CON 2 DADOS
            if (dadosX3 == 0) {

                dado1 = lanzarDado();
                dado2 = lanzarDado();

                 //aca muestro la pantalla con los datos
                printf("\n\t\t\t\t\t\t   GRAN CERDO\n");
                printf("-----------------------------------------------------------------------------------------------------------------------\n");

                printf(" %-s: %d Trufas Acumuladas  || %d OINKS %40s: %d Trufas Acumuladas  || %d OINKS\n", j1 ,trTgOiJ1[1],trTgOiJ1[2], j2,trTgOiJ2[1],trTgOiJ2[2]  );
                printf(" %-s %d %90s %d\n","Maximo Lanzamiento:", maxLanzJ1, "Maximo Lanzamiento: ",maxLanzJ2);
                //AGREGUEE UN INDICADOR DEL MAXIMO DE TRUFAS
                printf(" %-s %d %90s %d\n","Max Tr Lanzada:", maxTrufasPorLzJ1, "Max Tr Lanz: ",maxTrufasPorLzJ2);
                printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
                printf("\t\t\t\t\t\tTURNO DE %s\n", j1);

                printf("\t\t\t\t\t+------------------------------+\n");
                printf("\t\t\t\t\t|   RONDA: %2d                  |\n", RONDA);
                printf("\t\t\t\t\t|   TRUFAS DE LA RONDA: %2d     |\n",trTgOiJ1[0] );
                printf("\t\t\t\t\t|   LANZAMIENTOS: %2d           |\n",lanzamientos);
                printf("\t\t\t\t\t+------------------------------+");
                printf("\n");
                printf("\n\t\t\t\t\t\tLANZAMIENTOS #%d\n", lanzamientos);
                printf(" Presione ENTER para Lanzar\n\n");
                getchar();
                lanzamientos++;

                //son distintos entre si y distintos de 1 - ej: 5 y 3
                if ( dado1 != dado2  &&  dado1 != 1  &&  dado2 != 1 ) {
                        sumaPuntos = (dado1 + dado2);
                        trTgOiJ1[0] += sumaPuntos;                  // preguntar si seguir
                        output = 1;
                }else if ( dado1 == dado2 && dado1 != 1 && dado2 != 1    ){
                            sumaPuntos = (dado1 + dado2) * 2;
                            trTgOiJ1[0] += sumaPuntos;     // duplica puntos
                            trTgOiJ1[2] ++ ; //suma oink
                            output = 2;
                        }else if ( dado1 != dado2 &&(dado1 == 1 || dado2 == 1) ){
                                    trTgOiJ1[0] = 0;                    // pierde trufas ronda
                                    ceder = 1 ;                         // cae en el barro
                                    output = 3;
                                }else if( dado1 == 1 && dado2 == 1 ){
                                            ceder = 1;                  //cede el turno
                                            trTgOiJ1[1] = 0;            //pierde trufas Acumuladas
                                            trTgOiJ1[0] = 0;            //piede trufas ronda
                                            dadosX3 = 1 ;
                                            output = 4 ;
                                    }


                printf("\t\t\t\t\t  ***************************\n");
                printf("\t\t\t\t\t  *       DADO 1: %2d        *\n", dado1);
                printf("\t\t\t\t\t  *       DADO 2: %2d        *\n", dado2 );
                printf("\t\t\t\t\t  ***************************");
                switch(output){
                    case 1: printf("\n\t\t\t\t      MUY BIEN! SALIERON DADOS DISTINTOS!!");
                        break;
                    case 2: printf("\n\t\t\t\t MUY BIEN! SALIERON DADOS IGUALES, DUPLICAS PUNTOS!!");
                            printf("\n\t\t\t\t\t\t HICISTE 1 OINK !!");
                        break;
                    case 3: printf("\n\t\t\t\t Mala Suerte! Salio 1 AS, perdiste Trufas de la Ronda");
                        break;
                    case 4: printf("\n\t\t\t Mala Suerte! Salieron 2 AS, perdiste Trufas de la Ronda y acumuladas");
                        break;
                    default :
                        break;
                        }
                printf("\n\n\t\t\t\t\t\tSUMASTE %d PUNTOS !!\n", sumaPuntos);

                //VALIDACION PARA HITO MAXRRANO

                if(sumaPuntos > maxTrufasPorLzJ1 ){
                    maxTrufasPorLzJ1 = sumaPuntos;
                }

                //valido si tiene que continuar o no
                if(ceder == 0){

                    continuar = 'Z';
                    while(continuar != 'N' && continuar != 'S'){
                        printf("\n Desea seguir Lanzando? (S/N)");
                        cin>>continuar;
                        cin.ignore();
                    }

                    if(continuar == 'N') {
                        ceder = 1;
                    }
                }else if (ceder == 1){
                    printf("\n Presione ENTER para continuar");
                    getchar();
                }

            //FIN 2 DADOS
            } else if ( dadosX3 == 1){

            //COMIENZO 3 DADOS

                        dado1 = lanzarDado();
                        dado2 = lanzarDado();
                        dado3 = lanzarDado();

                         //aca muestro la pantalla con los datos
                        printf("\n\t\t\t\t\t\t   GRAN CERDO\n");
                        printf("-----------------------------------------------------------------------------------------------------------------------\n");

                        printf(" %-s: %d Trufas Acumuladas  || %d OINKS %35s: %d Trufas Acumuladas  || %d OINKS\n", j1 ,trTgOiJ1[1],trTgOiJ1[2], j2,trTgOiJ2[1],trTgOiJ2[2]  );
                        printf(" %-s %d %90s %d\n","Maximo Lanzamiento:", maxLanzJ1, "Maximo Lanzamiento: ",maxLanzJ2);
                        //AGREGUEE UN INDICADOR DEL MAXIMO DE TRUFAS
                        printf(" %-s %d %90s %d\n","Max Tr Lanzada:", maxTrufasPorLzJ1, "Max Tr Lanz: ",maxTrufasPorLzJ2);
                        printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
                        printf("\t\t\t\t\t\tTURNO DE %s\n", j1);

                        printf("\t\t\t\t\t+------------------------------+\n");
                        printf("\t\t\t\t\t|   RONDA: %2d                  |\n", RONDA);
                        printf("\t\t\t\t\t|   TRUFAS DE LA RONDA: %2d     |\n",trTgOiJ1[0] );
                        printf("\t\t\t\t\t|   LANZAMIENTOS: %2d           |\n",lanzamientos);
                        printf("\t\t\t\t\t+------------------------------+");
                        printf("\n");
                        printf("\n\t\t\t\t\tLANZAMIENTOS #%d\n", lanzamientos);
                        printf("\n Presione ENTER para Lanzar\n");
                        getchar();
                        lanzamientos++;

                        //son distintos entre si y distintos de 1 - ej: 5 y 3 y 6
                        if ( (dado1 != 1 && dado2 != 1 && dado3 != 1) && (((dado1 == dado2 && dado1 != dado3) || (dado1 == dado3 && dado1 != dado2 ) || (dado2 == dado3 && dado2 != dado1)) || (dado1!= dado2 && dado2 != dado3))) {
                                sumaPuntos = (dado1 + dado2 + dado3);
                                trTgOiJ1[0] += sumaPuntos;                  // preguntar si seguir
                                output = 1;

                              //Los 3 son iguales, pero distintos de 1
                        }else if ( (dado1 != 1 && dado2 != 1 && dado3 != 1) && (dado1 == dado2 && dado1 == dado3)    ){
                                    sumaPuntos = (dado1 + dado2 + dado3) * 2;
                                    trTgOiJ1[0] += sumaPuntos;     // duplica puntos
                                    trTgOiJ1[2] ++ ; //suma oink
                                    output = 2;
                                      //Hay un 1 en los 3 dados
                                }else if ( (dado1 != dado2 && dado2 != dado3) && (dado1 == 1 || dado2 == 1 || dado3 == 1) ){
                                            trTgOiJ1[0] = 0;                    // pierde trufas ronda
                                            ceder = 1 ;                         // cae en el barro
                                            output = 3;

                                              //hay 2 DADOS = 1
                                        }else if( (dado1 == 1 && dado2 == 1 && dado2 != dado3) || (dado1 == 1 && dado3 == 1 && dado2 != dado3) || (dado2 == 1 && dado3 == 1 && dado1 != dado2) ){
                                                    ceder = 1;                  //cede el turno
                                                    trTgOiJ1[1] = 0;            //pierde trufas Acumuladas
                                                    trTgOiJ1[0] = 0;            //piede trufas ronda
                                                    output = 4;

                                            }else if (dado1 == 1 && dado2 == 1 && dado3 == 1){
                                                        ceder = 1;                      //cae en el barro y cede
                                                        trTgOiJ2[1] += trTgOiJ1[1];     //le cede las trufas acumuladas al otro jugador
                                                        trTgOiJ2[0] += trTgOiJ1[0];      //le cede las trufas de la ronda al otro jugador
                                                        trTgOiJ1[1] = 0;                //pierde trufas acumuladas
                                                        trTgOiJ1[0] = 0;                //pierde trufas ronda
                                                        output = 5;

                                                    }

                        printf("\t\t\t\t\t  ***************************\n");
                        printf("\t\t\t\t\t  *       DADO 1: %2d        *\n", dado1);
                        printf("\t\t\t\t\t  *       DADO 2: %2d        *\n", dado2 );
                        printf("\t\t\t\t\t  *       DADO 3: %2d        *\n", dado3 );
                        printf("\t\t\t\t\t  ***************************");
                        switch(output){
                            case 1: printf("\n\t\t\t\t      MUY BIEN! SALIERON DADOS DISTINTOS DE AS!!");
                                break;
                            case 2: printf("\n\t\t\t\t MUY BIEN! SALIERON DADOS IGUALES, DUPLICAS PUNTOS!!");
                                    printf("\n\t\t\t\t\t\t HICISTE 1 OINK !!");
                                break;
                            case 3: printf("\n\t\t\t\t Mala Suerte! Salio 1 AS, perdiste Trufas de la Ronda");
                                break;
                            case 4: printf("\n\t\t\t\t Mala Suerte! Salieron 2 AS, perdiste Trufas de la Ronda");
                                break;
                            case 5: printf("\n\t\t\t\t Mala Suerte! Salieron 3 AS, le pasaste todas las trufas a %s ",j2);
                                break;
                            default :
                                break;
                        }
                        printf("\n\n\t\t\t\t\t\tSUMASTE %d PUNTOS !!\n", sumaPuntos);

                        //VALIDACION PARA HITO MAXRRANO

                        if(sumaPuntos > maxTrufasPorLzJ1 ){
                            maxTrufasPorLzJ1 = sumaPuntos;
                        }

                        //valido si tiene que continuar o no
                        if(ceder == 0){

                                continuar = 'Z';
                                while(continuar != 'N' && continuar != 'S'){

                                printf("\n Desea seguir Lanzando? (S/N)");
                                cin>>continuar;
                                cin.ignore();
                                }
                                if(continuar == 'N') {
                                    ceder = 1;
                                }
                        }else if (ceder == 1){
                            printf("\nPresione ENTER para continuar");
                            getchar();
                        }

            }//fin if 3 dados


            system("cls");
        } //fin while

        //sumo trufas de la Ronda a acumulados
        trTgOiJ1[1]+= trTgOiJ1[0];


        //valido si ambos tienen mas de 50 trufas, tiran con 3 dados
        if(trTgOiJ1[1] > 10 && trTgOiJ2[1] > 10 ) {
            dadosX3 = 1;
        }

        //valido si lanzamientos son mayores a su maximo
        if( flagLJ1 == 0) {
            flagLJ1 = 1;
            maxLanzJ1 = lanzamientos;
        }else if (lanzamientos > maxLanzJ1){
                    maxLanzJ1 = lanzamientos;
            }

//FIN FUNCION jugadaRonda
}





void jugadaRondaJ2(char j1[], char j2[], int trTgOiJ1[], int trTgOiJ2[], int &maxLanzJ1, int &flagLJ1, int &maxLanzJ2,  int &flagLJ2, int &dadosX3, int RONDA, int &maxTrufasPorLzJ1, int &maxTrufasPorLzJ2 ){

        int  ceder = 0, barro = 0, ases = 0;

        int lanzamientos = 0;



        //valido antes de entrar a ceder para saber si sigue o no tirando
        while( ceder == 0 && barro == 0){
            int dado1 = 0, dado2 = 0, dado3 = 0 , sumaPuntos = 0;
            char continuar;
            int output = 0;
           //INICIO VALIDACION CON 2 DADOS
            if (dadosX3 == 0) {

                dado1 = lanzarDado();
                dado2 = lanzarDado();

                 //aca muestro la pantalla con los datos
                printf("\n\t\t\t\t\t\t   GRAN CERDO\n");
                printf("-----------------------------------------------------------------------------------------------------------------------\n");

                printf(" %-s: %d Trufas Acumuladas  || %d OINKS %35s: %d Trufas Acumuladas  || %d OINKS\n", j1 ,trTgOiJ1[1],trTgOiJ1[2], j2,trTgOiJ2[1],trTgOiJ2[2]  );
                printf(" %-s %d %90s %d\n","Maximo Lanzamiento:", maxLanzJ1, "Maximo Lanzamiento: ",maxLanzJ2);

                //AGREGUEE UN INDICADOR DEL MAXIMO DE TRUFAS
                printf(" %-s %d %90s %d\n","Max Tr Lanzada:", maxTrufasPorLzJ1, "Max Tr Lanz: ",maxTrufasPorLzJ2);

                printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
                printf("\t\t\t\t\t\tTURNO DE %s\n", j2);

                printf("\t\t\t\t\t+------------------------------+\n");
                printf("\t\t\t\t\t|   RONDA: %2d                  |\n", RONDA);
                printf("\t\t\t\t\t|   TRUFAS DE LA RONDA: %2d     |\n",trTgOiJ2[0] );
                printf("\t\t\t\t\t|   LANZAMIENTOS: %2d           |\n",lanzamientos);
                printf("\t\t\t\t\t+------------------------------+");
                printf("\n");
                printf("\n\t\t\t\t\tLANZAMIENTOS #%d\n", lanzamientos);
                printf(" Presione ENTER para Lanzar\n\n");
                getchar();
                lanzamientos++;

                //son distintos entre si y distintos de 1 - ej: 5 y 3
                if ( dado1 != dado2  &&  dado1 != 1  &&  dado2 != 1 ) {
                        sumaPuntos = (dado1 + dado2);
                        trTgOiJ2[0] += sumaPuntos;                  // preguntar si seguir
                        output = 1;
                }else if ( dado1 == dado2 && dado1 != 1 && dado2 != 1    ){
                            sumaPuntos = (dado1 + dado2) * 2;
                            trTgOiJ2[0] += sumaPuntos;     // duplica puntos
                            trTgOiJ2[2] ++ ; //suma oink
                            output = 2;
                        }else if ( dado1 != dado2 &&(dado1 == 1 || dado2 == 1) ){
                                    trTgOiJ2[0] = 0;                    // pierde trufas ronda
                                    ceder = 1 ;                         // cae en el barro
                                    output = 3;
                                }else if( dado1 == 1 && dado2 == 1 ){
                                            ceder = 1;                  //cede el turno
                                            trTgOiJ2[1] = 0;            //pierde trufas Acumuladas
                                            trTgOiJ2[0] = 0;            //piede trufas ronda
                                            dadosX3 = 1 ;
                                            output = 4 ;
                                    }

                printf("\t\t\t\t\t  ***************************\n");
                printf("\t\t\t\t\t  *       DADO 1: %2d        *\n", dado1);
                printf("\t\t\t\t\t  *       DADO 2: %2d        *\n", dado2 );
                printf("\t\t\t\t\t  ***************************");
                switch(output){
                            case 1: printf("\n\t\t\t\t      MUY BIEN! SALIERON DADOS DISTINTOS DE AS!!");
                                break;
                            case 2: printf("\n\t\t\t\t MUY BIEN! SALIERON DADOS IGUALES, DUPLICAS PUNTOS!!");
                                    printf("\n\t\t\t\t\t\t HICISTE 1 OINK !!");
                                break;
                            case 3: printf("\n\t\t\t\t Mala Suerte! Salio 1 AS, perdiste Trufas de la Ronda");
                                break;
                            case 4: printf("\n\t\t\t Mala Suerte! Salieron 2 AS, perdiste Trufas de la Ronda y acumuladas");
                                break;
                            default :
                                break;
                        }
                printf("\n\n\t\t\t\t\t\tSUMASTE %d PUNTOS !!\n", sumaPuntos);
                //VALIDACION PARA HITO MAXRRANO

                        if(sumaPuntos > maxTrufasPorLzJ2 ){
                            maxTrufasPorLzJ2 = sumaPuntos;
                        }

                //valido si tiene que continuar o no
                if(ceder == 0){
                        continuar = 'Z';
                        while(continuar != 'N' && continuar != 'S'){

                            printf("\n Desea seguir Lanzando? (S/N)");
                            cin>>continuar;
                            cin.ignore();

                        }
                        if(continuar == 'N') {
                            ceder = 1;
                        }
                }else if (ceder == 1){
                    printf("\n Presione ENTER para continuar");
                    getchar();
                }

             //FIN 2 DADOS
            } else if ( dadosX3 == 1){


            //COMIENZO 3 DADOS

                        dado1 = lanzarDado();
                        dado2 = lanzarDado();
                        dado3 = lanzarDado();

                         //aca muestro la pantalla con los datos
                                         //aca muestro la pantalla con los datos
                        printf("\n\t\t\t\t\t\t   GRAN CERDO\n");
                        printf("-----------------------------------------------------------------------------------------------------------------------\n");

                        printf(" %-s: %d Trufas Acumuladas  || %d OINKS %35s: %d Trufas Acumuladas  || %d OINKS\n", j1 ,trTgOiJ1[1],trTgOiJ1[2], j2,trTgOiJ2[1],trTgOiJ2[2]  );
                        printf(" %-s %d %90s %d\n","Maximo Lanzamiento:", maxLanzJ1, "Maximo Lanzamiento: ",maxLanzJ2);

                        //AGREGUEE UN INDICADOR DEL MAXIMO DE TRUFAS
                        printf(" %-s %d %90s %d\n","Max Tr Lanzada:", maxTrufasPorLzJ1, "Max Tr Lanz: ",maxTrufasPorLzJ2);


                        printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
                        printf("\t\t\t\t\t\tTURNO DE %s\n", j2);

                        printf("\t\t\t\t\t+------------------------------+\n");
                        printf("\t\t\t\t\t|   RONDA: %2d                  |\n", RONDA);
                        printf("\t\t\t\t\t|   TRUFAS DE LA RONDA: %2d     |\n",trTgOiJ2[0] );
                        printf("\t\t\t\t\t|   LANZAMIENTOS: %2d           |\n",lanzamientos);
                        printf("\t\t\t\t\t+------------------------------+");
                        printf("\n");
                        printf("\n\t\t\t\t\tLANZAMIENTOS #%d\n", lanzamientos);
                        printf("\n Presione ENTER para Lanzar\n");
                        getchar();
                        lanzamientos++;

                        //son distintos entre si y distintos de 1 - ej: 5 y 3 y 6
                        if ( (dado1 != 1 && dado2 != 1 && dado3 != 1) && (((dado1 == dado2 && dado1 != dado3) || (dado1 == dado3 && dado1 != dado2 ) || (dado2 == dado3 && dado2 != dado1)) || (dado1!= dado2 && dado2 != dado3))) {
                                sumaPuntos = (dado1 + dado2 + dado3);
                                trTgOiJ2[0] += sumaPuntos;                  // preguntar si seguir
                                output = 1;

                              //Los 3 son iguales, pero distintos de 1
                        }else if ( (dado1 != 1 && dado2 != 1 && dado3 != 1) && (dado1 == dado2 && dado1 == dado3)    ){
                                    sumaPuntos = (dado1 + dado2 + dado3) * 2;
                                    trTgOiJ2[0] += sumaPuntos;     // duplica puntos
                                    trTgOiJ2[2] ++ ; //suma oink
                                    output = 2;
                                      //Hay un 1 en los 3 dados
                                }else if ( (dado1 != dado2 && dado2 != dado3) && (dado1 == 1 || dado2 == 1 || dado3 == 1) ){
                                            trTgOiJ2[0] = 0;                    // pierde trufas ronda
                                            ceder = 1 ;                         // cae en el barro
                                            output = 3;

                                              //hay 2 DADOS = 1
                                        }else if( (dado1 == 1 && dado2 == 1 && dado2 != dado3) || (dado1 == 1 && dado3 == 1 && dado2 != dado3) || (dado2 == 1 && dado3 == 1 && dado1 != dado2) ){
                                                    ceder = 1;                  //cede el turno
                                                    trTgOiJ2[1] = 0;            //pierde trufas Acumuladas
                                                    trTgOiJ2[0] = 0;            //piede trufas ronda
                                                    output = 4;

                                            }else if (dado1 == 1 && dado2 == 1 && dado3 == 1){
                                                        ceder = 1;                      //cae en el barro y cede
                                                        trTgOiJ1[1] += trTgOiJ2[1];     //le cede las trufas acumuladas al otro jugador
                                                        trTgOiJ1[0] += trTgOiJ2[0];      //le cede las trufas de la ronda al otro jugador
                                                        trTgOiJ2[1] = 0;                //pierde trufas acumuladas
                                                        trTgOiJ2[0] = 0;                //pierde trufas ronda
                                                        output = 5;

                                                    }

                        printf("\t\t\t\t\t  ***************************\n");
                        printf("\t\t\t\t\t  *       DADO 1: %2d        *\n", dado1);
                        printf("\t\t\t\t\t  *       DADO 2: %2d        *\n", dado2 );
                        printf("\t\t\t\t\t  *       DADO 3: %2d        *\n", dado3 );
                        printf("\t\t\t\t\t  ***************************");
                        switch(output){
                            case 1: printf("\n\t\t\t\t      MUY BIEN! SALIERON DADOS DISTINTOS!!");
                                break;
                            case 2: printf("\n\t\t\t\t MUY BIEN! SALIERON DADOS IGUALES, DUPLICAS PUNTOS!!");
                                    printf("\n\t\t\t\t\t\t HICISTE 1 OINK !!");
                                break;
                            case 3: printf("\n\t\t\t\t Mala Suerte! Salio 1 AS, perdiste Trufas de la Ronda");
                                break;
                            case 4: printf("\n\t\t\t\t Mala Suerte! Salieron 2 AS, perdiste Trufas de la Ronda");
                                break;
                            case 5: printf("\n\t\t\t\t Mala Suerte! Salieron 3 AS, le pasaste todas las trufas a %s ",j1);
                                break;
                            default :
                                break;
                        }
                        printf("\n\n\t\t\t\t\t\tSUMASTE %d PUNTOS !!\n", sumaPuntos);


                        //VALIDACION PARA HITO MAXRRANO

                        if(sumaPuntos > maxTrufasPorLzJ2 ){
                            maxTrufasPorLzJ2 = sumaPuntos;
                        }


                        //valido si tiene que continuar o no
                        if(ceder == 0){
                            continuar = 'Z';
                            while(continuar != 'N' && continuar != 'S'){

                                printf("\n Desea seguir Lanzando? (S/N)");
                                cin>>continuar;
                                cin.ignore();

                            }
                            if(continuar == 'N') {
                                ceder = 1;
                            }
                        }else if (ceder == 1){
                            printf("\n Presione ENTER para continuar");
                            getchar();
                        }


            }//fin if 3 dados


            system("cls");
        } //fin while

        //sumo trufas de la Ronda a acumulados
        trTgOiJ2[1]+= trTgOiJ2[0];


        //valido si ambos tienen mas de 50 trufas, tiran con 3 dados
        if(trTgOiJ1[1] > 10 && trTgOiJ2[1] > 10 ) {
            dadosX3 = 1;
        }

        //valido si lanzamientos son mayores a su maximo
        if( flagLJ2 == 0) {
            flagLJ2 = 1;
            maxLanzJ2 = lanzamientos;
        }else if (lanzamientos > maxLanzJ2){
                    maxLanzJ2 = lanzamientos;
            }

//FIN FUNCION jugadaRonda
}




void calculoGanador(char j1[], char j2[], int trTgOiJ1[], int trTgOiJ2[], int &maxLanzJ1, int &maxLanzJ2, char nomGan[], int &PDVGan , int &maxTrufasPorLzGralJ1, int &maxTrufasPorLzGralJ2){

        char maxTrufas[] = "Mas trufas en total";
        char cada50Trufas[] = "Cada 50 Trufas";
        char oinks[] = "oinks";
        char cerdoCodicioso[] = "Cerdo Codicioso";
        char maxrrano[] = "Maxrrano";
        int PDVmaxTrufasJ1 = 0, PDVmaxTrufasJ2 = 0;

        //calculo maximas trufas
        if(trTgOiJ1[1] > trTgOiJ2[1]){
            PDVmaxTrufasJ1 = 5;
            PDVmaxTrufasJ2 = 0;
        }else if (trTgOiJ1[1] < trTgOiJ2[1]){
                  PDVmaxTrufasJ1 = 0;
                  PDVmaxTrufasJ2 = 5;
            }else if( trTgOiJ1[1] == trTgOiJ2[1]){
                        PDVmaxTrufasJ1 = 5;
                        PDVmaxTrufasJ2 = 5;
                }

        //calculo cada 50 trufas
        int PDVcada50J1 = (int)trTgOiJ1[1]/50;
        int total50J1 = PDVcada50J1 *50;
        int PDVcada50J2 = (int)trTgOiJ2[1]/50;
        int total50J2 = PDVcada50J2 *50;


        //calculo Oinks

        int PDVoinksJ1 = trTgOiJ1[2] * 2;//multiplico oinks x2
        int PDVoinksJ2 = trTgOiJ2[2] * 2;//multiplico oinks x2


        //caclulo cerdo codicioso
        int PDVcerdoCodiciosoJ1 = 0;
        int PDVcerdoCodiciosoJ2 = 0;

        if(maxLanzJ1 > maxLanzJ2){
            PDVcerdoCodiciosoJ1 = 2;
            PDVcerdoCodiciosoJ2 = 0;
        }else if(maxLanzJ1 < maxLanzJ2){
                    PDVcerdoCodiciosoJ1 = 0;
                    PDVcerdoCodiciosoJ2 = 2;
            }else if (maxLanzJ1 == maxLanzJ2){
                        PDVcerdoCodiciosoJ1 = 2;
                        PDVcerdoCodiciosoJ2 = 2;

                }

        int PDVmaxrranoJ1 = 0;
        int PDVmaxrranoJ2 = 0;


        int sumaPDVJ1 = PDVmaxTrufasJ1 + PDVcada50J1 + PDVoinksJ1 + PDVcerdoCodiciosoJ1 + PDVmaxrranoJ1;
        int sumaPDVJ2 = PDVmaxTrufasJ2 + PDVcada50J2 + PDVoinksJ2 + PDVcerdoCodiciosoJ2 + PDVmaxrranoJ2;

         // CALCULO MAXRRANO
        int flagMaxrrano = 0;


            if (maxTrufasPorLzGralJ1 > maxTrufasPorLzGralJ2 ) {
                PDVmaxrranoJ1 = 1;
                flagMaxrrano = 1;
                sumaPDVJ2 = sumaPDVJ2 -1;
            }else if(maxTrufasPorLzGralJ1 < maxTrufasPorLzGralJ2) {
                        PDVmaxrranoJ2 = 1;
                        flagMaxrrano = 1;
                        sumaPDVJ1 = sumaPDVJ1 -1;
                }


        printf("\n\t\t\t\t\t\t   GRAN CERDO\n");
        printf("-----------------------------------------------------------------------------------------------------------------------\n\n\n");

        printf("%-36s %-36s%-36s", "HITO", j1, j2);
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("%-36s %-d PDV (%d trufas) %-17s %-d PDV (%d trufas)\n",maxTrufas, PDVmaxTrufasJ1, trTgOiJ1[1]," ", PDVmaxTrufasJ2, trTgOiJ2[1]);
        printf("%-36s %-d PDV (%d trufas)  %-17s %-d PDV (%d trufas)\n",cada50Trufas, PDVcada50J1, total50J1," ", PDVcada50J2, total50J2);
        printf("%-36s %-d PDV (%d oinks)   %-17s %-d PDV (%d oinks)\n",oinks, PDVoinksJ1, trTgOiJ1[2]," ", PDVoinksJ2, trTgOiJ2[2]);
        printf("%-36s %-d PDV (%d lanzam)  %-17s %-d PDV (%d lanzam)\n",cerdoCodicioso, PDVcerdoCodiciosoJ1, maxLanzJ1, " ",PDVcerdoCodiciosoJ2, maxLanzJ2);
        printf("%-36s %-d PDV (%d Tr Lanz)  %-17s %-d PDV (%d Tr Lanz)\n",maxrrano, PDVmaxrranoJ1, maxTrufasPorLzGralJ1, " ",PDVmaxrranoJ2, maxTrufasPorLzGralJ2);
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("%-36s %-d PDV %32d PDV", "TOTAL",sumaPDVJ1, sumaPDVJ2);

        if( flagMaxrrano == 1) {
            printf("\n Se desconto  1 PDV\n");
        }

        if(sumaPDVJ1 > sumaPDVJ2){
            printf("\n\nGANADOR: %s con %d puntos de Victoria", j1, sumaPDVJ1);
            strcpy(nomGan, j1);
            PDVGan = sumaPDVJ1;
        }else if(sumaPDVJ1 < sumaPDVJ2){
                    printf("\n\nGANADOR: %s con %d puntos de Victoria", j2, sumaPDVJ2);
                    strcpy(nomGan, j2);
                    PDVGan = sumaPDVJ2;
                }else if( sumaPDVJ1 == sumaPDVJ2) {
                            printf("\n\nES UN EMPATE");

                    }

        printf("\n Presione ENTER para continuar");
        getchar();
        system("cls");


}

void maximoGanador( char nomGan[], int &PDVGan, char nomMAXGan[], int &PDVMAXGan){

    if(PDVGan > PDVMAXGan) {
        PDVMAXGan = PDVGan;
        strcpy(nomMAXGan, nomGan);
    }


}


void lasEstadisticas(char nomMAXGan[], int PDVMAXGan ) {

     printf("\n\t\t\t\t\t\t   ESTADISTICAS\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n\n\n");

     printf("\t\t\t\t%-40s %-40s\n", "NOMBRE", "MAXIMO PDV");
     printf("\t\t\t\t----------------------------------------------------\n");
     printf("\t\t\t\t%-40s  %-40d", nomMAXGan, PDVMAXGan);

     printf("\n\n\nPresione ENTER para Volver al MENU");
              getchar();


}


void losCreditos(void){

     char nombreEquipo[] = "The Code Of War";

     char nombreA[] = "Marcos";
     char apellidoA[] = "Matesa";
     int legajoA = 26288;

     char nombreB[] = "Sebastian";
     char apellidoB[] = "Carracedo";
     int legajoB = 25843;

     char nombreC[] = "Gabriela";
     char apellidoC[] = "Lavia";
     int legajoC = 27260;

     char nombreD[] = "Gabriel";
     char apellidoD[] = "Antonietti";
     int legajoD = 25713;

     printf("\n\t\t\t\t\t\t   CREDITOS\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n\n\n");
     printf("\t\t%-36s %-36s %-36s\n", "NOMBRE", "APELLIDO", "LEGAJO");
     printf("\t\t--------------------------------------------------------------------------------\n");
     printf("\t\t%-36s %-36s %-d\n",nombreA,apellidoA,legajoA);
     printf("\t\t%-36s %-36s %-d\n",nombreB,apellidoB,legajoB);
     printf("\t\t%-36s %-36s %-d\n",nombreC,apellidoC,legajoC);
     printf("\t\t%-36s %-36s %-d\n",nombreD,apellidoD,legajoD);
     printf("\n\n\n\nCREADOR DEL JUEGO: Simon Angel");
     printf("\n\n\n\nLIBRERIA EXTERNA RLUTIL: https://github.com/tapio/rlutil");

     printf("\n\n\n Presione ENTER para Volver al MENU");
     getchar();

}


void lasReglas(void) {
     printf("\n\t\t\t\t\t\t   REGLAS\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n\n\n");

     printf(" -El Juego esta compuesto por 5 Rondas\n");
     printf(" -En Cada Ronda cada Jugador podrá lanzar los dados ilimitada cantidad de veces, si cumple ciertas condiciones\n");
     printf(" -Se le consultara al Jugador, segun corresponda, si desea continuar lanzado o si desea detenerse\n");
     printf(" -Si los dados son todos 1, se cae en el barro y se pierden las Trufas acumuladas y las Trufas de la Ronda Actual\n");
     printf(" -Si los dados son todos distintos de 1, se suman trufas por la suma de los dados\n");
     printf(" -Si los dados son todos iguales y distintos de 1, se suman trufas por el doble de la suma de los dados y hace un OINK\n");
     printf(" -Existen diferentes HITOS que dan a los Jugadores, PUNTOS DE VICTORIA (PDV)\n");
     printf(" -Gana quien obtenga mas Puntos de Victoria\n");
     printf("\t\t Mas trufas en total   |   5 PDV\n");
     printf("\t\t Cada 50 trufas        |   1 PDV\n");
     printf("\t\t Oink                  |   2 PDV * Cantidad de Oinks\n");
     printf("\t\t Cerdo Codicioso       |   3 PDV (ronda con mayor cantidad de lanzamientos\n");


     printf("\n\n\n Presione ENTER para Volver al MENU");
     getchar();

}
