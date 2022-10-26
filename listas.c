#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "listas.h"
#include "trabajo.h"


#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10

int listarxMarcaYcaja(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("ID\tNOMBRE\t   MARCA   COLOR    CAJA\n");
        for(int i = 0; i < tamM; i++)
        {
                for(int j= 0; j < tamA;j++)
                {
                    if(!autos[j].isEmpty)
                    {
                        if(autos[j].idMarca == marcas[i].id && autos[j].caja == 'm')
                        {
                            mostrarAuto(autos[j], marcas, tamM, colores, tamC, clientes, tamCl);
                        }
                    }
                }
        }

        for(int i = 0; i < tamM; i++)
        {
                for(int j= 0; j < tamA;j++)
                {
                    if(!autos[j].isEmpty)
                    {
                        if(autos[j].idMarca == marcas[i].id && autos[j].caja == 'a')
                        {
                            mostrarAuto(autos[j], marcas, tamM, colores, tamC, clientes, tamCl);
                        }
                    }
                }
        }
        ret =1;
    }
    return ret;
}

int listarMarcas(eAuto autos[], int tamA, eMarca marcas[], int tam)
{
    int ret = 0;

    if(autos != NULL && tamA > 0 && marcas != NULL && tam > 0)
    {
        system("cls");
        for(int i = 0; i < tam; i++)
        {
            for(int j = 0; j< tamA; j++)
            {
                if(!autos[j].isEmpty && autos[j].idMarca == marcas[i].id)
                {
                    printf("marca: %s\n", marcas[i].descripcion);
                }
            }
        }

        ret = 1;
    }
    return ret;
}

int listarColores(eAuto autos[], int tamA, eColor colores[], int tamC)
{
    int ret = 0;

    if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        for(int i = 0; i < tamC; i++)
        {
            for(int j = 0; j< tamA; j++)
            {
                if(!autos[j].isEmpty && autos[j].IdColor == colores[i].id)
                {
                    printf("color: %s\n", colores[i].NombreColor);
                }
            }
        }

        ret = 1;
    }
    return ret;
}

int listarServicios(eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS)
{
    int ret = 0;

        if(trabajos != NULL && tamTr > 0 && servicios != NULL && tamS > 0)
        {
            system("cls");
            for(int i = 0; i < tamS; i++)
            {
                for(int j = 0; j< tamTr; j++)
                {
                    if(!trabajos[j].isEmpty && trabajos[j].IdServicio == servicios[i].id)
                    {
                        printf("servicio: %s\n", servicios[i].descripcion);
                    }
            }

            ret = 1;
        }
    }
        return ret;
}
