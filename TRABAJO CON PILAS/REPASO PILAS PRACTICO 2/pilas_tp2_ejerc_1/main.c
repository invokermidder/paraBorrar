#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int main()
{
    Pila dada;
    Pila descarte;

    inicpila(&dada);
    inicpila(&descarte);

    srand(time(NULL));
    int i;
    int valores=rand()%100;
    int suma=0;
    for(i=0;i<valores;i++)
    {
        apilar(&dada,rand()%100);
    }
    mostrar(&dada);
    system("pause");
    while(!pilavacia(&dada))
    {
        suma=suma+tope(&dada);
        apilar(&descarte,desapilar(&dada));

    }
    while(!pilavacia(&descarte))
    {
        apilar(&dada,desapilar(&descarte));
    }
    printf("la suma de los elementos de dada es %d  ", suma);
    printf("\n");
    return 0;
}
