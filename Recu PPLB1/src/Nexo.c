#include "Nexo.h"


eTrabajo PedirDatos(eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP, int idTrabajoIncremental,eCliente listaC[],int tamC)
{
	eTrabajo trabajo;

	printf("Numero de ID otorgado: %d\n", idTrabajoIncremental);
	MostrarTodosLosClientes(listaC, tamC);
	trabajo.idCliente=GetIntConRango("Ingrese el ID del cliente:  ", "Error", 1, 4);
	MostrarBicicletas(listaB, tamB);
	trabajo.idBicicleta=GetIntConRango("Ingrese el ID de la bicicleta que desea darle un servicio: ", "Error", 25, 29);
	MostrarServicios(listaS, tamS);
	trabajo.idServicio=GetIntConRango("Ingrese el ID del servicio que desea: ", "Error", 20000, 20003);
	MostrarFormasDePago(listaP, tamP);
	trabajo.idFormaDePago=GetIntConRango("Ingrese el ID de la forma de pago que desea: ", "Error", 1, 6);
	trabajo.fecha.dia=GetIntConRango("Ingrese el dia, del 1 al 31: ", "Error", 1, 31);
	trabajo.fecha.mes=GetIntConRango("Ingrese el mes, del 1 al 12: ", "Error", 1, 12);
	trabajo.fecha.anio=GetIntConRango("Ingrese el año, de 1999 a 2021: ", "Error", 1999, 2021);
	trabajo.isEmpty=OCUPADO;

	return trabajo;
}

int DarAltaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP, int idTrabajoIncremental,eCliente listaC[],int tamC)
{
    int i;
    int rtn=0;

    i=BuscarLibre(listaT, tamT);

    if(i!=-1)
    {
    	 listaT[i] = PedirDatos(listaS, tamS, listaB, tamB, listaP, tamP, idTrabajoIncremental, listaC,tamC);
    	 listaT[i].id=idTrabajoIncremental;
    	 rtn=1;
    }

    return rtn;
}

int DarBajaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaCs[], int tamC)
{
    int id;
    int index;
    char respuesta;
    int rtn =0;
    int flag =0;

    if(MostrarTrabajos(listaT, tamT, listaS, tamS, listaB, tamB, listaCs, tamC))
    {
    	flag=1;
    }

    if(flag)
    {
    	 id=GetInt("Ingrese el ID del trabajo que desea dar de baja: ", "Error");
    	 while(BuscarTrabajoPorId(listaT, tamT, id)==-1)
		 {
    		 printf("Error. ");
			 id=GetInt("Ingrese el ID del trabajo que desea dar de baja: ", "Error");
			 flag++;
			 if(flag==5)//Hago uso de la bandera como un contador para romper el while por varios intentos fallidos
			 {
				 printf("Supero el limite de intentos para ingresar un ID, se regresara al menu principal.\n");
				 rtn=2;
				 break;
			 }
		 }
    	 if(flag!=5)
    	 {
    		 index=BuscarTrabajoPorId(listaT, tamT, id);
    		 respuesta=GetChar("Esta seguro que desea dar de baja el trabajo? Ingrese [s] para continuar o [n] para cancelar: ", "Error, [s] para continuar o [cualquier letra] para cancelar: ");
    		 respuesta=tolower(respuesta);
    		 rtn=2;
			 if(respuesta=='s')
			 {
				 listaT[index].isEmpty=VACIO;
				 rtn=1;
			 }
    	 }
    }

    return rtn;
}

int ModificarTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaCs[], int tamC)
{
	int id;
	char respuesta;
	int opcion;
	int flag=0;
	int rtn=0;
	int index;


	if(MostrarTrabajos(listaT, tamT, listaS, tamS, listaB, tamB, listaCs, tamC))
	{
		flag=1;
	}

	if(flag)
	{

		id=GetInt("Ingrese el ID del trabajo que desea modificar: ", "Error");
		while(BuscarTrabajoPorId(listaT, tamT, id)==-1)
		{
			printf("Error. ");
			id=GetInt("Ingrese el ID del trabajo que desea modificar: ", "Error");
			flag++;
			if(flag==5)//Hago uso de la bandera como un contador para romper el while por varios intentos fallidos
			{
				printf("Supero el limite de intentos para ingresar un ID, se regresara al menu principal.\n");
				break;
			}
		}
		if(flag!=5)
		{
			index=BuscarTrabajoPorId(listaT, tamT, id);
			respuesta=GetChar("Esta seguro que desea modificar el trabajo? Ingrese [s] para continuar o [cualquier letra] para cancelar: ", "Error, [s] para continuar o [cualquier letra] para cancelar: ");
			respuesta=tolower(respuesta);
			rtn=2;
			if(respuesta=='s')
			{
				printf("1-BICICLETA\n");
				printf("2-SERVICIO\n");
				printf("3-SALIR\n");
				rtn=2;
				opcion=GetIntConRango("Ingrese una opcion: ", "Error", 1, 3);
				switch(opcion)
				{
					case 1:
						MostrarBicicletas(listaB, tamB);
						listaT[index].idBicicleta=GetIntConRango("Ingrese el ID de la nueva bicicleta: ", "ERROR", 25, 29);
						rtn=1;
						break;
					case 2:
						MostrarServicios(listaS, tamS);
						listaT[index].idServicio=GetIntConRango("Ingrese el ID del nuevo servicio: ", "ERROR", 20000, 20003);
						rtn=1;
						break;
						//case 2 id con la tabla de los metodos de pago
				}
			}
		}
	}

	return rtn;
}

int MostrarUnTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaC[], int tamC)
{
	int rtn=0;
	char descripcionServicio[30];
	char marcaBicicleta[30];
	int indexServicio;
	int indexBicicleta;
	int rodado;
	char color[30];
	int indexCliente;

	if(listaS != NULL && tamS >0)
	{
		indexServicio=BuscarServicioPorId(listaS, tamS, trabajo.idServicio);
		if(indexServicio!=-1)
		{
			strcpy(descripcionServicio, listaS[indexServicio].descripcion);
		}
		else
		{
			strcpy(descripcionServicio, "ERROR");
		}

		indexBicicleta=BuscarBiciPorId(listaB, tamB, trabajo.idBicicleta);
		if(indexBicicleta!=-1)
		{
			strcpy(marcaBicicleta, listaB[indexBicicleta].marca);
			strcpy(color, listaB[indexBicicleta].color);
			rodado=listaB[indexBicicleta].rodadoBicicleta;
		}
		indexCliente=BuscarClientePorId(listaC, tamC, trabajo.idCliente);


		printf("%10d %20s %15s %10d %10s %10s %8d-%d-%d\n", trabajo.id, listaC[indexCliente].nombre, marcaBicicleta, rodado, color, descripcionServicio,
														trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
		rtn=1;
	}

	return rtn;
}

int MostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaC[], int tamC)
{
	int i;
	int rtn=0;

	if (listaT != NULL && tamT>0)
	{
		for(i=0;i<tamT;i++)
		{
			if(listaT[i].isEmpty == OCUPADO)
			{
				if(rtn==0) //uso la variable rtn para mostrar el encabezado
				{
					printf("%10s %20s %15s %10s %10s %10s %15s\n", "ID TRABAJO", "NOMBRE CLIENTE", "MARCA", "RODADO", "COLOR", "SERVICIO", "FECHA");
				}
				MostrarUnTrabajo(listaT[i], listaS, tamS, listaB, tamB,listaC,tamC);
				rtn=1;
			}
		}
	}

	return rtn;
}

void MostrarUnServicioPrestado(eAuxiliar listaAux)
{
	printf("%8s %7d %18.2f\n", listaAux.descripcion, listaAux.contador, listaAux.acumulador);

}

