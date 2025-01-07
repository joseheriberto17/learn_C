// fig07_01.c
// Usando los operadores & y *.
#include <stdio.h>

int main(void) {
    int a = 7;                // Variable entera
    int *aPtr = &a;           // El puntero apunta a la dirección de a

    // Mostrar la dirección de 'a' y el valor de 'aPtr'
    printf("Address of a is %p\nValue of aPtr is %p\n\n", &a, aPtr);

    // Mostrar el valor de 'a' y el valor al que apunta 'aPtr'
    printf("Value of a is %d\nValue of *aPtr is %d\n\n", a, *aPtr);

    // Mostrar que * y & son complementarios
    printf("Showing that * and & are complements of each other\n");
    printf("&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr);

    return 0;
}
