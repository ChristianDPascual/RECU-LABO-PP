#include "Cliente.h"
#define T 50
#define TRUE 0
#define FALSE -1


int inicializarCliente(eCliente lista[], int largo)
{
	int validacion=FALSE;
	int i=0;

	if(largo>0)
	{
		for(i=0;i<largo;i++)
		{
			lista[i].id=FALSE;
		}
		validacion=TRUE;
	}
	return validacion;
}

int contadorCliente(eCliente lista[],int tam)
{
	int total=0;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id!=FALSE)
			{
				total++;
			}
		}
	}

	return total;
}

int nuevoCliente(eCliente lista[],char DNI[],char nombre[],char apellido[],int tam)
{
	int validacion=FALSE;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id==FALSE)
			{
			    lista[i].id=generarID(lista,tam);
				strcpy(lista[i].DNI,DNI);
				strcpy(lista[i].nombre,nombre);
				strcpy(lista[i].apellido,apellido);
				validacion=TRUE;
				printf("ID: %d\tDNI: %s\tNOMBRE: %s\tAPELLIDO: %s\n",lista[i].id,DNI,nombre,apellido);
				break;
			}
		}
	}

	return validacion;
}

int generarID(eCliente lista[],int tam)
{
	int id=FALSE;
	int generador=1000;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id==FALSE)
			{
				id=generador+i;
				break;
			}
		}
	}

	return id;
}

int cargarCliente(eCliente lista[],int tam)
{
	int carga=FALSE;
	char nombre[T];
	char apellido[T];
	char DNI[T];

	printf("Ingrese el DNI\n");
	fflush(stdin);
    scanf("%[^\n]",DNI);

	while(validarDNI(DNI)==FALSE)
	{
		printf("Error, Ingrese el DNI\n");
		fflush(stdin);
		scanf("%[^\n]",DNI);
	}


	printf("Ingrese el nombre\n");
	fflush(stdin);
	scanf("%[^\n]",nombre);

	while(validarPalabra(nombre)==FALSE)
	{
		printf("Error, Ingrese el nombre\n");
		fflush(stdin);
		scanf("%[^\n]",nombre);
	}

	printf("Ingrese el apellido\n");
	fflush(stdin);
	scanf("%[^\n]",apellido);

	while(validarPalabra(apellido)==FALSE)
	{
		printf("Error, Ingrese el apellido\n");
		fflush(stdin);
		scanf("%[^\n]",apellido);
	}


	if(nuevoCliente(lista,DNI,nombre,apellido,tam)==TRUE)
	{
		carga=TRUE;
	}


	return carga;
}

void listarCliente(eCliente lista[],int TAM)
{
   int i;

   if(TAM>0)
   {
	   for(i=0;i<TAM;i++)
	   {
		   if(lista[i].id!=FALSE)
		   {

			   printf("ID: %d\tDNI: %s\tNOMBRE: %s\tAPELLIDO: %s\n",lista[i].id,
					                                                lista[i].DNI,
									    						    lista[i].nombre,
																    lista[i].apellido);

		   }
	   }
   }

}
int compararID(eCliente lista[],int direccion,int tam)
{
	int validacion=FALSE;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(direccion==lista[i].id)
			{
				validacion=TRUE;
				break;
			}
		}
	}


	return validacion;
	}

int cambiarDatos(eCliente lista[],char cambio[],int direccion,int tam,int opcion)
{
	int validacion=FALSE;
	int i;

	if(tam>0 && direccion>0)
	{
		for(i=0;i<tam;i++)
		{
			if(direccion==lista[i].id && opcion==1)
			{
				strcpy(lista[i].nombre,cambio);
				break;
			}
			else
			{
				if(direccion==lista[i].id && opcion==2)
				{
					strcpy(lista[i].apellido,cambio);
				    break;
				}
			}
		}
		validacion=TRUE;
	}

	return validacion;
}

int modificarCliente(eCliente lista[],int tam)
{
	    int modificacion=FALSE;
		int id;
		int opcion;
		char seleccion[T];
		char idc[T];
	    char nombre[T];
		char apellido[T];

		if(tam>0)
		{
			listarCliente(lista,tam);
			printf("Ingrese el ID del cliente que desea modificiar\n");
			fflush(stdin);
			scanf("%[^\n]",idc);
			id=atoi(idc);

			while(validarNumeroEntero(idc)==FALSE || compararID(lista,id,tam)==FALSE)
			{
				printf("ERROR, Ingrese el ID del cliente que desea modificiar\n");
				fflush(stdin);
				scanf("%[^\n]",idc);
				id=atoi(idc);
			}

			do{
				printf("Elija la opcion\n");
				printf("1 Cambiar nombre cliente\n");
				printf("2 Cambiar apellido cliente\n");
				printf("3 Volver al menu anterior\n");
				fflush(stdin);
				scanf("%[^\n]",seleccion);
				opcion=atoi(seleccion);
				while(validarNumeroEntero(seleccion)==FALSE && (opcion>0 || opcion<4))
				{
					printf("Error, elija una opcion valida\n");
					fflush(stdin);
					scanf("%[^\n]",seleccion);
					opcion=atoi(seleccion);

				}
				switch(opcion)
				{
				case 1:
					    printf("Ingrese el nombre\n");
						fflush(stdin);
						scanf("%[^\n]",nombre);

						while(validarPalabra(nombre)==FALSE)
						{
							printf("Error, Ingrese el nombre\n");
							fflush(stdin);
							scanf("%[^\n]",nombre);
						}
						if(cambiarDatos(lista,nombre,id,tam,opcion)==TRUE)
						{
							modificacion=TRUE;
						}
					break;
				case 2:
					     printf("Ingrese el apellido\n");
						 fflush(stdin);
						 scanf("%[^\n]",apellido);

						 while(validarPalabra(apellido)==FALSE)
					 	 {
							 printf("Error, Ingrese el apellido\n");
							 fflush(stdin);
							 scanf("%[^\n]",apellido);
		  				 }
						 if(cambiarDatos(lista,apellido,id,tam,opcion)==TRUE)
						 {
						 	modificacion=TRUE;
						 }
					break;
				}
			}while(opcion!=3);

		}

	return modificacion;
}

int bajaCliente(eCliente lista[],int tam)
{
	int baja=FALSE;
	int i;
	int id;
	char idc[T];

	if(tam>0)
	{
		listarCliente(lista,tam);
		printf("Ingrese el ID del cliente que desea dar de baja\n");
		fflush(stdin);
		scanf("%[^\n]",idc);
		id=atoi(idc);

		while(validarNumeroEntero(idc)==FALSE || compararID(lista,id,tam)==FALSE)
		{
			printf("ERROR, Ingrese el ID del cliente que desea dar de baja\n");
			fflush(stdin);
			scanf("%[^\n]",idc);
			id=atoi(idc);
		}

		for(i=0;i<tam;i++)
		{
			if(lista[i].id==id)
			{
				lista[i].id=FALSE;
				baja=TRUE;
				break;
			}
		}

	}

	return baja;
}
