#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
//////////////////////////////////////////////////////////////////////////////
    /* 1) Sumar los elementos de una pila (usar variables)*/

    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    int suma=0;

    while (!pilavacia(&dada))
    {
        suma = suma + tope(&dada);
        apilar(&aux, desapilar(&dada));
    }

    // paso los elementos de aux a dada
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    mostrar(&dada);
    printf("La suma de los elementos de dada es %d\n", suma);

//////////////////////////////////////////////////////////////////////////////
    // 2) Contar los elementos de una pila (usar variables)

    int cuenta=0;

    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
        cuenta++;
    }

    // paso los elementos de aux a dada
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("La cantidad de elementos que contiene dada es %d\n", cuenta);

//////////////////////////////////////////////////////////////////////////////
    //3) Calcular el promedio de los valores de una pila (usar variables)
    float promedio = 0;
    promedio = (float) suma/ (float) cuenta;

    printf("Y el promedio de dada es %.2f \n", promedio);

//////////////////////////////////////////////////////////////////////////////
    //4) Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables)

    Pila menor;
    inicpila(&menor);

    if (!pilavacia(&dada))
        apilar(&menor, desapilar(&dada));

    while(!pilavacia(&dada))
    {
        if(tope(&menor)>tope(&dada))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&dada));
        }
        else
            apilar(&aux, desapilar(&dada));
    }

    // paso los elementos de aux a dada
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("Pila dada ahora");
    mostrar(&dada);
    printf("Menor elemento de dada");
    mostrar(&menor);

//////////////////////////////////////////////////////////////////////////////
    //5) Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
    //   que se conserve el orden. (sin variables) */

    Pila ordenada, nuevoElemento;
    inicpila(&ordenada);
    inicpila(&nuevoElemento);


    apilar(&ordenada, 8);
    apilar(&ordenada, 6);
    apilar(&ordenada, 4);
    apilar(&ordenada, 2);
    apilar(&ordenada, 1);

    leer(&nuevoElemento);

    while (!pilavacia(&ordenada)&&tope(&ordenada)<tope(&nuevoElemento))
    {
        apilar(&aux, desapilar(&ordenada));
    }

    apilar(&ordenada, desapilar(&nuevoElemento));

    while (!pilavacia(&aux))
    {
        apilar(&ordenada, desapilar(&aux));
    }

    printf("\nPila ordenada ahora\n");
    mostrar(&ordenada);


//////////////////////////////////////////////////////////////////////////////
    // 6) Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
    //    la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
    //    ordenación por selección.

    Pila ordenadaXseleccion;

    inicpila(&ordenadaXseleccion);


    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    while (!pilavacia(&dada))
    {
        // saco el 1er elemento de la pila
        apilar(&menor, desapilar(&dada));

        // comparo con el resto de la pila
        while(!pilavacia(&dada))
        {
            if(tope(&menor)>tope(&dada))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else
                apilar(&aux, desapilar(&dada));
        }

        // paso lo q queda otra vez a dada
        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }

        // apilo el menor elemento en la pila correspondiente
        apilar(&ordenadaXseleccion, desapilar(&menor));
    } -+*

    printf("Pila dada\n");
    mostrar(&dada);

    printf("Pila ordenada x seleccion\n");
    mostrar(&ordenadaXseleccion);

//////////////////////////////////////////////////////////////////////////////
    // 7) Determinar si un elemento buscado está dentro de una pila

    apilar(&dada, 11);
    apilar(&dada, 14);
    apilar(&dada, 3);
    apilar(&dada, 7);
    apilar(&dada, 5);
    apilar(&dada, 3);
    apilar(&dada, 4);
    apilar(&dada, 6);

    int flag;
    int elemento =0;

    printf("Ingrese un elemento a buscar en la pila dada: ");
    scanf("%d", &elemento);

    while (!pilavacia(&dada)&&tope(&dada)!=elemento)
    {
        apilar(&aux, desapilar(&dada));
        flag = 0;
    }

    if (tope(&dada)== elemento)
        flag=1;

    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    if(flag==1)
        printf("\nEl elemento %d se encuentra en la pila dada", elemento);
    else
        printf("\nEl elemento %d no se encuentra en la pila dada", elemento);

    printf("\nPila dada");
    mostrar(&dada);

//////////////////////////////////////////////////////////////////////////////
    //   8) Eliminar un elemento de una pila.

    Pila descarte;
    inicpila(&descarte);

    printf("Ingrese un elemento a eliminar en la pila dada: ");
    scanf("%d", &elemento);

// recorro la pila mientras no se vacie y no encuentre el elemento
    while (!pilavacia(&dada)&&tope(&dada)!=elemento)
    {
        apilar(&aux, desapilar(&dada));
    }

    // si la pila no se vacio
    // es porque el while anterior "corto" por la segunda condicion
    // osea que el elemento que esta en el tope de dada es el que buscamos
    if(!pilavacia(&dada))
    {
        // lo sacamos
        apilar(&descarte, desapilar(&dada));
    }

    while (!pilavacia(&aux))
    {
        // y volvemos a poner todo el resto en dadad
        apilar(&dada, desapilar(&aux));
    }

    printf("\nPila dada");
    mostrar(&dada);

    printf("\nPila descarte");
    mostrar(&descarte);

    //

    return 0;
}
