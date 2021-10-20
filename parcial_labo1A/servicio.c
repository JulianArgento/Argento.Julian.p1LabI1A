#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "servicio.h"
#include "utn.h"


int mostrarServicios(eServicio lavados[], int tam)
{

    int todoOk = 0;

	if(lavados != NULL && tam > 0)
	{
		printf("*** Servicios ***\n");
		printf(" Id    Descripcion   Precio\n");
		for(int i = 0; i < tam; i++)
		{
			printf("%d    %s   %.2f\n", lavados[i].id, lavados[i].descripcion, lavados[i].precio);
		}

		todoOk = 1;
	}
	return todoOk;
}

int cargarServicio(eServicio lavados[], int tam, int idServicio , char descServicio[])
{
	int todoOk = 0;
	if(lavados != NULL && tam > 0 && descServicio != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lavados[i].id == idServicio)
			{
				strcpy(descServicio, lavados[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
