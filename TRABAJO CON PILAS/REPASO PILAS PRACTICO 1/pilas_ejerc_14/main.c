#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "conio.h"
#include "pila.h"

int main()
{
    system("color E");
    Pila dada;
    Pila aux;
    Pila par;
    Pila impar;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    srand(time(NULL));

    int i;
    int valores=rand()%20;

    for(i=0; i<valores; i++)
    {
        apilar(&dada,rand()%50);
    }
    printf("pila dada : ");
    mostrar(&dada);
    system("pause");

    while(!pilavacia(&dada))
    {
        apilar(&aux,desapilar(&dada));
        if(!pilavacia(&dada))
        {
            apilar(&aux,desapilar(&dada));
        }
        else
        {
            apilar(&impar,desapilar(&aux));
        }
    }

    if(!pilavacia(&impar))
    {
        printf(" !!! la pila es impar !!! ");
        mostrar(&impar);
    }
    else
    {
        apilar(&par,desapilar(&aux));
        printf(" !!! la pila es par !!! ");
        mostrar(&par);
    }
    return 0;
}
