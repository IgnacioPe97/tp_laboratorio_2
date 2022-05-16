/*
 * arrayPassenger.c
 *
 *  Created on: 09-05-2022
 *      Author: Ignacio Pereyra
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "arrayPassenger.h"
#include"validaciones.h"
#include <ctype.h>
#include <stdlib.h>
#define TAM 5


void addPassengers(ePassenger vec[], int tam,int *proximoId,int *bandera)
{
	int respuesta;
	int enteroInt;
	char auxCad[10];
	float auxFloat;
	int opcion;

	ePassenger nuevoPasajero;
	do{
	if(vec!=NULL && proximoId && tam>0)
	{


		for(int i=0;i<tam;i++)
		{

				nuevoPasajero.id=*proximoId;
				//scanf("%d", &nuevoPasajero->id);
				do
				{
					printf("Ingrese nombre:");
					fflush(stdin);
					gets(auxCad);
					respuesta=validarCadena(auxCad);
				}while(respuesta==1);
				strcpy(nuevoPasajero.name,auxCad);

				do
				{
					printf("Ingrese apellido:");
					fflush(stdin);
					gets(auxCad);
					respuesta=validarCadena(auxCad);
				}while(respuesta==1);
				strcpy(nuevoPasajero.lastName,auxCad);

				do
				{
					respuesta=validarFloat(&auxFloat,"ingrese precio: "," Error en el ingreso, ingrese otra vez", 1,100000,10);
				}while(respuesta==0);
				nuevoPasajero.price=auxFloat;


				do
				{
					printf("Ingrese codigo:");
					fflush(stdin);
					gets(auxCad);
					respuesta=validarCadena(auxCad);
				}while(respuesta==1);
				strcpy(nuevoPasajero.flycode,auxCad);

				do
				{
				respuesta=validarEntero(&enteroInt,"Ingrese tipo de pasajero: 1-Primera clase, 2- Turista, 3- Directo , 4. Escala ,  \n","Error, tipo de dato invalido. Ingrese nuevamente: \n ",1,4,5);
				}while(respuesta==-1);
				nuevoPasajero.typePassenger=enteroInt;
				do
				{
					respuesta=validarEntero(&enteroInt,"Ingrese estado de vuelo: 1-Cancelado, 2-Demorado , 3-Activo \n","Error, tipo de dato invalido. Ingrese nuevamente: \n ",1,3,5);
				}while(respuesta==-1);
				nuevoPasajero.statusFlight=enteroInt;

				(*proximoId)++;
				vec[i]=nuevoPasajero;
				*bandera=1;
				printf("Quiere agregar mas pasajeros? 1- SI 2-NO\n");
				scanf("%d",&opcion);
				system("pause");
		}
	}
	}while(opcion==2);


}
void mostrarPasajero(ePassenger emp,eEstadoVuelo estados[],eTipoPasajero tipo[],int tam)
{
	char descripcion[51];
	char descripcionTipo[51];
	cargarDescripcionVuelos(estados,tam,emp.statusFlight,descripcion);
	cargarDescripcionTipo(tipo,tam,emp.typePassenger,descripcionTipo);
	printf("   %4d       %18s            %18s             %6.2f        %10s        %10s       %10s    \n",
			emp.id,
			emp.name,
			emp.lastName,
			emp.price,
			emp.flycode,
			descripcionTipo,
			descripcion);
}


void listarPasajeros(ePassenger vec[],int tam,eEstadoVuelo estados[],eTipoPasajero tipo[],int tamsTipo,int tamEst)
{
	int flag=1;
	if(vec!=NULL && tam>0)
	{

		//system("cls");
		printf("    ID               NAME           LAST NAME              PRICE           FLYCODE             TYPE PASSENGER       STATUS FLFLIGHT\n");
		printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{	if(!vec[i].isEmpty)
			{
				mostrarPasajero(vec[i],estados,tipo,tam);
				flag=0;
			}
		}
		if(flag)
		{
			printf("		No hay datos registrados\n");
		}
	}
}
void inicializarPasajeros(ePassenger vec[], int tam)
{
	if(vec!=NULL && tam>0)
		{
			for(int i=0; i < tam; i++)
			{
				vec[i].isEmpty=1;
			}

		}
}
void modificarPasajero(ePassenger vec[],int tam,eEstadoVuelo estados[],eTipoPasajero tipo[],int tamsTipo,int tams,int banderaIngresoPasajero)
{
	if(banderaIngresoPasajero==1)
	{		int indice;
			int id;
			char auxCadena[51];
			float precio;
			int auxInt;
			int salir=0;

				if(vec!=NULL && tam>0)
				{
					listarPasajeros(vec,tam,estados,tipo,tamsTipo,tams);
					printf("Ingrese id: ");
					scanf("%d ", &id);
					if(buscarPasajero(vec,tam,id,&indice))
					{
						if(indice==-1)
						{
							printf("No existe un empleado con id: %d en el sistema\n", id);
						}
						else
						{
							for(int i = 0; i<tam;i++)
							{
								mostrarPasajero(vec[i],estados,tipo,tam);
							}
							do
							{switch(menuModificar())
							{
								case 1:
										printf("Ingrese nuevo nombre");
										fflush(stdin);
										gets(auxCadena);
										//valido el nombre
										strcpy(vec[indice].name,auxCadena);
										printf("Modificaste el nombre correctamente\n");
										break;
								case 2:
									printf("Ingrese nuevo apellido");
									fflush(stdin);
									gets(auxCadena);
									//valido el nombre
									strcpy(vec[indice].lastName,auxCadena);
									printf("Modificaste el apellido correctamente");
									break;
								case 3:
									printf("Ingrese nuevo precio");
									scanf("%f",&precio);
									//valido sueldo
									vec[indice].price = precio;
									printf("Modificaste precio correctamente\n");
									break;
								case 4:
									printf("Ingrese nuevo tipo de pasajero\n");
									scanf("%d",&auxInt);
									//valido auxInt
									vec[indice].typePassenger=auxInt;
									break;
								case 5:
									printf("Ingrese nuevo codigo de vuelo\n");
									fflush(stdin);
									gets(auxCadena);
									//valido codigo
									strcpy(vec[indice].flycode,auxCadena);
									break;
								case 6:
									salir=1;
									break;
							}
							}while(salir==0);

						}
					}
				}
	}else
	{
		printf("Te faltan ingresar pasajeros");
	}
}
void bajaPasajero(ePassenger vec[], int tam,eEstadoVuelo estados[],eTipoPasajero tipo[],int tamsTipo,int tams,int banderaIngresoPasajero)
{
	if(banderaIngresoPasajero==1)
		{
			int indice;
			int id;
			char confirma;
			if(vec!=NULL && tam>0)
			{
				listarPasajeros(vec,tam,estados,tipo,tamsTipo,tams);
				printf("Ingrese id: ");
				scanf("%d ", &id);
				if(buscarPasajero(vec,tam,id,&indice))
				{
					if(indice==-1)
					{
						printf("No existe un empleado con id: %d en el sistema\n", id);
					}
					else
					{
						for(int i = 0; i<tam;i++)
						{
							mostrarPasajero(vec[i],estados,tipo,tam);
						}
						printf("Confirma baja?");
						fflush(stdin);
						scanf("%c",&confirma);
						if(confirma=='s'|| confirma=='S')
						{
							vec[indice].isEmpty=1;
							printf("Baja exitosa\n");
						}
						else
						{
							printf("Baja cancelada por el usuario\n");
						}

					}
				}
			}
		}else
		{
			printf("Te faltan ingresar pasajeros");
		}
}
int menuModificar()
{
		int modifica;
		printf("1-Modificar nombre\n");
		printf("2-Modificar apellido\n");
		printf("3- Modificar precio\n");
		printf("4- Modificar tipo de pasajero\n");
		printf("5- Modificar codigo de vuelo\n");
		printf("6- Atras");
		scanf("%d",&modifica);
		return modifica;
}
int buscarPasajero(ePassenger vec[],int tam, int id, int* pIndex)
{
	int todoOK=0;

	if(vec!=NULL && pIndex!=NULL && tam>0) // valido vector y pIndex y tamaño
			{
				*pIndex = -1; //precargo la variable,
				for (int i = 0; i<tam; i++)
				{ //recorro estructura donde el primer valor ISEMPTY sea igual a 1 (ese lugar esta libre)
					if (!vec[i].isEmpty && vec[i].id==id)
					{
						*pIndex = i;
						todoOK=1;
						break;
					}
				}
			}
	return todoOK;
}
void hardcodearPasajeros(ePassenger vec[], int tam, int cant,eEstadoVuelo estados[],int tams,int* pNextId,int *banderaIngresoPasajero)
{
	ePassenger pasajeros[10]=
	{
			{0,"JUAN","Perez",346.5,"PRMA",1,1,0},
			{0,"NACHO","Musachio",441.9,"LOTR",3,3,0},
			{0,"CARLA","Ferreyra",662.8,"VNVP",4,2,0},
			{0,"FICO","Lorenzo",143.3,"PÑOY",1,1,0},
			{0,"MICA","Falcon",567.8,"QRET",2,2,0},
			{0,"CARLOS","Vicentini",405.9,"XTYB",2,3,0},
			{0,"MIKE","Figueroa",557.5,"QZRB",3,3,0},
			{0,"JOSE","Malni",445.7,"OMTX",4,2,0},
			{0,"SOFIA","Feitao",237.8,"WXYN",1,1,0},
			{0,"JUANCITO","Morales",553.5,"YBIM",2,0,0}
	};
	if(vec !=NULL && pNextId!= NULL && tam>0 && tam<=10 && cant <= tam)
	{
		for(int i = 0; i<cant; i++)
		{
			vec[i] = pasajeros[i];
			vec[i].id=*pNextId;//asigno el valor al id
			(*pNextId)++; //luego le sumo uno para que quede al proxiumo empleado ingredsante


		}

	}
}
int menuPasajeros()
{
	int opcion;
	system("cls");
	printf("   ***ABM Empleados***\n\n");
	printf("1-Alta de pasajero \n");
	printf("2- Modificar pasajero \n");
	printf("3-Baja Pasajero\n");
	printf("4- Informar Pasajeros\n");
	printf("5- Salir\n");
	printf("Ingrese Opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
void ordenarPasajerosDosCriterios(ePassenger vec[],int tam,int banderaIngreso)
{
	ePassenger auxPasajero;
	if(vec!=NULL && tam>0)
			{
				for( int i=0; i<tam-1; i++)
				{
					for(int j=1+i; j<tam; j++)
					{
						 if(vec[i].typePassenger == vec[j].typePassenger) //cuando son del mismo sexo
						 {
							 if(vec[i].lastName > vec[j].lastName) // swap cuando son del mismo sexo para ordenar por ID
							 {
								 auxPasajero=vec[i];
								 vec[i]=vec[j];
								 vec[j]=auxPasajero;
							 }
						 }
						 else //caigo cuando son empleados de distinto sexo
						 {
							 if(vec[i].typePassenger > vec[j].typePassenger)
						 	 {
								 	 auxPasajero=vec[i];
									 vec[i]=vec[j];
									 vec[j]=auxPasajero;
						 	 }

						 }
					}
				}
			}
}
int promedioPrecio(ePassenger vec[],int tam)
{
	int todoOk=0;
	float acumuladorSueldo=0;
	float promedioSueldo=0;
	int contadorEmpleados=0;


	if(vec !=NULL && tam>0)
	{
		for(int i = 0; i<tam; i++)
		{
			if(!vec[i].isEmpty) //verifico que cada empleado este cargado para sumar su sueldo, y asi no sumar la basura
			{
				acumuladorSueldo += vec[i].price;
				contadorEmpleados++;
			}
		}
		if(contadorEmpleados!=0)
		{
			printf("acumulador %f\n",acumuladorSueldo);
			printf("contador %d\n",contadorEmpleados);
			promedioSueldo = acumuladorSueldo/contadorEmpleados;
		}
		printf("El promedio de precio  es $ %.2f\n\n",promedioSueldo);
		todoOk=1;

	}
	return todoOk;
}
void cargarDescripcionVuelos(eEstadoVuelo estados[],int tam,int id,char desc[])
{
	if(estados != NULL && tam>0 && desc != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(estados[i].id==id)
			{
				strcpy(desc,estados[i].estadoVuelo);
				break;
			}
		}
	}
}
void cargarDescripcionTipo(eTipoPasajero tipo[],int tam,int id,char desc[])
{
	if(tipo != NULL && tam>0 && desc != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				if(tipo[i].id==id)
				{
					strcpy(desc,tipo[i].descripcion);
					break;
				}
			}
		}

}






