#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("color 1C");
    int numero=0;
    printf("Ingrese un numero : ");
    scanf("%d",&numero);

    switch(numero)
    {
        case 1 : printf("EJERCICIO 1 ");break;
        case 2 : printf("EJERCICIO 2  ");break;
        default : printf("Ingreso una opcion incorrecta : ");

    }
    return 0;
}
