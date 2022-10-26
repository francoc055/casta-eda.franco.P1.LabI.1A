#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "listas.h"
#include "trabajo.h"
#include "validaciones.h"


#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10


int inicializarTrabajo(eTrabajo trabajo[], int tamTr)
{
    int ret = 0;

    if(trabajo != NULL && tamTr > 0)
    {
        for(int i = 0; i < tamTr; i++)
        {
            trabajo[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}


int buscarLibreTrabajo(int* pIndice, eTrabajo trabajo[], int tamTr)
{
    int ret = 0;
    int indice = -1;

    if(pIndice != NULL && trabajo != NULL && tamTr > 0)
    {
        for(int i = 0; i < tamTr; i++)
        {
            if(trabajo[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        ret = 1;
    }
    return ret;
}

void mostrarServicio(eServicio servicio)
{
    printf("%d\t %s\n", servicio.id, servicio.descripcion);
}


int mostrarServicios(eServicio servicios[], int tamS)
{
    int ret = 0;

    if(servicios != NULL && tamS > 0)
    {
        for(int i = 0; i < tamS; i++)
        {
            mostrarServicio(servicios[i]);
        }

        ret =1;
    }
    return ret;
}


int cargarTrabajo (eTrabajo* pTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret =  0;

    if(pTrabajo != NULL && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl)
    {
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
        printf("ingresa el id del auto que desea: \n");
        scanf("%d", &pTrabajo->idAuto);
        while(!validarAuto(pTrabajo->idAuto, autos, tamA))
        {
            printf("id invalido: \n");
            scanf("%d", &pTrabajo->idAuto);
        }

        mostrarServicios(servicios, tamS);
        printf("ingresa el id del servicio que desea: \n");
        scanf("%d", &pTrabajo->IdServicio);
        while(!validarServicio(pTrabajo->IdServicio, servicios, tamS))
        {
            printf("id invalido: \n");
            scanf("%d", &pTrabajo->IdServicio);
        }

        printf("ingrese la fecha:\n");
        scanf("%d/%d/%d", &pTrabajo->fecha.dia, &pTrabajo->fecha.mes, &pTrabajo->fecha.anio);
        while(!validarFecha(pTrabajo->fecha.dia, pTrabajo->fecha.mes, pTrabajo->fecha.anio))
        {
            printf("fecha invalida. reingrese:\n");
            scanf("%d/%d/%d", &pTrabajo->fecha.dia, &pTrabajo->fecha.mes, &pTrabajo->fecha.anio);
        }

        pTrabajo->isEmpty = 0;

        ret = 1;
    }
    return ret;
}

int cargarDescripcionServicio(int id, char descripcion[], eServicio servicios[], int tamS)
{
    int ret = 0;
    if(descripcion != NULL && servicios != NULL && tamS > 0)
    {
        for(int i = 0; i < tamS; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descripcion, servicios[i].descripcion);
                break;
            }
        }

        ret = 1;
    }

    return ret;
}



int mostrarTrabajo(eTrabajo t, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM)
{
    int ret = 0;
    char desServicio[20];
    char descMarca[20];
    int idAuto;
    if(autos != NULL && tamA > 0 && servicios != NULL && tamS > 0)
    {
        for(int i = 0; i < tamA; i++)
        {
            if(!autos[i].isEmpty && autos[i].id == t.idAuto)
            {
                cargarDescripcionMarca(autos[i].idMarca, descMarca, marcas, tamM);
                idAuto = autos[i].id;
            }
        }

        cargarDescripcionServicio(t.IdServicio, desServicio, servicios, tamS);

         printf("%d\t %2d\t %10s\t %7s\t %d/%d/%d\n",t.id, idAuto, descMarca, desServicio, t.fecha.dia, t.fecha.mes, t.fecha.anio);

        ret =1;
    }
    return ret;
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM)
{
    int ret = 0;
    int flag = 1;

    if(trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0)
    {
        system("cls");
        printf("    **TRABAJOS\n");
        printf("ID\t ID AUTO     MARCA\t SERVICIOS\t FECHA\n");
        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS, marcas, tamM);
                flag = 0;
            }
        }

        if(flag)
        {
            printf("no hay nada para mostrar\n");
        }

        ret = 1;
    }
    return ret;
}


int altaTrabajo(int* pId, eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pId != NULL && trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    **ALTA TRABAJO\n");

        buscarLibreTrabajo(&indice, trabajos, tamTr);

        if(indice == -1)
        {
            printf("no hay capacidad\n");
        }
        else
        {
            cargarTrabajo(&auxTrabajo, autos, tamA, servicios, tamS, marcas, tamM, colores, tamC, clientes, tamCl);

            auxTrabajo.id = *pId;

            (*pId)++;

            trabajos[indice] = auxTrabajo;
        }
        ret = 1;
    }
    return ret;
}

int hardcodearTrabajo(int* pId, eTrabajo vec[], int tam, int cant)
{
    int ret = 0;

    eTrabajo trabajos[] =
    {
        {100, 1, 20000, {21,8,2022}},
        {101, 2, 20001, {15,9,2022}},
        {102, 3, 20002, {25,3,2022}},
        {103, 4, 20003, {4,10,2022}},
        {104, 5, 20001, {13,8,2022}},
    };

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

        for(int i = 0 ; i < cant ; i++)
        {

            vec[i] = trabajos[i];
            *pId = *pId+ 1;
        }
        ret = 1;
    }
    return ret;
}
