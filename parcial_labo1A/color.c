#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "utn.h"


int mostrarColores(eColor colores[], int tam)
{

    int todoOk = 0;

	if(colores != NULL && tam > 0)
	{
		printf("*** Colores ***\n");
		printf(" Id    Colores\n");
		for(int i = 0; i < tam; i++)
		{
			printf("%d    %10s\n", colores[i].id, colores[i].nombreColor);
		}

		todoOk = 1;
	}
	return todoOk;
}

int cargarColor(eColor colores[], int tam, int idColor , char nombreColor[])
{
	int todoOk = 0;
	if(colores != NULL && tam > 0 && nombreColor != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(colores[i].id == idColor)
			{
				strcpy(nombreColor, colores[i].nombreColor);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


