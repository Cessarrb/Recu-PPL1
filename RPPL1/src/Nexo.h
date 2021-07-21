#ifndef NEXO_H_
#define NEXO_H_
#include "eTrabajo.h"
#include "eServicio.h"
#include "MiBiblioteca.h"
#include "eBicicleta.h"
#include "eFormaPago.h"
#include "eCliente.h"
typedef struct
{
	int id;
	char descripcion[TAM_AUX];
	char bancarizado[TAM_AUX];
	char numOperacion[TAM_AUX];
	int contador;
	float acumulador;
	int contadorFormaDePago;
	int isEmpty;
}eAuxiliar;

/**
 * @fn eTrabajo PedirDatos(eServicio[], int)
 * @brief Pide todos los datos de trabajo y servicio
 *
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return el trabajo y servicios cargados
 */
eTrabajo PedirDatos(eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP, int idTrabajoIncremental,eCliente listaCs[],int tamC);

/**
 * @fn int DarAlta(eTrabajo[], int, eServicio[], int)
 * @brief Si hay espacio en el array pide el ingreso de datos para cargarlos
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si se cargaron con exito los datos del trabajo o 0 si no hay espacio en el array
 */
int DarAltaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP, int idTrabajoIncremental,eCliente listaCs[],int tamC);

/**
 * @fn int DarBaja(eTrabajo[], int, eServicio[], int)
 * @brief Si hay datos cargados te muestra un listado de los trabajos para darle de baja
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return 1 si se dio de baja un trabajo o 0 si no hay datos de trabajo cargados
 */
int DarBajaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaCs[], int tamC);

/**
 * @fn int ModificarTrabajo(eTrabajo[], int, eServicio[], int)
 * @brief Se ingresa un id donde si es valido permite modificar datos del trabajo como servicio el la bicicleta al que se le da el servicio
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return 1 si la modificacion fue exitosa o 0 si no hay datos para modificar
 */
int ModificarTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaC[], int tamC);

/**
 * @fn void MostrarUnTrabajo(eTrabajo, eServicio[], int)
 * @brief Muestra un trabajo
 *
 * @param trabajo
 * @param listaS
 * @param tamS
 */
int MostrarUnTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaC[], int tamC);

/**
 * @fn int MostrarTrabajos(eTrabajo[], int, eServicio[], int)
 * @brief Si hay datos de trabajos cargados muestra un listado de todos ellos con su respectivo servicio y bicicleta
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return 1 si los datos se mostraron o 0 si no hay datos para mostrar
 */
int MostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eCliente listaC[], int tamC);


/**
 * @fn void MostrarUnServicioPrestado(eAuxiliar)
 * @brief Muestra un servicio prestado
 *
 * @param listaAux
 */
void MostrarUnServicioPrestado(eAuxiliar listaAux);

/**
 * @fn int MostrarServiciosPrestados(eAuxiliar[], eTrabajo[], int, eServicio[], int)
 * @brief Muestra una lista del total de los servicios prestados mas el precio acumulado
 *
 * @param listaAux
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return
 */
