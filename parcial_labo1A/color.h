#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED



typedef struct{

    int id;
    char nombreColor[21];


}eColor;

int mostrarColores(eColor colores[], int tam);

int cargarColor(eColor colores[], int tam, int idColor , char nombreColor[]);


#endif // COLOR_H_INCLUDED
