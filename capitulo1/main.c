// Directiva del preprosesador. (Standard Input Output)
// ".h" abr. de header
#include <stdio.h>
#include <stdint.h>

// Los argumento de main no son obligatorios, a menos que quiera ejecutar el programa con argumentos
int main(int argc, char *argv[])
{
    uint8_t nombre = 0;

    printf("hola mundo %d",nombre);

    // Es posible que no se nesecite definir de forma explicita
    return 0;
}