#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
#include "conio.h"

int main()
{
    system("color A");
    Pila modelo,dada,aux1,aux2,aux3;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);


    apilar(&modelo,1);
    apilar(&modelo,3);
    apilar(&modelo,5);

    int i=0;
    char control='s';

    do
    {
        leer(&dada);
        printf("Desea seguir cargando? si/no : ");
        fflush(stdin);
        scanf("%d",&dada);
        i++;
    }
    while (control =='s' && i<3 );
    printf("PILA DADA : ");
    mostrar(&dada);
    printf("PILA MODELO : ");
    mostrar(&modelo);
    system("pause");

    while(!pilavacia(&modelo) && !pilavacia(&dada))
    {

        apilar(&aux1,desapilar(&modelo));
        if(tope(&aux1)==tope(&dada))
        {
            apilar(&aux2,desapilar(&dada));

        }
        else
        {
            apilar(&aux3,desapilar(&dada));
        }


    }

    printf("PILA MODELO : ");
    mostrar(&modelo);
    printf("PILA AUX1 : ");
    mostrar(&aux1);
    printf("PILA AUX2 : ");
    mostrar(&aux2);
    printf("PILA AUX3 : ");
    mostrar(&aux3);
    printf("PILA DADA SIN ELEMENTOS IGUALES A MODELO : ");
    mostrar(&dada);
    return 0;
}
