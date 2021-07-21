#ifndef ESERVICIO_H_
#define ESERVICIO_H_
#include "MiBiblioteca.h"

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
	int isEmpty;
}eServicio;

/**
 * @fn int BuscarServicioPorId(eServicio[], int, int)
 * @brief Busca el id de servicio y lo compara por un id que le pasen por parametro
 *
 * @param listaS
 * @param tamS
 * @param id
 * @return El indice del id encontrado o -1 si no encontro el id
 */
int BuscarServicioPorId(eServicio listaS[], int tamS, int id);

/**
 * @fn void HardcodeoDatosServicios(eServicio[], int)
 * @brief  hardcodea los datos de servicio
 *
 * @param listaS
 * @param tamS
 */
void HardcodeoDatosServicios(eServicio listaS[], int tamS);

/**
 * @fn void MostrarServicios(eServicio[], int)
 * @brief Muestra una lista de todos los servicios disponibles
 *
 * @param listaS
 * @param tamS
 */
int MostrarServicios(eServicio listaS[], int tamS);

/**
 * @fn void MostrarUnServicio(eServicio)
 * @brief muestra la lista de un servicio
 *
 * @param servicio
 */
void MostrarUnServicio(eServicio servicio);


#endif /* ESERVICIO_H_ */
