#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("color A");
    int nro_A = 0;
    int nro_B = 0;
    int resultado = 0;
    printf("Ingrese un numero : \n");
    scanf("%d",&nro_A);
    printf("Ingrese otro numero : \n");
    scanf("%i",&nro_B);

    resultado=nro_A+nro_B;
    printf("El resultado de su suma es %d : \n",resultado);
    printf("\n\n");
    system("pause");
    return 0;
}
