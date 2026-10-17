#ifndef FUNCIONES_GRUPO_H_INCLUDED
#define FUNCIONES_GRUPO_H_INCLUDED

///BIBLIOTECAS Y FUENTES REFERENCIADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

///CODIGOS DE ERROR
#define TODO_OK 0
#define E_APERTURA 1
#define E_LECTURA 2
#define E_MEMORIA 3
#define E_PORCENTAJE 4
#define E_PARAMETRO 5

///MENSAJES DE ERROR
#define MENSAJE_APERTURA    "Error en la apertura del archivo.\n"
#define MENSAJE_LECTURA     "Error en la lectura del archivo.\n"
#define MENSAJE_MEMORIA     "Error en la reserva de memoria.\n"
#define MENSAJE_PORCENTAJE  "Error en el factor del par�metro.\n"
#define MENSAJE_PARAMETRO   "Error. El par�metro ingresado es desconocido, o no cumple con los requisitos.\n"


int solucion(int argc, char* argv[]);


///FUNCIONES DE SOPORTE
//FUNCIONES GEN�RICAS
void** matrizCrear              (int x, int y, size_t tamElem);
void matrizDestruir             (void** mat, int x);


//FUNCIONES ESPECIFICAS
int buscar_nombre_archivo(int argc, char* argv[], int* ubic1, int* ubic2);


#endif // FUNCIONES_GRUPO_H_INCLUDED
