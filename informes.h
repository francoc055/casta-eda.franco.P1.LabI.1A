#include "auto.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief menu de opciones de los informes
 *
 * \return int devuelve la opcion que eligio el usuario
 *
 */
int menuInformes();
/** \brief el usuario elige un color y muestro los autos que halla del mismo
 *
 *\param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarAutosDeUnColor(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC, eCliente clientes[], int tamCl);
/** \brief  el usuario elige una marca y muestro los autos que halla de la misma
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarAutosDeUnaMarca(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC, eCliente clientes[], int tamCl);
/** \brief promedio de caja automatica y manual
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int porcentajeCajas(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC);
/** \brief lista de todos los autos segun el tipo de caja
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int listaAutosPorCaja(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC, eCliente clientes[], int tamCl);
/** \brief contador de cuanto autos hay de un color y marca
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int contadorAutosColorYmarca(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC);
/** \brief comparo las marcas que existen y muestro cual es la mas eligida
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int marcaMasElegida(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC);
///////////////////////////////////////////////
//informes trabajo
/** \brief muestro los trabajos que tiene un auto
 *
 * \param trabajos[] eTrabajo paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de array trabajos
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de array servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int trabajosDeUnAuto(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief muestro el importe que tiene el auto elegido
 *
 * \param trabajos[] eTrabajo paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de array trabajos
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de array servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int importesDeUnAuto(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief pido un servicio y muestro los autos a los que se realizo ese servicio y la fecha.
 *
 * \param trabajos[] eTrabajo paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de array trabajos
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de array servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarAutosYfechasDeUnServicio(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
/** \brief pido una fecha y muestro todos los servicios realizados en la misma.
 *
 * \param trabajos[] eTrabajo paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de array trabajos
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de array servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarServiciosEnUnaFecha(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
