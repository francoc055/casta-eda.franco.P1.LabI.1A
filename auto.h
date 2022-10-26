#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{
int id;
char descripcion[20];
}eMarca;

typedef struct{
int id;
char NombreColor[20];
}eColor;

typedef struct{
int id;
char nombre[20];
char sexo;
}eCliente;

typedef struct{
int id;
int idMarca;
int IdColor;
char caja;
int idCliente;
int isEmpty;
}eAuto;


#endif // AUTO_H_INCLUDED

int hardcodearAutos(int* pId, eAuto vec[], int tam, int cant);
/** \brief hace un printf de un indice de la estructura eMarca
 *
 * \param marca eMarca recibe por parametro la estructura eMarca
 * \return void
 *
 */
void mostrarMarca(eMarca marca);
/** \brief  muestra los distintos indice del array marcas
 *
 * \param marcas[] eMarca paso por parametro un array de marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarMarcas(eMarca marcas[], int tamM);

/** \brief hace un printf de un indice de la estructura eColor
 *
 * \param color eColor recibe por parametro la estructura eColor
 * \return void
 *
 */
void mostrarColor(eColor color);
/** \brief muestra los distintos indice del array marcas
 *
 * \param colores[] eColor paso por parametro un array de colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarColores(eColor colores[], int tamC);

/** \brief inicializa el campo isEmpty de la estructura eAuto
 *
 * \param aauto[] eAuto paso por parametro el array aauto para recorrerlo
 * \param tamA int paso el tamanio de array aauto
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int inicializarAuto(eAuto aauto[], int tamA);
/** \brief busca los campos isEmpty que esten en 1
 *
 * \param pId int* paso por referencia pId
 * \param aauto[] eAuto paso por parametro el array eAuto para recorrerlo
 * \param tamA int paso el tamanio de array aauto
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int buscarLibre(int* pId, eAuto aauto[], int tamA);
/** \brief cargo los datos del array marcas
 *
 * \param pAuto eAuto* paso por referencia pAuto
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 *
 */
int cargaraAuto(eAuto* pAuto, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief comparo la PK con FK y cargo la descripcion con un string
 *
 * \param id int paso id por parametro
 * \param descripcion[] char paso descripcion por parametro
 * \param marcas[] eMarca  paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int cargarDescripcionMarca(int id, char descripcion[], eMarca marcas[], int tamM);
/** \brief comparo la PK con FK y cargo la descripcion con un string
 *
 * \param id int  int paso id por parametro
 * \param nombreColor[] char paso descripcion por parametro
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int  paso el tamanio de array colores
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int cargarDescripcionColor(int id, char nombreColor[], eColor colores[], int tamC);
/** \brief muestro la estructura auto en un indice
 *
 * \param a eAuto paso por parametro una estructura Eauto
 * \param marcas[] eMarca  paso por param marcas para recorrerlo
 * \param tamM int  paso el tamanio de array marcas
 * \param colores[] eColor paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarAuto(eAuto a, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief muestro los autos del array autos
 *
 * \param autos[] eAuto  paso por param autos para recorrerlo
 * \param tamA int  paso el tamanio de array autos
 * \param marcas[] eMarca  paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int  paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int mostrarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief doy de alta el auto
 *
 * \param pId int* paso por referencia pId
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int altaAuto(int* pId, eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief busco el id que el usario me ingresa
 *
 * \param pIndice int* paso por referencia pIndice
 * \param id int paso por parametro id
 * \param autos[] eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int buscarLugarId(int* pIndice, int id, eAuto autos[], int tamA);
/** \brief doy de baja un auto
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief modifico un auto segun el id que ingresa el usuario
 *
 * \param autos[] eAuto  eAuto  paso por param autos para recorrerlo
 * \param tamA int paso el tamanio de array autos
 * \param marcas[] eMarca paso por param marcas para recorrerlo
 * \param tamM int paso el tamanio de array marcas
 * \param colores[] eColor  paso por param colores para recorrerlo
 * \param tamC int paso el tamanio de array colores
 * \return int  devuelve 1 si salio todo bien de lo contrario 0
 *
 */
int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/** \brief menu de opciones de la modificaion
 *
 * \return int devuelvo la opcion que eligio el usuario
 *
 */
int menuModificacion();


void mostrarCliente(eCliente cliente);
int mostrarClientes(eCliente clientes[],int tamC);
int cargarNombreCliente(int id, char nombre[], eCliente clientes[], int tamC);
