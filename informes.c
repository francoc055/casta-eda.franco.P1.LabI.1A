#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "listas.h"
#include "trabajo.h"
#include "validaciones.h"
#include "informes.h"


#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10

int menuInformes()
{
    int opcion;

    printf("1-mostrar autos segun el color\n");
    printf("2-mostrar autos segun la marca\n");
    printf("3-promedio cajas manual y automatico\n");
    printf("4-listar autos por caja\n");
    printf("5-contar autos de color y marca\n");
    printf("6-marca mas elegida\n");
    printf("7-trabajos que se le hicieron a un auto\n");
    printf("8-importe de un auto\n");
    printf("9-auto y fecha que realizo un servicio\n");
    printf("10-servicios en una fecha\n");
    printf("11-salir\n");

    scanf("%d", &opcion);

    return opcion;
}

int mostrarAutosDeUnColor(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int auxId;
    int flag = 0;
    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        mostrarColores(colores, tamC);
        printf("ingrese el id del color que desea mostrar: \n");
        scanf("%d", &auxId);
        while(!validarColor(auxId, colores, tamC))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &auxId);
        }
        printf("ID\tNOMBRE\t   MARCA   COLOR    CAJA\n");
        for(int i =0; i < tamC;i++)
        {
            if(!autos[i].isEmpty && autos[i].IdColor == auxId)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("no hay autos de ese color\n");
        }
        system("pause");
        ret = 1;
    }
    return ret;
}

int mostrarAutosDeUnaMarca(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int auxId;
    int flag = 0;
    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl)
    {
        system("cls");
        mostrarMarcas(marcas, tamM);
        printf("ingrese el id de la marca que desea mostrar: \n");
        scanf("%d", &auxId);
        while(!validarMarca(auxId, marcas, tamM))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &auxId);
        }
        printf("ID\tNOMBRE\t   MARCA   COLOR    CAJA\n");
        for(int i =0; i < tamC;i++)
        {
            if(!autos[i].isEmpty && autos[i].idMarca == auxId)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("no hay autos de esa marca\n");
        }
        system("pause");
        ret = 1;
    }
    return ret;
}

int porcentajeCajas(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC)
{
    int ret = 0;
    int contadorCajaM = 0;
    int contadorCajaA = 0;
    int totalAutos;
    float promedioManual;
    float promedioAutom;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        for(int i = 0; i < tamA; i++)
        {
            if(!autos[i].isEmpty)
            {
                if(autos[i].caja == 'm')
                {
                    contadorCajaM++;
                }
                else if(autos[i].caja == 'a')
                {
                    contadorCajaA++;
                }
            }
        }
        totalAutos = contadorCajaA + contadorCajaM;

        if(contadorCajaM > 0)
        {
            promedioManual = (float) (contadorCajaM * 100) / totalAutos;
            printf("promedio caja manual: %.2f\n", promedioManual);
        }
        if(contadorCajaA > 0)
        {
            promedioAutom = (float) (contadorCajaA * 100) / totalAutos;
            printf("promedio caja automatico: %.2f\n", promedioAutom);
        }


        ret = 1;
    }
    return ret;
}

int listaAutosPorCaja(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int flagM = 0;
    int flagA = 0;
    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl)
    {
        system("cls");
        printf("autos caja manual\n");
        printf("ID\tNOMBRE\t   MARCA   COLOR    CAJA\n");
        for(int i =0; i < tamA;i++)
        {
            if(!autos[i].isEmpty && autos[i].caja == 'm')
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
                flagM = 1;

            }
        }
        printf("\n\n");
        printf("autos caja automatico\n");
        printf("ID\tNOMBRE\t   MARCA   COLOR    CAJA\n");
        for(int i =0; i < tamA;i++)
        {
            if(!autos[i].isEmpty && autos[i].caja == 'a')
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
                flagA = 1;
            }
        }
        if(!flagA)
        {
            printf("no hay autos con esta caja\n");
        }

        if(!flagM)
        {
            printf("no hay autos con esta caja\n");
        }

        ret = 1;
    }
     return ret;
}


