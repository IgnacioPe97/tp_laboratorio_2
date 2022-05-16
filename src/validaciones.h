/*
 * validaciones.h
 *
 *  Created on: 11-05-2022
 *      Author: Ignacio Pereyra
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */
/** \brief determina si un numero es par / devuelve 1 en caso afirmativo / 0 en caso negativo
 *
 * \param numero int
 * \return int
 *
 */
int encontrarParidad(int numero);

/** \brief Pide el ingreso de un numero entero y lo retorna
 *
 * \return int
 *
 */
int pedirEntero();

/** \brief pide el ingreso de un numero entero dentro de un rango determinado que se pasa como min y max
 *
 * \param min int
 * \param max int
 * \return int
 *
 */
int pedirEnteroRango(int min, int max);

/// \brief valida si el numero que se le pasa es o no cero / devuelve 1 si no es 0 / devuelve 0 si es 0
///
/// \param numero int
/// \return int
///
///
int validarDistintoDeCero(int numero);

/// \brief valida si el float que se le pasa tiene valores después de la coma / devuelve 1 en caso que no haya decimales despues de la coma / devuelve 0 en caso contrario
///
/// \param numero float
/// \return int
///
///
int validarDecimales(float numero);

/** \brief recibe una cadena y devuelve el largo sin incluir \0
 *
 * \param vect[] char
 * \return int
 *
 */
int miStrlen(char vect[]);

/** \brief recibe una cadena y verifica que tenga letras u otros carcateres
 *
 * \param vect[] char
 * \return int devuelve 0 si osn todas letras, devuelve 1 si encuentra otro tipo de caracter
 *
 */
int validarCadena(char vect[]);

/** \brief recibe una cadena donde guardara un string validado y con el primer caracter en mayuscula
 *
 * \param cadena[] char
 * \param mensaje[] char
 * \param limite int
 * \return int
 *
 */
int pedirCadena(char cadena[], char mensaje[], int limite);

/** \brief convierte a mayuscula el primer caracter de una cadena
 *
 * \param cadena[] char
 * \return int
 *
 */
int mayusculaPrimerCaracter(char cadena[]);

/** \brief convierte una cadena a entero en caso de serlo
 *
 * \param
 * \param
 * \return
 *
 */
int getInt (int* pResultado);

/** \brief guarda una cadena en la direccion recibida
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
int myGets(char* cadena, int longitud);

/** \brief valida si la cadena que recibe es un entero, imprime un mensaje para ingresar el dato
 *          y otro en caso de error, y se puede setear un numero maximo de intentos en caso de ingresos fallidos
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int validarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief valida si una cadena recibida esta compupuesta solo por enteros
 *
 * \param cadena char*
 * \return int
 *
 */
int esNumerica(char* cadena);

/** \brief convierte una cadena a float  en caso de serlo
 *
 * \param
 * \param
 * \return
 *
 */
int getFloat (float* pResultado);

/** \brief valida si la cadena que recibe es float, imprime un mensaje para ingresar el dato
 *          y otro en caso de error, y se puede setear un numero maximo de intentos en caso de ingresos fallidos
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return int
 *
 */
int validarFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief valida si una cadena recibida esta compupuesta solo por floats
 *
 * \param str[] char
 * \return int
 *
 */
int esNumericoFlotante(char str[]);
