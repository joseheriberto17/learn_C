#include <stdio.h>

void recursiva(int n) {
    static int acumulador = 0;  // Persiste entre llamadas recursivas
    acumulador += n;
    printf("Nivel: %d, Acumulador: %d\n", n, acumulador);

    if (n > 0)
        recursiva(n - 1);  // Llamada recursiva

    printf("Saliendo del nivel %d, Acumulador: %d\n", n, acumulador);
}

int main() {
    recursiva(3); // Comienza desde el nivel 3
    return 0;
}
