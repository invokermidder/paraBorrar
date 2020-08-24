#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

void Carga_pila (Pila *P, int *x);
void Pasa_pila (Pila *P, Pila *X);
void Ord_pila (Pila *X,Pila *D);
int Retorna_Menor (Pila *cuatro);
void Nueva_ordenada (Pila *lol,Pila *lel);
int Suma_dos_elementos (Pila *P);
void carga_random (Pila *P);
float suma_elementos (Pila *P);
int cuenta_elementos (Pila *P);
float calcula_promedio (Pila *P);
void karga_pila (Pila *P);

int main()
{
    system("color A");
    Pila dada;
    inicpila(&dada);
    int validos=0;
    printf("Ingrese la cantidad de elementos que desea cargar en la pila : ");
    scanf("%d",&validos);

    printf("\n Cargando pila...\n  ");
    printf("\n\n");

    Carga_pila(&dada,validos); /// PRIMER EJERCICIO CARGAR UNA PILA ///
    mostrar(&dada);
    system("pause");


    printf("\n \n PASA PILA : "); /// PASAR PILA ///
    printf("\n");
    Pila pasada;
    inicpila(&pasada);
    Pasa_pila(&dada,&pasada);
    printf("PILA PASADA : ");
    mostrar(&pasada);
    system("pause");


    printf("\n \n ORDENAR PILA : "); /// ORDENAR LA PILA ///
    printf("\n");
    Pila nueva;
    inicpila(&nueva);
    Ord_pila(&pasada,&nueva);
    printf("PILA NUEVA : ");
    mostrar(&nueva);
    system("pause");

    printf("\n\n RETORNA MENOR : ");
    printf("\n");
    Pila duracel;
    inicpila(&duracel);
    apilar(&duracel,3);
    apilar(&duracel,14);
    apilar(&duracel,11);
    apilar(&duracel,77);

    mostrar(&duracel);

    printf("EL MENOR ELEMENTO DE LA PILA ES : %d \n\n ",Retorna_Menor(&duracel));

    system("pause");

    printf("\n\n Nueva Pila ordenada : ");
    Pila ordenada;
    inicpila(&ordenada);
    Nueva_ordenada(&duracel,&ordenada);
    printf("PILA ORDENADA : ");
    mostrar(&ordenada);
    system("pause");

    printf("\n\n Sumas el tope y el anterior de una pila : ");
    Pila prueba;
    inicpila(&prueba);
    apilar(&prueba,5);
    apilar(&prueba,20);
    apilar(&prueba,77);
    apilar(&prueba,41);
    printf("PILA PRUEBA : ");
    mostrar(&prueba);

    int sumita=Suma_dos_elementos(&prueba);
    mostrar(&prueba);
    printf("\n\n la suma de los dos elementos es : %d ",sumita);
    printf("\n\n");
    system("pause");
    printf("\n\n");
    printf("EJERCICIO 9 , CARGA,SUMA,CUENTA Y PROMEDIA LOS ELEMENTOS DE UNA PILA : \n");

    Pila dadda;
    inicpila(&dadda);
    carga_random(&dadda);
    printf("PILA RANDOM : ");
    mostrar(&dadda);
    float zuma1=suma_elementos(&dadda);
    printf("LA SUMA DE SUS ELEMENTOS ES : %0.2f ",zuma1);

    int validos1=cuenta_elementos(&dadda);
    printf("\n\n LA PILA TIENE %d ELEMENTOS !\n\n",validos1);

    float promedio=calcula_promedio(&dadda);
    printf("EL PROMEDIO DE SUS ELEMENTOS ES : %0.3f",promedio);
    system("pause");
    printf("\n\n");
    printf("EJERCICIO 10 PASAR DE ENTERO A DECIMAL : \n\n");
    Pila entera;
    inicpila(&entera);
    karga_pila(&entera);
    printf("PILA ENTERA : ");
    mostrar(&entera);

    return 0;
}
void Carga_pila (Pila *P, int *x) /// FUNCION PARA CARGAR UNA PILA ///
{
    int i=0;
    char control='s';
    do
    {
        leer(P);
        printf("Ingrese un valor : ");
        fflush(stdin);
        i++;
        printf("Desea seguir cargando la pila ? s/n \n");
        fflush(stdin);
        scanf("%c",&control);

    }
    while((control == 's') && (i<x));


}
void Pasa_pila (Pila *P, Pila *X) /// FUNCION PARA PASAR LOS ELEMENTOS DE UNA PILA A LA OTRA ///
{

    while(!pilavacia(P))
    {
        apilar(X,desapilar(P));
    }

}
void Ord_pila (Pila *X,Pila *D) /// PASAR LOS ELEMNTOS DE UNA PILA DE MANERA TAL QUE QUEDEN ORDENADOS ///
{
    while(!pilavacia(X))
    {
        apilar(D,desapilar(X));
    }
}
int Retorna_Menor (Pila *cuatro) /// FUNCION QUE RETORNA EL MENOR ELEMENTO DE UNA PILA ///
{
    Pila aux1;
    Pila menor;
    inicpila(&aux1);
    inicpila(&menor);


    apilar(&menor,desapilar(cuatro));
    while(!pilavacia(cuatro))
    {
        if(tope(cuatro)<tope(&menor))
        {
            apilar(&aux1,desapilar(&menor));
            apilar(&menor,desapilar(cuatro));

        }
        else
        {
            apilar(&aux1,desapilar(cuatro));
        }
    }
    while(!pilavacia(&aux1))
    {
        apilar(cuatro,desapilar(&aux1));
    }


    return tope(&menor);
}
void Nueva_ordenada (Pila *lol,Pila *lel) /// FUNCION QUE GENERA UNA PILA ORDENADA UTILIZANDO LA PILA DEL EJERCICIO ANTERIOR ///
{
    Pila aux1;
    inicpila(&aux1);
    while(!pilavacia(lol))
    {
        apilar(&aux1,Retorna_Menor(lol));
    }
    while(!pilavacia(&aux1))
    {
        apilar(lel,desapilar(&aux1));
    }
}
int Suma_dos_elementos (Pila *P) /// FUNCION QUE SUMA EL TOPE Y EL ANTERIOR AL TOPE...  FALTA ULTIMAR DETALLES//
{
    Pila aux1;
    Pila aux2;
    inicpila(&aux2);
    inicpila(&aux1);
    int x=0;
    int i=0;
    while(!pilavacia(P) && i<2)
    {
        x=x+tope(P);
        apilar(&aux1,desapilar(P));
    }



    while(!pilavacia(&aux1))
    {
        apilar(P,desapilar(&aux1));

    }


    return x;
}

