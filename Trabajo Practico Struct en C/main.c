#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct
{
    int matricula;
    char nombre[30];
    char genero[10];
} stAlumno;
int menuStrcut ();
int cargaStructAlumno (stAlumno A[],int dim);
void muestraStructAlumno (stAlumno A);
void muestraStructVariosAlumnos (stAlumno A[],int dim);
int posicionMenor (stAlumno A[],int pos,int dim);
void ordenaXseleccion (stAlumno A[],int dim);

int main()
{
    int dim=0,opcion=0;
    stAlumno utn[10];
    do
    {
        opcion=menuStrcut();
        switch(opcion)

        {
        case 1 :
            dim=cargaStructAlumno(utn,10);

            break;
        case 2:
            muestraStructVariosAlumnos(utn,dim);

            break;
        case 3 :
            ordenaXseleccion(utn,dim);
            printf("\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("Saliendo del menu...");
            Sleep(3000);

        }
    }
    while(opcion!=0);
    return 0;
}
int menuStrcut ()
{
    system("cls");
    system("color 1F");
    int opcion=0;
    printf("\n-------------------------------------------------\n");
    printf("BIENVENIDOS AL MENU DE ESTRUCTURAS EN C ");
    printf("\n-------------------------------------------------\n");
    printf("\nOPCION 1 : CARGA UNA ESTRUCTURA ");
    printf("\nOPCION  :  MUESTRA UNA ESTRUCTURA");
    printf("\nOPCION  :  ORDENA POR SELECCION");
    printf("\nOPCION  : ");
    printf("\nOPCION  : ");
    printf("\nOPCION  : ");
    printf("\nPARA SALIR PRESIONE : 0 ");
    printf("\nINGRESE UNA OPCION : ");
    scanf("%d",&opcion);
    return opcion;
}
int cargaStructAlumno (stAlumno A[],int dim)
{
    system("cls");
    printf("Ingrese los datos del alumno : \n");
    int i=0;
    char letra='s';
    while(i<dim && letra=='s')
    {
        printf("Matricula : ");
        scanf("%d",&A[i].matricula);

        printf("Nombre : ");
        fflush(stdin);
        gets(A[i].nombre);

        printf("Genero : ");
        fflush(stdin);
        gets(A[i].genero);

        printf("Para cargar otro alumno s :  ");
        fflush(stdin);
        scanf("%c",&letra);
        i++;
    }
    printf("\n");
    system("pause");
    return i;

}

void muestraStructVariosAlumnos (stAlumno A[],int dim)
{
    system("cls");
    system("color 4F");
    int i;
    for(i=0; i<dim; i++)
    {
        printf("\nMatricula : %d ",A[i].matricula);
        printf("\nNombre : %s ",A[i].nombre);
        printf("\nGenero : %s",A[i].genero);

        printf("\n----------------------\n");
    }
    printf("\n");
    system("pause");
}
int posicionMenor (stAlumno A[],int pos,int dim)
{
    stAlumno menor=A[pos];
    int posmenor= pos;
    for(int i=pos+1; i<dim; i++)
    {
        if(menor.matricula>A[i].matricula)
        {
            menor=A[i];
            posmenor=i;
        }
    }
    return posmenor;
}
void ordenaXseleccion (stAlumno A[],int dim)
{
    int posmenor;
    stAlumno  aux;
    int i=0;
    while(i<dim && A[i].matricula<posmenor)
    {
        posmenor=posicionMenor(A,i,dim);
        aux=A[posmenor];
        A[posmenor]=A[i];
        A[i]=aux;
        i++;
    }

}
