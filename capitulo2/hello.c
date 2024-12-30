// esto es un comentario

/*
    comentarios multilinea
*/

// directiva del preprocesador
// estándar de entrada/salida
// printf
#include <stdio.h>

// funcion principal
int main()
{
    // siempre se recomienda inicializarlo
    // no definir con nombre que empiezen con digito o 
    // "_" (conflito con  identificadores generados por el compilador o biblioteca estandar)
    // ejemplo
    // total_commissions o totalCommissions
    int integer1 = 0;
    int integer2 = 0;

    printf("Hello, WSL!\n");
    printf("digite el primer numero: ");
    //  cadena de control de formato , 
    scanf("%d",&integer1);

    printf("digite el segundo numero: ");
    scanf("%d",&integer2);

    int suma = 0;
    suma = integer1 +integer2;

    printf("el resultado es: %d\n",suma);

    return 0;
}