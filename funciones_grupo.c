/*
    Integrantes del grupo. En caso de ser un grupo de dos integrantes, no completar el último campo.
    Si alguno de los integrantes del grupo dejara la materia, completar de todos modos sus datos, aclarando que no entrega.
    -----------------
    Apellido:
    Nombre:
    DNI:
    Entrega:
    -----------------
    Apellido:
    Nombre:
    DNI:
    Entrega:
    -----------------
    Apellido:
    Nombre:
    DNI:
    Entrega:
    -----------------
	Apellido:
    Nombre:
    DNI:
    Entrega:
    -----------------
*/

#include "funciones_grupo.h"


int solucion(int argc, char* argv[])
{
    ///DECLARACIONES Y PREARREGLOS

    int ubicacion_nombre_archivo1 = 0, ubicacion_nombre_archivo2 = 0;
    int error;

    // compruebo que se haya pasado el nombre del archivo
    error = buscar_nombre_archivo(argc, argv, &ubicacion_nombre_archivo1, &ubicacion_nombre_archivo2);
    if (error == E_APERTURA)
    {
        printf("\nError: No se adjunto ningun archivo .bmp.");
        return E_APERTURA;
    }
    if (ubicacion_nombre_archivo2 == 0)
        printf("\nAdvertencia: Solo se detecto un archivo BMP, no se haran concatenaciones.\n");
    if (error == E_PARAMETRO)
        printf("\nAdvertencia: Se adjuntaron mas de dos archivos bmp. Solo se usaran los dos primeros.");


    printf("\n%s\n", argv[ubicacion_nombre_archivo1]); /// DE TESTEO  - BORRAR ///

    return TODO_OK;
}



int buscar_nombre_archivo(int argc, char* argv[], int* ubic1, int* ubic2)
{
    ///DECLARACIONES
    //Se declara una variable contador para contar nombres de archivo.
    int contNombreArch = 0;
    //Se declara una variable para la longitud del parametro.
    int longitud;

    ///CUERPO DEL ALGORITMO
    for (int i = 1; i < argc; i++)
    {
        longitud = strlen(argv[i]);
        if (longitud >= 4 && strcmp(argv[i] + longitud - 4, ".bmp") == 0)
        {
            if (contNombreArch == 0)
                *ubic1 = i;
            else if (contNombreArch == 1)
                *ubic2 = i;
            contNombreArch++;
        }
    }

    ///CIERRE DEL ALGORITMO
    //Si no se cont� ning�n archivo '.bmp'
    if (contNombreArch == 0)
    {
        //Devuelve ERROR
        printf("%s", MENSAJE_APERTURA);
        return E_APERTURA;
    }

    //Si se cont� m�s de dos archivos '.bmp'
    else if (contNombreArch > 2)
    {
        //Devuelve ERROR
        printf("%s", MENSAJE_PARAMETRO);
        return E_PARAMETRO;
    }


    //Si no ocurrio ninguna excepcion
    else
        //El programa cierra correctamente
        return TODO_OK;
}
