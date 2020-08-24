#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int main()
{
    Pila santi;
    Pila aux1;
    Pila aux2;

    inicpila(&santi);
    inicpila(&aux1);
    inicpila(&aux2);

    srand(time(NULL));
    apilar(&santi,1);
    apilar(&santi,3);
    apilar(&santi,5);
    apilar(&santi,7);
    apilar(&santi,9);
    leer(&aux1);

    printf("PILA SANTI : ");
    mostrar(&santi);
    printf("PILA AUX1 : ");
    mostrar(&aux1);
    system("pause");
    while(!pilavacia(&santi) && tope(&santi)>tope(&aux1) )
    {
        apilar(&aux2,desapilar(&santi));
    }
    if(!pilavacia(&aux1))
    {
        apilar(&santi,desapilar(&aux1));
    }
    while(!pilavacia(&aux2))
    {
        apilar(&santi,desapilar(&aux2));
    }
    mostrar(&santi);
    return 0;
}
