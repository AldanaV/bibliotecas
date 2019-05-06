//SOLO LOS SOCIOS HACEN ABM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAM 10
#define TAMLIBROS 10

typedef struct
{
    int codigoAutor;
    char apellidoAutor[20];
    char nombreAutor[20];
    int ocupado;
}eAutores;

typedef struct
{
    int codigoLibro;
    char titulo[20];
    char codiAutor[20];
}eLibros;

typedef struct
{
    int codigoSocio;
    char apellidoSocio[20];
    char nombreSocio[20];
    char sexo;
    int telefono;
    char email[20];
    int fechaAsociado;
    int ocupado;
}eSocios;

typedef struct
{
    int codigoPrestamo;
    int codiLibro;
    int codiSocio;
    int fechaPrestamo;
}ePrestamo;

int menu();
void inicializar(eSocios vec[],int tam);
int buscarLibre(eSocios vec[],int tam);
void mostrar(eSocios socio);
void mostrarTodo(eSocios vec[],int tam);
int buscarSocio(eSocios vec[], int tam, int codigo);
void altaSocios(eSocios vec[],int tam);
void modificar(eSocios vec[],int tam);
void eliminar(eSocios vec[],int tam);


int main()
{
    eAutores lista[TAM]=
    {
      {1,"ramirez","lucia"},
      {2,"gonzalez","marcos"},
      {3,"serati","lucas"},
      {4,"hernandez","sofia"},
      {5,"escalera","miguel"},
      {6,"hepp","ana"},
      {7,"coronado","martina"},
      {8,"aguilar","soledad"},
      {9,"villalba","sonia"},
      {10,"perez","diego"},
    };

    eLibros libros[TAMLIBROS]=
    {
        {40,"el alba",1},
        {41,"la bruja de near",2},
        {42,"una cancion salvaje",3},
        {43,"warcross",4},
        {44,"lie",5},
        {45,"cementerio de animales",6},
        {46,"misery",7},
        {47,"it",8},
        {48,"el resplandor",9},
        {49,"las dos caras",10},
    };

    char seguir='s';
    char confirma;

    eSocios socio[TAM];
    inicializar(socio,TAM);

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                altaSocios(socio,TAM);
                system("cls");
                system("pause");
                break;
            case 2:
                system("cls");
                modificar(socio,TAM);
                system("cls");

                break;

        }
    }

    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("Menu de opciones: ");
    printf("\n\n1.Alta");
    printf("\n2.Modificacion");
    printf("\n3.Baja");
    printf("\n4.Listar socios");
    printf("\n5.Listar libros");
    printf("\n6.Listar autores");
    printf("\n7.Prestamos");
    printf("\n8.Salir");

    printf("\n\nSu opcion es: ");
    scanf("%d",&opcion);

    return opcion;
}


void inicializar(eSocios vec[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vec[i].ocupado==0;
    }
}

int buscarLibre(eSocios vec[],int tam)
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

void mostrarTodo(eSocios vec[],int tam)
{
    int i;
    int contador=0;

    printf("Codigo   Apellido   Nombre   Sexo   Email   Telefono\n\n");
    fflush(stdin);
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
        printf("No hay autores que mostrar\n");
    }

}

void mostrar(eSocios socio)
{
    printf("%d %s %s %c %s %d %d",socio.codigoSocio,socio.apellidoSocio,socio.nombreSocio,socio.sexo,socio.email,socio.telefono,socio.fechaAsociado);
}

int buscarSocio(eSocios vec[], int tam, int codigo)
{

    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].codigoSocio == codigo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaSocios(eSocios vec[],int tam)
{
    int indice;
    int auxCodigo;
    int esta;

    indice=buscarLibre(vec,tam);

    if(indice==-1)
    {
        printf("no hay lugar en el sistema");
    }
    else
    {
        printf("Ingrese codigo del socio: ");
        scanf("%d",&auxCodigo);

        esta=buscarSocio(vec,tam,auxCodigo);
        if(esta!=-1)
        {
            printf("Existe un socio con el codigo %d en el sistema\n",auxCodigo);
        }
        else
        {
            vec[indice].codigoSocio=auxCodigo;

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(vec[indice].apellidoSocio);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombreSocio);

            printf("Ingrese sexo f/m:");
            scanf("%c",&vec[indice].sexo);

            printf("Ingrese telefono: ");
            scanf("%d",&vec[indice].telefono);

            printf("Ingrese email: ");
            fflush(stdin);
            gets(vec[indice].email);

            printf("Ingrese fecha de asociado: ");
            scanf("%d",&vec[indice].fechaAsociado);

            vec[indice].ocupado=1;
            printf("Alta exitosa");
        }
    }
}

void modificar(eSocios vec[],int tam)
{
    int i;
    int auxCodigo;
    char auxNombre[20];
    char auxApellido[20];
    char auxSexo;
    char auxEmail[20];
    char resp;
    int opcion;

    mostrarTodo(vec,tam);

    printf("\nIngrese codigo a modificar: ");
    scanf("%d",&auxCodigo);

    for(i=0;i<tam;i++)
    {
        if(vec[i].codigoSocio==auxCodigo)
        {
            printf("seguro que desea modificar? s/n");
            resp=getch();
            if(resp=='s')
            {
               printf("Menu de modificaciones");
               printf("1.Apellido");
               printf("2.Nombre");
               printf("3.Sexo");
               printf("4.Telefono");
               printf("5.Email");
               printf("6.Salir");

               printf("Su opcion es: ");
               scanf("%d",&opcion);

               switch(opcion)
               {
                    case 1:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(auxApellido);
                        strcpy(vec[i].apellidoSocio,auxApellido);
                        break;
                    case 2:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxNombre);
                        strcpy(vec[i].nombreSocio,auxNombre);
                        break;
                    case 3:
                        printf("Ingrese nuevo sexo: f/m");
                        scanf("%c",&vec[i].sexo,auxSexo);
                        strcpy(vec[i].sexo,auxSexo);
                        break;
                    case 4:
                        printf("Ingrese nuevo telefono: ");
                        scanf("%d",&vec[i].telefono);
                        break;
                    case 5:
                        printf("Ingrese nuevo email: ");
                        fflush(stdin);
                        gets(auxEmail);
                        strcpy(vec[i].email,auxEmail);
                        break;

               }
            }
            else
            {
                printf("se ha cancelado la operacion");
                break;
            }
        }
    }

}

void eliminar(eSocios vec[],int tam)
{
    int i;
    int auxCodigo;
    char resp;

    mostrarTodo(vec,tam);

    printf("Ingrese codigo a eliminar");
    scanf("%d",&auxCodigo);

    for(i=0;i<tam;i++)
    {
        if(auxCodigo==vec[i].codigoSocio)
        {
            printf("se ha encontrado el codigo de socio. seguro que desea eliminarlo? s/n");
            fflush(stdin);
            resp=getch();

            if(resp=='s')
            {
                vec[i].ocupado=0;
                printf("socio eliminado");
            }
            else
            {
                printf("se ha cancelado la operacion");
            }
            break;
        }
    }
}
