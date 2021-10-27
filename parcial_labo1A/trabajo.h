#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "auto.h"
#include "fecha.h"
#include "servicio.h"
#include "color.h"
#include "marca.h"



typedef struct{

    int id;
    int patente;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

/** \brief inicializa el array de trabajos, poniendo los campos isEmpty en 1
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tam del array
 * \return int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);




/** \brief busca la primera posicion libre (isEmpty=1) y devuelve su indice
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int tam del array
 * \return int devuelve el indice del lugar libre, o -1 en caso de error
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);




/** \brief da de alta un trabajo en el array de trabajos con los datos ingresados por el usuario
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam_trabajo int tam del array de trabajos
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param servicios[] eServicio array de servicios
 * \param marcas[] eMarca array de marcas
 * \param tam_marca int tam del array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_servicios int tam del array de servicios
 * \param pIdt int* puntero al id de trabajos, usado para asignarlo al trabajo e incrementarlo
 * \return int devuelve 1 en caso de exito y 0 en caso de error
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam_trabajo, eAuto lista[],int tam, eServicio servicios[],eMarca marcas[],int tam_marca, eColor colores[],int tam_colores, int tam_servicios,int* pIdt);




/** \brief imprime un trabajo recibido por parametro en pantalla
 *
 * \param unTrabajo eTrabajo trabajo que se desea imprimir
 * \param servicios[] eServicio array de servicios
 * \param tam_servicios int tam del array de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[],int tam_servicios);





/** \brief muestra el contenido del array de trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tam del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tam_servicios int  tam del array de servicios
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[],int tam_servicios);




/** \brief da a elegir un auto al usuario, y luego muestra todos los trabajos que le fueron realizados a ese auto.
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam_trabajos int tam del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tam_servicios int tam del array de servicios
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int informarTrabajosAuto(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca);




/** \brief da a elegir al usuario un tipo de servicio y luego muestra todos los trabajos y autos a los que se le realizo ese servicio
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam_trabajos int tam del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tam_servicios int tam del array de servicios
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int informarServicioAutos(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca );



/** \brief da a elegir al usuario un auto del array de autos, y luego informa el importe total que tendra que pagar ese auto por la suma de servicios realizados
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam_trabajos int tam del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tam_servicios int tam del array de servicios
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int informarImporteAuto(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca );




/** \brief el usuario ingresa una fecha y se muestran todos los trabajos realizados en esa fecha
 *
 * \param lista[] eAuto
 * \param tam int
 * \param trabajos[] eTrabajo
 * \param tam_trabajos int
 * \param servicios[] eServicio
 * \param tam_servicios int
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tam_colores int
 * \param tam_marca int
 * \return int
 *
 */
int informarFechaServicios(eAuto lista[],int tam,eTrabajo trabajos[],int tam_trabajos, eServicio servicios[],int tam_servicios, eMarca marcas[], eColor colores[], int tam_colores,int tam_marca );


#endif // TRABAJO_H_INCLUDED
