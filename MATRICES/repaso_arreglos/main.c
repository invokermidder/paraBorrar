#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
const int git=50;
int CargaArreglo (int A[],int dim);
void muestraArregloInt (int A[],int dim);
int enterosRandom (int A[],int dim);
int posicionMenor (int A[],int pos,int c);
void ordenaXseleccion (int A[],int dim);
int BuscaDato (int A[],int dim,int dato);
int agregaElemento (int A[],int dim,int elemento);
int sumaElementos (int A[],int dim);
int cantElemnt (int A[],int dim);
float calculaPromedio (int A[],int dim);
char cargaStrings (char C[],int dim);
int Capicua (int A[],int dim);

int main()
{
    int flag=0;
    int kpicua[5]= {1,2,3,2,1};
    flag=Capicua(kpicua,5);
    if(flag==1)
    {
        printf("\n El No arreglo es capicua ");
    }
    else
    {
        printf("\n  es capicua");
    }
//    int dimension=0;
//   int   Arreglo[50];
//   int dato=14;
//   int data=6;
//
//    dimension=CargaArreglo(Arreglo,50);
//    muestraArregloInt(Arreglo,dimension);
//       int sumita=sumaElementos(Arreglo,dimension);
//    printf("\nla suma de sus elementos es %d ",sumita);
//    dimension=cantElemnt(Arreglo,dimension);
//    printf("\nel arreglo tiene %d elementos ",dimension);
//    float promedio=calculaPromedio(Arreglo,dimension);
//    printf("\n El promedio de sus elementos es %0.2f ",promedio);
//    printf("\n");
//    system("pause");
//    int Rancho[git];
//    dimension=enterosRandom(Rancho,git);
//    muestraArregloInt(Rancho,dimension);
//    ordenaXseleccion(Rancho,dimension);
//    muestraArregloInt(Rancho,dimension);
//     agregaElemento(Rancho,dimension,data);
//    muestraArregloInt(Rancho,dimension+1);
//     BuscaDato(Rancho,dimension,dato);
//     char NombreYapellido[100];
//     dimension=cargaStrings(NombreYapellido,100);
//     muestraStrings(NombreYapellido,dimension);
    return 0;
}
int CargaArreglo (int A[],int dim)
{
    int i=0;
    char control='s';
    while(i<dim && control=='s' || control=='S')
    {
        printf("Ingrese un elemento al arreglo : ");
        fflush(stdin);
        scanf("%d",&A[i]);
        i++;
        printf("Para continuar [s] para salir presione otra tecla : ");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}
void muestraArregloInt (int A[],int dim)
{
    system("cls");
    int i;
    for(i=0; i<dim; i++)
    {

        if(i%5==0)
        {
            printf("\n");
        }
        printf("[%d]",A[i]);
    }
    printf("\n");
    system("pause");
}
int enterosRandom (int A[],int dim)
{
    srand(time(NULL));
    int i;
    dim=rand()%30;
    for(i=0; i<dim; i++)
    {
        A[i]=rand()%100;
    }
    return i;
}
int posicionMenor (int A[],int pos,int c)
{
    int menor=A[pos];
    int posmenor=pos;
    int i=pos+1;
    while(i<c)
    {
        if(menor>A[i])
        {
            menor=A[i];
            posmenor=i;
        }
        i++;
    }
    return posmenor;
}
void ordenaXseleccion (int A[],int dim)
{
    int i=0;
    int posmenor=0;
    int aux=0;
    while(i<dim-1)
    {
        posmenor=posicionMenor(A,i,dim);
        aux=A[posmenor];
        A[posmenor]=A[i];
        A[i]=aux;
        i++;
    }
}
int BuscaDato (int A[],int dim,int dato)
{
    int i=0;
    int flag=0;
    while(i<dim && !flag)
    {
        if(dato==A[i])
        {
            flag=1;
        }
        i++;
    }
    if(flag==1)
    {
        printf("El dato %d se encuentra en el arreglo ",dato);
    }
    else
    {
        printf("El dato %d NO se encuentra en el arreglo ", dato);
    }

}
int agregaElemento (int A[],int dim,int elemento)
{
    int i=dim-1;
    while(i<dim && elemento<A[i])
    {
        A[i+1]=A[i];

        i--;
    }
    A[i+1]=elemento;
    return i+1;
}
int sumaElementos (int A[],int dim)
{
    int i;
    int suma=0;
    for(i=0; i<dim; i++)
    {
        suma +=A[i];
    }
    return suma;
}
int cantElemnt (int A[],int dim)
{
    int i=0;
    while(i<dim)
    {
        A[i];
        i++;
    }
    return i;
}
float calculaPromedio (int A[],int dim)
{
    int i;
    float promedio=0;
    for(i=0; i<dim; i++)
    {
        promedio=sumaElementos(A,dim)/cantElemnt(A,dim);
    }
    return promedio;
}
char cargaStrings (char C[],int dim)
{
    printf("Ingrese su nombre y apellido completo  : ");
    gets(C);

    return C;
}
void     muestraStrings (char C[],int dim)
{
    printf("Su nombre y apellido es : \n");
    printf("%s",C);
}
int Capicua (int A[],int dim)

{
    int i=0;
    int flag=0;
    int ultimo=dim-1;
    while(i<ultimo && flag==0)
    {
        if(A[i]!=A[ultimo])
        {
            flag=1;
        }
        i++;
        ultimo--;

    }
    return flag;
}
