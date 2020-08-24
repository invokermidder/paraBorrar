#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    system("color E");
    Pila A;
    Pila B;
    Pila aux1;
    Pila aux2;

    inicpila(&A);
    inicpila(&B);
    inicpila(&aux1);
    inicpila(&aux2);


    apilar(&A,1);
    apilar(&A,2);
    apilar(&A,3);

    apilar(&B,4);
    apilar(&B,5);
    apilar(&B,6);
    apilar(&B,6);


    mostrar(&A);
    mostrar(&B);
    while(!pilavacia(&A))
    {
        apilar(&aux1,desapilar(&A));
    }
    printf("PILA A : ");
    mostrar(&A);
    while(!pilavacia(&B))
    {
        apilar(&aux2,desapilar(&B));
    }
    printf("PILA B : ");
    mostrar(&B);
    /*apilar(&A,desapilar(&aux2));*/
    if(pilavacia(&A) == pilavacia(&B))
    {
        printf("\n");
        printf("las pilas tienen la misma cantidad de elementos!!! ");
        printf("\n");
    }
    else
    {
        printf("las pilas NO tienen la misma cantidad de elementos");
    }
    printf("\n\n");
    system("pause");


    return 0;
}
