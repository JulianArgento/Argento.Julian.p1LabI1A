#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"

typedef struct{

    int id;
    int idMarca;
    int idColor;
    char caja;
    int isEmpty;

}eAuto;

int inicializarAutos(eAuto lista[], int tam);

int buscarLibre(eAuto lista[], int tam);

int altaAuto(eAuto lista[], int tam, eColor colores[] , int tam_colores , eMarca marcas[], int tam_marca,int* pId);

void mostrarAuto(eAuto unAuto, eMarca marcas[], eColor colores[], int tam_colores,int tam_Marca);

int mostrarAutos(eAuto lista[],int tam, eMarca marcas[], eColor colores[], int tam_colores,int tam_Marca);

int buscarAutoId(eAuto lista[], int tam, int id);

int bajaAuto(eAuto lista[], eColor colores[],eMarca marcas[],int tam ,int tam_colores,int tam_marca);

int modificarAuto(eAuto lista[], int tam, eColor colores[], eMarca marcas[], int tam_colores, int tam_marca);

int ordenarAutos(eAuto lista[], int tam);

int checkAutoCargado(eAuto lista[],int tam);

#endif // AUTO_H_INCLUDED
