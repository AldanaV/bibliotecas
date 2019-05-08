#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
#include "informes.h"
#include "input.h"
#define PROVE 5
#define STOCK 10

int main()
{
    int salir =0;
    eProveedores proveedores[PROVE];
    eProductos productos[STOCK];
    inicializarProveedores(proveedores,PROVE);
    inicializarStock(productos,STOCK);

    do
    {
        switch(menu())
        {
        case '1':
            altas(productos,proveedores,STOCK,PROVE);
            system("pause");
            break;
        case '2':
            modificarProducto(productos,STOCK);
            system("pause");
            break;
        case '3':
            bajaProducto(productos,STOCK);
            system("pause");
            break;
        case '6':
            salir=1;
            break;
        default:
            printf("opcion no valida");
            break;
        }
    }
    while(salir!=1);
    return 0;
}