int MostrarServiciosPrestados(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void InicializarAxuliar(eAuxiliar[], eTrabajo[], int, eServicio[], int)
 * @brief Inicializa la estructura auxiliar;
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 */
int InicializarAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void ContadorAcumuladorAxuliar(eAuxiliar[], eTrabajo[], int, eServicio[], int)
 * @brief Cuenta los trabajos realizados y acumula los precios por cada uno
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 */
int ContadorAcumuladorAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void OrdenarPorFecha(eTrabajo[], int, eBicicleta[], int)
 * @brief Ordena la lista de trabajos por fecha y ante igualdad de fecha por marca
 *
 * @param listaT
 * @param tamT
 * @param listaB
 * @param tamB
 */
void OrdenarPorFecha(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB);

/**
 * @fn void OrdenarPorMarca(eTrabajo[], int, eBicicleta[], int)
 * @brief Ordena la lista de trabajos por marca de bicicleta
 *
 * @param listaT
 * @param tamT
 * @param listaB
 * @param tamB
 */
void OrdenarPorMarca(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB);

/**
 * @fn int ServicioConMasTrabajosRealizado(eTrabajo[], int, eServicio[], int)
 * @brief muestra cual es el servicio con mayor cantidad de trabajos mas la cantidad, y ante igualal de trabajos muestra ambos servicios
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return
 */
int ServicioConMasTrabajosRealizado(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void ListaBicicletasPorServicio(eTrabajo[], int, eServicio[], int, eBicicleta[], int)
 * @brief Muestra una lista de bicicletas con su respectivo servicio mas el precio del mismo
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si puede mostrar la lista 0 si no pudo
 */
int ListaBicicletasPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);


/**
 * @fn int BicicletasRojasEligidasPorUsiario(eTrabajo[], int, eServicio[], int, eBicicleta[], int)
 * @brief Muestra la cantidad de bicicletas rojas elegidas por el usuario
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si pudo contar una bicicleta 0 si no pudo
 */
int BicicletasRojasEligidasPorUsiario(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

/**
 * @fn int MostrarUnTrabajOConFormaDePago(eTrabajo, eServicio[], int, eBicicleta[], int, eFormaPago[], int)
 * @brief Muestra un trabajo con su respectiva forma de pago
 *
 * @param trabajo
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @param listaP
 * @param tamP
 * @return 1 si se puede mostrar un trabajo 0 si no pudo
 */
int MostrarUnTrabajOConFormaDePago(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

/**
 * @fn int ListaTrabajosConFormaDePago(eTrabajo[], int, eServicio[], int, eBicicleta[], int, eFormaPago[], int)
 * @brief Muestra toda la lista de trabajos todos los datos, incluyendo servicios, bicicletaas y forma de pago
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @param listaP
 * @param tamP
 * @return 1 si puede mostrar un trabajo 0 si no pudo
 */
int ListaTrabajosConFormaDePago(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

/**
 * @fn int ListaFormaDePagoMasUtilizada(eTrabajo[], int, eServicio[], int, eBicicleta[], int, eFormaPago[], int)
 * @brief Muestra una lista de los trabajos pero solo con la forma de pago mas utilizada, y ante igualdad con otras formas de pago mostraria ambas
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @param listaP
 * @param tamP
 * @return
 */
int ListaTrabajoFormaDePagoMasUtilizada(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

/**
 * @fn int InicializarAxuliarFormaDePaga(eAuxiliar[], eTrabajo[], int, eFormaPago[], int)
 * @brief Inicializa el auxiliar de la forma de pago
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaP
 * @param tamP
 * @return 1 si pude inicializar los datos 0 si no pudo
 */
int InicializarAxuliarFormaDePaga(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP);

/**
 * @fn void ContadorAuxiliarFormaDePaga(eAuxiliar[], eTrabajo[], int, eFormaPago[], int)
 * @brief cuenta y acumula la cantidad de formas de pago que se utilizan
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaP
 * @param tamP
 */
void ContadorAuxiliarFormaDePaga(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP);

/**
 * @fn int MaximoAuxiliarFormaDePago(eAuxiliar[], eTrabajo[], int, eFormaPago[], int)
 * @brief
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaP
 * @param tamP
 * @return
 */
int MaximoAuxiliarFormaDePago(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP);

/**
 * @fn int ClienteConMasTrabajos(eTrabajo[], int, eCliente[], int)
 * @brief recorre la lista de trabajos y clientes buscando el cliente que tenga mas trabajos
 *
 * @param listaT
 * @param tamB
 * @param listaC
 * @param tamC
 * @return el cliente con mas trabajos
 */
int ClienteConMasTrabajos(eTrabajo listaT[],int tamB, eCliente listaC[], int tamC);

/**
 * @fn int FiltroDeClientes(eTrabajo[], int, eBicicleta[], int, eCliente[], int, eServicio[], int)
 * @brief
 *
 * @param listaT
 * @param tamT
 * @param listaB
 * @param tamB
 * @param listaC
 * @param tamC
 * @param listaS
 * @param tamS
 * @return
 */
int FiltroDeClientes(eTrabajo listaT[], int tamT, eBicicleta listaB[],int tamB, eCliente listaC[],int tamC, eServicio listaS[], int tamS);

/**
 * @fn void ContadorYAcumuladorTrabajos(eCliente[], int, eTrabajo[], int, eServicio[], int, int[], float[])
 * @brief Cuenta los trabajos y acumula el precio por cada trabajo segun el cliente
 *
 * @param listaC
 * @param tamC
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param contador
 * @param acumulador
 */
void ContadorYAcumuladorTrabajos(eCliente listaC[], int tamC, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, int contador[], float acumulador[]);

/**
 * @fn void MostrarUnClienteConTrabajos(eCliente, int, int, float)
 * @brief muestra un cliente con su trabajo
 *
 * @param Cliente
 * @param tamC
 * @param contador
 * @param acumulador
 */
void MostrarUnClienteConTrabajos(eCliente Cliente, int tamC, int contador, float acumulador);

/**
 * @fn int MostrarTodosClientesConTrabajos(eCliente[], int, eTrabajo[], int, eServicio[], int, eBicicleta[], int)
 * @brief Muestra todos los clientes con la cantidad de trabajos y el precio a pagar y tiene un filtro para que el usuario elija si quiere
 * ver los servicios del cliente con mas trabajos o filtrarlo por ID
 *
 * @param listaC
 * @param tamC
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si pudo mostrar un cliente 0 si no pudo
 */
int MostrarTodosClientesConTrabajos(eCliente listaC[], int tamC, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);
#endif /* NEXO_H_ */