int contadorAutosColorYmarca(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC)
{
    int ret = 0;
    int idMarca;
    int idColor;
    int contador = 0;
    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        mostrarMarcas(marcas, tamM);
        printf("ingrese el id de la marca que desea mostrar: \n");
        scanf("%d", &idMarca);
        while(!validarMarca(idMarca, marcas, tamM))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &idMarca);
        }

        mostrarColores(colores, tamC);
        printf("ingrese el id del color que desea mostrar: \n");
        scanf("%d", &idColor);
        while(!validarColor(idColor, colores, tamC))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &idColor);
        }

        for(int i =0; i < tamC;i++)
        {
            if(!autos[i].isEmpty && autos[i].idMarca == idMarca && autos[i].IdColor == idColor)
            {
                contador++;
            }
        }
        if(contador > 0)
        {
            printf("hay %d autos\n", contador);
        }
        else
        {
            printf("no hay autos de ese color y marca\n");
        }
        system("pause");
        ret = 1;
    }
    return ret;
}


int marcaMasElegida(eAuto autos[],int tamA, eMarca marcas[],int tamM, eColor colores[],int tamC)
{
    int ret = 0;
    int contadores[] = {0, 0, 0 ,0 ,0 ,0};
    int mayor;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        for(int i = 0; i < tamM; i++)
        {
           for(int j = 0; j < tamA; j++)
           {
               if(!autos[j].isEmpty && autos[j].idMarca == marcas[i].id)
               {
                    contadores[i]++;
               }
           }
        }

        for(int i = 0; i < tamM; i++)
        {
            if(i == 0 || contadores[i] > mayor)
            {
                mayor = contadores[i];
                printf("la marca mas elegida por los clientes es: %s\n", marcas[i].descripcion);
            }
        }
        system("pause");
        ret = 1;
    }

    return ret;
}

///////////////////////////////////////////////////////////////////////////
//informes trabajo
int trabajosDeUnAuto(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int idAuto;
    char descServicio[20];
    int flag = 0;
    if(trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
        printf("ingrese id del auto: \n");
        scanf("%d", &idAuto);
        while(!validarAuto(idAuto, autos, tamA))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &idAuto);
        }
        for(int i = 0; i < tamTr; i ++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].idAuto == idAuto)
            {
                cargarDescripcionServicio(trabajos[i].IdServicio, descServicio, servicios, tamS);
                printf("servicio: %s\n", descServicio);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("no se le hizo ningun trabajo\n");
        }
        ret = 1;
    }
    return ret;
}

int importesDeUnAuto(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int idAuto;
    int flag = 0;
    if(trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
        printf("ingrese id del auto: \n");
        scanf("%d", &idAuto);
        while(!validarAuto(idAuto, autos, tamA))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &idAuto);
        }
        for(int i = 0; i < tamTr; i ++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].idAuto == idAuto)
            {
                printf("Importe: %.2f\n", servicios[i].precio);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("no se le hizo ningun trabajo\n");
        }
        ret = 1;
    }
    return ret;
}


int mostrarAutosYfechasDeUnServicio(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int ret = 0;
    int idServicio;
    int flag = 0;
    if(trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 )
    {
        system("cls");
        mostrarServicios(servicios, tamS);
        printf("ingrese el id de un servicio: \n");
        scanf("%d", &idServicio);
        while(!validarServicio(idServicio, servicios, tamS))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &idServicio);
        }
        printf("ID\t ID AUTO     MARCA\t SERVICIOS\t FECHA\n");
        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].IdServicio == idServicio)
            {
                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS, marcas, tamM);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("a ningun auto se le realizo este servicio\n");
        }

        ret = 1;
    }
    return ret;
}


int mostrarServiciosEnUnaFecha(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int ret = 0;
    int idTrab;
    char descServicio[20];
    int flag = 0;
    if(trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 )
    {
        system("cls");
        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                printf("%d %d/%d/%d\n",trabajos[i].id, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            }
        }
        printf("ingrese el id de la fecha que desea: \n");
        scanf("%d", &idTrab);

        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].id == idTrab)
            {
                cargarDescripcionServicio(trabajos[i].IdServicio, descServicio, servicios, tamS);
                printf("servicio: %s\n", descServicio);
                flag =1;
            }
        }

        if(!flag)
        {
            printf("no hay servicios en esta fecha");
        }


        ret = 1;
    }
    return ret;
}
