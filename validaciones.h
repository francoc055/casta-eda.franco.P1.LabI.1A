#include "auto.h"
#include "trabajo.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED



/** \brief valido el id de que ingresa el usuario
 *
 * \param id int paso por param el id
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de marcas
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int validarMarca(int id, eMarca marcas[], int tamM);
/** \brief  valido el id de que ingresa el usuario
 *
 * \param id int paso por param el id
 * \param colores[] eColor paso por param colores para recorrerlo
 * \param tamC int  paso el tamanio de marcas
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int validarColor(int id, eColor colores[], int tamC);
/** \brief  valido el id de que ingresa el usuario
 *
 * \param id int paso por param el id
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de servicios
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int validarServicio(int id, eServicio servicios[], int tamS);
/** \brief  valido el id de que ingresa el usuario
 *
 * \param id int paso por param el id
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int validarAuto(int id, eAuto autos[], int tamA);
/** \brief valido el valor que ingresa el usuario
 *
 * \param valor char paso por param un valor char
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int validarCaja(char valor);
/** \brief valido las fechas que ingresa el usuario
 *
 * \param dia int paso por param el valor dia
 * \param mes int paso por param el valor mes
 * \param anio int paso por param el valor anio
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int validarFecha(int dia, int mes, int anio);

int validarCliente(int id, eCliente clientes[], int tamCl);
