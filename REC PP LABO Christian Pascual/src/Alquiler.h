#ifndef ALQUILER_H_
#define ALQUILER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "Cliente.h"
#define T 50
#define ALQUILADO 0
#define FINALIZADO -1

typedef struct{
	int cliente;
	int estado;
	char equipo[T];
	int tiempo;
	char operador[T];
	int codigo;

}eAlquiler;

#endif /* ALQUILER_H_ */

int inicializarAlquiler(eAlquiler[], int);
int nuevoAlquiler(eAlquiler[],eCliente[],int);
int compararEquipo(char[]);
int cargarAlquiler(eAlquiler[],int,char[],int,char[],int);
void listarAlquileres(eCliente[],eAlquiler[],int);
int finalizarAlquiler(eCliente[],eAlquiler[],int);
int generarIDAlquiler(eAlquiler[],int);
int contarAlquileres(eAlquiler [],int);

