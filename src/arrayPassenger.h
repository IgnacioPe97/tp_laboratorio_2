/*
 * arrayPassenger.h
 *
 *  Created on: 09-05-2022
 *      Author: Ignacio Pereyra
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

typedef struct
{
	int id;
	char estadoVuelo[51];
}eEstadoVuelo;
typedef struct
{
	int id;
	char descripcion[51];
}eTipoPasajero;
#endif /* ARRAYPASSENGER_H_ */

void addPassengers(ePassenger vec[], int tam,int *proximoId,int *bandera);
void mostrarPasajero(ePassenger emp,eEstadoVuelo estados[],eTipoPasajero tipo[],int tam);
void listarPasajeros(ePassenger vec[],int tam,eEstadoVuelo estados[],eTipoPasajero tipo[],int tamsTipo,int tamEst);
void inicializarPasajeros(ePassenger vec[], int tam);
void modificarPasajero(ePassenger vec[],int tam,eEstadoVuelo estados[],eTipoPasajero tipo[],int tamsTipo,int tams,int banderaIngresoPasajero);
void cambiarDatos(ePassenger vec[],int modifica);
int buscarPasajero(ePassenger vec[],int tam, int id, int* pIndex);
void cambiarDatos(ePassenger vec[],int modifica);
int menuModificar();
void bajaPasajero(ePassenger vec[], int tam,eEstadoVuelo estados[],eTipoPasajero tipo[],int tamsTipo,int tams,int banderaIngresoPasajero);
void hardcodearPasajeros(ePassenger vec[], int tam, int cant,eEstadoVuelo estados[],int tams,int* pNextId,int *banderaIngresoPasajero);
int menuPasajeros();
void ordenarPasajerosDosCriterios(ePassenger vec[],int tam,int banderaIngreso);
void cargarDescripcionVuelos(eEstadoVuelo estados[],int tam,int id,char desc[]);
void cargarDescripcionTipo(eTipoPasajero tipo[],int tam,int id,char desc[]);

int promedioPrecio(ePassenger vec[],int tam);