int MostrarServiciosPrestados(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	eAuxiliar listaAux[tamS];
	int i;
	int j;
	int rtn=0;
	InicializarAxuliar(listaAux, listaT, tamT, listaS, tamS);
	ContadorAcumuladorAxuliar(listaAux, listaT, tamT, listaS, tamS);

	if(listaT !=NULL && listaS != NULL && tamT>0)
	{
		for(i=0;i<tamS;i++)
		{
			for(j=0;j<tamT;j++)
			{
				if(listaAux[i].isEmpty==OCUPADO)
				{
					if(rtn==0)
					{
						printf("%8s %10s %18s\n","SERVICIO", "CANTIDAD", "TOTAL PESOS");
					}
					MostrarUnServicioPrestado(listaAux[i]);
					rtn=1;
					break;
				}
			}
		}
	}

	return rtn;
}


int InicializarAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	int rtn=0;
    int i;

    for(i=0;i<tamS;i++)
    {
        auxiliar[i].id=listaS[i].id;
        strcpy(auxiliar[i].descripcion, listaS[i].descripcion);
        auxiliar[i].contador=0;
        auxiliar[i].acumulador=0;
        auxiliar[i].isEmpty=VACIO;
        rtn=1;
    }

    return rtn;
}

int ContadorAcumuladorAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{

	int rtn=0;
    int i;
    int j;

    if(auxiliar != NULL && listaT != NULL && tamT>0 && listaS != NULL && tamS>0)
    {
		for(i=0;i<tamT;i++)
		{
			for(j=0;j<tamS;j++)
			{
				if(auxiliar[j].id==listaT[i].idServicio)
				{
					auxiliar[j].contador++; //Lo uso para una funcion
					auxiliar[j].acumulador+=listaS[j].precio; //Lo uso para otra funcion
					auxiliar[j].isEmpty=OCUPADO;
				}
			}
		}
    }

    return rtn;
}


void OrdenarPorFecha(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB)
{
	int i;
	int j;
	int indexBicicleta;
	int indexBicicletaDos;
	eTrabajo auxiliar;

	if(listaT != NULL && tamT>0 && listaB != NULL && tamB>0)
	{
			for(i=0;i<tamT-1;i++)
			{
				for(j=i+1;j<tamT;j++)
				{
					indexBicicleta = BuscarBiciPorId(listaB, tamB, listaT[i].idBicicleta);
					indexBicicletaDos = BuscarBiciPorId(listaB, tamB, listaT[j].idBicicleta);
					if(listaT[i].fecha.anio>listaT[j].fecha.anio)
					{
						auxiliar=listaT[i];
						listaT[i]=listaT[j];
						listaT[j]=auxiliar;
					}
					if(listaT[i].fecha.anio==listaT[j].fecha.anio && strcmp(listaB[indexBicicleta].marca, listaB[indexBicicletaDos].marca)>0)
					{
						auxiliar=listaT[i];
						listaT[i]=listaT[j];
						listaT[j]=auxiliar;
					}
				}
			}
	}
}

void OrdenarPorMarca(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB)
{
	eTrabajo auxTrabajo;
	int i;
	int j;
	int indexBicicleta;
	int indexBicicletaDos;

	if(listaT != NULL && tamT>0 && listaB != NULL && tamB>0)
	{
		for(i=0;i<tamT-1;i++)
		{
			for(j=i+1;j<tamT;j++)
			{
				indexBicicleta = BuscarBiciPorId(listaB, tamB, listaT[i].idBicicleta);
				indexBicicletaDos = BuscarBiciPorId(listaB, tamB, listaT[j].idBicicleta);

				if (strcmp(listaB[indexBicicleta].marca, listaB[indexBicicletaDos].marca)>0)
				{
					auxTrabajo=listaT[i];
					listaT[i]=listaT[j];
					listaT[j]=auxTrabajo;
				}
			}
		}
	}
}

