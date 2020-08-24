#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
int main()
{
    Pila origen;
    Pila descarte;
    inicpila(&origen);
    inicpila(&descarte);
    leer(&origen);
    leer(&origen);
    leer(&origen);

    float suma=0;
    float promedio;
    while(!pilavacia(&origen))
    {
        suma=suma+tope(&origen);
        apilar(&descarte,desapilar(&origen));
    }
    while (!pilavacia(&descarte))
    {
        apilar(&origen,desapilar(&descarte));
    }
    mostrar(&origen);
    system("pause");
    promedio=suma/3;
    printf("el promedio es %0.2f ",promedio);

    return 0;
}
