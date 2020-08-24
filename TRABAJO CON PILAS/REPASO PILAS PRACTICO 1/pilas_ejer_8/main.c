#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    system("color E");
    Pila mazo;
    Pila jugador1;
    Pila jugador2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    int i=0;
    char control='s';
    do
    {
        leer(&mazo);
        printf("Desea seguir cargando? s/n : ");
        fflush(stdin);
        scanf("%d",&mazo);
        i++;
    }

    while(i<10 && control=='s');
    printf("PILA MAZO : ");
    mostrar(&mazo);

    while(!pilavacia(&mazo))
    {
        apilar(&jugador1,desapilar(&mazo));
        apilar(&jugador2,desapilar(&mazo));
    }
    printf("PILA JUGADOR 1 :");
    mostrar(&jugador1);
    printf("PILA JUGADOR 2 : ");
    mostrar(&jugador2);
    system("pause");
    return 0;
}
