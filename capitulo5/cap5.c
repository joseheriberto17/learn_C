// fig05_08.c
// Ejemplo de ámbitos en C.
#include <stdio.h>

void useLocal(void); // prototipo de función
void useStaticLocal(void); // prototipo de función
void useGlobal(void); // prototipo de función

int x = 1; // variable global

int main(void) {
    int x = 5; // variable local en main

    printf("local x in outer scope of main is %d\n", x);

    { // inicio de un nuevo ámbito
        int x = 7; // variable local en el nuevo ámbito
        printf("local x in inner scope of main is %d\n", x);
    } // fin del nuevo ámbito

    printf("local x in outer scope of main is %d\n", x);

    useLocal(); // useLocal tiene una variable local automática
    useStaticLocal(); // useStaticLocal tiene una variable local estática
    useGlobal(); // useGlobal utiliza la variable global x
    useLocal(); // useLocal reinicializa su variable local automática
    useStaticLocal(); // useStaticLocal conserva el valor previo de x
    useGlobal(); // la variable global x también conserva su valor

    printf("\nlocal x in main is %d\n", x);
}

// useLocal reinicializa la variable local x en cada llamada
void useLocal(void) {
    int x = 25; // inicializada cada vez que useLocal es llamada

    printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
    ++x;
    printf("local x in useLocal is %d before exiting useLocal\n", x);
}

// useStaticLocal inicializa x solo en la primera llamada
// Retiene el valor de x entre llamadas
void useStaticLocal(void) {
    static int x = 50; // inicializada una vez

    printf("\nlocal static x is %d on entering useStaticLocal\n", x);
    ++x;
    printf("local static x is %d on exiting useStaticLocal\n", x);
}

// useGlobal modifica la variable global x en cada llamada
void useGlobal(void) {
    printf("\nglobal x is %d on entering useGlobal\n", x);
    x *= 10;
    printf("global x is %d on exiting useGlobal\n", x);
}
