#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dataWarehouse.h"
#include "auto.h"




int idColores[10] = {5001, 5002, 5000, 5001, 5001, 5003, 5004, 5002, 5004, 5001};

int idMarcas[10] = {1001, 1002, 1002, 1001, 1001, 1003, 1000, 1002, 1000, 1001};

char cajas[10]= {'m','a','m','m','m','a','m','m','m','a'};

int hardcodearAutos(eAuto lista[], int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			lista[i].idColor= idColores[i];
			lista[i].idMarca=idMarcas[i];
			lista[i].caja=cajas[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}



