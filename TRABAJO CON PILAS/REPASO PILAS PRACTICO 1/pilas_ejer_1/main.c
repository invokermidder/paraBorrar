#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    system("color A");
    Pila duracell;
    inicpila(&duracell);
    Pila aux1;
    Pila aux2;
    inicpila(&aux1);
    inicpila(&aux2);

    int i=0;
    char letra='s';
    do
    {
        leer(&duracell);
        printf("desea seguir cargando ? s/n : ");
        fflush(stdin);
        scanf("%d",&duracell);
        i++;
    }while(i<5 && letra=='s');
    printf("PILA DURACELL \n");
    mostrar(&duracell);
    while (!pilavacia(&duracell))
    {
        ///if(tope(&aux1)<3)
        apilar(&aux1,desapilar(&duracell));
        ///apilar(&aux2,desapilar(tope(&aux1)));

    }
    apilar(&aux2,desapilar(&aux1));  /// FORMA PEDORRA ///
    apilar(&aux2,desapilar(&aux1));  /// FORMA PEDORRA ///
    printf("PILA AUX1 \n");
    mostrar(&aux1);
    printf("PILA AUX2 \n");
    mostrar(&aux2);
    return 0;
}
