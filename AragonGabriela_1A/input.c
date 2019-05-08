#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
#include "informes.h"
#include "input.h"

/**
 * \brief Verifica si el valor recibido es numérico
 * \param texto Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char texto[])
{
    int i=0;
    while(texto[i] != '\0')
    {
        if(texto[i] < '0' || texto[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


/** \brief Valida que el caracter recibido este entre los valores xx y xx de la tabla ASCII
y de no ser asi se le pide al usuario que reingrese una opcion valida
 * \param opcion Caracter a ser evaluado
 * \return opcion Caracter que esta entre los parametros pedidos
 */
char validarMenu (char opcion)
{
    while ((int)opcion<49 || (int)opcion>54)
    {
        printf("\n  Opcion no valida...\n");
        printf("  Reingrese una opcion del menu: ");
        scanf("%c",&opcion);
    }
    return opcion;
}

/** \brief Verifica si el valor recibido puede ser un flotante
 * \param flotante Array de caracteres a verificar
 * \return correcto Devuelve 1(uno) si la cadena posee numeros,un punto y ningun espacio
 * Devuelve 0(cero) si la cadena tiene mas de un punto, espacios, y otro caracter que no sea un numero
 */
int validarFloat(char flotante[])
{
    int i=0;
    int contadorPuntos=0;

    while(flotante[i]!= '\0')
    {
        if((flotante[i] == ' ') && (flotante[i] != '.') && (flotante[i] < '0' || flotante[i] > '9'))
        {
            return 0;
        }
        if(flotante[i] == '.')
        {
            contadorPuntos++;
        }
        i++;
    }
    if(contadorPuntos==1)
    {
        return 1;
    }

    return 0;
}