int ServicioConMasTrabajosRealizado(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	eAuxiliar listaAux[tamS];
	int rtn=0;
	int i=0;
	int maxServicio;
	int flag=0;
	int indexServicio;

	InicializarAxuliar(listaAux, listaT, tamT, listaS, tamS);
	ContadorAcumuladorAxuliar(listaAux, listaT, tamT, listaS, tamS);

	for(i=0;i<tamS;i++)
	{
		if(listaAux[i].isEmpty==OCUPADO)
		{
			if(flag==0 || listaAux[i].contador>maxServicio)
			{
				maxServicio=listaAux[i].contador;
				flag=1;
			}
		}
	}

	for(i=0;i<tamS;i++)
	{
		if(listaAux[i].isEmpty==OCUPADO)
		{
			if(listaAux[i].contador==maxServicio)
			{
				indexServicio=BuscarServicioPorId(listaS, tamS, listaAux[i].id);
				printf("El servicio con mayor cantidad de trabajos es: %s con %d trabajos\n", listaS[indexServicio].descripcion, maxServicio);
				rtn=1;
			}
		}
	}

	return rtn;
}


int ListaBicicletasPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
    int i;
    int j;
    int indexBicicleta;
    int rtn=0;

    if(listaT != NULL && listaS != NULL && tamS>0 && listaB != NULL && tamB>0)
    {
		for(i=0;i<tamS;i++)
		{
			printf("---------------------------------------------\n");
			printf("Servido de %s | Precio: %.2f\n", listaS[i].descripcion, listaS[i].precio);
			printf("%2s %15s %10s %15s\n", "ID", "MARCA", "RODADO", "COLOR");
			for(j=0;j<tamT;j++)
			{
				if(listaT[j].idServicio==listaS[i].id)
				{
					indexBicicleta=BuscarBiciPorId(listaB, tamB, listaT[j].idBicicleta);
					printf("%2d %15s %10d %15s\n", listaB[indexBicicleta].idBicicleta, listaB[indexBicicleta].marca,
							listaB[indexBicicleta].rodadoBicicleta, listaB[indexBicicleta].color);
					rtn=1;
				}
			}
			printf("---------------------------------------------\n");
		}
    }

    return rtn;
}

int BicicletasRojasEligidasPorUsiario(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
	int i;
	int j;
	int indexBicicleta;
	int rtn=0;
	int contador=0;

	for(i=0;i<tamS;i++)
	{
		for(j=0;j<tamT;j++)
		{
			if(listaT[j].idServicio==listaS[i].id)
			{
				indexBicicleta=BuscarBiciPorId(listaB, tamB, listaT[j].idBicicleta);
				if(strcmp(listaB[indexBicicleta].color, "Rojo")==0)
				{
					contador++;
					rtn=1;
				}
			}
		}
	}

	printf("La cantidad de bicicletas rojas con servicio elegido por el usuario es: %d", contador);

	return rtn;
}

