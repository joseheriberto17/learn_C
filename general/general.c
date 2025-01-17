#include <stdio.h>

struct cuenta
{
    int idCuenta;
    float valor;
    char *nombre;
    long cell;
}usuario;



int main(){
    //inicializado valores
    usuario.idCuenta =21;
    usuario.valor = 5000;
    usuario.nombre = "jose heriberto";
    usuario.cell = 3126849682;
    
    printf("%s",usuario.nombre);

    return 0;
}