#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila origen;
    Pila aux1;
    Pila aux2;
    inicpila(&origen);
    inicpila(&aux1);
    inicpila(&aux2);
    int i=0;
    char letra='s';
    while(letra=='s' && i<5)
    {
        leer(&origen);
        printf("Desea seguir cargando ? s/n : ");
        fflush(stdin);
        scanf("%i",&origen);
        i++;
    }
    printf("PILA ORIGEN :");
    mostrar(&origen);
    apilar(&aux1,desapilar(&origen));

    while (!pilavacia(&origen))
    {
        apilar(&aux2,desapilar(&origen));
    }
    /*printf("pila aux1: ");
    mostrar(&aux1);
    printf("pila aux2 : ");
    mostrar(&aux2);*/
    apilar(&origen,desapilar(&aux1));
    while(!pilavacia(&aux2))
    {
        apilar(&origen,desapilar(&aux2));
    }
    printf("PILA ORIGEN CON TOPE EN LA BASE : ");
    mostrar(&origen);
    return 0;
}
