#ifndef EBICICLETA_H_
#define EBICICLETA_H_
#include "MiBiblioteca.h"

typedef struct
{
	int idBicicleta; //comienza en 25
	char marca[25];
	int rodadoBicicleta;
	char color[25];
	int isEmpty;
}eBicicleta;


void HardcodeoDatosBicicleta(eBicicleta listaB[], int tamB);

int BuscarBiciPorId(eBicicleta listaB[], int tamB, int id);

void MostrarUnaBicicleta(eBicicleta bicicleta);

int MostrarBicicletas(eBicicleta listaB[], int tamB);



#endif /* EBICICLETA_H_ */
