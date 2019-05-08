#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
#include "informes.h"
#include "input.h"

/** \brief Total y promedio de los importes, y cuantos productos superan ese promedio
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void informarA(eProductos produc[],int tam)
{
    float total=0,promedio;
    int cantSupProm=0,i,contador=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0)
        {
            total=total+produc[i].importe;
            contador++;
        }
    }
    promedio=total/contador;
    printf("\n-A-Total y promedio de los importes, y cuantos productos superan ese promedio\n");
    printf("\nTOTAL: %.2f",total);
    printf("\nPROMEDIO: %.2f",promedio);
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].importe>promedio)
        {
            cantSupProm=cantSupProm+produc[i].stock;
        }
    }
    printf("\nCANTIDAD: %d",cantSupProm);
}

/** \brief Total y promedio de los importes, y cuantos productos no superan ese promedio
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void informarB(eProductos produc[],int tam)
{
    float total=0,promedio;
    int cantMenProm=0,i,contador=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0)
        {
            total=total+produc[i].importe;
            contador++;
        }
    }
    promedio=total/contador;
    printf("\n-B-Total y promedio de los importes, y cuantos productos no superan ese promedio\n");
    printf("\nTOTAL: %.2f",total);
    printf("\nPROMEDIO: %.2f",promedio);
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].importe<promedio)
        {
            cantMenProm=cantMenProm+produc[i].stock;
        }
    }
    printf("\nCANTIDAD: %d",cantMenProm);
}

/** \brief La cantidad de productos cuyo stock es menor o igual a 10
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void informarC(eProductos produc[],int tam)
{
    int i,cantidad=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].stock<=10)
        {
            cantidad=produc[i].stock;
        }
    }
    printf("\n-C-La cantidad de productos cuyo stock es menor o igual a 10\n");
    printf("\nCANTIDAD: %d",cantidad);
}

/** \brief La cantidad de productos cuyo stock es mayor a 10
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void informarD(eProductos produc[],int tam)
{
    int i,cantidad=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].stock>10)
        {
            cantidad=produc[i].stock;
        }
    }
    printf("\n-D-La cantidad de productos cuyo stock es mayor a 10\n");
    printf("\nCANTIDAD: %d",cantidad);
}

/** \brief realiza la opcion elegida por el usuario del menu informar
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void informar(eProductos produc[],int tam)
{
    int salir=0;
    do
    {
        switch(menuInformar())
        {
        case 'A':
            informarA(produc,tam);
            system("pause");
            break;
        case 'B':
            informarB(produc,tam);
            system("pause");
            break;
        case 'C':
            informarC(produc,tam);
            system("pause");
            break;
        case 'D':
            informarD(produc,tam);
            system("pause");
            break;
        case 'E':
            salir=1;
            break;
        }
    }
    while(salir!=1);
}

/** \brief Listado de los productos por importe(descendente) y descripcion(ascendente)
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void listarA(eProductos produc[],int tam)
{
    int i,j;
    eProductos auxProd;
    printf("\n-A-Listado de los productos por importe(descendente) y descripcion(ascendente)\n");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(produc[i].estado!=0 && produc[j].estado!=0 && produc[i].importe>produc[j].importe)
            {
                auxProd = produc[i];
                produc[i] = produc[j];
                produc[j] = produc[i];
            }
            else if(produc[i].estado!=0 && produc[j].estado!=0 && produc[i].importe == produc[j].importe && stricmp(produc[i].descripcion,produc[j].descripcion)>0)
            {
                auxProd = produc[i];
                produc[i] = produc[j];
                produc[j] = produc[i];
            }
        }
    }
    mostrarProductos(produc,tam);
}

/** \brief Todos los productos que en cantidad son menos o igual a 10
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void listarB(eProductos produc[],int tam)
{
    int i;
    printf("\n-B-Todos los productos que en cantidad son menos o igual a 10\n");
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].stock<=10)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief Todos los productos que en cantidad son mayor a 10
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void listarC(eProductos produc[],int tam)
{
    int i;
    printf("\n-C-Todos los productos que en cantidad son mayor a 10\n");
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].stock>10)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief Todos los productos que superan el promedio de los importes
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void listarD(eProductos produc[],int tam)
{
    float promedio,acumulador=0;
    int i,contador=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0)
        {
            acumulador=acumulador+produc[i].importe;
            contador++;
        }
    }
    promedio=acumulador/contador;
    printf("\n-D-Todos los productos que superan el promedio de los importes\n");
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].importe>promedio)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief Todos los productos que no superan el promedio de los importes
 * \param produc Array a ser analizado
 * \param tam Entero que indica el tamaño del array
 */
void listarE(eProductos produc[],int tam)
{
    float promedio,acumulador=0;
    int i,contador=0;
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0)
        {
            acumulador=acumulador+produc[i].importe;
            contador++;
        }
    }
    promedio=acumulador/contador;
    printf("\n-E-Todos los productos que no superan el promedio de los importes\n");
    for(i=0; i<tam; i++)
    {
        if(produc[i].estado!=0 && produc[i].importe<promedio)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief Todos los proveedores cuya cantidad de producto es menor o igual a 10
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarF(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int i,j;
    printf("\n-F-Todos los proveedores cuya cantidad de producto es menor o igual a 10\n");
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && proveed[i].codigo==produc[j].proveedor && produc[j].stock<=10)
                {
                    mostrarUnProveed(proveed[i]);
                }
            }
        }
    }
}

