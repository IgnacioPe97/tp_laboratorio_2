/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#include <ctype.h>
#define TAM 5
#define TAMS 3
#define TAMSTIPO 4

int main(void) {
	setbuf(stdout,NULL);
	int proximoId=1000;
	int banderaIngresoPasajero=1;
	char opcionSalir;

	ePassenger nuevoPasajero[TAM];
	eEstadoVuelo estados[TAMS]=
	{
		{1,"Cancelado"},
		{2,"Demorado"},
		{3,"Activo"}
	};

	eTipoPasajero tipo[TAMSTIPO]=
	{
		{1,"Primera clase"},
		{2,"Turista"},
		{3,"Directo"},
		{4,"Escala"}
	};
	inicializarPasajeros(nuevoPasajero,TAM);
	hardcodearPasajeros(nuevoPasajero,TAM,5,estados,TAMS,&proximoId,&banderaIngresoPasajero);
	listarPasajeros(nuevoPasajero,TAM,estados,tipo,TAMSTIPO,TAMS);
	//modificarPasajero(nuevoPasajero,TAM);
	//bajaPasajero(nuevoPasajero,TAM);
	do
	{
		switch(menuPasajeros())
		{
		case 1:

				addPassengers(nuevoPasajero,TAM,&proximoId, &banderaIngresoPasajero);
			break;
		case 2:
				modificarPasajero(nuevoPasajero,TAM,estados,tipo,TAMSTIPO,TAMS,banderaIngresoPasajero);
			break;
		case 3:
				bajaPasajero(nuevoPasajero,TAM,estados,tipo,TAMSTIPO,TAMS,banderaIngresoPasajero);
			break;
		case 4:
			//ordenarPasajerosDosCriterios(nuevoPasajero,TAM, banderaIngresoPasajero);
			promedioPrecio(nuevoPasajero,TAM);
			listarPasajeros(nuevoPasajero,TAM,estados,tipo,TAMSTIPO,TAMS);

			break;
		case 5:
			printf("quiere salir?");
			scanf("%c",&opcionSalir);
			break;
		}
	}while(opcionSalir !='s'|| opcionSalir != 'S');





	return EXIT_SUCCESS;
}
