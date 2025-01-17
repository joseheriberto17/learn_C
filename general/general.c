#include <stdio.h>

struct cuenta
{
    int idCuenta;
    float valor;
    char *nombre;
    long cell;
} usuario;

int main()
{

    struct cuenta *usuarioPtr = &usuario;

    // inicializado valores
    usuario.idCuenta = 21;
    usuario.valor = 5000;
    usuario.nombre = "jose heriberto";
    usuario.cell = 3126849682;

    // usuario[1].idCuenta = 25;
    // usuario[1].valor = 10000;
    // usuario[1].nombre = "juan daniel";
    // usuario[1].cell = 3214566789;


    puts("impresion por valor");
    printf("%8s: %s\n", "nombre", usuario.nombre);
    printf("%8s: %2.2f$\n", "valor", usuario.valor);
    printf("%8s: %d\n", "idCuenta", usuario.idCuenta);
    printf("%8s: %ld\n", "celular", usuario.cell);

    puts("");

    puts("impresion por referencia");
    printf("%8s: %s\n", "nombre", usuarioPtr->nombre);
    printf("%8s: %2.2f$\n", "valor", usuarioPtr->valor);
    printf("%8s: %d\n", "idCuenta", usuarioPtr->idCuenta);
    printf("%8s: %ld\n", "celular", usuarioPtr->cell);

    return 0;
}