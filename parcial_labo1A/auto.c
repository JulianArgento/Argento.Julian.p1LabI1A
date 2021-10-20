#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
#include "fecha.h"
#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include <string.h>
#include <ctype.h>
#include "utn.h"




int inicializarAutos(eAuto lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eAuto lista[], int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaAuto(eAuto lista[], int tam, eColor colores[], int tam_colores, eMarca marcas[], int tam_marca,int* pId)
{
    int todoOk = 0;
    int indice;
    eAuto auxAuto;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 && pId != NULL)
    {
        system("cls");
        printf("            *** Alta Auto ***              \n");
        printf("---------------------------------------------\n");

        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxAuto.id = *pId;
            (*pId)++;

            mostrarMarcas(marcas,tam_marca);
            printf("Ingrese el id de la marca: ");
            fflush(stdin);
            scanf("%d", &auxAuto.idMarca);

            while(auxAuto.idMarca<1000||auxAuto.idMarca>1004)
            {
                printf("error. Ingrese una marca que este en la lista.\n");
                printf("Vuelva a ingresar el id de la marca: ");
                fflush(stdin);
                scanf("%d", &auxAuto.idMarca);
            }

            printf("\n\n");


            mostrarColores(colores,tam_colores);
            printf("\n\n");
            printf("Ingrese id del color : ");
            scanf("%d", &auxAuto.idColor);
            while(auxAuto.idColor<5000||auxAuto.idColor>5004)
            {
                printf("error. id ingresado no valido\n");
                printf("Ingrese id del color : ");
                scanf("%d", &auxAuto.idColor);
            }

            printf("\n\n");




            printf("Ingrese la caja del auto ('m' manual, 'a' automatica): ");
            fflush(stdin);
            scanf("%c", &auxAuto.caja);
            while(auxAuto.caja!='m'&&auxAuto.caja!='a')
            {
                printf("Ese tipo de caja no existe. Ingrese la caja del auto ('m' manual, 'a' automatica): ");
                fflush(stdin);
                scanf("%c", &auxAuto.caja);
            }

            auxAuto.isEmpty = 0;

            lista[indice] = auxAuto;

        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarAuto(eAuto unAuto, eMarca marcas[], eColor colores[], int tam_colores,int tam_Marca)
{


    char nombreColor[21];
    char descMarca[21];

    cargarColor(colores,tam_colores,unAuto.idColor,nombreColor);
    cargarMarca(marcas,tam_Marca,unAuto.idMarca,descMarca);


    printf("  %d   %6s      %s   %c    \n",
           unAuto.id,
           descMarca,
           nombreColor,
           unAuto.caja);



}

int mostrarAutos(eAuto lista[],int tam, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca)
{

    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 )
    {
        system("cls");
        printf("       *** Listado de Autos ***      \n");
        printf("   Id   Marca    Color   Caja\n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarAuto(lista[i],marcas,colores,tam_colores,tam_marca);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Autos para mostrar, se debe dar de alta algun auto antes de poder mostrarlo.\n");

        }
        todoOk=1;
    }
    return todoOk;



}

int buscarAutoId(eAuto lista[], int tam, int id)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaAuto(eAuto lista[], eColor colores[],eMarca marcas[],int tam,int tam_colores,int tam_marca)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 )
    {
        system("cls");
        printf("       *** Baja Auto ***      \n");
        printf("----------------------------------\n");

        mostrarAutos(lista,tam,marcas,colores,tam_colores,tam_marca);


        printf("Ingrese el id del auto que desea dar de baja: ");
        scanf("%d", &id);

        indice = buscarAutoId(lista, tam, id);

        if(indice == -1)
        {
            printf("No existe una bici con id: %d\n", id);
        }
        else
        {
            printf("\n\n");
            mostrarAuto(lista[indice],marcas,colores,tam_colores,tam_marca);
            printf("\n\n");
            printf("Confirma baja? (s para si): \n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                printf("Auto dado de baja.\n");
                todoOk = 1;
            }
            else
            {
                printf("Se ha cancelado la baja \n");
            }
        }
    }
    return todoOk;
}

int modificarAuto(eAuto lista[], int tam, eColor colores[], eMarca marcas[], int tam_colores, int tam_marca)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    int auxMarca;
    int auxColor;


    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0)
    {
        system("cls");
        printf("       *** Modificar Auto ***      \n");
        printf("----------------------------------\n");

        mostrarAutos(lista,tam,marcas,colores,tam_colores,tam_marca);


        printf("\n\n");

        printf("Ingrese id del auto que se desea modificar: ");
        scanf("%d", &id);

        indice = buscarAutoId(lista,tam,id);

        if(indice == -1)
        {
            printf("No existe un auto con id: %d\n", id);
        }
        else
        {
            mostrarAuto(lista[indice],marcas,colores,tam_colores,tam_marca);
            printf("Confirma modificacion? ('s' para confirmar)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            confirma = tolower(confirma);

            if(confirma == 's')
            {
                switch(subMenu())
                {
                case 1:
                    mostrarColores(colores,tam_colores);
                    printf("\n\n");
                    printf("Ingrese id del nuevo color : ");
                    scanf("%d", &auxColor);
                    while(auxColor<5000||auxColor>5004)
                    {
                        printf("error. id ingresado no valido\n");
                        printf("Ingrese id del nuevo color : ");
                        scanf("%d", &auxColor);
                    }

                    printf("\n\n");



                    lista[indice].idColor=auxColor;
                    break;


                case 2:
                    mostrarMarcas(marcas,tam_marca);
                    printf("Ingrese el id de la nueva marca: ");
                    fflush(stdin);
                    scanf("%d", &auxMarca);

                    while(auxMarca<1000||auxMarca>1004)
                    {
                        printf("error. Ingrese una marca que este en la lista.\n");
                        printf("Vuelva a ingresar el id de la nueva marca: ");
                        fflush(stdin);
                        scanf("%d", &auxMarca);
                    }

                    printf("\n\n");
                    lista[indice].idMarca=auxMarca;

                    break;

                }
                todoOk = 1;
            }
            else
            {
                printf("Se ha cancelado la modificacion \n");
            }
        }
    }
    return todoOk;





}

int ordenarAutos(eAuto lista[], int tam)
{
    int todoOk = 0;
    eAuto auxAuto;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(lista[i].idMarca > lista[j].idMarca ||
                        (lista[i].idMarca == lista[j].idMarca &&
                         lista[i].id>lista[j].id))
                {
                    auxAuto = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxAuto;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int checkAutoCargado(eAuto lista[],int tam)
{
    int check=0;
    if(lista!= NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                check=1;
                return check;
                break;
            }

        }
    }
    return check;
}



