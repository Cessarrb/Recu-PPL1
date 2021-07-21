#ifndef EFORMAPAGO_H_
#define EFORMAPAGO_H_
#include "MiBiblioteca.h"

typedef struct
{
	int idFormaDePago;
	char descripcionPago[30];
	char bancarizado[30];
	char numOperacion[30];
}eFormaPago;


/**
 * @fn int BuscarPagoPorId(eFormaPago[], int, int)
 * @brief Busca el id que le pasan por parametro en la lista y si lo encuentra retorna su posicion
 *
 * @param listaP
 * @param tamP
 * @param id
 * @return posicion del id encontrado -1 si encontro el id
 */
int BuscarPagoPorId(eFormaPago listaP[], int tamP, int id);

void HardcodeoDatosFormaPago(eFormaPago listaP[], int tamP);

/**
 * @fn void MostrarUnaFormaDePago(eFormaPago)
 * @brief Muestra una forma de pago
 *
 * @param pago
 */
void MostrarUnaFormaDePago(eFormaPago pago);

/**
 * @fn int MostrarFormasDePago(eFormaPago[], int)
 * @brief Muestra todas las formas de pago
 *
 * @param listaP
 * @param tamP
 * @return 1 si puede mostrar una forma de pago 0 si no pudo
 */
int MostrarFormasDePago(eFormaPago listaP[], int tamP);

#endif /* EFORMAPAGO_H_ */
