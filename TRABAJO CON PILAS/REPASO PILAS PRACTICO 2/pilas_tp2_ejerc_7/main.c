#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
int main()
{
    system("color A");
    Pila cargada;
    Pila descarte;
    Pila elemento;
    Pila encontrado;
    inicpila(&encontrado);
    inicpila(&cargada);
    inicpila(&descarte);
    inicpila(&elemento);
    apilar(&elemento,5);
    srand(time(NULL));
    int i;
    int valores=rand()%20;
    int flag=0;

    for(i=0; i<valores; i++)
    {
        apilar(&cargada,rand()%10);
    }
    printf("PILA CARGADA : ");
    mostrar(&cargada);
    printf("PILA ELEMNTO : ");
    mostrar(&elemento);
    system("pause");

    while(!pilavacia(&cargada))
    {
        if(tope(&cargada) == tope(&elemento))
        {

            apilar(&encontrado,desapilar(&cargada));

        }
        else
        {

            apilar(&descarte,desapilar(&cargada));

        }

    }
    if(tope(&encontrado)==tope(&elemento))
    {
        flag=1;
        printf("EL ELEMENTO SE ENCUENTRA EN LA PILA !!!! ");
    }else
    {
        flag=0;
        printf("EL ELEMENTO NOOO SE ENCUENTRA EN LA PILA PAPU SEGUI PARTICIPANDO !!! ");
    }
    while(!pilavacia(&descarte))
    {
        apilar(&cargada,desapilar(&descarte));
    }
    apilar(&cargada,desapilar(&encontrado));

    printf("\n");

    printf("PILA CARGADA : ");
    mostrar(&cargada);

    return 0;
}
