#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[51];
    int estado;
} eProveedores;

typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;
    int stock;
    int proveedor;
    int estado;
} eProductos;

char menu();
char menuAlta();
char menuModificar();
char menuInformar();
char menuListar();
void inicializarProveedores(eProveedores[],int);
void inicializarStock(eProductos[],int);
int buscarLibreProvee(eProveedores[],int);
int buscarLibreProduc(eProductos[],int);
void altas(eProductos[],eProveedores[],int,int);
void altaProvee(eProveedores[],int);
int validarProveedor(eProveedores[],int,int);
void altaProduc(eProductos[],eProveedores[],int,int);
int buscarProducto(eProductos[],int,int);
void modificarProducto(eProductos[],int);
void bajaProducto(eProductos[],int);
void mostrarUnProd(eProductos prod);
void mostrarProductos(eProductos[],int);
void mostrarUnProveed(eProveedores proveed);

#endif
