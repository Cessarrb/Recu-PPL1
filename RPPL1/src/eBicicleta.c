#include "eBicicleta.h"


void HardcodeoDatosBicicleta(eBicicleta listaB[], int tamB)
{
    int i;
    eBicicleta listaHard[]={{25, "Specialized", 26, "Rojo", OCUPADO},{26, "Merida", 12, "Marron", OCUPADO},
    						{27, "Trek", 16, "Azul", OCUPADO},{28, "Scott", 22, "Amarillo", OCUPADO},{29, "Mars", 24, "Verde", OCUPADO}};

    for(i=0;i<tamB;i++)
    {
    	listaB[i]=listaHard[i];
    }
}

int BuscarBiciPorId(eBicicleta listaB[], int tamB, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (listaB!=NULL && tamB>0)
	{
		for (i=0;i<tamB;i++)
		{
			if (listaB[i].idBicicleta==id && listaB[i].isEmpty==OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}

void MostrarUnaBicicleta(eBicicleta bicicleta)
{
	printf("%2d %15s %10d %15s\n", bicicleta.idBicicleta, bicicleta.marca, bicicleta.rodadoBicicleta, bicicleta.color);
}

int MostrarBicicletas(eBicicleta listaB[], int tamB)
{
	int rtn=0;
	int i;

	if (listaB != NULL && tamB>0)
	{
		printf("%2s %15s %10s %15s\n", "ID", "MARCA", "RODADO", "COLOR");

		for(i=0;i<tamB;i++)
		{
			if(listaB[i].isEmpty == OCUPADO)
			{
				MostrarUnaBicicleta(listaB[i]);
				rtn=1;
			}
		}
	}

	return rtn;
}
