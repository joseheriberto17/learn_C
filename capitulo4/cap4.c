#include <stdio.h>

void main()
{
    puts("iniciando bucle con while");

    int count = 0;
    while (count <= 5)
    {
        printf("%d", ++count);
    }
    puts("");

    printf("iniciando bucle con for");

    for (size_t i = 0; i < 10; i++)
    {
        printf("%ld", i);
    }
    puts("");

    printf("iniciando un switch, ingrese un caracter: ");

    int grade = 0;

    while ((grade = getchar()) != EOF)
    {

        switch (grade)
        {
        case 'A':
        case 'a':
            puts("primer lugar");
            break;
        case 'B':
        case 'b':
            puts("segundo lugar");
            break;

        case '\n':
        case '\t':
        case ' ':
            // ingnorar
            break;
        default:
            puts("grado desconocido");
            break;
        }
    }

    signed char a; // int_8
    printf("El tamaño de short int es: %zu bytes\n", sizeof(short int));
    printf("El tamaño de int es: %zu bytes\n", sizeof(int));
}