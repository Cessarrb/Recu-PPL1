#include "Nexo.h"
#define TS 4
#define TT 15
#define TB 5
#define TP 6
#define TC 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_AUX 50
#define VACIO -1
#define OCUPADO 0

int main(void)
{
	setbuf(stdout, NULL);

	int idTrabajoIncremental = 9;
	int opcion;

	//Estructuras
	eTrabajo listaT[TT];
	eServicio listaS[TS];
	eBicicleta listaB[TB];
	eFormaPago listaP[TP];
	eCliente listaC[4];

	InicializarTrabajo(listaT, TT);
	//Hardcodeo
	HardcodeoDatosTrabajos(listaT, 8);
	HardcodeoDatosBicicleta(listaB, TB);
	HardcodeoDatosServicios(listaS, TS);
	HardcodeoDatosFormaPago(listaP, TP);
	HardcodeoDatosClientes(listaC, TC);


	do
	{
		opcion=Menu();
		switch(opcion)
		{
			case 1:
				if(DarAltaTrabajo(listaT, TT, listaS, TS, listaB, TB, listaP, TP, idTrabajoIncremental, listaC, TC))
				{
					idTrabajoIncremental+=1;
					printf("Se dio de alta!\n");
				}
				else
				{
					printf("No hay espacio.\n");
				}
				break;
			case 2:
				switch(ModificarTrabajo(listaT, TT, listaS, TS, listaB, TB, listaC, 4))
				{
					case 0:
						printf("No hay datos cargados.\n");
						break;
					case 1:
						printf("Dato modificado con exito!\n");
						break;
					case 2:
						printf("Modificacion cancelada\n");
						break;
				}
				break;
			case 3:
				switch(DarBajaTrabajo(listaT, TT, listaS, TS, listaB, TB, listaC, TC))
				{
					case 0:
						printf("No hay datos cargados.\n");
						break;
					case 1:
						printf("Baja exitosa!\n");
						break;
					case 2:
						printf("Baja cancelada\n");
						break;
				}
				break;
			case 4:
				OrdenarPorFecha(listaT, TT, listaB, TB);
				if(!MostrarTrabajos(listaT, TT, listaS, TS, listaB, TB, listaC, TC))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 5:
				MostrarServicios(listaS, TS);
				break;
			case 6:
				if(!MostrarServiciosPrestados(listaT, TT, listaS, TS))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 7:
				OrdenarPorMarca(listaT, TT, listaB, TB);
				if(!MostrarTrabajos(listaT, TT, listaS, TS, listaB, TB, listaC, TC))
				{
					printf("Ocurrio un error.\n");
				}
				break;
			case 8:
				if(!ServicioConMasTrabajosRealizado(listaT, TT, listaS, TS)) //El o los servicios
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 9:
				if(!ListaBicicletasPorServicio(listaT, TT, listaS, TS, listaB, TB))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 10:
				BicicletasRojasEligidasPorUsiario(listaT, TT, listaS, TS, listaB, TB);
				break;
			case 11:
				if(!ListaTrabajosConFormaDePago(listaT, TT, listaS, TS, listaB, TB, listaP, TP))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 12:
				if(!ListaTrabajoFormaDePagoMasUtilizada(listaT, TT, listaS, TS, listaB, TB, listaP, TP))
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 13:
				if(!MostrarTodosClientesConTrabajos(listaC, TC, listaT, TT, listaS, TS, listaB, TB))
				{
					printf("No hay datos cargados.\n");
				}
				break;
		}
	}while(opcion!=14);


	return EXIT_SUCCESS;
}

