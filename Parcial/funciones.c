#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu()
{
    int opcion;

    printf("Menu de opciones: \n\n");
    printf("1.Alta\n");
    printf("2.Modificar\n");
    printf("3.Baja\n");
    printf("4.Listar socios\n");
    printf("5.Listar libros\n");
    printf("6.Listar autores\n");
    printf("7.Prestamos\n");
    printf("8.Salir\n\n");

    printf("Su opcion es: ");
    scanf("%d",&opcion);

    return opcion;

}

void inicializarSocio(eSocios vec[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vec[i].estado=0;
    }
}

int buscarSocio(eSocios vec[],int tam, int codigoSocio)
{
    int i;
    int indice=-1;

    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==1 && vec[i].codigoSocio==codigoSocio)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int buscarLibre(eSocios vec[],int tam)
{
    int i;
    int indice=-1;

    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void altaSocio(eSocios vec[],int tam)
{
    int encontrado;
    int espacio;
    int codigoSocio;

    espacio=buscarLibre(vec,tam);

    if(espacio==-1)
    {
        printf("No hay lugar en el sistema\n\n");
    }
    else
    {
        system("cls");
        printf("Ingrese el codigo del socio: ");
        scanf("%d",&codigoSocio);

        encontrado=buscarSocio(vec,tam,codigoSocio);

        if(encontrado!=-1)
        {
            printf("Este codigo de socio ya esta en el sistema!");
        }
        else
        {
            vec[espacio].codigoSocio=codigoSocio;

            printf("Ingrese apellido del socio: ");
            fflush(stdin);
            gets(vec[espacio].apellido);

            printf("Ingrese nombre del socio: ");
            fflush(stdin);
            gets(vec[espacio].nombre);

            printf("Ingrese sexo del socio f/m: ");
            scanf("%c",&vec[espacio].sexo);

            printf("Ingrese telefono del socio: ");
            fflush(stdin);
            gets(vec[espacio].telefono);

            printf("Ingrese email del socio: ");
            fflush(stdin);
            gets(vec[espacio].email);

            printf("Ingrese dia de asociado: ");
            scanf("%d",&vec[espacio].fechaS.dia);
            printf("Ingrese mes de asociado: ");
            scanf("%d",&vec[espacio].fechaS.mes);
            printf("Ingrese anio de asociado: ");
            scanf("%d",&vec[espacio].fechaS.anio);

            vec[espacio].estado=1;

            printf("\n\nSe ha registrado de forma exitosa.\n\n");


        }
    }
}

void listarSocios(eSocios vec[],int tam)
{
    int i;
    int cont=0;

    printf("Codigo \tApellido \tNombre \tSexo  \tTelefono  \tEmail \t\t\tFecha\n\n");

    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==1)
        {
            cont=1;
            printf("%d\t%s\t%s\t%c\t%s\t%s\t%d/%d/%d\n\n",vec[i].codigoSocio,vec[i].apellido,vec[i].nombre,vec[i].sexo,vec[i].telefono,vec[i].email,vec[i].fechaS.dia,vec[i].fechaS.mes,vec[i].fechaS.anio);

        }
    }

    if(cont=0)
    {
        printf("Todavia no se han registrado socios");
    }
}

void modificarSocio(eSocios vec[],int tam)
{
    int i;
    int opcion;
    int auxCodigo;

    listarSocios(vec,tam);

    printf("Ingrese el codigo a modificar: ");
    scanf("%d",&auxCodigo);

    for(i=0;i<tam;i++)
    {
        if(auxCodigo==vec[i].codigoSocio && vec[i].estado==1)
        {
            printf("\n\nSe ha encontrado al socio, que desea modificar?");
            printf("\n1.Apellido");
            printf("\n2.Nombre\n");
            printf("3.Sexo\n");
            printf("4.Telefono\n");
            printf("5.Email\n");

            printf("\n\nSu opcion es: ");
            scanf("%d",&opcion);
            printf("\n");

            switch(opcion)
            {
                case 1:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(vec[i].apellido);
                    break;
                case 2:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(vec[i].nombre);
                    break;
                case 3:
                    printf("Ingrese nuevo sexo f/m: ");
                    scanf("%c",&vec[i].sexo);
                    break;
                case 4:
                    printf("Ingrese nuevo telefono: ");
                    fflush(stdin);
                    gets(vec[i].telefono);
                    break;
                case 5:
                    printf("Ingrese nuevo email: ");
                    fflush(stdin);
                    gets(vec[i].email);
                    break;
            }
        }
    }
}

void bajaSocio(eSocios vec[],int tam)
{
    int i;
    int codigoS;
    char resp;

    listarSocios(vec,tam);

    printf("Ingrese el codigo del socio a eliminar: ");
    scanf("%d",&codigoS);

    for(i=0;i<tam;i++)
    {
        if(codigoS==vec[i].codigoSocio && vec[i].estado==1)
        {
            printf("Se ha encontrado el codigo ingresado, seguro que desea eliminarlo? s/n: ");
            fflush(stdin);
            resp=getch();

            if(resp=='s')
            {
                vec[i].estado=0;
                printf("\n\nEl socio ha sido eliminado\n");
            }
            else
            {
                printf("Se ha cancelado la operacion");
            }
            break;
        }
    }

}

void listarLibros(eLibros vec[],int tam)
{
    int i;

    printf("Codigo Libro\tTitulo\tCodigo Autor\n\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\t\t%s\t\t%d\n",vec[i].codigoLibro,vec[i].titulo,vec[i].codigoAutor);
    }
}

void listarAutores(eAutores vec[],int tam)
{
    int i;

    printf("Codigo Autor\tApellido\tNombre\n\n");

    for(i=0;i<tam;i++)
    {
        printf("%d\t\t%s\t\t%s\n",vec[i].codigoAutor,vec[i].apellido,vec[i].nombre);
    }
}

void altaPrestamos(eLibros libro[],int tamLibro,eSocios socio[],int tamSoc,ePrestamo prestamo[],int tamPres)
{
    int i;
    int codigoPres=400;


    for(i=0;i<tamPres;i++)
    {
        prestamo[i].codigoPrestamo=codigoPres+i;

        system("cls");
        listarLibros(libro,tamLibro);
        printf("\nIngrese el codigo del libro a prestar: ");
        scanf("%d",&prestamo[i].codigoLibro);

        printf("\n");
        listarSocios(socio,tamSoc);
        printf("Ingrese su codigo de socio: ");
        scanf("%d",&prestamo[i].codigoSocio);

        printf("Indicar fecha de prestamo: \n");
        printf("Dia: ");
        scanf("%d",&prestamo[i].fechaPres.dia);

        printf("Mes: ");
        scanf("%d",&prestamo[i].fechaPres.mes);

        printf("Anio: ");
        scanf("%d",&prestamo[i].fechaPres.anio);


        printf("\n\nSe ha realizado el prestamo\n\n");
        system("pause");
        system("cls");

    }


}
