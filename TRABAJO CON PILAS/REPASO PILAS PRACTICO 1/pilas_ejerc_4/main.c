#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila origen;
    Pila destino;
    Pila descarte;
    inicpila(&origen);
    inicpila(&descarte);
    inicpila(&destino);
    int i=0;
    char control='s';
    while (control=='s' && i<5)
    {
        leer(&origen);
        printf("Desea seguir cargando la pila? s/n :");
        fflush(stdin);
        scanf("%i");
        i++;
    }
    printf("PILA ORIGEN");
    mostrar(&origen);
    while (!pilavacia(&origen))
    {
        apilar(&descarte,desapilar(&origen));
    }
    while (!pilavacia(&descarte))
    {
        apilar(&destino,desapilar(&descarte));
    }
    printf("PILA DESTINO");
    mostrar(&destino);
    return 0;
}
