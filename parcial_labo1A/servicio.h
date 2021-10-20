#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int id;
    char descripcion[26];
    float precio;



}eServicio;


int mostrarServicios(eServicio lavados[], int tam);

int cargarServicio(eServicio lavados[], int tam, int idServicio , char descServicio[]);
#endif // SERVICIO_H_INCLUDED
