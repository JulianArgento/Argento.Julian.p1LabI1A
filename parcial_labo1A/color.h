#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED



typedef struct{

    int id;
    char nombreColor[21];


}eColor;

/** \brief muestra el contenido del array de colores
 *
 * \param colores[] eColor array de colores
 * \param tam int tam del array
 * \return int devuelve 1 en caso de haber podido mostrar la lista, y 0 en caso de error
 *
 */
int mostrarColores(eColor colores[], int tam);




/** \brief recibe el id de un color que se desee mostrar y carga su nombre en el string recibido por parametro
 *
 * \param colores[] eColor array de colores
 * \param tam int tam del array
 * \param idColor int id del color que se desea cargar
 * \param nombreColor[] char string en donde se cargara el nombre del color
 * \return int devuelve 1 en caso de cargar el color, 0 en caso de error.
 *
 */
int cargarColor(eColor colores[], int tam, int idColor , char nombreColor[]);


#endif // COLOR_H_INCLUDED
