typedef struct
{
    int codigoAutor;
    char apellido[30];
    char nombre[30];

}eAutores;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int codigoLibro;
    char titulo[40];
    int codigoAutor;
}eLibros;

typedef struct
{
    int codigoSocio;
    char apellido[30];
    char nombre[30];
    char sexo;
    char telefono[16];
    char email[30];
    int estado;
    eFecha fechaS;

}eSocios;

typedef struct
{
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPres;

}ePrestamo;



int menu();
void inicializarSocio(eSocios vec[],int tam);
int buscarSocio(eSocios vec[],int tam, int codigoSocio);
int buscarLibre(eSocios vec[],int tam);
void altaSocio(eSocios vec[],int tam);
void modificarSocio(eSocios vec[],int tam);
void listarSocios(eSocios vec[],int tam);
void bajaSocio(eSocios vec[],int tam);
void listarLibros(eLibros vec[],int tam);
void listarAutores(eAutores vec[],int tam);
void altaPrestamos(eLibros libro[],int tamLibro,eSocios socio[],int tamSoc,ePrestamo prestamo[],int tamPres);