/** \brief Todos los productos provistos por cada proveedor
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarG(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int i,j;
    printf("\n-G-Todos los productos provistos por cada proveedor\n");
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            mostrarUnProveed(proveed[i]);
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && produc[j].proveedor==proveed[i].codigo)
                {
                    mostrarUnProd(produc[j]);
                }
            }
        }
    }
}

/** \brief Todos los productos provistos por un proveedor determinado
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarH(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int auxCodigo,i,j;
    printf("\nIngrese el codigo del proveedor a mostrar: ");
    scanf("%d",&auxCodigo);
    printf("\n-H-Todos los productos provistos por un proveedor determinado\n");
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && proveed[i].codigo==produc[j].proveedor && proveed[i].codigo==auxCodigo)
                {
                    mostrarUnProd(produc[j]);
                }
            }
        }
    }
}

/** \brief El proveedor que provee mas productos, mostrando productos
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarI(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int contador=0,mayor=0,i,j;
    eProveedores auxProveed;
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && produc[j].proveedor==proveed[i].codigo)
                {
                    contador = contador+produc[j].stock;
                }
            }
            if(contador>mayor)
            {
                mayor=contador;
                auxProveed =proveed[i];
            }
        }
    }
    printf("\n-I-El proveedor que provee mas productos, mostrando productos\n");
    mostrarUnProveed(auxProveed);
    for(i=0; i<tamProd; i++)
    {
        if(produc[i].estado!=0 && auxProveed.codigo==produc[i].proveedor)
        {
            mostrarUnProd(produc[i]);
        }
    }
}
/** \brief El proveedor que provee menos productos, mostrando ese producto
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarJ(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int i,j,contador=0,menor,mayor=0;
    eProveedores auxProveed;
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && produc[j].proveedor==proveed[i].codigo)
                {
                    contador = contador+produc[j].stock;
                }
            }
            if(contador>mayor)
            {
                mayor=contador;
            }
            else
            {
                menor=contador;
            }
        }
    }
    printf("\n-J-El proveedor que provee menos productos, mostrando ese producto\n");
    mostrarUnProveed(auxProveed);
    for(i=0; i<tamProd; i++)
    {
        if(produc[i].estado!=0 && auxProveed.codigo==produc[i].proveedor)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief El proveedor que provee el producto mas caro, mostrando ese producto
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarK(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int i,j;
    float auxMasCaro=0,contador=0;
    eProveedores auxProveed;
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && proveed[i].codigo==produc[j].proveedor)
                {
                    contador=produc[i].importe;
                }
                if(contador>auxMasCaro)
                {
                    auxMasCaro=contador;
                    auxProveed=proveed[i];
                }
            }
        }
    }
    printf("\n-K-El proveedor que provee el producto mas caro, mostrando ese producto\n");
    mostrarUnProveed(auxProveed);
    for(i=0; i<tamProd; i++)
    {
        if(produc[i].estado!=0 && auxProveed.codigo==produc[i].proveedor)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief El proveedor que provee el producto mas barato, mostrando ese producto
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listarL(eProveedores proveed[],eProductos produc[],int tamProv,int tamProd)
{
    int i,j;
    float auxMasCaro=0,auxMasBarato,contador=0;
    eProveedores auxProveed;
    for(i=0; i<tamProv; i++)
    {
        if(proveed[i].estado!=0)
        {
            for(j=0; j<tamProd; j++)
            {
                if(produc[j].estado!=0 && proveed[i].codigo==produc[j].proveedor)
                {
                    contador=produc[i].importe;
                }
                if(contador>auxMasCaro)
                {
                    auxMasCaro=contador;
                }
                else
                {
                    auxMasBarato=contador;
                    auxProveed=proveed[i];
                }
            }
        }
    }
    printf("\n-L-El proveedor que provee el producto mas barato, mostrando ese producto\n");
    mostrarUnProveed(auxProveed);
    for(i=0; i<tamProd; i++)
    {
        if(produc[i].estado!=0 && auxProveed.codigo==produc[i].proveedor)
        {
            mostrarUnProd(produc[i]);
        }
    }
}

/** \brief realiza la opcion elegida por el usuario del menu listar
 * \param proveed Array de proveedores
 * \param produc Array de productos
 * \param tamProv Entero que indica el tamaño del array proveedores
 * \param tamProd Entero que indica el tamaño del array productos
 */
void listar(eProductos produc[],eProveedores proveed[],int tamProd,int tamProv)
{
    int salir=0;
    do
    {
        switch(menuListar())
        {
        case 'A':
            listarA(produc,tamProd);
            system("pause");
            break;
        case 'B':
            listarB(produc,tamProd);
            system("pause");
            break;
        case 'C':
            listarC(produc,tamProd);
            system("pause");
            break;
        case 'D':
            listarD(produc,tamProd);
            system("pause");
            break;
        case 'E':
            listarE(produc,tamProd);
            system("pause");
            break;
        case 'F':
            listarF(proveed,produc,tamProd,tamProd);
            system("pause");
            break;
        case 'G':
            listarG(proveed,produc,tamProv,tamProd);
            system("pause");
            break;
        case 'H':
            listarH(proveed,produc,tamProv,tamProd);
            system("pause");
            break;
        case 'I':
            listarI(proveed,produc,tamProv,tamProd);
            system("pause");
            break;
        case 'J':
            listarJ(proveed,produc,tamProv,tamProd);
            system("pause");
            break;
        case 'K':
            listarK(proveed,produc,tamProv,tamProd);
            system("pause");
            break;
        case 'L':
            listarL(proveed,produc,tamProv,tamProd);
            system("pause");
            break;
        }
    }
    while(salir!=1);
}
