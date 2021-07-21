#ifndef ECLIENTE_H_
#define ECLIENTE_H_
#include "MiBiblioteca.h"

typedef struct
{
	int id;
	char nombre[50];
	int dni;
	int telefono;
	int isEmpty;
}eCliente;

/**
 * @fn void HardcodeoDatosClientes(eCliente[], int)
 * @brief Hardcodeo de datos
 *
 * @param listaC
 * @param tamC
 */
void HardcodeoDatosClientes(eCliente listaC[], int tamC);

/**
 * @fn void MostrarUnCliente(eCliente)
 * @brief
 *
 * @param Cliente
 */
void MostrarUnCliente(eCliente Cliente);

/**
 * @fn void MostrarTodosLosClientes(eCliente[], int)
 * @brief Muestra todos los clientes
 *
 * @param listaC
 * @param tamC
 */
void MostrarTodosLosClientes(eCliente listaC[], int tamC);

/**
 * @fn int BuscarClientePorId(eCliente[], int, int)
 * @brief Busca un cliente por ID
 *
 * @param listaC
 * @param tamC
 * @param id
 * @return
 */
int BuscarClientePorId(eCliente listaC[], int tamC, int id);
#endif /* ECLIENTE_H_ */
