#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[21];



}eMarca;

/** \brief muestra el contenido del array de marcas.
 *
 * \param marcas[] eMarca array de marcas
 * \param tam int tam de el array
 * \return int devuelve 1 en caso de poder mostrarlo, 0 en caso de error
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);


/** \brief carga en el string ingresado por parametro la descripcion de la marca que tenga el mismo id que el ingresado
 *
 * \param marcas[] eMarca array de marcas
 * \param tam int tam del array
 * \param idMarca int id de la marca que desea cargar
 * \param descMarca[] char string donde se cargara la descripcion de la marca
 * \return int 1 en caso de poder cargarlo, 0 en caso de error
 *
 */
int cargarMarca(eMarca marcas[], int tam, int idMarca , char descMarca[]);

#endif // MARCA_H_INCLUDED
