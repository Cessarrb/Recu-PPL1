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

void HardcodeoDatosClientes(eCliente listaClientes[], int tamC);
void MostrarUnCliente(eCliente Cliente);
void MostrarTodosLosClientes(eCliente listaClientes[], int tamC);
int BuscarClientePorId(eCliente listaC[], int tamC, int id);
#endif /* ECLIENTE_H_ */
