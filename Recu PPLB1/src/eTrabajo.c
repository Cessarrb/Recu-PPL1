#include "eTrabajo.h"

int Menu()
{
    int opcion;

    printf("\n\t***************\n");
    printf("  \t*     MENU    *");
    printf("\n\t***************\n");
    printf("1. ALTA TRABAJO\n");
    printf("2. MODIFICAR TRABAJO\n");
    printf("3. BAJA TRABAJO \n");
    printf("4. LISTADO TRABAJO\n");
    printf("5. LISTADO SERVICIOS\n");
    printf("6. TOTAL SERVICIOS PRESTADOS\n");
    printf("7. LISTADO ORDENADO POR MARCA DE BICICLETA\n");
    printf("8. SERVICIOS CON MAS TRABAJOS\n");
    printf("9. LISTADO DE SERVICIOS REALIZADOS A BICICLETAS\n");
    printf("10. CANTIDAD DE BICICLETAS ROJAS CON SERVICIO ELEGIO POR USUARIO\n");
    printf("11. LISTADO DE TRABAJOS CON FORMAS DE PAGO\n");
    printf("12. FORMA DE PAGO MAS UTILIZADA\n");
    printf("13. LISTADO DE CLIENTES CON TRABAJOS A PAGAR\n");
    opcion=GetIntConRango("Elija una opcion: ", "Error", 1, 14);

    return opcion;
}

void InicializarTrabajo(eTrabajo listaT[], int tamT)
{
	int i;

	for(i=0;i<tamT;i++)
	{
		listaT[i].isEmpty = VACIO;
	}
}

void HardcodeoDatosTrabajos(eTrabajo listaT[], int tamT)
{
    int i;
    eTrabajo listaHard[]={{1,1, 25, 1, 20000, {10,9,1818}, OCUPADO},{2,2, 26, 2, 20001, {24,2,1904}, OCUPADO},
    						{3,3, 27, 3, 20002,{6,4,2019}, OCUPADO},{4,3, 28, 4, 20003, {17,5,2019}, OCUPADO},
							{5,4, 29, 1, 20001, {15,5,2020}, OCUPADO},{6,4, 28, 6, 20002, {1,5,2012}, OCUPADO},
    						{7,2, 26, 1, 20001, {15,5,2020}, OCUPADO},{8,2, 25, 5, 20003, {1,5,2021}, OCUPADO}};

    for(i=0;i<tamT;i++)
    {
    	listaT[i]=listaHard[i];
    }
}

int BuscarLibre(eTrabajo listaT[], int tamT)
{
	int i;
	int index;
	index = -1;

	for(i=0;i<tamT;i++)
	{
		if(listaT[i].isEmpty==VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int BuscarTrabajoPorId(eTrabajo listaT[], int tamT, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (listaT!=NULL && tamT>0)
	{
		for (i=0;i<tamT;i++)
		{
			if (listaT[i].id==id && listaT[i].isEmpty==OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}
