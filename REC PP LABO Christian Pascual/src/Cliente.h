#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#define T 50
typedef struct{
	int id;
	char DNI[T];
	char nombre[T];
	char apellido[T];
}eCliente;

#endif /* CLIENTE_H_ */

int inicializarCliente(eCliente[], int);
int contadorCliente(eCliente lista[],int tam);
int cargarCliente(eCliente[],int);
int generarID(eCliente[],int);
int nuevoCliente(eCliente[],char[],char[],char[],int);
void listarCliente(eCliente[],int);
int compararID(eCliente[],int,int);
int modificarCliente(eCliente[],int);
int cambiarDatos(eCliente[],char[],int,int,int);
int bajaCliente(eCliente[],int);
