#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

#define TAMSOCIO 5
#define TAMLIBRO 12
#define TAMAUTOR 10
#define TAMPRES 5


//-----------------------------------------------------------------------

int main()
{
    char seguir='s';

    eAutores autores[TAMAUTOR]={{111,"Sanchez","Luis"},{112,"Kaji","Yuuki"},{113,"Castillo","Micaela"},{114,"Ruiz","Gonzalo"},{115,"Escalera","Diego"},{116,"Aguilar","Mauro"},{117,"Mariee","Lu"},{118,"Meyer","Marisa"},{119,"Klune","Tj"},{120,"King","Stephen"}};
    eLibros libros[TAMLIBRO]={{4000,"Wolfsong",119},{4001,"Warcross",117},{4002,"Renegados",118},{4003,"It",120},{4004,"Archienemigos",118},{4005,"El alba",111},{4006,"Secuestros",112},{4007,"Smile",113},{4008,"Torture",114},{4009,"Misarables",115},{4010,"Signos",116},{4011,"Lost",111}};
    eSocios socios[TAMSOCIO];
    ePrestamo prestamo[TAMPRES];
    inicializarSocio(socios,TAMSOCIO);

    do
    {
        switch(menu())
        {
            case 1:
                altaSocio(socios,TAMSOCIO);
                system("pause");
                system("cls");
                break;
            case 2:
                modificarSocio(socios,TAMSOCIO);
                system("pause");
                system("cls");
                break;
            case 3:
                bajaSocio(socios,TAMSOCIO);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                listarSocios(socios,TAMSOCIO);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                listarLibros(libros,TAMLIBRO);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                listarAutores(autores,TAMAUTOR);
                system("pause");
                system("cls");
                break;
            case 7:
                altaPrestamos(libros,TAMLIBRO,socios,TAMSOCIO,prestamo,TAMPRES);
                system("cls");
                break;
            case 8:
                seguir='n';
                break;
            default:
                system("cls");
                printf("Error, reingrese opcion.\n\n");
                system("pause");
                system("cls");
                break;
        }
    }while(seguir=='s');

    return 0;
}

//----------------------------------------------------------------------------------
