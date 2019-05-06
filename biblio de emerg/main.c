#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int ocupado;

}eEmpleado;

void inicializar(eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
void mostrar(eEmpleado emp);
int buscarEmpleado(eEmpleado vec[],int tam,int legajo);
void alta(eEmpleado vec[],int tam);
void mostrarTodo(eEmpleado vec[],int tam);
void modificar(eEmpleado vec[],int tam);
void eliminar(eEmpleado vec[],int tam);

int main()
{
    printf("Hello world!\n");
    return 0;
}

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
    int aux;
    char auxNombre[20];
    char auxApellido[20];
    char resp;

    mostrarTodo(vec,tam);

    printf("\nIngrese legajo a modificar: ");
    scanf("%d",&aux);

    for(i=0;i<tam;i++)
    {
        if(vec[i].legajo==aux)
        {
            printf("seguro que desea modificar? s/n");
            resp=getch();
            if(resp=='s')
            {
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(auxNombre);
                strcpy(vec[i].nombre,auxNombre);

                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(auxApellido);
                strcpy(vec[i].apellido,auxApellido);

                break;

            }
            else
            {
                printf("se ha cancelado la operación");
                break;
            }
        }
    }


}

void eliminar(eEmpleado vec[],int tam)
{
    int i;
    int auxLegajo;
    char respuesta;

    mostrarTodo(vec,tam);

    printf("Ingrese legajo a eliminar: ");
    scanf("%d",&auxLegajo);

    for(i=0;i<tam;i++)
    {
        if(auxLegajo==vec[i].legajo)
        {
            printf("se ha encontrado el legajo. seguro que desea eliminarlo?");
            fflush(stdin);
            respuesta=getch();

            if(respuesta=='s')
            {
                vec[i].ocupado=0;
                printf("Legajo eliminado.");
            }
            else
            {
                printf("La operación ha sido cancelada.");
            }


            break;

        }
    }

}
