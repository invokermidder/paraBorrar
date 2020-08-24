#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
#include "conio.h"
/// EJERCICIO NRO 13 DE PILAS
/// Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.
int main()
{
    system("COLOR A");
    Pila limite,dada,mayores,menores;
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);
    srand(time(NULL));
    int i;
    int valores=rand()%10;
    for(i=0;i<valores;i++)
    {
        apilar(&limite,rand()%100);
    }

    for(i=0;i<valores;i++)
    {
        apilar(&dada,rand()%100);
    }
    printf("pila limite : ");
    mostrar(&limite);
    printf("pila dada : ");
    mostrar(&dada);
    system("pause");
    while(!pilavacia(&dada))
    {
        if(tope(&dada)>= tope(&limite))
        {
            apilar(&mayores,desapilar(&dada));
        }else
        {
            apilar(&menores,desapilar(&dada));
        }
    }
    printf("pila mayores : ");
    mostrar(&mayores);
    printf("pila menores : ");
    mostrar(&menores);

    return 0;
}
