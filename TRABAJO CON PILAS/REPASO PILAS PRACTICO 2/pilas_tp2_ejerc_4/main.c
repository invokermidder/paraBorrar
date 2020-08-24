#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int main()
{
    Pila comun;
    Pila menor;
    Pila descarte;
    //Pila descarte2;

    inicpila(&comun);
    inicpila(&menor);
    //inicpila(&descarte2);
    inicpila(&descarte);
    srand(time(NULL));
    int i;
    int valor=rand()%50;
    for (i=0;i<valor;i++)
    {
        apilar(&comun,rand()%100);
    }
    mostrar(&comun);
    system("pause");
    apilar(&menor,desapilar(&comun));
    while(!pilavacia(&comun))
    {
        if(tope(&comun)< tope(&menor))
        {
            apilar(&descarte,desapilar(&menor));
            apilar(&menor,desapilar(&comun));
        }else
        {
            apilar(&descarte,desapilar(&comun));
        }
    }
    while (!pilavacia(&descarte))
    {
        apilar(&comun,desapilar(&descarte));
    }

    printf("PILA CON MENOR ELEMENTO : ");
    mostrar(&menor);

    printf("PILA COMUN : ");
    mostrar(&comun);
    return 0;
}
