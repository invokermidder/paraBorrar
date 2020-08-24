#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
int main()
{
    system("color A");
    Pila modelo;
    Pila dada;
    Pila descarte1;
    Pila descarte2;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&descarte1);
    inicpila(&descarte2);
    srand(time(NULL));
    int cantidad=rand()%40;
    int i;
    for(i=0; i<cantidad; i++)
    {
        apilar(&modelo,rand()%20);
    }
    printf("PILA MODELO : ");
    mostrar(&modelo);
    for(i=0; i<cantidad; i++)
    {
        apilar(&dada,rand()%20);
    }
    printf("PILA DADA : ");
    mostrar(&dada);
    system("pause");
    while(!pilavacia(&dada))
    {
        if(tope(&dada) == tope(&modelo))
        {
            apilar(&descarte1,desapilar(&dada));
        }
        else
        {
            apilar(&descarte2,desapilar(&dada));
        }

    }
    printf("pila descarte1 : ");
    mostrar(&descarte1);
    printf("pila descarte2 : ");
    mostrar(&descarte2);
    system("pause");
    while(!pilavacia(&descarte2))
    {
        apilar(&dada,desapilar(&descarte2));
    }
    printf("\n");
    printf("PILA DADA SIN ELEMENTOS IGUALES AL TOPE DE MODELO : ");
    mostrar(&dada);

    return 0;
}
