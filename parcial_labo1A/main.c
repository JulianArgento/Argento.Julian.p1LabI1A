#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "dataWareHouse.h"
#include "color.h"
#include "auto.h"
#include "fecha.h"
#include "trabajo.h"
#include "servicio.h"
#include "marca.h"
#include "servicio.h"

#define TAM 20
#define TAM_MARCA 5
#define TAM_COLORES 5
#define TAM_SERVICIOS 4
#define TAM_TRABAJOS 30


int main()
{



    char salir='n';
    int nextId= 2000;
    int nextIdTrabajo= 2000;

    eAuto lista[TAM];
    eTrabajo trabajos[TAM_TRABAJOS];

    eMarca marcas[TAM_MARCA]=
    {

        {1000,"Renault"},
        {1001,"Ford"},
        {1002,"Fiat"},
        {1003,"Chevrolet"},
        {1004,"Peugeot"},



    };


    eColor colores[TAM_COLORES] =
    {

        {5000,"Negro"},
        {5001,"Blanco"},
        {5002,"Rojo"},
        {5003,"Gris"},
        {5004,"Azul"},

    };

    eServicio lavados[TAM_SERVICIOS] =
    {

        {20000, "Lavado", 450},
        {20001, "Pulido", 500},
        {20002, "Encerado", 600},
        {20003, "Completo", 900}
    };


    inicializarAutos(lista,TAM);
    inicializarTrabajos(trabajos,TAM_TRABAJOS);

    //hardcodearAutos(lista,TAM,5,&nextId);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(altaAuto(lista,TAM,colores,TAM_COLORES,marcas,TAM_MARCA,&nextId))
            {
                printf("Alta de Auto con exito\n\n");

            }
            else
            {
                printf("Ocurrio un error, no se pudo dar de alta el auto ingresado.\n\n");
            }
            break;

        case 2:
            system("cls");

            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }


            if(modificarAuto(lista,TAM,colores,marcas,TAM_COLORES,TAM_MARCA))
            {
             printf("Auto modificado con exito\n\n");
            }
            else
            {
                printf("Ocurrio un error, no se pudo modificar el auto con exito\n\n");
            }
            break;

        case 3:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }


            system("cls");
            if(!bajaAuto(lista,colores,marcas,TAM,TAM_COLORES,TAM_MARCA))
            {
                printf("Ocurrio un error. Ha fallado la baja .\n\n");
            }
            break;
        case 4:

            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");
            ordenarAutos(lista,TAM);
            mostrarAutos(lista,TAM,marcas,colores,TAM_COLORES,TAM_MARCA);
            break;
        case 5:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }


            system("cls");
            mostrarMarcas(marcas,TAM_MARCA);
            break;
        case 6:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");
            mostrarColores(colores,TAM_COLORES);
            break;
        case 7:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");
            mostrarServicios(lavados,TAM_SERVICIOS);
            break;

        case 8:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");

            if(altaTrabajo(trabajos,TAM_TRABAJOS,lista,TAM,lavados,marcas,TAM_MARCA,colores,TAM_COLORES,TAM_SERVICIOS,&nextIdTrabajo))
            {
                printf("Trabajo dado de alta.\n");
            }
            else
            {
                printf("Hubo un error al dar de alta el trabajo\n");
            }
            break;

        case 9:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");

            mostrarTrabajos(trabajos,TAM_TRABAJOS,lavados,TAM_SERVICIOS);
            break;



        case 10:
            printf("Desea salir? (s para si)");
            scanf("%c",&salir);
            break;


        }




        system("pause");
    }
    while(salir=='n');






    return 0;
}

