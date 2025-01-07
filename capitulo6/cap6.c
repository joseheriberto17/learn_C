// fig06_01.c
// Inicializando los elementos de un arreglo a ceros.
#include <stdio.h>

void array(void){
     int n[5] = {0}; // n es un arreglo de cinco enteros

    // Asignar 0 a los elementos del arreglo n
    for (size_t i = 0; i < 5; ++i) {
        n[i] = 0; // asignar 0 al elemento en la posición i
    }

    printf("%s%8s\n", "Elemento", "Valor");

    // Mostrar el contenido del arreglo n en formato tabular
    for (size_t i = 0; i < 5; ++i) {
        printf("%7zu%8d\n", i, n[i]);
    }
}

void arrayString(void){
    char string[]= {'f','i','r','s','t'};

    printf("%c",string[0]);
}

// La función main comienza la ejecución del programa
int main(void) {
   arrayString();
}