/// LAS SIGUIENTES 4 FUNCIONES CALCULAN EL PROMEDIO DE LOS ELEMENTOS DE UNA PILA ///

void carga_random (Pila *P)
{
    srand(time(NULL));
    int i;
    int valores=rand()%10;
    for(i=0;i<valores;i++)
    {
        apilar(P,rand()%100);
    }
}
float suma_elementos (Pila *P)
{
    int sumar=0;
    Pila aux1;
    inicpila(&aux1);
   while(!pilavacia(P))
   {
       sumar=sumar+tope(P);
       apilar(&aux1,desapilar(P));
   }
   while(!pilavacia(&aux1))
   {
       apilar(P,desapilar(&aux1));
   }
    return sumar;
}

int cuenta_elementos (Pila *P)
{
   int kuenta=0;
   int contador=0;
   Pila aux1;
   inicpila(&aux1);
   while(!pilavacia(P))
   {
       apilar(&aux1,desapilar(P));
       contador++;
   }
    while(!pilavacia(&aux1))
    {
        apilar(P,desapilar(&aux1));
    }

    return contador;
}


float calcula_promedio (Pila *P)
{
    float promedio=0;
    promedio=suma_elementos(P)/cuenta_elementos(P);

    return promedio;
}
void karga_pila (Pila *P)
{
    int i=0;
    int cantidad=0;
    char continuar='s';
    printf("Ingrese la cantidad de elementos que quiere cargar en la pila : ");
    scanf("%d",&cantidad);
    do
    {
      leer(P);
      printf("Desea continuar?");
      fflush(stdin);
      i++;
      printf("Para continuar presione s :\n");
      scanf("%c",&continuar);
    }while(i<cantidad && continuar=='s');
}
