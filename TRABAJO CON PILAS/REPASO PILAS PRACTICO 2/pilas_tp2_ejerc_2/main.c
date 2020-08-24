#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
/// EJERCICIO NRO 2 DE PILAS - PRACTICO 2- ///
int main()
{
    Pila elemnto;
    Pila descarte;
    inicpila(&elemnto);
    inicpila(&descarte);
    leer(&elemnto);
    leer(&elemnto);
    leer(&elemnto);
    leer(&elemnto);
    leer(&elemnto);

    int validos=0;

    while (!pilavacia(&elemnto))
    {
        apilar(&descarte,desapilar(&elemnto));
        validos++;
    }
    while(!pilavacia(&descarte))
    {
        apilar(&elemnto,desapilar(&descarte));
    }
    printf("PILA ELEMENTO : ");
    mostrar(&elemnto);

    printf("la pila tiene %d elementos ", validos);
    return 0;
}
