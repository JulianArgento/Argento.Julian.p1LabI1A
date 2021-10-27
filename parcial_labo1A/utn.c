#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}




int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux)&&strlen(aux)<51)
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int menu()
{
    system("cls");

    int opcion;

    printf("-----ABM-----\n\n\n");
    printf("-----Elija la operacion a realizar-----\n\n\n");
    printf("1. Altas\n");
    printf("2. Modificar \n");
    printf("3. Baja \n");
    printf("4. Listar autos\n");
    printf("5. Listar marcas\n");
    printf("6. Listar colores \n");
    printf("7. Listar servicios \n");
    printf("8. Alta trabajos\n");
    printf("9. Mostrar trabajos\n");
    printf("10.Informes\n");
    printf("11.Salir\n");


    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;




}

int subMenu()
{
    system("cls");

    int opcion;


    printf("-----Elija la modificacion a realizar-----\n\n\n");
    printf("1. Color\n");
    printf("2. Marca \n");

    printf("3. Salir\n");

    printf("Ingrese opcion: ");
    printf("\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}

int menuInformes()
{
    system("cls");

    int opcion;


    printf("-----Elija el informe a realizar-----\n\n\n");
    printf("1. Mostrar autos segun color\n");
    printf("2. Mostrar autos segun marca\n");
    printf("3. Promedio de autos segun caja\n");
    printf("4. Listado de autos por caja\n");
    printf("5. Contar cuantos autos hay de cierta marca y color\n");
    printf("6. Marcas mas elegidas por los clientes\n");
    printf("7. Todos los trabajos de un auto\n");
    printf("8. Importe de un auto especifico\n");
    printf("9. Informe de servicio\n");
    printf("10. Servicios realizados en cierta fecha\n");
    printf("11. Salir\n");

    printf("Ingrese opcion: ");
    printf("\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}

int validateDate(int dia, int mes, int anio)
{
    int todoOk = 0;

    if(
        (dia > 0 && dia < 32) &&
        (mes > 0 && mes < 13) &&
        (anio > 0 && anio < 2022)
       )
    {
        todoOk = 1;
    }

    return todoOk;
}

