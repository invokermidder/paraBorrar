#include <stdio.h>
#include <stdio.h>
#include "../pila.h"


int main ()
{

    Pila a, b;
    inicpila(&a);
    inicpila(&b);

    apilar(&a, 1);
    apilar(&a, 2);
    apilar(&a, 3);
    apilar(&a, 4);
    apilar(&a, 5);

    apilar(&b, 1);
    apilar(&b, 3);
    apilar(&b, 6);
    apilar(&b, 5);
    apilar(&b, 4);

    printf("Pila a\n");
    mostrar(&a);

    printf("Pila b\n");
    mostrar(&b);

    Pila destino;
    inicpila(&destino);



    Pila aux, descarte;
    inicpila(&aux);
    inicpila(&descarte);

    while(!pilavacia(&a))
    {
        while(!pilavacia(&b))
        {
            if (tope(&a)==tope(&b))
                apilar(&descarte, desapilar(&b));
            else
                apilar(&aux, desapilar(&b));
        }

        apilar(&destino, desapilar(&a));

        while (!pilavacia(&aux))
        {
            apilar(&b, desapilar(&aux));
        }

    }

    while(!pilavacia(&b))
    {
        apilar(&destino, desapilar(&b));
    }


    printf("Pila destino\n");
    mostrar(&destino);

    printf("Pila a\n");
    mostrar(&a);

    printf("Pila b\n");
    mostrar(&b);
    return 0;
}
