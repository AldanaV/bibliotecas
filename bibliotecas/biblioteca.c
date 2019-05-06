#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int ocupado;

}eEmpleado;

void inicializar(eEmpleado vec[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vec[i].ocupado==0;
    }
}

int buscarLibre(eEmpleado vec[],int tam)
{
    int i;
    int indice=-1;

    for(i=0;i<tam;i++)
    {
        if(vec[i].ocupado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrar(eEmpleado emp)
{
    printf("%d %s %s %f",emp.legajo,emp.nombre,emp.apellido,emp.sueldo);
}

int buscarEmpleado(eEmpleado vec[],int tam,int legajo)
{
    int i;
    int indice=-1;

    for(i=0;i<tam;i++)
    {
        if(vec[i].ocupado==1 && vec[i].legajo==legajo)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void alta(eEmpleado vec[],int tam)
{
    int esta;
    int legajo;
    int indice;

    indice=buscarLibre(vec,tam);

    if(indice==-1)
    {
        printf("\no hay espacio en el sistema.");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d",&legajo);

        esta=buscarEmpleado(vec,tam,legajo);

        if(esta!=-1)
        {
            printf("Existe un empleado con el legajo %d en el sistema\n",legajo);
            mostrar(vec[esta]);
        }
        else
        {
            vec[indice].legajo=legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(vec[indice].apellido);

            printf("Ingrese sueldo: ");
            scanf("%f",&vec[indice].sueldo);

            vec[indice].ocupado=1;

            printf("alta exitosa\n\n");
        }
    }
}

void mostrarTodo(eEmpleado vec[],int tam)
{
    int i;
    int contador=0;

    printf("Legajo Nombre Apellido Sueldo\n\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].ocupado==1)
        {
            mostrar(vec[i]);
            contador++;
        }
    }

    if(contador==0)
    {
        printf("No hay empleados que mostrar\n");
    }

}

void modificar(eEmpleado vec[],int tam)
{
    int i;
    int auxLegajo;
    int opcion;
    char resp;
    int flag=0;

    mostrarTodo(vec,tam);

    printf("Ingrese legajo a modificar: ");
    scanf("%d",&auxLegajo);

    for(i=0;i<tam;i++)
    {
        if(vec[i].legajo==auxLegajo)
        {
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(vec[i].nombre);
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            gets(vec[i].apellido);
            printf("Ingrese nuevo sueldo: ");
            scanf("%f",&vec[i].sueldo);

            printf("\n\nEsta seguro que sea modificar? s/n");
            scanf("%c",&resp);

            if(resp='s')
            {
                printf("modificacion exitosa!");
                flag=1;
            }
            else
            {
                printf("se ha cancelado la operacion");
                flag=0;
            }

        }
    }

}

void eliminar(eEmpleado vec[],int tam)
{
    int i;
    int auxLegajo;
    int flag=0;
    int respuesta;

    mostrarTodo(vec,tam);

    printf("Ingrese legajo a eliminar: ");
    scanf("%d",&auxLegajo);

    for(i=0;i<tam;i++)
    {
        if(auxLegajo==vec[i].legajo)
        {
            printf("se ha encontrado el legajo. seguro que desea eliminarlo?");
            printf("Su respuesta es: ");
            scanf("%c",&respuesta);

            if(respuesta='s')
            {
                vec[i].ocupado=0;
                printf("Legajo eliminado.");
            }
            else
            {
                printf("La operación ha sido cancelada.");
            }

            flag=1;
            break;

        }
    }
    if(flag==0)
    {
        printf("legajo inexistente");
        getch();
    }
}

