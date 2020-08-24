#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("color A");
    float PrimerNota = 0;
    float SegundaNota = 0;
    float TercerNota = 0 ;
    float suma = 0;
    float promedio = 0;
    printf("Ingrese la primer nota : \n");
    scanf("%f",&PrimerNota);
    printf("Ingrese la primer nota : \n");
    scanf("%f",&SegundaNota);
    printf("Ingrese la primer nota : \n");
    scanf("%f",&TercerNota);
    suma=PrimerNota+SegundaNota+TercerNota;
    promedio=suma/3;
    printf("el promedio de las 3 notas es %0.2f : ",promedio);

    return 0;
}
