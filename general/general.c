// fig06_09.c
// Arreglos estáticos y automáticos.
#include <stdio.h>

void staticArrayInit(void); // prototipo
void automaticArrayInit(void); // prototipo

int main(void) {
    puts("Primera llamada a cada función:");
    staticArrayInit();
    automaticArrayInit();

    puts("\n\nSegunda llamada a cada función:");
    staticArrayInit();
    automaticArrayInit();
}

// Demuestra un arreglo local estático
void staticArrayInit(void) {
    static int array1[3]; // inicializado a 0 por defecto

    puts("\nValores al entrar a staticArrayInit:");
    for (size_t i = 0; i < 3; ++i) {
        printf("array1[%zu] = %d ", i, array1[i]);
    }

    puts("\nValores al salir de staticArrayInit:");
    for (size_t i = 0; i < 3; ++i) {
        printf("array1[%zu] = %d ", i, array1[i] += 5);
    }
}

// Demuestra un arreglo local automático
void automaticArrayInit(void) {
    int array2[3] = {1, 2, 3}; // inicializado en cada llamada

    puts("\nValores al entrar a automaticArrayInit:");
    for (size_t i = 0; i < 3; ++i) {
        printf("array2[%zu] = %d ", i, array2[i]);
    }

    puts("\nValores al salir de automaticArrayInit:");
    for (size_t i = 0; i < 3; ++i) {
        printf("array2[%zu] = %d ", i, array2[i] += 5);
    }
}
