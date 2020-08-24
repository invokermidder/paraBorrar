#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    system("color A");
    Pila dada;
    Pila aux1;
    Pila aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    int  i=0;
    char control='s';
    do
    {
        leer(&dada);
        printf("Desea seguir cargando? s/n :");
        fflush(stdin);
        scanf("%d",&dada);
        i++;
    }
    while(i<5 && control=='s');
    printf("PILA DADA : ");
    mostrar(&dada);
    system("pause");
    while(!pilavacia(&dada))
    {
        apilar(&aux1,desapilar(&dada));
    }
    apilar(&aux2,desapilar(&aux1));
    while(!pilavacia(&aux1))
    {
        apilar(&dada,desapilar(&aux1));
    }
    apilar(&dada,desapilar(&aux2));
    printf("PILA DADA CON LA BASE EN EL TOPE : ");
    mostrar(&dada);



    return 0;
}
