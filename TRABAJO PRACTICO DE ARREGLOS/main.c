#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#include <string.h>
#include <windows.h>
int menu();
int menuEjercicioSeis(); /// Submenu ejercicio 6 //

int carga_arreglo(int A[], int dimension);
void muestra_arreglo (int A[],int dim);
int arreglo_random (int A[],int dim);
int suma_arreglo (int A[]);
int arrego_to_pila (int A[], int *P);
int reales_arreglo (float R[],int dim);
void imprime_reales (float R[],int dim);

int caracteres (char A[],int dim);
void muestra_caracteres (char A[],int dim);
int buscaDatoChar (char A[],int dim,int dato);
int InsertaCaracter (char A[],int dim, int letra);
int RandomChars (char R[],int dim);
char BuscaMaximoCaracter (char BMC[],int dim);
void AnalizaCapicua (int A[],int dim);

/// este es un algoritmo de ordenacion por seleccion del punto 11 de la guia y utiliza 2 funciones///
int buscaMenorElemento (int M[],int pos,int cantVal);
void ordenacion_por_Seleccion (int M[],int validos);
/// FIN DE ALGORITMO DE ORDENAMIENTO POR SELECCION ///




int main()
{
    int dim=0;
    int arreglo[10];
    int select;
    int ar_random[10];
    int sumita=0;
    int arreglo_a_pila [5]= {1,2,3,4,5};
    Pila dada;
    inicpila(&dada);
    float arreglo_reales[100];
    char EncuentraElemento [100];
    char dato='r';
    char Ejer7 [5]= {'a','b','c','e','f'};
    char letra='c';
    char AARR[20];
    char MaxCart=0;
    int diez[] = {1,4,2,8,9,5,7,6,0,3};
    int Capicua [9]= {1,2,3,4,5,4,3,2,1};


    do
    {
        select=menu();
        switch(select)
        {
        case 1 :
            system("cls");
            system("color A");
            dim=carga_arreglo(arreglo,10);
            muestra_arreglo(arreglo,dim);
            printf("\n");
            system("pause");
            break;
        case 2 :
            system("cls");
            dim=arreglo_random(ar_random,10);
            muestra_arreglo(ar_random,dim);
            printf("\n");
            system("pause");
            break;
        case 3  :
            system("cls");
            dim=arreglo_random(ar_random,10);
            muestra_arreglo(ar_random,dim);
            sumita=suma_arreglo(ar_random);
            printf("la suma del arreglo es : [%d]\n ",sumita);

            printf("\n");
            system("pause");
            break;
        case 4 :
            system("cls");
            //arrego_to_pila(arreglo_a_pila,&dada);
            muestra_arreglo(arreglo_a_pila,5);
            printf("\n PILA CON ELEMENTOS DEL ARREGLO :");
            mostrar(&dada);
            printf("\n");
            system("pause");
            break;
        case 5  :
            system("cls");
            dim=reales_arreglo(arreglo_reales,100);
            imprime_reales(arreglo_reales,dim);
            printf("\n");
            system("pause");
            break;
        case 6 :
            system("cls");

            do
            {
                select=menuEjercicioSeis();
                switch(select)
                {

                case 'a' :

                    system("cls");
                    dim=caracteres(EncuentraElemento,100);
                    muestra_caracteres(EncuentraElemento,dim);
                    buscaDatoChar(EncuentraElemento,dim,dato);
                    printf("\n");
                    system("pause");
                    break;
                case 'b' :
                    printf("AQUI DEBERIA ESTAR LA OTRA FUNCION !");
                    printf("\n");
                    system("pause");
                    break;
                case  's' :
                    system("cls");
                    printf("VOLVIENDO AL MENU PRINCIPAL...");
                    Sleep(3000);
                }
            }
            while(select!='s');
            break;
        case 7  :
            system("cls");
            InsertaCaracter(Ejer7,5,letra);
            muestra_caracteres(Ejer7,5);
            muestra_caracteres(Ejer7,5+1);

            printf("\n");
            system("pause");
            break;
        case 8  :
            dim=RandomChars(AARR,20);
            muestra_caracteres(AARR,dim);

            printf("\n");
            system("pause");
            break;
        case 9  :
            MaxCart=BuscaMaximoCaracter(Ejer7,5);
            printf("El maximo caracter es : %c ",MaxCart);
            printf("\n");
            system("pause");
            break;
        case  10 :
            system("cls");
            dim=arreglo_random(ar_random,10);
            muestra_arreglo(ar_random,dim);
            ordenacion_por_Seleccion(ar_random,dim);
            muestra_arreglo(ar_random,dim);
            printf("\n");
            system("pause");
            break;
        case 11 :
            muestra_arreglo(Capicua,9);
            AnalizaCapicua(Capicua,9);

            printf("\n");
            system("pause");
            break;
        case 0  :

            printf("\n !!! OPCION INCORRECTA !!! \n");
            break;

        }
    }
    while(select!=0);





    return 0;
}
int menu()
{
    system("color 1A");
    int input;
    system("cls");
    printf("\n \t\t\t\t\t**********************");
    printf(" \n \t\t\t \t\t   MENU DE ARREGLOS    ");
    printf("\n \t\t\t\t\t**********************");
    printf("\n");
    printf("\n OPCION 1 : CARGAR UN ARREGLO Y RETORNAR SUS VALIDOS ");
    printf("\n OPCION 2 : CARGAR UN ARREGLO");
    printf("\n OPCION 3 : SUMAR LOS ELEMENTOS DEL UN ARREGLO ");
    printf("\n OPCION 4 : PASAR DE ARREGLO A PILA  ");
    printf("\n OPCION 5 : ARREGLO DE REALES ");
    printf("\n OPCION 6 : BUSCA UN DATO EN ARREGLO DE CARACTERES ");
    printf("\n OPCION 7 : INSERTA UN CARACTER EN UN ARREGLO ORDENADO DE CHARS ");
    printf("\n OPCION 8 : CARGA RANDOM DE CARACTERES ");
    printf("\n OPCION 9 : OBTIENE MAXIMO CARACTER ");
    printf("\n OPCION 10 : ORDENACION POR SELECCION ");
    printf("\n OPCION 11 : DETERMINA SI UN ARREGLO ES CAPICUA O NO ");
    printf("\n PRESIONE 0 PARA SALIR DEL MENU !");
    printf("\n INGRESE UNA OPCION : ");
    scanf("%d",&input);
    printf("-------------------------\n");
    return input;
}
int menuEjercicioSeis()
{
    system("cls");
    system("color 4F");
    char input;
    printf("SUBMENU EJERCICIO 6 ");
    printf("\n");
    printf("\n OPCION a : BUSCA DATO DE FORMA PEDORRA CON UN FLAG : ");
    printf("\n OPCION b : BUSCA DATO RETORNANDO LA POSICION EXACTA  ");
    printf("\n PARA SALIR PRESIONE LA LETRA s PARA SALIR ");
    printf("\n INGRESE UNA OPCION : ");
    scanf("%c",&input);

    return input;
}
int carga_arreglo(int A[], int dimension) /// CARGA UN ARREGLO DE ENTEROS Y RETORNA SUS VALIDOS ///
{
    char control='s';
    int validos=0;
    while(control=='s' && validos<dimension)
    {
        printf("Ingrese un valor entero : ");
        fflush(stdin);
        scanf("%d",&A[validos]);
        validos++;
        printf("Desea continuar? s/n :\t ");
        fflush(stdin);
        scanf("%c",&control);

    }
    return validos;
}
void muestra_arreglo (int A[],int dim) /// MUESTRA UN ARREGLO DE ENTEROS ///
{

    int val;
    printf("\n Arreglo de enteros \n");
    printf("\n");
    for(val=0; val<dim; val++)
    {
        printf("-[%d]",A[val]);

    }
    printf("\n");
}
int arreglo_random (int A[],int dim)/// REALIZA UNA CARGA RANDOM DE ENTEROS RETORNANDO LOS VALIDOS ///

