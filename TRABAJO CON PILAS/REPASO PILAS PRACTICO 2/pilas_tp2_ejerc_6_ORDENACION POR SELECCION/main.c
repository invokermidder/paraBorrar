#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int main()
{
    system("color A ");
    Pila dada;
    Pila menor;
    Pila aux;
    Pila ordenada;
    inicpila(&dada);
    inicpila(&menor);
    inicpila(&aux);
    inicpila(&ordenada);
    srand(time(NULL));
    int i;
    int valores=rand()%40;

    for(i=0;i<valores;i++)
    {
        apilar(&dada,rand()%100);
    }
    printf("pila dada : ");
    mostrar(&dada);
    system("pause");


    while(!pilavacia(&dada))
    {
        apilar(&menor,desapilar(&dada));
        while(!pilavacia(&dada) )
        {
            if(tope(&menor)>tope(&dada))
            {
                apilar(&aux,desapilar(&menor));
                apilar(&menor,desapilar(&dada));
            }
            else
            {
                apilar(&aux,desapilar(&dada));
            }
        }
        while (!pilavacia(&aux))
        {
            apilar(&dada,desapilar(&aux));
        }
        apilar(&ordenada,desapilar(&menor));


    }

    printf("pila dada : ");
    mostrar(&dada);
    printf("pila ordenada : ");
    mostrar(&ordenada);
    return 0;
}
