#include <stdio.h>

struct cuenta
{
    int idCuenta;
    float valor;
    char *nombre;
    long cell;
} usuario[5];

void mostrarDatosPorValor(struct cuenta data[],int size);
void mostrarDatosPorReferencia(struct cuenta *usuarioPtr,int size);

int main()
{

    struct cuenta *usuarioPtr = usuario;

    // inicializado valores
    usuario[0].idCuenta = 21;
    usuario[0].valor = 5000;
    usuario[0].nombre = "jose heriberto";
    usuario[0].cell = 3126849682;

    usuario[1].idCuenta = 25;
    usuario[1].valor = 10000;
    usuario[1].nombre = "juan daniel";
    usuario[1].cell = 3214566789;


    mostrarDatosPorValor(usuario,5);

    puts("");

    mostrarDatosPorReferencia(usuarioPtr,5);
    puts("");

    usuarioPtr++;

    mostrarDatosPorReferencia(usuarioPtr,5);
    puts("");

    usuarioPtr--;

    mostrarDatosPorReferencia(usuarioPtr,5);

    char *color[] = "blue";

    color[0] = 'c';

    return 0;
}

void mostrarDatosPorValor(struct cuenta data[],int size){

    puts("impresion por valor");
    printf("%8s: %s\n", "nombre", data[0].nombre);
    printf("%8s: %2.2f$\n", "valor", data[0].valor);
    printf("%8s: %d\n", "idCuenta", data[0].idCuenta);
    printf("%8s: %ld\n", "celular", data[0].cell);
}

void mostrarDatosPorReferencia(struct cuenta *usuarioPtr,int size){

    puts("impresion por referencia");
    printf("%8s: %s\n", "nombre", usuarioPtr->nombre);
    printf("%8s: %2.2f$\n", "valor", usuarioPtr->valor);
    printf("%8s: %d\n", "idCuenta", usuarioPtr->idCuenta);
    printf("%8s: %ld\n", "celular", usuarioPtr->cell);
}

