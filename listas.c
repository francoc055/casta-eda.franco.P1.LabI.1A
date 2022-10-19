#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10

int listarxMarcaYcaja(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int ret = 0;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        for(int i = 0; i < tamM; i++)
        {

            for(int j= 0; j < tamA;j++)
            {
                if(!autos[j].isEmpty && autos[j].idMarca == marcas[i].id)
                {
                    printf("marca\t caja\n");
                    printf("%s\t %c\n\n", marcas[i].descripcion, autos[j].caja);
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
        for(int i = 0; i < tamC; i++)
        {
            for(int j = 0; j< tamA; j++)
            {
                if(!autos[j].isEmpty && autos[j].idMarca == colores[i].id)
                {
                    printf("color: %s\n", colores[i].NombreColor);
                }
            }
        }

        ret = 1;
    }
    return ret;
}

int listarServicios(eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    int ret = 0;

        if(autos != NULL && tamA > 0 && servicios != NULL && tamS > 0)
        {
            for(int i = 0; i < tamS; i++)
            {
                for(int j = 0; j< tamA; j++)
                {
                    if(!autos[j].isEmpty && autos[j].idMarca == servicios[i].id)
                    {
                        printf("servicio: %s\n", servicios[i].descripcion);
                    }
            }

            ret = 1;
        }
    }
        return ret;
}
