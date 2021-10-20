#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "color.h"
#include "marca.h"
#include "auto.h"
#include "servicio.h"


typedef struct{

    int id;
    int patente;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

int inicializarTrabajos(eTrabajo trabajos[], int tam);


int buscarLibreTrabajo(eTrabajo lista[], int tam);


int altaTrabajo(eTrabajo trabajos[], int tam_trabajo, eAuto lista[],int tam, eServicio servicios[],eMarca marcas[],int tam_marca, eColor colores[],int tam_colores, int tam_servicios,int* pIdt);

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tam_servicios);


int mostrarTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[],int tam_servicios);



#endif // TRABAJO_H_INCLUDED
