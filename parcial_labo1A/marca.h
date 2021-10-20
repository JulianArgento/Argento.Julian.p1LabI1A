#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[21];



}eMarca;

int mostrarMarcas(eMarca marcas[], int tam);
int cargarMarca(eMarca marcas[], int tam, int idMarca , char descMarca[]);


#endif // MARCA_H_INCLUDED
