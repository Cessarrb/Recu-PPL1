#include "MiBiblioteca.h"

#define TAM_BUFFER 200

int GetInt(char MSJ[], char MSJ_ERROR[])
{
   	int numero;
   	char buffer[TAM_BUFFER];


    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(ValidarInt(buffer)==0)
    {
    	printf("%s. %s", MSJ_ERROR, MSJ);
    	fflush(stdin);
    	gets(buffer);
    }

    numero=atoi(buffer);

    return numero;
}

int GetIntConRango(char MSJ[], char MSJ_ERROR[], int RANGO_MIN, int RANGO_MAX)
{
	int indexNumero;

	indexNumero=GetInt(MSJ, MSJ_ERROR);

	while(indexNumero<RANGO_MIN || indexNumero>RANGO_MAX)
	{
		printf("Error, numero fuera de rango, minimo: %d o maximo: %d\n", RANGO_MIN, RANGO_MAX);
		indexNumero=GetInt(MSJ, MSJ_ERROR);
	}

	return indexNumero;
}

int ValidarInt(char numero[])
{
	int i;
	int rtn=1;

	if(numero != NULL)
	{
		for (i=0;i<strlen(numero);i++)
		    {
		        if(!(isdigit(numero[i])))
		        {
		            rtn=0;
		            break;
		        }
		    }
	}

    return rtn;
}

float GetFloat(char MSJ[], char MSJ_ERROR[])
{
	float numero;
	char buffer[TAM_BUFFER];


	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(ValidarFloat(buffer)==0)
	{
		printf("%s. %s", MSJ_ERROR, MSJ);
		fflush(stdin);
		gets(buffer);
	}

	numero=atof(buffer);

	return numero;
}

float GetFloatConRango(char MSJ[], char MSJ_ERROR[], float RANGO_MIN, float RANGO_MAX)
{
	float indexNumero;

	indexNumero=GetFloat(MSJ, MSJ_ERROR);

	while(indexNumero<RANGO_MIN || indexNumero>RANGO_MAX)
	{
		printf("Error, numero fuera de rango, minimo: %f o maximo: %f\n", RANGO_MIN, RANGO_MAX);
		indexNumero=GetFloat(MSJ, MSJ_ERROR);
	}

	return indexNumero;
}

int ValidarFloat(char numero[])
{
	int i;
	int rtn=1;
	int contadorPuntos;

	contadorPuntos=0;

	if(numero !=NULL)
	{
		for (i=0;i<strlen(numero);i++)
		{
			if(i==0 && (numero[i]=='+' || numero[i]=='-'))
			{
				continue;
			}
				if(numero[i]<'0' || numero[i]>'9')
				{
					if(numero[i] == '.' && contadorPuntos==0)
					{
						contadorPuntos++;
					}
					else
					{
						rtn=0;
						break;
					}
				}
		}
	}
    return rtn;
}

char GetChar(char MSJ[], char MSJ_ERROR[])
{
	char buffer[TAM_BUFFER];
	char rtn;

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(ValidarAlfanumerico(buffer)==0 || strlen(buffer)>1)
    {
        printf("%s", MSJ_ERROR);
        fflush(stdin);
        gets(buffer);
    }

    rtn=buffer[0];

    return rtn;
}

void GetString(char CADENA[], char MSJ[], char MSJ_ERROR[], int TAM)
{
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)==0 || strlen(buffer)>TAM)
	    {
	        printf("%s, %s", MSJ_ERROR, MSJ);
	        fflush(stdin);
	        gets(buffer);
	    }
	strcpy(CADENA, buffer);
}

int VerificarNumero(int numero)
{
    int verificacion;

    if(numero>0 || numero<0)
    {
        verificacion=1;
    }
    else
	{
		verificacion=0;
	}

    return verificacion;
}

float CalcularPromedio(int numero, int otroNumero)
{
    float promedio;

    promedio=(float)numero/otroNumero;

    return promedio;
}

int SumaAntecesores(int numero)
{
    int i;
    int suma;

    suma=0;

    for(i=numero;i<2;i++)
    {
        suma=suma+i;
    }

    return suma;
}

int ValidarAlfanumerico(char MSJ[])
{
    int i;
    int resultado;

    resultado=1;

    if(strlen(MSJ)>0)
    {
    	for(i=0;i<strlen(MSJ);i++)
		{
			if(isalpha(MSJ[i])==0)
			{
				resultado=0;
				break;
			}
		}
    }
    else
    {
    	resultado=0;
    }

    return resultado;
}

int SumarDosNumero(int numero, int otroNumero)
{
	int sumar;

	sumar=numero+otroNumero;

	return sumar;
}

int ValidacionPar(int numero)
{
    int resultado;

    if(numero%2==0)
    {
        resultado=1;
    }
    else
    {
        resultado=0;
    }

    return resultado;
}

void MostrarFlotante(float numero)
{
    printf("el numero ingresado es %f", numero);
}




