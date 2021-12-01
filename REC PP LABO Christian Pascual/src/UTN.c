#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#define TRUE 0
#define FALSE -1


int mostrarMenu()
{
	int opcion;

	do{
	 printf("Elija la opcion correspondiente:\n");
	 printf("1- Alta Cliente\n");
	 printf("2- Modificar datos cliente\n");
	 printf("3- Baja cliente\n");
	 printf("4- Nuevo Alquiler\n");
	 printf("5- Fin alquiler\n");
	 printf("6- Informes\n");
	 printf("7- Finalizar Programa\n");
	 scanf("%d",&opcion);
	 while(opcion<1 || opcion>7)
	 {
	 	printf("Error ingrese una opcion valida\n");
		scanf("%d",&opcion);
	 }
	}while(opcion<1 && opcion>7);

	return opcion;
}

int validarDNI(char DNI[])
{
	int ok=FALSE;
	int valor=1;
	int auxiliar;
	int i;


	if(DNI!=NULL)
	{
		for(i=0;i<strlen(DNI);i++)
		{
		   auxiliar=isdigit(DNI[i]);
		   if(auxiliar==0)
		   {
			   valor=-1;
			   break;
		   }
		}

		 if(valor==-1 ||((strlen(DNI))>8) || ((strlen(DNI))<7))
		 {

			 printf("ERROR, el DNI ingresado no es valido\n");

		 }
		 else
		 {
			 ok=TRUE;
		 }

	}

	return ok;
}

int validarPalabra(char nombre[])
{
	int validacion=TRUE;
	int largo;
	int i;
	int control;

	largo=strlen(nombre);
	for(i=0;i<largo;i++)
	{
		control=isalpha(nombre[i]);
		if(control==0)
		{
			validacion=FALSE;
			break;
		}
	}

	return validacion;
}

int validarNumeroEntero(char numero[])
{
	int i;
	int largo;
	int control;
	int validacion=TRUE;

	largo=strlen(numero);

	for(i=0;i<largo;i++)
	{
	   control=isdigit(numero[i]);
	   if(control==0)
	   {
		   validacion=FALSE;
		   break;
	   }
	}

	return validacion;
}
int validarNumeroFlotante(char numero[])
{
	    int validacion=TRUE;
		int i;
		int comas=0;
		int valor=0;
		int control;

		for(i=0;i<strlen(numero);i++)
		{
		   control=isdigit(numero[i]);
		   if(control==0 && valor==0)
		   {
			   valor=-1;
			   if(numero[i]=='.' && i>1 && comas==0)
			   {
				valor=0;
				comas++;
			   }
			   else
			   {
				   validacion=FALSE;
				   break;
			   }

		   }
		}

	return validacion;
}



int DarRespuesta()
{
	int validacion;
	int i;
	char respuesta[3];
	char letra;

	printf("Desea continuar(si/no)\n");
	fflush(stdin);
	scanf("%[^\n]",respuesta);

	while(validarPalabra(respuesta)==FALSE)
	{
		printf("Error, desea continuar(si/no)\n");
			fflush(stdin);
			scanf("%[^\n]",respuesta);
	}

	for(i=0;i<3;i++)
	{
			letra=tolower(respuesta[i]);
			respuesta[i]=letra;
	}

	if(strcmp(respuesta,"si")==TRUE)
	{
		validacion=TRUE;
	}
	else
	{
		validacion=FALSE;
	}

	return validacion;
}

