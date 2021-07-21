#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAM_BUFFER 200
#define TAM_AUX 50
#define VACIO -1
#define OCUPADO 0

int GetInt(char MSJ[], char MSJ_ERROR[]);
float GetFloat(char MSJ[], char MSJ_ERROR[]);
char GetChar(char MSJ[], char MSJ_ERROR[]);
void GetString(char cadena[], char MSJ[], char MSJ_ERROR[], int TAM);

int GetIntConRango(char MSJ[], char MSJ_ERROR[], int RANGO_MIN, int RANGO_MAX);
float GetFloatConRango(char MSJ[], char MSJ_ERROR[], float RANGO_MIN, float RANGO_MAX);

int ValidarInt(char numero[]);
int ValidarFloat(char numero[]);
int ValidacionPar(int);
int ValidarAlfanumerico(char msj[]);

float CalcularPromedio(int, int);
int SumaAntecesores(int);
int SumarDosNumero(int, int);
void MostrarFlotante(float);

#endif /* MIBIBLIOTECA_H_ */
