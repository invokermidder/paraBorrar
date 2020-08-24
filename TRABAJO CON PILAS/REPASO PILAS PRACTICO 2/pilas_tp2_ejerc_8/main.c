#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    system("color E");
    Pila origen;
    Pila descarte;
    Pila aux1;

    inicpila(&origen);
    inicpila(&descarte);
    inicpila(&aux1);

    srand(time(NULL));
    int i;
    int valores=rand()%10;
    int elemento=0;

    printf("Ingrese un valor para comprar y eliminar : \n");
    scanf("%d",&elemento);
    for(i=0; i<valores; i++)
    {
        apilar(&origen,rand()%10);
    }
    printf("PILA ORIGEN : ");
    mostrar(&origen);
    system("pause");
    while(!pilavacia(&origen))
    {
        if(tope(&origen)==elemento)
        {
            apilar(&descarte,desapilar(&origen));

        }
        else
        {
            apilar(&aux1,desapilar(&origen));

        }
    }
    while(!pilavacia(&aux1))
    {
        apilar(&origen,desapilar(&aux1));
    }
    mostrar(&origen);




    return 0;
}
