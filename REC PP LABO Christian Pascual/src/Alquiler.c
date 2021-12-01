#include "Alquiler.h"

int inicializarAlquiler(eAlquiler lista[], int largo)
{
	int validacion=FINALIZADO;
	int i=0;

	if(largo>0)
	{
		for(i=0;i<largo;i++)
		{
			lista[i].estado=FINALIZADO;
			lista[i].codigo=FINALIZADO;
		}
		validacion=ALQUILADO;
	}
	return validacion;
}
int generarIDAlquiler(eAlquiler lista[],int tam)
{
	int id=FINALIZADO;
	int generador=1000;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].estado==FINALIZADO)
			{
				id=generador+i;
				break;
			}
		}
	}

	return id;
}
int contarAlquileres(eAlquiler lista[],int tam)
{
	int contador=0;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].estado==ALQUILADO)
			{
				contador++;
			}
		}
	}

	return contador;
	}
int compararEquipo(char equipo[])
{
	int comparar=FINALIZADO;
	int i;
	char opciones[3][T]={"AMOLADORA","MEZCLADORA","TALADRO"};
	char letra;

	for(i=0;i<strlen(equipo);i++)
	{
		letra=toupper(equipo[i]);
		equipo[i]=letra;
	}

	for(i=0;i<3;i++)
	{
		if(strcmp(equipo,opciones[i])==0)
		{
			comparar=ALQUILADO;
			break;
		}
	}

	return comparar;
	}
int cargarAlquiler(eAlquiler lista[],int id,char equipo[],int tiempo,char operador[],int tam)
{
	int carga=FINALIZADO;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].estado==FINALIZADO)
			{
				lista[i].cliente=id;
				lista[i].estado=ALQUILADO;
				lista[i].tiempo=tiempo;
				strcpy(lista[i].equipo,equipo);
				strcpy(lista[i].operador,operador);
				lista[i].codigo=generarIDAlquiler(lista,tam);
				carga=ALQUILADO;
				break;
			}
		}
	}

	return carga;
	}

int nuevoAlquiler(eAlquiler listaA[],eCliente listaC[],int tam)
{
	int validacion=FINALIZADO;
	int id;
	int tiempo;
	char tiempoC[T];
	char idc[T];
	char equipo[T];
	char operador[T];

		if(tam>0)
		{
			listarCliente(listaC,tam);
			printf("Ingrese el ID del cliente que realizara el alquiler\n");
			fflush(stdin);
			scanf("%[^\n]",idc);
			id=atoi(idc);

			while(validarNumeroEntero(idc)==FINALIZADO || compararID(listaC,id,tam)==FINALIZADO)
			{
				printf("ERROR, Ingrese el ID del cliente que realizara el alquiler\n");
				fflush(stdin);
				scanf("%[^\n]",idc);
				id=atoi(idc);
			}

				printf("Ingrese la cantidad de dias que se alquila el equipo\n");
				fflush(stdin);
			    scanf("%[^\n]",tiempoC);
			    tiempo=atoi(tiempoC);

				while(validarNumeroEntero(tiempoC)==FINALIZADO && tiempo>0)
				{
					printf("Error,Ingrese la cantidad de dias que se alquila el equipo\n");
					fflush(stdin);
					scanf("%[^\n]",tiempoC);
					tiempo=atoi(tiempoC);
				}


				printf("Ingrese el operador\n");
				fflush(stdin);
				scanf("%[^\n]",operador);

				while(validarPalabra(operador)==FINALIZADO)
				{
					printf("Error, Ingrese el operador\n");
					fflush(stdin);
					scanf("%[^\n]",operador);
				}

				printf("Ingrese(TEXTO) el equipo que se alquilo (AMOLADORA,MEZCLADORA,TALADRO)\n");
				fflush(stdin);
				scanf("%[^\n]",equipo);

				while(validarPalabra(operador)==FINALIZADO || compararEquipo(equipo)==FINALIZADO)
				{
					printf("Error, Ingrese el Equipo\n");
					fflush(stdin);
					scanf("%[^\n]",equipo);
				}

				if(cargarAlquiler(listaA,id,equipo,tiempo,operador,tam)==ALQUILADO)
				{
					validacion=ALQUILADO;
				}


		}

	return validacion;
}

void listarAlquileres(eCliente listaC[],eAlquiler listaA[],int tam)
{
	int i;
	int j;

	if(tam>0)
	{
		for(j=0;j<tam;j++)
		{
			if(listaC[j].id!=FINALIZADO)
			{
			printf("DNI: %s\tNOMBRE: %s\t APELLIDO: %s\tID CLIENTE: %d\n",listaC[j].DNI,listaC[j].nombre,listaC[j].apellido,listaC[j].id);
		      for(i=0;i<tam;i++)
		      {
			    if(listaA[i].estado==ALQUILADO && listaA[i].codigo!=FINALIZADO && listaA[i].cliente==listaC[j].id)
			    {
				  printf("EQUIPO: %s\tOPERADOR: %s\tCANTIDAD DE DIAS %d\n",listaA[i].equipo,
																		   listaA[i].operador,
																		   listaA[i].tiempo);
			    }
		       }
			}
		}
	}

}

int finalizarAlquiler(eCliente listaC[],eAlquiler listaA[],int tam)
{
	int baja=FINALIZADO;
	int id;
	char idc[T];
	int tiempo;
	char tiempoC[T];
	int i;

	        if(tam>0)
			{
				listarCliente(listaC,tam);
				printf("Ingrese el ID del cliente que realizo el alquiler\n");
				fflush(stdin);
				scanf("%[^\n]",idc);
				id=atoi(idc);

				while(validarNumeroEntero(idc)==FINALIZADO || compararID(listaC,id,tam)==FINALIZADO)
				{
					printf("ERROR, Ingrese el ID del cliente que realizo el alquiler\n");
					fflush(stdin);
					scanf("%[^\n]",idc);
					id=atoi(idc);
				}

				printf("Ingrese la cantidad de dias que se alquilo el equipo\n");
				fflush(stdin);
				scanf("%[^\n]",tiempoC);
				tiempo=atoi(tiempoC);

					while(validarNumeroEntero(tiempoC)==FINALIZADO && tiempo>0)
					{
						printf("Error,Ingrese la cantidad de dias que se alquilo el equipo\n");
						fflush(stdin);
						scanf("%[^\n]",tiempoC);
						tiempo=atoi(tiempoC);
					}

					for(i=0;i<tam;i++)
					{
						if(listaA[i].cliente==id)
						{
							listaA[i].tiempo=tiempo;
							listaA[i].estado=FINALIZADO;
							break;
						}
					}
					baja=ALQUILADO;



			}


	return baja;
	}