{


    srand(time(NULL));
    int val=0;
    while(val<dim)
    {
        A[val]=rand()%100;
        val++;
    }
    return val;
}
int suma_arreglo (int A[])/// REALIZA UNA SUMA DE LOS ELEMENTOS DEL ARREGLO DE ENTEROS ///
{
    int i=0;
    int sumar=0;
    while(i<10)
    {
        sumar=sumar+A[i];
        i++;

    }
    return sumar;
}
int arrego_to_pila (int A[], int *P)/// PASA LOS ELEMENTOS DE UN ARREGLO A UNA PILA ///
{
    int i=0;
    while(i<5)
    {
        apilar(P,A[i]);
        i++;
    }

    return i;
}
int reales_arreglo (float R[],int dim) /// CARGA UN ARREGLO DE NUMEROS REALES(FLOAT) ///
{
    int  i=0;

    char continuar='s';
    while(i<dim && continuar=='s' || continuar=='S')
    {
        printf("Ingrese un elemento : ");
        fflush(stdin);
        scanf("%f",&R[i]);
        i++;
        printf("Desea continuar? s/n :  ");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    return i;
}
void imprime_reales (float R[],int dim) /// MUESTRA UN ARREGLO DE REALES ////
{
    int val=0;
    while(val<dim)
    {
        printf("[%0.2f]",R[val]);
        val++;

    }
}
int caracteres (char A[],int dim) /// CARGA UN ARREGLO DE LETRAS ///
{
    int contuniar=0;
    int elementos=0;
    while(elementos<dim && contuniar==0)
    {
        printf("Ingrese un caracter al arreglo : ");
        fflush(stdin);
        scanf("%c",&A[elementos]);
        elementos++;
        printf("Presion 0 para continuar 1 para salir : ");
        fflush(stdin);
        scanf("%d",&contuniar);
    }
    return elementos;
}
void muestra_caracteres (char A[],int dim) /// MUESTRA UN ARREGLO DE LETRAS ///
{
    printf("\n------------------\n");
    int i;
    for(i=0; i<dim; i++)
    {
        printf("[%c]",A[i]);
    }
    printf("\n-------------------");
}
int buscaDatoChar (char A[],int dim,int  dato) /// BUSCA UN DATO EN UN ARREGLO DE LETRAS ///
{

    int val=0;
    int flag=0;
    while (val<dim && flag==0)
    {
        if(A[val]==dato)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
        val++;
    }
    if(flag==1)
    {
        printf("\n EL DATO -[%c]- SE HA ENCONTRADO !",dato);
    }
    else
    {
        printf("\n EL DATO -[%c]- NO SE ENCONTRO!!  ",dato);
    }

    return flag;
}
int InsertaCaracter (char A[],int dim, int letra)  /// INSERTA UN CARACTER EN UN ARREGLO ORDENADO ALFABETICAMENTE ///
{
    int i=dim-1; /// se lo iguala a dim-1 para poner el cursor en la posicion final del arreglo ///
    while(i>=0 && letra<A[i])
    {
        A[i+1]=A[i];        ///este while recorre el arreglo comparando los elementos ///
        i--;                /// se decrementa porque lo recorre del final hacia el principio ///
    }
    A[i+1]=letra; /// inserta el elemento en el arreglo ///
    return i+1; /// le avisa al main que el arreglo crecio un espacio mas ///
}
int RandomChars (char R[],int dimension)
{
    int i;
    srand(time(NULL));
    dimension=rand()%50;
    for(i=0; i<dimension; i++)
    {
        R[i]=rand()%97+20;
    }
    return i;
}
char BuscaMaximoCaracter (char BMC[],int dim) /// ESTA FUNCION BUSCA EL MAXIMO CARACTER DE UN ARREGLO DE CARACTERES Y LO RETORNA ///
{
    int i=0;
    char maxChar=BMC[i];      ///LA VARIABLE maxChar SE INICIALIZA CON EL VALOR DE BMC[0] PARA IR COMPARANDO ///
    for(i+1; i<dim; i++)
    {
        if(BMC[i]>maxChar)   /// COMPARO LA POSICION DEL ARREGLO CON EL CARACTER ///
        {
            maxChar=BMC[i];  /// SI SE CUMPLE Y LA POSICION DEL ARREGLO ES MAYOR A MAXCHAR SE COPIA ESA POSICION EN LA VARIABLE//
        }
    }
    //printf("El maximo caracter es : %c ",maxChar);
    return maxChar;
}

/////////////////////////////////////////////////////////////////////////////
//  ARREGLO : [8]-[3]-[1]-[6]
//  SUBINDICE  0   1   2   3
//  MENOR=M[POS] == 8
// POSMENOR=POS  == 0
///////////////////////////////////////////////////////////////////////////

int buscaMenorElemento (int M[],int pos,int cantVal)
{
    int  menor=M[pos]; /// GUARDA EN MENOR EL PRIMER ELEMENTO DEL SUBINDICE 0  ///
    int posmenor=pos;  /// GUARDA POSICION DEL MENOR ELEMENTO (SUBINDICE 0 )   ///
    int i=pos+1;  /// PARA QUE ME DIGA QUE ARRANCA DE POS + 1 ...ACA LE DECIMOS DE DONDE ARRANCAR A COMPARAR///

    while(i<cantVal)
    {
        if(menor>M[i])
        {
            menor=M[i];  /// GUARDO EL VALOR QUE ESTA EN EL ARREGLO
            posmenor=i;  // GUARDO LA POSICION EN LA QUE ESTOY PARADO ///
        }
        i++;
    }

    return posmenor; /// RETORNA POSMENOR PORQUE
}
void ordenacion_por_Seleccion (int M[],int validos)
{
    int posmenor;
    int aux;
    int i=0;
    while(i<validos-1)
    {
        posmenor=buscaMenorElemento(M,i,validos);
        aux=M[posmenor];
        M[posmenor]=M[i];
        M[i]=aux;
        i++;
    }

}
void AnalizaCapicua (int A[],int dim)
{
    int i=0;
    int flag=0;
    int ultimo=dim-1;
    while (i<ultimo && flag==0)
    {
        if(A[i]!=A[ultimo])
        {
            flag=1;
        }
        i++;
        ultimo--;
    }
    if (flag==0)
    {
        printf("El arreglo es capicua !");
    }
    else
    {
        printf("Lo siento el arreglo no es capicua !");
    }
}
