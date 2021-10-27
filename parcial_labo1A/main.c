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
#define TAM_TRABAJOS 10


int main()
{



    char salir='n';
    int nextId= 2000;
    int nextIdTrabajo= 2000;

    eAuto lista[TAM];

    inicializarAutos(lista,TAM);


    eMarca marcas[TAM_MARCA]=
    {

        {1000,"Renault"},
        {1001,"Ford"},
        {1002,"Fiat"},
        {1003,"Chevrolet"},
        {1004,"Peugeot"},



    };

    eTrabajo trabajos[TAM_TRABAJOS]=
    {
        {2000,2001,20001,25,02,2002,0},
        {2001,2001,20000,20,12,2012,0},
        {2002,2002,20002,11,11,2020,0},
        {2003,2003,20002,13,11,2012,0},
        {2004,2003,20001,13,11,2012,0},
        {2000,2002,20001,25,02,2002,0},
        {2001,2002,20000,20,12,2012,0},
        {2002,2000,20002,11,11,2020,0},
        {2003,2000,20002,13,11,2012,0},
        {2004,2000,20001,13,11,2012,0}

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


    hardcodearAutos(lista,TAM,5,&nextId);

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
            if(!mostrarAutos(lista,TAM,marcas,colores,TAM_COLORES,TAM_MARCA))
            {
                printf("Hubo un error al mostrar los autos\n");
            }
            break;
        case 5:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }


            system("cls");

            if(!mostrarMarcas(marcas,TAM_MARCA))
            {
                printf("Hubo un error al mostrar las marcas\n");

            }
            break;


        case 6:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");

            if( !mostrarColores(colores,TAM_COLORES))
            {
                printf("Hubo un error al mostrar los colores\n");
            }


            break;
        case 7:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");

            if( !mostrarServicios(lavados,TAM_SERVICIOS))
            {
                printf("Hubo un error al mostrar los servicios\n");
            }

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

            if(!mostrarTrabajos(trabajos,TAM_TRABAJOS,lavados,TAM_SERVICIOS))
            {
                printf("Hubo un error al mostrar los trabajos.\n");
            }

            break;

        case 10:
            if(!checkAutoCargado(lista,TAM))
            {
                printf("Debe ingresar un auto antes.\n");
                break;
            }

            system("cls");


            switch(menuInformes())
            {


            case 1:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!mostrarAutoColor(lista,TAM,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al mostrar los autos.\n");
                }



                break;


            case 2:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!mostrarAutoMarca(lista,TAM,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al mostrar los autos\n");
                }



                break;


            case 3:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!informarPromedioCaja(lista,TAM))
                {
                    printf("Hubo un error al mostrar los autos\n");
                }



                break;

            case 4:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!mostrarAutosCaja(lista,TAM,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al informar los autos\n");
                }



                break;

            case 5:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!mostrarAutoMarcaColor(lista,TAM,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al informar los autos\n");
                }



                break;

            case 6:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!informeMarcasMasElegidas(lista,TAM,marcas,TAM_MARCA))
                {
                    printf("Hubo un error al informar las marcas mas elegidas.\n");
                }



                break;

            case 7:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!informarTrabajosAuto(lista,TAM,trabajos,TAM_TRABAJOS,lavados,TAM_SERVICIOS,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al informar los trabajos realizados en el auto elegido.\n");
                }



                break;

            case 8:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!informarImporteAuto(lista,TAM,trabajos,TAM_TRABAJOS,lavados,TAM_SERVICIOS,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al informar los trabajos realizados en el auto elegido.\n");
                }



                break;

            case 9:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!informarServicioAutos(lista,TAM,trabajos,TAM_TRABAJOS,lavados,TAM_SERVICIOS,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al informar los trabajos realizados en el auto elegido.\n");
                }



                break;

            case 10:
                if(!checkAutoCargado(lista,TAM))
                {
                    printf("Debe ingresar un auto antes.\n");
                    break;
                }

                system("cls");

                if(!informarFechaServicios(lista,TAM,trabajos,TAM_TRABAJOS,lavados,TAM_SERVICIOS,marcas,colores,TAM_COLORES,TAM_MARCA))
                {
                    printf("Hubo un error al informar los trabajos realizados en el auto elegido.\n");
                }



                break;




                case 11:
                break;
            }



            break;



            case 11:
            printf("Desea salir? (s para si)");
            scanf("%c",&salir);
            break;


        }




        system("pause");
    }
    while(salir=='n');






    return 0;
}

