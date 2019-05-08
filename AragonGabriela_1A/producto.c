#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
#include "informes.h"
#include "input.h"

/** \brief inicializa el estado del array de proveedores en 0(cero) porque estan vacias
 * \param proveed Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void inicializarProveedores(eProveedores proveed[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        proveed[i].estado = 0;
        proveed[i].codigo = i+1;
    }
}

/** \brief inicializa el estado del array de proveedores en 0(cero) porque estan vacias
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void inicializarStock(eProductos produc[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        produc[i].estado = 0;
        produc[i].codigo = i+1;
    }
}

/** \brief Busca en un array de estructuras cual es la primera estructura vacia
 * \param vec[] Array de estructuras a ser recorrido
 * \param tam Entero que determina la cantidad de estructuras del array
 * \return indice Numero entero que devuelve: -1 en caso de que no haya estructuras vacias, ó el indice
 del vector en caso de que una estructura tenga su estado en 0(cero) por lo que se la considera vacia
 */
int buscarLibreProvee(eProveedores proveed[],int tam)
{
    int i,indice = -1;
    for(i=0; i<tam; i++)
    {
        if(proveed[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Busca en un array de estructuras cual es la primera estructura vacia
 * \param vec[] Array de estructuras a ser recorrido
 * \param tam Entero que determina la cantidad de estructuras del array
 * \return indice Numero entero que devuelve: -1 en caso de que no haya estructuras vacias, ó el indice
 del vector en caso de que una estructura tenga su estado en 0(cero) por lo que se la considera vacia
 */
int buscarLibreProduc(eProductos produc[],int tam)
{
    int i,indice = -1;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Muestra un menu de opciones y permite elegir una
 * \return opcion Devuelve un caracter cargado con la opcion elegida por el usuario
 */
char menu()
{
    char opcion;
    system("cls");
    printf("-------MENU-------\n\n");
    printf("-1- Altas\n");
    printf("-2- Modificar\n");
    printf("-3- Baja\n");
    printf("-4- Informar\n");
    printf("-5- Listar\n");
    printf("-6- Salir\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion = validarMenu (opcion);
    return opcion;
}

/** \brief muestra todos los elementos de una estructura
 * \param proveed Estructura a ser mostrada
 */
void mostrarUnProveed(eProveedores proveed)
{
    printf("COD: %d %s\n",proveed.codigo,proveed.descripcion);
}

/** \brief muestra todos los elementos de una estructura
 * \param prod Estructura a ser mostrada
 */
void mostrarUnProd(eProductos prod)
{
    printf("COD:%d\t$ %.2f\t%d unid\tPROVEEDOR:%d\n",prod.codigo,prod.importe,prod.stock);
    printf("%s\n",prod.descripcion);
}

/** \brief recorre un array de estructuras para mostrar todos sus elementos
 * \param produc Array de estructuras a ser recorrido
 * \param tam Entero que indica el tamaño del array
 */
void mostrarProductos(eProductos produc[],int tam)
{
    int i;
    system("cls");
    printf("\n\n-------LISTA DE PRODUCTOS-------\n\n");
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief muestra un menu para las altas
 * \return char Devuelve el caracter correspondiente a la oopcion elegida por el usuario
 */
char menuAlta()
{
    char opcion;
    system("cls");
    printf("\n\n-------ALTAS-------\n\n");
    printf("-1- Alta Proveedores\n");
    printf("-2- Alta Productos\n");
    printf("-3- Salir\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    while((int)opcion<49 || (int)opcion>51)
    {
        printf("\n  Opcion no valida...\n");
        printf("  Reingrese una opcion del menu ");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    return opcion;
}

/** \brief muestra el menu de opciones para informar
 * \return char Devuelve el caracter correspondiente a la oopcion elegida por el usuario
 */
char menuInformar()
{
    char opcion;
    system("cls");
    printf("\n\n-------INFORMAR-------\n\n");
    printf("-A-Total y promedio de los importes, y cuantos productos superan ese promedio\n");
    printf("-B-Total y promedio de los importes, y cuantos productos no superan ese promedio\n");
    printf("-C-La cantidad de productos cuyo stock es menor o igual a 10\n");
    printf("-D-La cantidad de productos cuyo stock es mayor a 10\n");
    printf("-E-Salir\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=toupper(opcion);
    while((int)opcion<65 || (int)opcion>69)
    {
        printf("\n  Opcion no valida...\n");
        printf("  Reingrese una opcion del menu ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=toupper(opcion);
    }
    return opcion;
}

/** \brief muestra el menu de opciones para listar
 * \return char Devuelve el caracter correspondiente a la oopcion elegida por el usuario
 */
char menuListar()
{
    char opcion;
    system("cls");
    printf("\n\n-------LISTAR-------\n\n");
    printf("-A-Listado de los productos por importe(descendente) y descripcion(ascendente)\n");
    printf("-B-Todos los productos que en cantidad son menos o igual a 10\n");
    printf("-C-Todos los productos que en cantidad son mayor a 10\n");
    printf("-D-Todos los productos que superan el promedio de los importes\n");
    printf("-E-Todos los productos que no superan el promedio de los importes\n");
    printf("-F-Todos los proveedores cuya cantidad de producto es menor o igual a 10\n");
    printf("-G-Todos los productos provistos por cada proveedor\n");
    printf("-H-Todos los productos provistos por un proveedor determinado\n");
    printf("-I-El proveedor que provee mas productos, mostrando productos\n");
    printf("-J-El proveedor que provee menos productos, mostrando ese producto\n");
    printf("-K-El proveedor que provee el producto mas caro, mostrando ese producto\n");
    printf("-L-El proveedor que provee el producto mas barato, mostrando ese producto\n");
    printf("-M-Salir\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=toupper(opcion);
    while((int)opcion<65 || (int)opcion>77)
    {
        printf("\n  Opcion no valida...\n");
        printf("  Reingrese una opcion del menu ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=toupper(opcion);
    }
    return opcion;
}

/** \brief busca en el array de productos el codigo ingresado por el usuario
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array a ser recorrido
 * \param codigo Entero ingresado por el usuario
 * \return 0(cero) en caso de no haber encontrado el mismo codigo
    o si lo encuentra el indice del elemento del array
 */
int buscarProducto(eProductos produc[],int tam,int codigo)
{
    int i,encontrado=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].codigo==codigo)
        {
            encontrado=i;
            break;
        }
    }
    return encontrado;
}


/** \brief realiza el alta de proveedores y/o productos
 * \param produc Array de productos donde dar de alta
 * \param proveed Array de proveedores donde dar de alta
 * \param tamStock Entero que indica el tamaño del array productos
 * \param tamProveed Entero que indica el tamaño del array proveedores
 */
void altas(eProductos produc[],eProveedores proveed[],int tamStock,int tamProveed)
{
    int salir=0,i;
    do
    {
        switch(menuAlta())
        {
        case '1':
            altaProvee(proveed,tamProveed);
            system("pause");
            break;
        case '2':
            for(i=0; i<tamProveed; i++)
            {
                if(proveed[i].estado!=0)
                {
                    altaProduc(produc,proveed,tamStock,tamProveed);
                }
                else
                {
                    printf("\nNo puede ingresar productos sin antes ingresar proveedor\n");
                }
            }
            system("pause");
            break;
        case '3':
            salir=1;
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            system("pause");
            break;
        }
    }
    while(salir!=1);
}

/** \brief baja logica de alguna estructura del array producto
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void bajaProducto(eProductos produc[],int tam)
{
    int auxCodigo,esta;
    char confirm;
    system("cls");
    printf("\n\n-------BAJA PRODUCTO-------\n\n");
    printf("Ingrese el codigo del producto: ");
    scanf("%d",&auxCodigo);
    esta=buscarProducto(produc,tam,auxCodigo);
    if(esta==0)
    {
        printf("\n\nCodigo no encontrado\n\n");
    }
    else
    {
        printf("\n\nProducto encontrado\n");
        mostrarUnProd(produc[esta]);
        printf("\n\nConfirma la baja? S/N\t");
        fflush(stdin);
        scanf("%c",&confirm);
        confirm=tolower(confirm);
        while(confirm!='s'&&confirm!='n')
        {
            printf("\n\nIngrese solo <S> o <N> \t");
            scanf("%c",&confirm);
            confirm=tolower(confirm);
        }
        if(confirm=='s')
        {
            produc[esta].estado=0;
        }
    }
}

/** \brief muestra el menu para las modificaciones
 * \return char Caracter elegido por el usuario que indica una opcion del menu
 */
char menuModificar()
{
    char opcion;
    printf("\n\nModificar:\n\n");
    printf("-1-Descripcion\n-2-Importe\n-3-Stock\n-4-Salir\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    while((int)opcion<49 || (int)opcion>52)
    {
        printf("\n  Opcion no valida...\n");
        printf("  Reingrese una opcion del menu: \n");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    return opcion;
}

/** \brief funcion que mediante un codigo ingresado por el usuario permite modificar el contenido
de un producto existente(descripcion,precio y/o cantidad)
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void modificarProducto(eProductos produc[],int tam)
{
    int auxCodigo,esta;
    int salir=0;
    char auxDesc[51];
    char auxPrecio[15];
    int auxStock;
    system("cls");
    printf("\n\n-------MODIFICAR PRODUCTOS-------\n\n");
    printf("Ingrese el codigo del producto: ");
    scanf("%d",&auxCodigo);
    esta=buscarProducto(produc,tam,auxCodigo);
    if(esta==0)
    {
        printf("\n\nCodigo no encontrado\n");
    }
    else if(produc[esta].estado!=0 && esta!=0)
    {
        printf("\n\nProducto encontrado\n");
        mostrarUnProd(produc[esta]);
        system("pause");

        do
        {
            switch(menuModificar())
            {
            case '1':
                printf("\nDescripcion del Producto: ");
                fflush(stdin);
                scanf("%[^\n]",auxDesc);
                while(strlen(auxDesc)>51)
                {
                    printf("\nDescripcion extensa, solo puede ingresar 50 caracteres\nReingrese: \n");
                    fflush(stdin);
                    scanf("%[^\n]",auxDesc);
                }
                strcpy(produc[esta].descripcion,auxDesc);
                system("pause");
                break;
            case '2':
                printf("\n\nPrecio: $ ");
                fflush(stdin);
                gets(auxPrecio);
                while((validarFloat(auxPrecio)!=1)&&(strlen(auxPrecio)>15))
                {
                    printf("\nValor no permitido, solo numeros y un punto\nReingrese: \n");
                    fflush(stdin);
                    gets(auxPrecio);
                }
                produc[esta].importe=atof(auxPrecio);
                system("pause");
                break;
            case '3':
                printf("\n\nCantidad: ");
                scanf("%d",&auxStock);
                while(isdigit(auxStock)!=1)
                {
                    printf("\nValor no permitido, solo numeros enteros\nReingrese: \n");
                    scanf("%d",&auxStock);
                }
                produc[esta].stock=auxStock;
                system("pause");
                break;
            case '4':
                salir=1;
                system("pause");
                break;
            }
        }
        while(salir!=1);
    }

    printf("\n\nModificacion exitosa\n\n");
}


/** \brief permite al usuario ingresar un proveedor si hay espacio disponible
 * \param proveed Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void altaProvee(eProveedores proveed[],int tam)
{
    char auxDesc[51];
    int indice;
    system("cls");
    printf("\n\n-------ALTA PROVEEDORES-------\n\n");
    indice=buscarLibreProvee(proveed,tam);
    if(indice==-1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a nuevos proveedores.\n\n");
    }
    else
    {
        printf("\nIngrese descripcion del Proveedor: ");
        fflush(stdin);
        scanf("%[^\n]",auxDesc);
        while(strlen(auxDesc)>51)
        {
            printf("\nDescripcion extensa, solo puede ingresar 50 caracteres:\nReingrese: \n");
            fflush(stdin);
            scanf("%[^\n]",auxDesc);
        }
    }
    strcpy(proveed[indice].descripcion,auxDesc);
    proveed[indice].estado =1;
    printf("\n\nAlta exitosa\n");
}

/** \brief busca en el array la coincidencia para saber si existe determinado proveedor
 * \param proveed Array a ser analizado
 * \param aux Entero que se utilizara para la comparacion
 * \param tam Entero que indica el tamaño del array
 * \return 0(cero) si no hay coincidencia, o el indice de la estructura que coincide
 */
int validarProveedor(eProveedores proveed[],int aux,int tam)
{
    int i,esta=0;
    for(i=0; i<tam; i++)
    {
        if(proveed[i].estado!=0 && aux==proveed[i].codigo)
        {
            esta=1;
        }
    }
    return esta;
}

/** \brief permite realizar al usuario la alta de productos
 * \param produc Array de productos
 * \param proveed Array de proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 */
void altaProduc(eProductos produc[],eProveedores proveed[],int tamProd,int tamProv)
{
    char auxDesc[51];
    int indice,esta;
    char auxStock[5];
    char auxPrecio[15];
    int auxProv,i;
    system("cls");
    printf("\n-------ALTA PRODUCTOS-------\n\n");
    indice=buscarLibreProduc(produc,tamProd);
    if(indice==-1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta nuevos productos.\n\n");
    }
    else
    {
        printf("\nDescripcion del Producto: ");
        fflush(stdin);
        scanf("%[^\n]",auxDesc);
        while(strlen(auxDesc)>51)
        {
            printf("\nDescripcion extensa, solo puede ingresar 50 caracteres\nReingrese: \n");
            fflush(stdin);
            scanf("%[^\n]",auxDesc);
        }
        printf("\n\nPrecio: $ ");
        fflush(stdin);
        gets(auxPrecio);
        while((validarFloat(auxPrecio)!=1)&&(strlen(auxPrecio)>15))
        {
            printf("\nValor no permitido, solo numeros y un punto\nReingrese: \n");
            fflush(stdin);
            gets(auxPrecio);
        }
        printf("\n\nCantidad: ");
        fflush(stdin);
        scanf("%s",auxStock);
        while(esNumerico(auxStock) && strlen(auxStock)>5)
        {
            printf("\nValor no permitido, solo numeros enteros\nReingrese: \n");
            fflush(stdin);
            scanf("%s",auxStock);
        }
        printf("\n\nCodigos de Proveedor disponible: ");
        for(i=0; i<tamProv; i++)
        {
            if(proveed[i].estado!=0)
            {
                printf("%d\t%s",proveed[i].codigo,proveed[i].descripcion);
            }
        }
        printf("\nProveedor elegido: ");
        scanf("%d",&auxProv);
        esta=validarProveedor(proveed,auxProv,tamProv);
        while(esta != 1)
        {
            printf("\nProveedor inexistente\nReingrese: ");
            scanf("%d",&auxProv);
            esta=validarProveedor(proveed,auxProv,tamProv);
        }
    }
    strcpy(produc[indice].descripcion,auxDesc);
    produc[indice].importe = atof(auxPrecio);
    produc[indice].stock = atoi(auxStock);
    produc[indice].proveedor = auxProv;
    produc[indice].estado = 1;
    printf("\n\nAlta exitosa\n\n");
}
