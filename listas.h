#include "trabajo.h"
#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#endif // LISTAS_H_INCLUDED


/** \brief lista por marca y caja del auto
 *
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de marcas
 * \param colores[] eColor paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de colores
 * \param clientes[] eCliente paso por param clientes para recorrerlo
 * \param tamCl int paso el tamanio de colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int listarxMarcaYcaja(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief lista de las marcas que se dieron de alta en autos
 *
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tam int paso el tamanio de marcas
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int listarMarcas(eAuto autos[], int tamA, eMarca marcas[], int tam);
/** \brief lista de los colores que se dieron de alta en autos
 *
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int listarColores(eAuto autos[], int tamA, eColor colores[], int tamC);
/** \brief  lista de los servicios que se dieron de alta en autos
 *
 * \param trabajos[] eTrabajo  paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de trabajos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de servicios
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int listarServicios(eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS);

