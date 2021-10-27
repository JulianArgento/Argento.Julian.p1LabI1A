
#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"
#include "servicio.h"


typedef struct{

    int id;
    int idMarca;
    int idColor;
    char caja;
    int isEmpty;

}eAuto;



/** \brief inicializa de manera logica el array de autos, poniendo el campo isEmpty en 1
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array
 * \return int devuelve 1 en caso de que se haya podido inicializar y 0 en caso de error
 *
 */
int inicializarAutos(eAuto lista[], int tam);



/** \brief busca en un array de autos la primera posicion vacia (donde el isEmpty sea 1).
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array
 * \return int devuelve el indice de la posicion libre, o -1 en caso de no encontrar ninguna
 *
 */
int buscarLibre(eAuto lista[], int tam);



/** \brief pide que se ingrese los datos de un auto y lo da de alta en la primera posicion libre
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tam_marca int tam del array de marcas
 * \param pId int* puntero a id, utilizado para asignar y aumentar el id
 * \return int devuelve 1 en caso de alta exitosa y 0 en caso de error
 *
 */
int altaAuto(eAuto lista[], int tam, eColor colores[] , int tam_colores , eMarca marcas[], int tam_marca,int* pId);



/** \brief recibe los datos de un auto y lo imprime en pantalla
 *
 * \param unAuto eAuto auto a mostrar
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_Marca int tam del array de marcas
 * \return void
 *
 */
void mostrarAuto(eAuto unAuto, eMarca marcas[], eColor colores[], int tam_colores,int tam_Marca);



/** \brief imprime en pantalla de forma encolumnada el array de autos
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_Marca int tam del array de marcas
 * \return int retorna 1 en caso de exito y 0 en caso de error
 *
 */
int mostrarAutos(eAuto lista[],int tam, eMarca marcas[], eColor colores[], int tam_colores,int tam_Marca);



/** \brief recibe un id y busca un auto con ese id en el array ingresado, retornando el indice en donde se encuentra
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param id int id del auto a buscar
 * \return int indice del auto buscado, o -1 en caso de que no exista o en caso de error
 *
 */
int buscarAutoId(eAuto lista[], int tam, int id);



/** \brief da de baja un auto de manera logica (isEmpty en 1)
 *
 * \param lista[] eAuto array de autos
 * \param colores[] eColor array de colores
 * \param marcas[] eMarca array de nmarcas
 * \param tam int tam del array de autos
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int retorna 1 en caso de baja exitosa y 0 en caso de error
 *
 */
int bajaAuto(eAuto lista[], eColor colores[],eMarca marcas[],int tam ,int tam_colores,int tam_marca);




/** \brief permite al usuario modificar el color o la marca de un auto del array.
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param colores[] eColor array de colores
 * \param marcas[] eMarca array de marcas
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int retorna 1 en caso de modificacion exitosa y 0 en caso de error
 *
 */
int modificarAuto(eAuto lista[], int tam, eColor colores[], eMarca marcas[], int tam_colores, int tam_marca);



/** \brief ordena el array de autos por marca y, en caso de igualdad de marca, por id.
 *
 * \param lista[] eAuto array de autos a ordenar
 * \param tam int tam del array
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int ordenarAutos(eAuto lista[], int tam);



/** \brief checkea si al menos 1 auto fue dado de alta
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array
 * \return int retorna 1 en caso de que haya algun auto, retorna 0 si no hay autos dados de alta
 *
 */
int checkAutoCargado(eAuto lista[],int tam);




/** \brief pide al usuario elegir un color y luego muestra el contenido del array de autos filtrado por el color elegido
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_Marca int tam del array de marcas
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutoColor(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_Marca);




/** \brief pide al usuario elegir una marca y luego muestra los autos del array de autos que tengan como marca la elegida
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutoMarca(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca);



/** \brief informa que promedio de autos tiene caja automatica, y que promedio tiene caja manual
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int informarPromedioCaja(eAuto lista[],int tam);



/** \brief muestra los autos filtrados por caja, primero los de caja automatica y luego los de caja manual
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutosCaja(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca);






/** \brief pide al usuario que elija un color y una marca de la lista, cuenta los autos que sean de esa marca y tengan ese color y devuelve la suma
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param marcas[] eMarca array de marcas
 * \param colores[] eColor array de colores
 * \param tam_colores int tam del array de colores
 * \param tam_marca int tam del array de marcas
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutoMarcaColor(eAuto lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca);






/** \brief retorna el nombre de la marca (o las marcas, en caso de empate) mas elegidas entre el array de autos
 *
 * \param lista[] eAuto array de autos
 * \param tam int tam del array de autos
 * \param marcas[] eMarca array de marcas
 * \param tam_marca int tam del array de marcas
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int informeMarcasMasElegidas(eAuto lista[],int tam,eMarca marcas[],int tam_marca);




#endif // AUTO_H_INCLUDED
