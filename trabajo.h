#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

typedef struct{
int id;
char descripcion[20];
float precio;
}eServicio;

typedef struct{
int id;
int idAuto;
int IdServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;



#endif // TRABAJO_H_INCLUDED
/** \brief inicializa el campo isEmpty con 0 de la estructura eAuto
 *
 * \param trabajo[] eTrabajo paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de trabajos
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int inicializarTrabajo(eTrabajo trabajo[], int tamTr);
/** \brief busca los campos isEmpty que esten en 1
 *
 * \param pIndice int* paso por referencia pId
 * \param trabajo[] eTrabajo paso por param trabajos para recorrerlo
 * \param tamTr int paso el tamanio de trabajos
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int buscarLibreTrabajo(int* pIndice, eTrabajo trabajo[], int tamTr);

/** \brief muestro la estructura servicio con sus datos
 *
 * \param servicio eServicio paso por parametro una estructura Eservicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);
/** \brief muestra los distintos indice del array servicios
 *
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de trabajos
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarServicios(eServicio servicios[], int tamS);


/** \brief cargo los datos del array trabajo
 *
 * \param
 * \param
 * \return
 *
 */
int cargarTrabajo (eTrabajo* pTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief comparo la PK con FK y cargo la descripcion con un string
 *
 * \param id int paso id por parametro
 * \param descripcion[] char  paso descripcion por parametro
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de trabajos
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int cargarDescripcionServicio(int id, char descripcion[], eServicio servicios[], int tamS);
/** \brief muestro la estructura trabajo con sus datos
 *
 * \param t eTrabajo paso por parametro una estructura Eauto
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de marcas
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarTrabajo(eTrabajo t, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM);
/** \brief muestro los trabajos del array trabajos
 *
 * \param trabajos[] eTrabajo paso por parametro una estructura Eauto
 * \param tamTr int paso el tamanio de trabajos
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de marcas
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM);
/** \brief doy de alta trabajos
 *
 * \param pId int* paso por referencia pId
 * \param trabajos[] eTrabajo paso por parametro una estructura Eauto
 * \param tamTr int paso el tamanio de trabajos
 * \param autos[] eAuto paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de autos
 * \param servicios[] eServicio paso por param servicios para recorrerlo
 * \param tamS int paso el tamanio de servicios
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de marcas
 * \param colores[] eColor paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int altaTrabajo(int* pId, eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);

int hardcodearTrabajo(int* pId, eTrabajo vec[], int tam, int cant);

