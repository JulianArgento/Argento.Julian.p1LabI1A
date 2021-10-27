#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int id;
    char descripcion[26];
    float precio;



}eServicio;


/** \brief muestra el contenido del array de servicios
 *
 * \param lavados[] eServicio array de servicios
 * \param tam int tam del array
 * \return int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarServicios(eServicio lavados[], int tam);

/** \brief carga el servicio de mismo id que el ingresado en el string ingresado por parametro
 *
 * \param lavados[] eServicio array de servicios
 * \param tam int tam del array
 * \param idServicio int id del servicio que se desea cargar
 * \param descServicio[] char string donde se cargara la descripcion del servicio
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargarServicio(eServicio lavados[], int tam, int idServicio , char descServicio[]);





/** \brief recibe el id de cierto servicio y una direccion de memoria donde asignar el precio del servicio.
 *
 * \param lavados[] eServicio array de servicios
 * \param tam int tam del array de servicios
 * \param idServicio int id del servicio del que se requiere el precio
 * \param precio int* direccion de memoria donde se guardara el precio
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int cargarPrecio(eServicio lavados[],int tam, int idServicio, int* precio);

#endif // SERVICIO_H_INCLUDED
