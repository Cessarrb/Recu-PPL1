#include "eServicio.h"

int BuscarServicioPorId(eServicio listaS[], int tamS, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (listaS!=NULL && tamS>0)
	{
		for (i=0;i<tamS;i++)
		{
			if (listaS[i].id==id && listaS[i].isEmpty==OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}

void HardcodeoDatosServicios(eServicio listaS[], int tamS)
{
    int i;
    eServicio listaHard[]={{20000, "Limpieza", 250, OCUPADO},{20001, "Parche", 300, OCUPADO},
						{20002, "Centrado", 400, OCUPADO},{20003, "Cadena", 350, OCUPADO}};

    for(i=0;i<tamS;i++)
    {
    	listaS[i]=listaHard[i];
    }
}

void MostrarUnServicio(eServicio servicio)
{
	printf("%5d %15s %10.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int MostrarServicios(eServicio listaS[], int tamS)
{
	int rtn=0;
	int i;

	if (listaS != NULL && tamS>0)
	{
		printf("%5s %15s %10s\n", "ID", "DESCRIPCION", "PRECIO");

		for(i=0;i<tamS;i++)
		{
			if(listaS[i].isEmpty == OCUPADO)
			{
				MostrarUnServicio(listaS[i]);
				rtn=1;
			}
		}
	}

	return rtn;
}
