#include "eFormaPago.h"

int BuscarPagoPorId(eFormaPago listaP[], int tamP, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (listaP != NULL && tamP>0)
	{
		for (i=0;i<tamP;i++)
		{
			if (listaP[i].idFormaDePago==id)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}


void HardcodeoDatosFormaPago(eFormaPago listaP[], int tamP)
{
    int i;
    eFormaPago listaHard[]={{1, "Mercado Pago", "Sí", "Opcional"},{2, "Tarjeta de credito", "Sí", "Opcional"},
    						{3, "Efectivo", "No", "Opcional"},{4, "Tarjeta de debito", "Sí", "Opcional"},
							{5, "Cheque nominativo", "Si", "Opcional"},{6, "Por definir", "Opcional", "Opcional"}};

    for(i=0;i<tamP;i++)
    {
    	listaP[i]=listaHard[i];
    }
}

void MostrarUnaFormaDePago(eFormaPago pago)
{
	printf("%2d %20s %15s %20s\n", pago.idFormaDePago, pago.descripcionPago, pago.bancarizado, pago.numOperacion);
}

int MostrarFormasDePago(eFormaPago listaP[], int tamP)
{
	int rtn=0;
	int i;

	if (listaP != NULL && tamP>0)
	{
		printf("%2s %20s %15s %20s\n", "ID", "DESCRIPCION", "BANCARIZADO", "NUM. DE OPERACION");

		for(i=0;i<tamP;i++)
		{
			MostrarUnaFormaDePago(listaP[i]);
			rtn=1;
		}
	}

	return rtn;
}
