#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "marca.h"
#include "utn.h"


int mostrarMarcas(eMarca marcas[], int tam)
{

    int todoOk = 0;

	if(marcas != NULL && tam > 0)
	{
		printf("*** Marcas ***\n");
		printf(" Id    Marcas\n");
		for(int i = 0; i < tam; i++)
		{
			printf("%d    %10s\n", marcas[i].id, marcas[i].descripcion);
		}

		todoOk = 1;
	}
	return todoOk;
}

int cargarMarca(eMarca marcas[], int tam, int idMarca , char descMarca[])
{
	int todoOk = 0;
	if(marcas != NULL && tam > 0 && descMarca != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(marcas[i].id == idMarca)
			{
				strcpy(descMarca, marcas[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


