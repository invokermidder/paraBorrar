#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    system("color A");
    Pila origen;
    Pila distinto;
    Pila aux;
    inicpila(&origen);
    inicpila(&distinto);
    inicpila(&aux);
    int i=0;
    char control='s';


    do
    {
        leer(&origen);
        printf("desea seguir cargando s/n? :");
        fflush(stdin);
        scanf("%i",&origen);
        i++;
    }
    while(control=='s' && i<5);
    system("cls");
    printf("PILA ORIGEN : ");
    mostrar(&origen);
    system("pause");
    while(!pilavacia(&origen))
    {

        if(tope(&origen) == 8 )
        {
            apilar(&aux,desapilar(&origen));
        }
        else
        {
            apilar(&distinto,desapilar(&origen));
        }

    }
    while(!pilavacia(&aux))
    {
        apilar(&origen,desapilar(&aux));
    }


    printf("PILA ORIGEN");
    mostrar(&origen);
    printf("PILA DISTINTO");
    mostrar(&distinto);
    return 0;
}
