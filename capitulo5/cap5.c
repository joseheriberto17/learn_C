#include <stdio.h>

int maximum(int x, int y, int z); // prototipo de función

int main(void) {
    int number1 = 0; // primer entero ingresado por el usuario
    int number2 = 0; // segundo entero ingresado por el usuario
    int number3 = 0; // tercer entero ingresado por el usuario

    printf("%s", "Enter three integers: ");
    scanf("%d%d%d", &number1, &number2, &number3);

    // number1, number2 y number3 son argumentos
    // de la llamada a la función maximum
    printf("Maximum is: %d\n", maximum(number1, number2, number3));
}

// Definición de la función maximum
int maximum(int x, int y, int z) {
    int max = x; // suponer que x es el mayor

    if (y > max) { // si y es mayor que max,
        max = y;   // asignar y a max
    }

    if (z > max) { // si z es mayor que max,
        max = z;   // asignar z a max
    }

    return max; // max es el valor más grande
}
