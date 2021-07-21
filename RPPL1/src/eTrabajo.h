#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#include "MiBiblioteca.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	int idCliente;
	int idBicicleta; //comienza en 25
	int idFormaDePago;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

/**
 * @fn int Menu()
 * @brief Imprime un menu con las opciones del abm
 *
 * @return retorna la opcion elegida
 */
int Menu();

/**
 * @fn void InicializarTrabajo(eTrabajo[], int)
 * @brief Inicializa el array de trabajo en -1 (VACIO)
 *
 * @param listaT
 * @param tamT
 */
void InicializarTrabajo(eTrabajo listaT[], int tamT);
/**
 * @fn void HardcodeoDatosTrabajos(eTrabajo[], int)
 * @brief  Hardcodea los datos de trabajo
 *
 * @param listaT
 * @param tamT
 */
void HardcodeoDatosTrabajos(eTrabajo listaT[], int tamT);

/**
 * @fn int BuscarLibre(eTrabajo[], int)
 * @brief Busca en el indice de trabajo que haya un lugar libre
 *
 * @param listaT
 * @param tamT
 * @return El indice del lugar libre
 */
int BuscarLibre(eTrabajo listaT[], int tamT);

/**
 * @fn int BuscarTrabajoPorId(eTrabajo[], int, int)
 * @brief Busca el id de trabajo y lo compara por un id que le pasen por parametro
 *
 * @param listaT
 * @param tamT
 * @param id
 * @return El indice del id encontrado o -1 si no encontro el id
 */
int BuscarTrabajoPorId(eTrabajo listaT[], int tamT, int id);

/**
 * @fn void OrdenarPorFecha(eTrabajo[], int)
 * @brief Ordena el listado de trabajo por año y si hay igualdad de año por marca de bicileta
 *
 * @param listaT
 * @param tamT
 */
#endif /* ETRABAJO_H_ */
