#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

void obtenerInfoCadena(void);
void conversionDeCadena(void);
void usoDeFuncionesEstandar(void);
void manipularCadenas(void);
void copiarPorMemoria(char *, char *, size_t);

// uso de la biblioteca de funcion de caracteres en C
int main(void)
{
    // obtenerInfoCadena();
    // void conversionDeCadena(void)
    // void usoDeFuncionesEstandar(void);

    // void manipularCadenas(void);

    // void compararCadenas(void);

    char dataSrc[10] = "123456";
    char dataDest[10] = "";

    printf("dataDest: %s\n", dataDest);
    copiarPorMemoria(dataDest, dataSrc, (sizeof(dataSrc) / sizeof(dataSrc[0])));
    printf("dataDest: %s\n", dataDest);

    printf("tamano del agreglo: %zu , tamaño en bytes: %zu\n", (sizeof(dataSrc) / sizeof(dataSrc[0])), (sizeof(dataSrc)));

    // char x[] = "123456789"; // Inicializar el arreglo x

    // printf("data: %s",&x[3]);
    // printf((char *)memmove(x,&x[3],));

    return 0;
}

void copiarPorMemoria(char *arrayPtrDest, char *arrayPtrSrc, size_t n)
{
    memcpy(arrayPtrDest, arrayPtrSrc, n);
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

void conversionDeCadena(void)
{
    const char *nPtr = "25.2334asd";
    char *nnPtr; // puntero para mostrar el resto de la cadena

    double d = strtod(nPtr, &nnPtr);
    printf("%20s: %f, restos: %s\n", "valor double", d, nnPtr);

    long int ld = strtol(nPtr, &nnPtr, 10);
    printf("%20s: %ld, restos: %s\n", "valor long int", ld, nnPtr);

    unsigned long lu = strtoul(nPtr, &nnPtr, 10);
    printf("%20s: %lu, restos: %s\n", "valor unsigned long", lu, nnPtr);
}

void usoDeFuncionesEstandar(void)
{
    char sentence[20] = "";

    // leer una linea de texto fgets
    fgets(sentence, 7, stdin);
    printf("cadena: %s", sentence);

    // imrpmiri un caracter
    printf("putchar[1]: ");
    putchar(sentence[1]);

    // imprimir una linea con getchar
    int c = 0;
    putc('\n', stdout);
    while (c != '\n')
    {
        c = getchar();
        printf("%c", c);
    }

    // sprintf(sentence, "integer:%6d\ndouble:%7.2f", 1234, 1.456);
}

void manipularCadenas(void)
{
    char data[] = "12";

    printf("%s", data);

    char cadenaVacia1[20] = "";
    char cadenaActual1[20] = "123456789012345678";

    puts("uso de strcpy");
    printf("cadenaVacia: %s, cadenaAltual: %s\n", cadenaVacia1, cadenaActual1);
    strcpy(cadenaVacia1, cadenaActual1);
    printf("cadenaVacia: %s, cadenaAltual: %s\n", cadenaVacia1, cadenaActual1);
    puts("");

    char cadenaVacia2[10] = {"abcdefg"};
    char cadenaActual2[20] = {"123456789012345678"};

    puts("uso de strncpy");
    printf("cadenaVacia: %s, cadenaAltual: %s\n", cadenaVacia2, cadenaActual2);
    strncpy(cadenaVacia2, cadenaActual2, 5);
    printf("cadenaVacia: %s, cadenaAltual: %s\n", cadenaVacia2, cadenaActual2);
    puts("");

    char cadenaA1[20] = "abcdefghi";
    char cadenaB1[10] = "123456789";

    puts("uso de strcat");
    printf("cadenaA: %s, cadenaB: %s\n", cadenaA1, cadenaB1);
    strcat(cadenaA1, cadenaB1);
    printf("cadenaA: %s, cadenaB: %s\n", cadenaA1, cadenaB1);
    puts("");

    char cadenaA2[20] = "abcdefghi";
    char cadenaB2[10] = "123456789";

    puts("uso de strncat");
    printf("cadenaA: %s, cadenaB: %s\n", cadenaA2, cadenaB2);
    strncat(cadenaA2, cadenaB2, 3);
    printf("cadenaA: %s, cadenaB: %s\n", cadenaA2, cadenaB2);
    puts("");
}

void compararCadena(void)
{
    char cadenaA1[10] = {'1', '2', '3', '4', '5'};
    char cadenaB1[10] = {'1', '2', '3', '4', '5'};

    printf("strcmp: %d\n", strcmp(cadenaA1, cadenaB1));

    char cadenaA2[10] = "12345";
    char cadenaB2[10] = "123jk";

    printf("strncmp: %d\n", strncmp(cadenaA2, cadenaB2, 3));
}