#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "listas.h"
#include "trabajo.h"
#include "validaciones.h"


#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10

int validarMarca(int id, eMarca marcas[], int tamM)
{
    int esValido = 0;
    if(marcas != NULL && tamM > 0 && id > 0)
    {
        for(int i = 0; i < tamM; i++)
        {
            if(marcas[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }
    return esValido;
}

int validarColor(int id, eColor colores[], int tamC)
{
    int esValido = 0;
    if(colores != NULL && tamC > 0 && id > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(colores[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }
    return esValido;
}

int validarServicio(int id, eServicio servicios[], int tamS)
{
    int esValido = 0;
    if(servicios != NULL && tamS > 0 && id > 0)
    {
        for(int i = 0; i < tamS; i++)
        {
            if(servicios[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }
    return esValido;
}

int validarAuto(int id, eAuto autos[], int tamA)
{
    int esValido = 0;
    if(autos != NULL && tamA > 0 && id > 0)
    {
        for(int i = 0; i < tamA; i++)
        {
            if(autos[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }
    return esValido;
}


int validarCaja(char valor)
{
    int ret = 0;
    valor = tolower(valor);

    if(valor == 'm' || valor == 'a')
    {
        ret = 1;
    }
    return ret;
}

int validarFecha(int dia, int mes, int anio)
{
    int ret = 0;
    int flag = 0;

    if(mes > 0 && mes <= 12)
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia > 0 && dia <= 31)
            {
                flag = 1;
            }
            break;
        case 2:
                if(dia > 0 && dia <= 28)
                {
                    flag = 1;
                }
            break;
        case 6:
        case 4:
        case 9:
        case 11:
            if(dia > 0 && dia <= 30)
            {
                flag = 1;
            }
        }
    }


    if(flag)
    {
        ret = 1;
    }

    return ret;
}

int validarCliente(int id, eCliente clientes[], int tamCl)
{
    int esValido = 0;
    if(clientes != NULL && tamCl > 0 && id > 0)
    {
        for(int i = 0; i < tamCl; i++)
        {
            if(clientes[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }
    return esValido;
}
