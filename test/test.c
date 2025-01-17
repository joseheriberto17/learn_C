#include <stdio.h>

int main() {
    char str[] = "Hello, world!";
    str[0] = 'h';  // Intento de modificar un literal de cadena (comportamiento indefinido)
    printf("%s\n", str);
    return 0;
}