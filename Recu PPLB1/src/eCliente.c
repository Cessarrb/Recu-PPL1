#include "eCliente.h"


void HardcodeoDatosClientes(eCliente listaClientes[], int tamC)
{
    int i;
    eCliente listaHard[]={{1,"Dante Ferro", 41895457, 1175045604, OCUPADO},{2,"Maria Gimenez",40456784,1145946454, OCUPADO},{3,"Carlos Villa", 42789694,1178946545, OCUPADO},{4,"Lucas Gonzales",42369748,1145789865, OCUPADO}};

    for(i=0;i<tamC;i++)
    {
    	listaClientes[i]=listaHard[i];
    }
}

void MostrarUnCliente(eCliente Cliente)
{
	printf("%2d %15s %10d %15d\n", Cliente.id, Cliente.nombre, Cliente.dni, Cliente.telefono);
}

void MostrarTodosLosClientes(eCliente listaClientes[], int tamC){
	int i;

	for(i=0;i<tamC;i++)
	{
		if(i==0){
			printf("%2s %15s %10s %15s\n", "ID", "NOMBRE", "DNI", "TELEFONO");
		}
		MostrarUnCliente(listaClientes[i]);
	}
}

int BuscarClientePorId(eCliente listaC[], int tamC, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (listaC!=NULL && tamC>0)
	{
		for (i=0;i<tamC;i++)
		{
			if (listaC[i].id==id)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}
