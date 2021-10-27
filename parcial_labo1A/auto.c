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
    char caja[20];

    char automatico[20]= "Automatica";
    char manual[20]= "Manual";


    if(unAuto.caja=='a')
    {
        strcpy(caja,automatico);
    }
    else
    {
        strcpy(caja,manual);
    }


    char nombreColor[21];
    char descMarca[21];

    cargarColor(colores,tam_colores,unAuto.idColor,nombreColor);
    cargarMarca(marcas,tam_Marca,unAuto.idMarca,descMarca);


    printf("  %d      %6s       %6s        %6s   \n",
           unAuto.id,
           descMarca,
           nombreColor,
           caja);



}

int mostrarAutos(eAuto lista[],int tam, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca)
{

    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 )
    {
        system("cls");
        printf("       *** Listado de Autos ***      \n");
        printf("   Id      Marca       Color         Caja\n");
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


int mostrarAutoColor(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 )
    {
        int idColor;
        char nombreColor[20];



        mostrarColores(colores,tam_colores);
        printf("\n\n");
        printf("Ingrese id del color que desea buscar : ");
        scanf("%d", &idColor);
        while(idColor<5000||idColor>5004)
        {
            printf("error. id ingresado no valido\n");
            printf("Ingrese id del color que desea buscar : ");
            scanf("%d", &idColor);
        }

        printf("\n\n");

        cargarColor(colores,tam_colores,idColor,nombreColor);

        printf("       *** Listado de Autos de color %s***      \n",nombreColor);
        printf("   Id   Marca    Color   Caja\n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idColor==idColor)
            {
                mostrarAuto(lista[i],marcas,colores,tam_colores,tam_marca);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Autos para mostrar de ese color.\n");

        }
        todoOk=1;
    }

    return todoOk;


}

int mostrarAutoMarca(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 )
    {
        int idMarca;
        char descMarca[20];



        mostrarMarcas(marcas,tam_marca);
        printf("Ingrese el id de la marca: ");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(idMarca<1000||idMarca>1004)
        {
            printf("error. Ingrese una marca que este en la lista.\n");
            printf("Vuelva a ingresar el id de marca a buscar: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

        cargarMarca(marcas,tam_marca,idMarca,descMarca);

        printf("\n\n");



        printf("       *** Listado de Autos de marca %s***      \n",descMarca);
        printf("   Id   Marca    Color   Caja\n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==idMarca)
            {
                mostrarAuto(lista[i],marcas,colores,tam_colores,tam_marca);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Autos para mostrar de esa marca.\n");

        }
        todoOk=1;
    }

    return todoOk;


}

int mostrarAutosCaja(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca)
{
    int todoOk=0;

    int flagAutomaticos=1;
    int flagManuales=1;




    if(lista !=NULL&&marcas!=NULL&&colores!=NULL&&tam>0&&tam_colores>0&&tam_marca>0)
    {
        printf("\n\n");
        printf("       *** Listado de Autos de caja Automatica***      \n");
        printf("   Id   Marca    Color   Caja\n");
        printf("-----------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].caja=='a')
            {
                printf("\n");
                mostrarAuto(lista[i],marcas,colores,tam_colores,tam_marca);
                flagAutomaticos = 0;

            }
        }

        if(flagAutomaticos)
        {
            printf("\n\n");
            printf("No hay autos de caja Automatica\n\n");
        }

        printf("\n\n");

        printf("       *** Listado de Autos de caja Manual***      \n");
        printf("   Id   Marca    Color   Caja\n");
        printf("-----------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].caja=='m')
            {
                printf("\n");
                mostrarAuto(lista[i],marcas,colores,tam_colores,tam_marca);
                flagManuales = 0;

            }
        }



        if(flagManuales)
        {
            printf("\n\n");
            printf("No hay autos de caja Manual\n\n");
        }

        todoOk=1;
    }

    return todoOk;



}



int mostrarAutoMarcaColor(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 )
    {
        int idMarca;
        char descMarca[20];
        int idColor;
        char nombreColor[20];
        int contador=0;



        mostrarMarcas(marcas,tam_marca);
        printf("Ingrese el id de la marca a buscar: ");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(idMarca<1000||idMarca>1004)
        {
            printf("error. Ingrese una marca que este en la lista.\n");
            printf("Vuelva a ingresar el id de marca a buscar: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

        cargarMarca(marcas,tam_marca,idMarca,descMarca);

        printf("\n\n");

        mostrarColores(colores,tam_colores);
        printf("\n\n");
        printf("Ingrese id del color que desea buscar : ");
        scanf("%d", &idColor);
        while(idColor<5000||idColor>5004)
        {
            printf("error. id ingresado no valido\n");
            printf("Ingrese id del color que desea buscar : ");
            scanf("%d", &idColor);
        }
        cargarColor(colores,tam_colores,idColor,nombreColor);
        printf("\n\n");


        system("cls");
        printf("       *** Suma de Autos de marca %s y de color %s***      \n",descMarca,nombreColor);
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idMarca==idMarca&&lista[i].idColor==idColor)
            {
                contador++;
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Autos de esa marca y color.\n\n\n");

        }
        else
        {
            printf("Hay un total de %d autos de marca %s y de color %s\n\n",contador,descMarca,nombreColor);

        }
        todoOk=1;
    }

    return todoOk;


}





int informeMarcasMasElegidas(eAuto lista[],int tam,eMarca marcas[],int tam_marca)
{


    int todoOk= 0;
    int contadores[5]= {0};
    int mayorCantidadMarca;

    if(lista != NULL  && marcas != NULL && tam > 0  && tam_marca > 0)
    {

        printf("  *** Informe marca mas elegida ***\n");
        printf("-----------------------------------------\n");


        for(int i=0; i<tam_marca; i++)
        {


            for(int j=0; j<tam; j++)
            {
                if(lista[j].idMarca==marcas[i].id&&lista[j].isEmpty==0)
                {
                    contadores[i]++;
                }


            }


        }

        for(int i=0; i<tam_marca; i++)
        {
            if(i==0||contadores[i]>mayorCantidadMarca)
            {
                mayorCantidadMarca=contadores[i];
            }


        }

        for(int i=0; i<tam_marca; i++)
        {
            if(contadores[i]==mayorCantidadMarca)
            {
                printf("%s\n",marcas[i].descripcion);
            }


        }


        todoOk=1;


    }


    return todoOk;

}

int informarPromedioCaja(eAuto lista[],int tam)
{
    int todoOk= 0;
    int contadorAutomaticos=0;
    int contadorManuales=0;
    int total;

    float promedioAutomaticos;
    float promedioManuales;

    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {

            if(lista[i].caja=='a')
            {
                contadorAutomaticos++;
            }
            else
            {
                contadorManuales++;
            }



        }


        total= contadorAutomaticos+contadorManuales;


        if(total!=0)
        {
            promedioAutomaticos= (float) (contadorAutomaticos*100)/total;

            promedioManuales= (float) (contadorManuales*100)/total;

             printf("  *** Informe promedio segun caja ***\n");
            printf("-----------------------------------------\n");
            printf("El promedio de autos con caja manual es de %.2f porciento.\nEl promedio de autos con caja automatica es de %.2f porciento.\n",promedioManuales,promedioAutomaticos);
            todoOk=1;

        }







    }


    return todoOk;

}




