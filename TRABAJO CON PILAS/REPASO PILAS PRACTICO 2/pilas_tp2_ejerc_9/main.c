#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
int main()
{
        Pila dada;
    Pila aux1, aux2, aux3;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);

// apilamos elementos para provar su "capicues" :p

    apilar(&dada, 1);
    //apilar(&dada, 2);
    apilar(&dada, 2);
    apilar(&dada, 3);
    apilar(&dada, 2);
    apilar(&dada, 1);

    mostrar(&dada);

////////////////////////////////////////////////////////////
// VERSION ENROSCADA...
///////////////////////////////////////////////////////////

    // primero cuento los elementos
    int cuenta = 0;
    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
        cuenta++;
    }

    // paso a dada otra vez

    while(!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }


    int control = cuenta/2;

    int aux=0;

    // paso la mitad a aux1
    while(aux<control)
    {
        apilar(&aux1, desapilar(&dada));
        aux++;
    }

    // verifico q la pila sea impar,
    // si es asi... saco el valor que sobra
    if(cuenta%2!=0)
        apilar(&aux2, desapilar(&dada));

    // comparo los topes para constatar q sea capicua...
    // en dada me queda el resto de los elementos
    // en el mismo orden que en aux1
    while((!pilavacia(&dada)&&!pilavacia(&aux1))&&(tope(&dada)==tope(&aux1)))
    {
        apilar(&aux3, desapilar(&dada));
        apilar(&aux3, desapilar(&aux1));
    }

    if (pilavacia(&dada)&&pilavacia(&aux1))
       printf("La pila es capicua\n");
    else
        printf("La pila no es capicua\n");



    return 0;
}
