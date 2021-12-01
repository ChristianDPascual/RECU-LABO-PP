#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "Cliente.h"
#include "Alquiler.h"
#define T 50
#define L 1000
#define TRUE 0
#define FALSE -1

int main(void)
{
	setbuf(stdout,NULL);
	eCliente listadoClientes[L];
	eAlquiler listadoAlquileres[L];
	int cantidad;
	int contador;
	int opcion;


	if((inicializarCliente(listadoClientes,L))==TRUE && (inicializarAlquiler(listadoAlquileres,L)==TRUE))
	{

	do{
	cantidad=contadorCliente(listadoClientes,L);

	contador=contarAlquileres(listadoAlquileres,L);

	switch(opcion=mostrarMenu())
	{
	case 1:
		if(cargarCliente(listadoClientes,L)==TRUE)
		{
			printf("se cargo con exito\n");
		}
		else
		{
			printf("Ocurrio un error\n");
		}
		break;
	case 2:
		if(cantidad>0 && modificarCliente(listadoClientes,L)==TRUE)
		{
			printf("El cambio se realizo con exito\n");
		}
		else
		{
			if(cantidad==0)
			{
			    printf("No hay clientes cargados\n");
			}
			else
			{
				printf("No se realizaron cambios\n");
			}
		}
		break;
	case 3:
		if(cantidad>0 && bajaCliente(listadoClientes,L)==TRUE)
		{
			printf("La baja con exito\n");
		}
		else
		{
			if(cantidad==0)
			{
				printf("No hay clientes cargados\n");
			}
			else
			{
				printf("No se realizo la baja\n");
			}
		}
		break;
	case 4:
		if(nuevoAlquiler(listadoAlquileres,listadoClientes,L)==TRUE)
		{
			printf("Se cargo con exito el alquiler\n");
		}
		else
		{
			if(contador==0)
			{
				printf("No hay alquileres\n");
			}
			else
			{
				printf("ocurrio un error\n");
			}
		}
		break;
	case 5:
		if(contador>0 && finalizarAlquiler(listadoClientes,listadoAlquileres,L)==TRUE)
		{
			printf("Se finalizo con exito el alquiler\n");
		}
		else
		{
			if(contador==0)
			{
				printf("No hay alquileres\n");
			}
			else
			{
				printf("ocurrio un error\n");
			}
		}
		break;
	case 6:
		if(contador>0)
	    {
			listarAlquileres(listadoClientes,listadoAlquileres,L);
	    }
		else
		{
			if(contador==0)
			{
				printf("No hay alquileres\n");
			}
			else
			{
				printf("ocurrio un error\n");
			}
		}
		break;
	case 7:
		printf("Programa Finalizado\n");
		break;
	}
	}while(opcion!=7);
    }
	else
	{
		printf("Ocurrio un error y no se pudo inicializar el programa\n");
	}



	return EXIT_SUCCESS;
}
