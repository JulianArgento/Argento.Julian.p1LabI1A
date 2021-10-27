#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "auto.h"


#endif // DATAWAREHOUSE_H_INCLUDED

/** \brief hardcodea el array de autos, pidiendo la cantidad de autos que se deben hardcodear.
 *
 * \param lista[] eAuto array de autos a hardcodear
 * \param tam int tam del array
 * \param cant int cantidad de autos a hardcodear
 * \param pId int* puntero al id, que se asignara a cada auto y se incrementara
 * \return int retorna 1 en caso de poder hardcodearlo, 0 en caso de error
 *
 */
int hardcodearAutos(eAuto lista[], int tam, int cant, int* pId);
