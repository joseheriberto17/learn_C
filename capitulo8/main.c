#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void obtenerInfoCadena(void);

// uso de la biblioteca de funcion de caracteres en C
int main(void)
{
    // obtenerInfoCadena();
    


    return 0;
}

void obtenerInfoCadena(void)
{
    printf("%31s: %d\n", "es un espacio", isblank(' '));
    printf("%31s: %d\n", "es un caracter de control", iscntrl('\n'));
    printf("%31s: %d\n", "es un caracter especial", ispunct('#'));
    printf("%31s: %d\n", "es alfanumerico:", isalnum('a'));
    printf("%31s: %d\n", "es letra mayuscula", isupper('A'));
    printf("%31s: %d\n", "es letra minuscula", islower('a'));
    printf("%31s: %d\n", "es una letra", isalpha('a'));
    printf("%31s: %d\n", "es un digito", isdigit('2'));
    printf("%31s: %d\n", "es un hexagexima", isxdigit('f'));
    printf("%31s: %d\n", "es un caracter de espacio", isspace('\t'));
    printf("%31s: %d\n", "es caracter imprimible", isprint('s'));
    printf("%31s: %d\n", "es un caracter especial", isgraph('d'));
    printf("%31s: %d\n", "pasar a minuscula", tolower('A'));
    printf("%31s: %d\n", "pasar a mayuscula", toupper('a'));
}