int MostrarUnTrabajOConFormaDePago(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP)
{
	int rtn=0;
	char descripcionServicio[30];
	char marcaBicicleta[30];
	int indexServicio;
	int indexBicicleta;
	int indexFormaDePago;
	int rodado;
	char color[30];

	if(listaS != NULL && tamS >0)
	{
		indexServicio=BuscarServicioPorId(listaS, tamS, trabajo.idServicio);
		if(indexServicio!=-1)
		{
			strcpy(descripcionServicio, listaS[indexServicio].descripcion);
		}
		else
		{
			strcpy(descripcionServicio, "ERROR");
		}

		indexBicicleta=BuscarBiciPorId(listaB, tamB, trabajo.idBicicleta);
		if(indexBicicleta!=-1)
		{
			strcpy(marcaBicicleta, listaB[indexBicicleta].marca);
			strcpy(color, listaB[indexBicicleta].color);
			rodado=listaB[indexBicicleta].rodadoBicicleta;
		}

		indexFormaDePago=BuscarPagoPorId(listaP, tamP, trabajo.idFormaDePago);

		printf("%2d %15s %10d %10s %10s %20s %15s %20s %8d-%d-%d\n", trabajo.id, marcaBicicleta, rodado, color, descripcionServicio, listaP[indexFormaDePago].descripcionPago,
														listaP[indexFormaDePago].bancarizado, listaP[indexFormaDePago].numOperacion,
														trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
		rtn=1;
	}

	return rtn;
}

int ListaTrabajosConFormaDePago(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP)
{
	int i;
	int rtn=0;

	if (listaT != NULL && tamT>0)
	{
		for(i=0;i<tamT;i++)
		{
			if(listaT[i].isEmpty == OCUPADO)
			{
				if(rtn==0) //uso la variable rtn para mostrar el encabezado
				{
					printf("%2s %15s %10s %10s %10s %20s %15s %20s %15s\n", "ID", "MARCA", "RODADO", "COLOR", "SERVICIO", "FORMA DE PAGO", "BANCARIZADO", "NUM. DE OPERACION", "FECHA");
				}
				MostrarUnTrabajOConFormaDePago(listaT[i], listaS, tamS, listaB, tamB, listaP, tamP);
				rtn=1;
			}
		}
	}

	return rtn;
}

int ListaTrabajoFormaDePagoMasUtilizada(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP)
{
	eAuxiliar listaAux[tamP];
	int rtn=0;
	int i=0;
	int j=0;
	int maxFormaDePago;

	InicializarAxuliarFormaDePaga(listaAux, listaT, tamT, listaP, tamP);
	ContadorAuxiliarFormaDePaga(listaAux, listaT, tamT, listaP, tamP);
	maxFormaDePago=MaximoAuxiliarFormaDePago(listaAux, listaT, tamT, listaP, tamP);

	for(i=0;i<tamP;i++)
	{
		for(j=0;j<tamT;j++)
		{
			if(listaAux[i].contadorFormaDePago==maxFormaDePago && listaAux[i].id==listaT[j].idFormaDePago)
			{
				if(rtn==0) //uso la variable rtn para mostrar el encabezado
				{
					printf("%2s %15s %10s %10s %10s %20s %15s %20s %15s\n", "ID", "MARCA", "RODADO", "COLOR", "SERVICIO", "FORMA DE PAGO", "BANCARIZADO", "NUM. DE OPERACION", "FECHA");
				}
				MostrarUnTrabajOConFormaDePago(listaT[j], listaS, tamS, listaB, tamB, listaP, tamP);
				rtn=1;
			}
		}
	}
	return rtn;

}


int InicializarAxuliarFormaDePaga(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP)
{
	int i;
	int rtn=0;

	for(i=0;i<tamP;i++)
	{
		auxiliar[i].id=listaP[i].idFormaDePago;
		strcpy(auxiliar[i].descripcion, listaP[i].descripcionPago);
		strcpy(auxiliar[i].bancarizado, listaP[i].bancarizado);
		strcpy(auxiliar[i].numOperacion, listaP[i].numOperacion);
		auxiliar[i].contadorFormaDePago=0;
		rtn=1;
	}

	return rtn;
}

void ContadorAuxiliarFormaDePaga(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP)
{
	int i;
	int j;

	for(i=0;i<tamT;i++)
	{
		for(j=0;j<tamP;j++)
		{
			if(auxiliar[j].id==listaT[i].idFormaDePago)
			{
				auxiliar[j].contadorFormaDePago++;
			}
		}
	}
}

int MaximoAuxiliarFormaDePago(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP)
{
	int i;
	int maxServicio;
	int flag=0;

	for(i=0;i<tamP;i++)
	{
		if(flag==0 || auxiliar[i].contadorFormaDePago>maxServicio)
		{
			maxServicio=auxiliar[i].contadorFormaDePago;
			flag=1;
		}
	}

	return maxServicio;
}

int ClienteConMasTrabajos(eTrabajo listaT[], int tamT, eCliente listaC[], int tamC)
{
	int i;
	int j;
	int maximo;
	int acumulador[tamC];
	int iDClienteMasTrabajos;
	int flag = 0;


	for(i=0;i<tamC;i++)
	{
		acumulador[i] = 0;
		for(j=0;j<tamT;j++)
		{
			if(listaC[i].id == listaT[j].idCliente)
			{
				acumulador[i]++;
			}
		}
		if(flag == 0 || acumulador[i] > maximo)
		{
			maximo = acumulador[i];
			iDClienteMasTrabajos = listaC[i].id;
			flag = 1;
		}
	}
	return iDClienteMasTrabajos;
}


int FiltroDeClientes(eTrabajo listaT[], int tamT, eBicicleta listaB[],int tamB, eCliente listaC[],int tamC, eServicio listaS[], int tamS)
{
	int rtn=0;
	int i;
	int j;
	int IdClienteMasTrabajos;
	int indexCliente;
	int indexServicio;
	int opcion;
	int flag=0;


	printf("1-Filtrar por cliente con mas trabajos y mostrar sus servicios\n");
	printf("2-Ingresar ID del cliente y listar trabajos con sus servicios\n");
	printf("3-Salir\n");
	opcion=GetInt("Ingrese una opcion: ", "Error");

	if(opcion==1)
	{
		IdClienteMasTrabajos = ClienteConMasTrabajos(listaT, tamT, listaC, tamC);
		flag=1;
	}
	else if(opcion==2)
	{
		IdClienteMasTrabajos=GetIntConRango("Ingrese el ID del cliente: ", "Error", 1, 4);
		flag=1;
	}

	if(flag==1)
	{
		for (i=0;i<tamB;i++)
		{
			if(i==0)
			{
				printf("%10s %20s %15s %15s %15s %10s %10s %10s %10s\n", "ID CLIENTE", "NOMBRE", "DNI", "TELEFONO", "MARCA", "RODADO", "COLOR", "SERVICIO", "PRECIO");
			}
			for(j=0;j<tamT;j++)
			{
				indexCliente=BuscarClientePorId(listaC, tamC, listaT[j].idCliente);
				indexServicio=BuscarServicioPorId(listaS, tamS, listaT[j].idServicio);
				if(listaT[j].idCliente == IdClienteMasTrabajos && listaT[j].idBicicleta == listaB[i].idBicicleta)
				{
					printf("%10d %20s %15d %15d %15s %10d %10s %10s %10.2f\n", listaT[j].idCliente, listaC[indexCliente].nombre, listaC[indexCliente].dni,listaC[indexCliente].telefono,
																	listaB[i].marca, listaB[i].rodadoBicicleta, listaB[i].color, listaS[indexServicio].descripcion, listaS[indexServicio].precio);
					rtn=1;
				}
			}
		}
	}
	return rtn;
}

void MostrarTodosUnCliente(eCliente Cliente, int tamC, int contador, float acumulador)
{

	printf("%10d %20s %10d %15d %20d %20.2f\n", Cliente.id, Cliente.nombre, Cliente.dni, Cliente.telefono, contador, acumulador);
}

int MostrarTodosClientes(eCliente listaC[], int tamC, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB)
{
	int i;
	int j;
	int rtn=0;
	int contador[tamC];
	float acumulador[tamC];
	int index;

	for(i=0;i<tamC;i++)
	{
		contador[i] = 0;
		acumulador[i] = 0;
		for(j=0;j<tamT;j++)
		{
			index=BuscarServicioPorId(listaS, tamS, listaT[j].idServicio);
			if(listaC[i].id == listaT[j].idCliente)
			{
				contador[i]++;
				acumulador[i]+=listaS[index].precio;
			}
		}
	}

	if (listaT != NULL && tamT>0)
	{
		for(i=0;i<tamC;i++)
		{
			for(j=0;j<tamT;j++)
			{
				if(rtn==0) //uso la variable rtn para mostrar el encabezado
				{
					printf("%10s %20s %10s %15s %20s %20s\n", "ID CLIENTE","NOMBRE", "DNI", "TELEFONO", "CANT. TRABAJOS", "PRECIO TOTAL");
				}
				if(listaC[i].id == listaT[j].idCliente)
				{
					//printf("%10d %20s %10d %15d %20d %20.2f\n", listaC[i].id, listaC[i].nombre, listaC[i].dni, listaC[i].telefono, contador[i], acumulador[i]);
					MostrarTodosUnCliente(listaC[i], tamC, contador[i], acumulador[i]);
					rtn=1;
					break;
				}
			}
		}
	}

	FiltroDeClientes(listaT, tamT, listaB, tamB, listaC, tamC, listaS, tamS);


	return rtn;
}
