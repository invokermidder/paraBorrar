#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h" ///es importante crear la biblioteca de time para poder usar la carga random ///

int main()
{
    Pila modelo;
    inicpila(&modelo);
    srand(time(NULL));
    int cantidad=rand()%40; /// para darle la cantidad de elementos a la pila de 1 a 40 elementos ///
    int i;
    for (i=0;i<cantidad;i++)
    {
        apilar(&modelo,(rand()%100)+1); /// aca le da el valor a cada elemento de 1 a 100 por ejemplo ///
    }
    mostrar(&modelo);
    return 0;
}
