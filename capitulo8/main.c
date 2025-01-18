#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

void obtenerInfoCadena(void);

// uso de la biblioteca de funcion de caracteres en C
int main(void)
{
    // obtenerInfoCadena();


    const char *nPtr = "25.2334asd";
    char *nnPtr; // puntero para mostrar el resto de la cadena

    double d = strtod(nPtr, &nnPtr);
    printf("%20s: %f, restos: %s\n","valor double", d, nnPtr);

    long int ld = strtol(nPtr, &nnPtr,10);
    printf("%20s: %ld, restos: %s\n","valor long int", ld,nnPtr);

    unsigned long lu = strtoul(nPtr, &nnPtr,10);
    printf("%20s: %lu, restos: %s\n","valor unsigned long",lu,nnPtr);

    // printf("getchar: %x\n",getchar());

    char sentence[7] = "";
    fgets(sentence,7,stdin);

    printf("%s",sentence);

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