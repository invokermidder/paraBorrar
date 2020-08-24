#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
int menuSwitch ();
/// FUNCIONES CON NUMEROS ENTEROS ///
void cargaMatriz (int f,int c,int M[f][c]);
void muestraMatriz (int f,int c,int M[f][c]);
void mtrRandom (int f, int c, int M[f][c]);
int sumaMatriz (int f,int c, int M[f][c]);
int cant_Elem_Mtz (int f,int c, int M[f][c]);
float calculaPromedioMtz (int f,int c,int M[f][c]);
int buscaDatoMtz (int f,int c,int M[f][c],int dato);
/// FUNCIONES CON STRINGS ///
int matrizPalabras (int f,int c,char N[f][c]);
void imprime_Palabras (int f,int c,char N[f][c]);


int main()
{


    int Matrixx[3][3];
    int opcion=0, sumita=0, datito=2, dimension=0,cantletras=0;
    float promedio=0;
    char nombres[30][30];
    do
    {
        opcion=menuSwitch();
        switch(opcion)
        {
        case 1 :
            system("cls");
            cargaMatriz(3,3,Matrixx);
            printf("\n");
            system("pause");
            break;
        case 2 :
            system("cls");
            muestraMatriz(3,3,Matrixx);
            printf("\n");
            system("pause");
            break;
        case 3 :
            system("cls");
            mtrRandom(3,3,Matrixx);
            printf("\n");
            system("pause");
            break;
        case 4 :
            system("cls");
            sumita=sumaMatriz(3,3,Matrixx);
            printf("La suma de sus elementos es [ %d ]",sumita);
            printf("\n");
            system("pause");
            break;
        case 5 :
            system("cls");
            promedio=calculaPromedioMtz(3,3,Matrixx);
            printf("El promedio de sus elementos es %f ",promedio);
            printf("\n");
            system("pause");
            break;
        case 6 :
            system("cls");
            buscaDatoMtz(3,3,Matrixx,datito);
            printf("\n");
            system("pause");
            break;
        case 7 :
            system("cls");
            dimension=matrizPalabras(30,30,nombres);
            printf("la matriz tiene %d palabras",dimension);
            printf("\n");
            system("pause");
            break;
            case 8 :
            system("cls");
            imprime_Palabras(dimension,30,nombres);
            printf("\n");
            system("pause");
            break;


        default :
            system("cls");
            printf("Saliendo del menu...");
            Sleep(3000);
        }

    }
    while(opcion!=0);



    return 0;
}
int menuSwitch ()
{
    system("cls");
    system("color 4F");
    int opcion=0;
    printf(" %c %c %c %c %c %c %c %c %c ", 219,219,219,219,219,219,219,219,219,219);
    printf("BIENVENIDO AL MENU DE MATRICES!");
    printf(" %c %c %c %c %c %c %c %c %c ", 219,219,219,219,219,219,219,219,219,219);
    printf("\n");
    printf("\nOPCION 1 : CARGAR UNA MATRIZ DE ENTEROS POR EL USUARIO ");
    printf("\nOPCION 2 : MUESTRA UNA MATRIZ DE ENTEROS ");
    printf("\nOPCION 3 : CARGA UNA MATRIZ DE FORMA RANDOM");
    printf("\nOPCION 4 : SUMA ELEMENTOS DE UNA MATRIZ ");
    printf("\nOPCION 5 : CALCULA PROMEDIO DE UNA MATRIZ ");
    printf("\nOPCION 6 : BUSCA UN DATO EN UNA MATRIZ DE ENTEROS");
    printf("\nOPCION 7 : CARGA UNA MATRIZ DE STRINGS Y RETORNA LA CANTIDAD DE PALABRAS ");
    printf("\nOPCION 8 : MUESTRA UNA MATRIZ STRINGS");
    printf("\nOPCION  : ");
    printf("\nOPCION  : ");
    printf("\n");
    printf("\n");
    printf("\n-------------------------\n");
    printf("\nPARA SALIR PRESIONE 0 \n ");
    printf("\n-------------------------\n");
    printf("\nINGRESE UNA OPCION : ");
    printf("\n-------------------------\n");
    scanf("%d",&opcion);
    return opcion;
}
/// ESTA FUNCION CARGA UNA MATRIZ CON INTERVENCION DEL USUARIO ///
void cargaMatriz (int f,int c,int M[f][c])
{
    printf("FUNCION CARGA MATRIZ\n ");
    int a,b;
    for(a=0; a<f; a++)
    {
        for(b=0; b<c; b++)
        {
            printf("Ingrese un valor : ");
            scanf("%d",&M[a][b]);

        }
    }
}
/// ESTA FUNCION MUESTRA UNA MATRIZ DE ENTEROS ///
void muestraMatriz (int f,int c,int M[f][c])
{
    printf("FUNCION MUESTRA MATRIZ\n ");
    int a,b;
    for(a=0; a<f; a++)
    {
        for(b=0; b<c; b++)
        {

            printf("[-%d-]",M[a][b]);
        }
        printf("\n");
    }
}
/// ESTA FUNCION CARGA UNA MATRIZ DE NUMEROS ENTEROS DE FORMA ALEATORIA///
void mtrRandom (int f, int c, int M[f][c])
{
    printf("FUNCION DE CARGA RANDOM...\n");
    srand(time(NULL));
    int i,x;
    for(i=0; i<f; i++)
    {
        for(x=0; x<c; x++)
        {
            M[i][x]=rand()%100;
        }
    }
    printf("Su matriz fue cargada correctamente!!");
}
/// FUNCION DEL EJERCICIO 4 SUMA LOS ELEMENTOS DE UNA MATRIZ Y LOS RETORNA ///
int sumaMatriz (int f,int c, int M[f][c])
{

    int sumar=0,i,x;
    for(i=0; i<f; i++)
    {
        for(x=0; x<c; x++)
        {
            sumar+=M[i][x];
        }
    }
    return sumar;
}
/// FUNCION AUXILIAR PARA EL EJERCICIO 5 DE CALCULA PROMEDIO ///
/// ESTA FUNCION CUENTA LA CANTIDAD DE ELEMENTOS DE UNA MATRIZ Y LOS RETORNA ///
int cant_Elem_Mtz (int f,int c, int M[f][c])
{
    int i,x,totalElementos=0;

    for(i=0; i<f; i++)
    {
        for(x=0; x<c; x++)
        {
            M[i][x];
        }
    }
    totalElementos=i*x;
    return totalElementos;
}
/// FUNCION MAIN DEL EJERCICIO 5 CALCULA PROMEDIO DE UNA MATRIZ DE NROS ENTEROS ///
float calculaPromedioMtz (int f,int c,int M[f][c])
{
    printf("Calcula el promedio de los elementos de una matriz\n");
    float promedio;
    int i,x;
    for(i=0; i<f; i++)
    {
        for(x=0; x<c; x++)
        {
            promedio=sumaMatriz(f,c,M)/cant_Elem_Mtz(f,c,M);
        }
    }
    return promedio;
}
int buscaDatoMtz (int f,int c,int M[f][c],int dato)
{
    int i=0,x,flag=0;
    while(i<f && flag==0)
    {
        x=0;
        while(x<c && flag==0)
        {
            if(M[i][x]==dato)
            {
                flag=1;
            }
            x++;
        }
        i++;
    }
    if(flag==1)
    {
        printf("el dota %d se encuentra en el arreglo! ",dato);
    }
    else
    {
        printf("El dato %d NO se encuentra en el arreglo! ",dato);
    }
}
int matrizPalabras (int f,int c,char N[f][c])

{
    int i=0;
    char control='s';
    int validos=0;
    while(i<f && control=='s')
    {
        printf("Ingrese un nombre : ");
        fflush(stdin);
        gets(N[i]);
        i++;
        printf("Para continuar [s] para salir otra tecla ");
        fflush(stdin);
        scanf("%c",&control);
    }
       validos=strlen(N[i]);
       printf("validos %d ",validos);
       system("pause");
    return validos;
}
void imprime_Palabras (int f,int c,char N[f][c])
{
    int i,x;
    for(i=0;i<f;i++)
    {


       printf("Usted ingreso los siguientes nombres : %s ",N[i]);
       printf("\n");

    }

}
