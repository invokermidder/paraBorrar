#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
int menu();
void carga_pila (Pila *P);
void imprime_1();
void imprime_2();


int main()
{
    Pila dada;
    inicpila(&dada);
    int select;

    do
    {
        select=menu();
        switch(select)
        {
        case 1 :
            //printf("\b");
            carga_pila(&dada);
            mostrar(&dada);
            printf("\n");
            system("pause");
            break;
        case 2 :
            imprime_1();
            printf("\n");
            system("pause");
            break;
        case 3 :
            imprime_2();
            printf("\n");
            system("pause");
            break;
        case 0 :
            printf("\n\n EL PROGRAMA TERMINO DE EJECUTARSE !");
        }
    }
    while(select!=0);
    system("pause");
    return 0;
}
int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Agrega elementos a Pila");
    printf("\n2-Pasa elemento de una pila a otra");
    printf("\n3-Pasa elementos de una pila a otra (conserva el orden)");
    printf("\n4-Retorna el menor elemento de una lista");
    printf("\n5-Pasa elementos de una pila a otra y genera una nueva pila ordenada");
    printf("\n6-Inserta un elemento en una pila ordenada (conserva el orden)");
    printf("\n7-Pasa los elementos de una pila a otra, genera una ordenada (usa funcion 6)");
    printf("\n8-Suma y retorna primeros 2 elementos de una pila,sin alterar su contenido");
    printf("\n9-Calcula promedio de una pila (usa funcion de suma, division y cuenta)");
    printf("\n10-Recibe pila con numeros de un digito y los transforma en un numero decimal");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;

}
void carga_pila (Pila *P)
{
    int i=0;
    int cantidad=0;
    printf("\nIngrese la cantidad de elementos a cargar en su pila :\n");
    scanf("%d",&cantidad);
    char control='s';
    do
    {
        leer(P);
        printf("Desea continuar? s/n \n:");
        fflush(stdin);
        scanf("%c",&control);
        i++;
    }
    while(control=='s' && i<cantidad);
}
void imprime_1()
{
    printf("Aqui deberia estar la funcion 2 :");
}
void imprime_2()
{
    printf("Aqui deberia estar la funcion 3 : ");
}
