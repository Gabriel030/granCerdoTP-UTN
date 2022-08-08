#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void seleccionPrimerJugador (char n1[], char n2[], int L, char j1[], char j2[] );
int lanzarDado(void);
void pedirNombres(char n1[], char n2[], int);
int mostrarMenu(void);
void jugadaRondaJ1(char j1[], char j2[], int trTgOiJ1[], int trTgOiJ2[], int &maxLanzJ1, int &flagLJ1, int &maxLanzJ2,  int &flagLJ2, int &dadosX3, int ronda, int &maxTrufasPorLzJ1, int &maxTrufasPorLzJ2 );
void jugadaRondaJ2(char j1[], char j2[], int trTgOiJ1[], int trTgOiJ2[], int &maxLanzJ1, int &flagLJ1, int &maxLanzJ2,  int &flagLJ2, int &dadosX3, int ronda, int &maxTrufasPorLzJ1, int &maxTrufasPorLzJ2 );
void calculoGanador(char j1[], char j2[], int trTgOiJ1[], int trTgOiJ2[], int &maxLanzJ1, int &maxLanzJ2, char nomGan[], int &PDVGan, int &maxTrufasPorLzGralJ1, int &maxTrufasPorLzGralJ2 );
void lasEstadisticas(char nomMAXGan[], int PDVMAXGan );
void maximoGanador( char nomGan[], int &PDVGan, char nomMAXGan[], int &PDVMAXGan);
void losCreditos(void);
void lasReglas(void);


#endif // FUNCIONES_H_INCLUDED



