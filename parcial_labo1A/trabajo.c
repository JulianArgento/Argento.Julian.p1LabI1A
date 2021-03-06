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




int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
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

int altaTrabajo(eTrabajo trabajos[], int tam_trabajo, eAuto lista[],int tam, eServicio servicios[],eMarca marcas[],int tam_marca, eColor colores[],int tam_colores, int tam_servicios,int* pIdt)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(lista != NULL &&trabajos != NULL && servicios != NULL && colores != NULL && marcas != NULL && tam > 0 && pIdt != NULL)
    {
        system("cls");
        printf("            *** Alta Trabajo ***              \n");
        printf("---------------------------------------------\n");

        indice = buscarLibreTrabajo(trabajos, tam);
        if(indice == -1)
        {
            printf("No hay lugar para mas trabajos en el sistema\n");
        }
        else
        {
            auxTrabajo.id = *pIdt;
            (*pIdt)++;

            mostrarAutos(lista,tam,marcas,colores,tam_colores,tam_marca);
            printf("Ingrese el id del auto: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.patente);

            while(buscarAutoId(lista,tam,auxTrabajo.patente)==-1)
            {
                printf("error. Ingrese un auto que este en la lista.\n");
                printf("Vuelva a ingresar el id del auto: ");
                fflush(stdin);
                scanf("%d", &auxTrabajo.patente);
            }

            printf("\n\n");


            mostrarServicios(servicios,tam_servicios);
            printf("Ingrese el id del servicio: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.idServicio);

            while(auxTrabajo.idServicio<20000||auxTrabajo.idServicio>20003)
            {
                printf("error, id no valido. Vuelva a ingresar el id del servicio que desea: ");
                fflush(stdin);
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf("\n\n");




            printf("Ingrese la fecha (dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
            while(!validateDate(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio))
            {
                printf("Error, ingrese una fecha valida (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
            }

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;

        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tam_servicios)
{



    char descServicio[26];

    cargarServicio(servicios,tam_servicios,unTrabajo.idServicio,descServicio);


    printf("  %d       %d       %6s   %d/%d/%d    \n",
           unTrabajo.id,
           unTrabajo.patente,
            descServicio,
           unTrabajo.fecha.dia,
           unTrabajo.fecha.mes,
           unTrabajo.fecha.anio);



}

int mostrarTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[],int tam_servicios)
{

    int todoOk = 0;
    int flag = 1;
    if(trabajos != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de Trabajos ***      \n");
        printf("   IdTrabajo   IdAuto    Servicio   Fecha\n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_servicios);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Trabajos para mostrar");

        }
        todoOk=1;
    }
    return todoOk;



}

int informarTrabajosAuto(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca )
{
    int todoOk= 0;
    int idAuto;
    int flag=1;

    if(lista != NULL  && marcas != NULL && tam > 0  && tam_marca > 0)
    {
        mostrarAutos(lista,tam,marcas,colores,tam_colores,tam_marca);
        printf("Ingrese el id del auto: ");
        fflush(stdin);
        scanf("%d", &idAuto);

        while(buscarAutoId(lista,tam,idAuto)==-1)
        {
            printf("error. Ingrese un auto que este en la lista.\n");
            printf("Vuelva a ingresar el id del auto: ");
            fflush(stdin);
            scanf("%d", &idAuto);
        }

        printf("\n\n");

        printf("       *** Listado de Trabajos realizados a ese auto ***      \n");
        printf("   IdTrabajo   IdAuto    Servicio   Fecha\n");
        printf("---------------------------------------------\n");

        for(int i=0; i<tam_trabajos; i++)
        {
            if(trabajos[i].patente==idAuto&&trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_servicios);
                flag=0;
            }



        }

        if(flag)
        {
            printf("\n\n");
            printf("No se ha encontrado ningun trabajo asosiado a ese auto.");
        }


        todoOk=1;
    }


    return todoOk;

}

int informarImporteAuto(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca )
{
    int todoOk= 0;
    int idAuto;
    int flag=1;
    int sumaImporte=0;
    int precio;

    if(lista != NULL  && marcas != NULL && tam > 0  && tam_marca > 0)
    {
        mostrarAutos(lista,tam,marcas,colores,tam_colores,tam_marca);
        printf("Ingrese el id del auto: ");
        fflush(stdin);
        scanf("%d", &idAuto);

        while(buscarAutoId(lista,tam,idAuto)==-1)
        {
            printf("error. Ingrese un auto que este en la lista.\n");
            printf("Vuelva a ingresar el id del auto: ");
            fflush(stdin);
            scanf("%d", &idAuto);
        }

        printf("\n\n");


        for(int i=0; i<tam_trabajos; i++)
        {
            if(trabajos[i].patente==idAuto&&trabajos[i].isEmpty==0)
            {
                cargarPrecio(servicios,tam_servicios,trabajos[i].idServicio,&precio);
                sumaImporte+=precio;
                flag=0;
            }



        }

        if(flag)
        {
            printf("\n\n");
            printf("No se ha encontrado ningun trabajo asociado a ese auto.\n\n");
        }else
        {
            printf("El importe total cargado a ese auto es de %d.\n\n",sumaImporte);
        }


        todoOk=1;
    }


    return todoOk;

}

int informarServicioAutos(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca )
{
    int todoOk= 0;
    int flag=1;
    int idServicio;


    if(lista != NULL  && marcas != NULL && tam > 0  && tam_marca > 0)
    {
        mostrarServicios(servicios,tam_servicios);
            printf("Ingrese el id del servicio: ");
            fflush(stdin);
            scanf("%d", &idServicio);

            while(idServicio<20000||idServicio>20003)
            {
                printf("error, id no valido. Vuelva a ingresar el id del servicio que desea: ");
                fflush(stdin);
                scanf("%d", &idServicio);
            }

            printf("\n\n");

            printf("       *** Listado de Trabajos de ese servicio***      \n");
            printf("   Id   IdAuto    Servicio   Fecha\n");
            printf("---------------------------------------------\n");
            for(int i=0; i<tam_trabajos; i++)
            {
                if(trabajos[i].idServicio==idServicio&&trabajos[i].isEmpty==0)
                {
                    mostrarTrabajo(trabajos[i],servicios,tam_servicios);
                    flag=0;
                }

            }



        if(flag)
        {
            printf("\n\n");
            printf("No se ha encontrado ningun trabajo asociado a ese auto.\n\n");
        }


        todoOk=1;
    }


    return todoOk;

}


int informarFechaServicios(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca )
{

    int todoOk=0;
    int flag=1;
    eFecha auxFecha;


     if(lista != NULL  && marcas != NULL && tam > 0  && tam_marca > 0)
    {
            printf("Ingrese la fecha (dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%d/%d/%d", &auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
            while(!validateDate(auxFecha.dia,auxFecha.mes,auxFecha.anio))
            {
                printf("Error, ingrese una fecha valida (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
            }

            printf("\n\n");

            printf("       *** Listado de Servicios realizados en esa fecha***      \n");
            printf("   IdTrabajo   IdAuto    Servicio   Fecha\n");
            printf("---------------------------------------------\n");
            for(int i=0; i<tam_trabajos; i++)
            {
                if(trabajos[i].fecha.dia == auxFecha.dia && trabajos[i].fecha.mes == auxFecha.mes && trabajos[i].fecha.anio == auxFecha.anio && trabajos[i].isEmpty==0)
                {
                    mostrarTrabajo(trabajos[i],servicios,tam_servicios);
                    flag=0;
                }

            }



        if(flag)
        {
            printf("\n\n");
            printf("No se ha encontrado ningun servicio realizado en esta fecha.\n\n");
        }


        todoOk=1;
    }


    return todoOk;

}










