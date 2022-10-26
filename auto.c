#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "validaciones.h"


#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10


void mostrarMarca(eMarca marca)
{
    printf("%d\t %s\n", marca.id, marca.descripcion);
}
int mostrarMarcas(eMarca marcas[], int tamM)
{
    int ret = 0;

    if(marcas != NULL && tamM > 0)
    {
        for(int i = 0; i < tamM; i++)
        {
            mostrarMarca(marcas[i]);
        }

        ret =1;
    }
    return ret;
}


void mostrarColor(eColor color)
{
    printf("%d\t %s\n", color.id, color.NombreColor);
}
int mostrarColores(eColor colores[], int tamC)
{
    int ret = 0;

    if(colores != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            mostrarColor(colores[i]);
        }

        ret =1;
    }
    return ret;
}


int inicializarAuto(eAuto aauto[], int tamA)
{
    int ret = 0;

    if(aauto != NULL && tamA > 0)
    {
        for(int i = 0; i < tamA; i++)
        {
            aauto[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}

int buscarLibre(int* pId, eAuto aauto[], int tamA)
{
    int ret = 0;
    int indice = -1;

    if(pId != NULL && aauto != NULL && tamA > 0)
    {
        for(int i = 0; i < tamA; i++)
        {
            if(aauto[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pId = indice;
        ret = 1;
    }
    return ret;
}

int cargaraAuto(eAuto* pAuto, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret =  0;
    int auxMarca;
    int auxColor;
    int auxCliente;

    if(pAuto != NULL && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        mostrarMarcas(marcas, tamM);
        printf("ingresa el id de la marca que desea: \n");
        scanf("%d", &auxMarca);
        while(!validarMarca(auxMarca, marcas, tamM))
        {
            printf("id invalido\n");
            scanf("%d", &auxMarca);
        }

        mostrarColores(colores, tamC);
        printf("ingresa el id del color que desea: \n");
        scanf("%d", &auxColor);
        while(!validarColor(auxColor, colores, tamC))
        {
            printf("id invalido\n");
            scanf("%d", &auxColor);
        }

        printf("ingrese que tipo de caja desea:\n");
        fflush(stdin);
        scanf("%c", &pAuto->caja);
        while(!validarCaja(pAuto->caja))
        {
            printf("caja invalida. reingrese:\n");
            fflush(stdin);
            scanf("%c", &pAuto->caja);
        }

        mostrarClientes(clientes, tamCl);
        printf("ingrese el id del cliente: \n");
        scanf("%d", &auxCliente);
        while(!validarCliente(auxCliente, clientes, tamCl))
        {
            printf("id invalido. reingrese: \n");
            scanf("%d", &auxCliente);
        }

        pAuto->idMarca = auxMarca;
        pAuto->IdColor = auxColor;
        pAuto->idCliente = auxCliente;
        pAuto->isEmpty = 0;

        ret = 1;
    }
    return ret;
}

int cargarDescripcionMarca(int id, char descripcion[], eMarca marcas[], int tamM)
{
    int ret = 0;
    if(descripcion != NULL && marcas != NULL && tamM > 0)
    {
        for(int i = 0; i < tamM; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descripcion, marcas[i].descripcion);
                break;
            }
        }

        ret = 1;
    }

    return ret;
}

int cargarDescripcionColor(int id, char nombreColor[], eColor colores[], int tamC)
{
    int ret = 0;
    if(nombreColor != NULL && colores != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(nombreColor, colores[i].NombreColor);
                break;
            }
        }

        ret = 1;
    }

    return ret;
}

int mostrarAuto(eAuto a, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    char descMarca[20];
    char nombreColor[20];
    char nombreCliente[20];

    if(marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        cargarDescripcionMarca(a.idMarca, descMarca, marcas, tamM);
        cargarDescripcionColor(a.IdColor, nombreColor, colores, tamC);
        cargarNombreCliente(a.idCliente, nombreCliente, clientes, tamCl);

        printf("%1d %12s %9s %7s %5c\n", a.id, nombreCliente, descMarca, nombreColor, a.caja);

        ret =1;
    }
    return ret;
}

int mostrarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int flag = 1;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    **AUTOS\n");
        printf("ID\tNOMBRE\t   MARCA   COLOR    CAJA\n");
        for(int i = 0; i < tamA; i++)
        {
            if(!autos[i].isEmpty)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
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


int altaAuto(int* pId, eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int indice;
    eAuto auxAuto;

    if(pId != NULL && autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        printf("    **ALTA AUTO\n");

        buscarLibre(&indice, autos, tamA);

        if(indice == -1)
        {
            printf("no hay capacidad\n");
        }
        else
        {
            cargaraAuto(&auxAuto, marcas, tamM, colores, tamC, clientes, tamCl);

            auxAuto.id = *pId;

            (*pId)++;

            autos[indice] = auxAuto;
        }
        ret = 1;
    }
    return ret;
}

int hardcodearAutos(int* pId, eAuto vec[], int tam, int cant)
{
    int ret = 0;

    eAuto almacenAutos[] =
    {
        {1, 1000, 5000, 'a', 3000},
        {2, 1001, 5001, 'm', 3001},
        {3, 1002, 5002, 'a', 3002},
        {4, 1003, 5003, 'a', 3003},
        {5, 1004, 5002, 'm', 3004}
    };
    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

        for(int i = 0 ; i < cant ; i++)
        {

            vec[i] = almacenAutos[i];
            *pId = *pId+ 1;
        }
        ret = 1;
    }
    return ret;
}

//baja
int buscarLugarId(int* pIndice, int id, eAuto autos[], int tamA)
{
    int ret = 0;
    int indice = -1;

    if(autos != NULL && tamA > 0)
    {
        for(int i = 0; i < tamA; i++)
        {
            if(!autos[i].isEmpty && autos[i].id == id)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
    }
    return ret;
}

int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int id;
    int indice;
    char confirma;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        printf("    **BAJA AUTO\n\n");
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
        printf("ingrese id: \n");
        scanf("%d", &id);

        buscarLugarId(&indice, id, autos, tamA);
        if(indice == -1)
        {
            printf("no existe ese id\n");
        }
        else
        {
            mostrarAuto(autos[indice], marcas, tamM, colores, tamC, clientes, tamCl);
            printf("confirma baja?\n");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                autos[indice].isEmpty = 1;
                ret = 1;
            }
            else
            {
                printf("baja cancelada por el usuario");
            }
        }
    }

    return ret;
}

//modificar
int menuModificacion()
{
    int opcion;

    printf("    **MODIFICAR\n");
    printf("1-marca\n");
    printf("2-color\n");
    printf("3-salir\n");
    scanf("%d", &opcion);

    return opcion;
}

int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int ret = 0;
    int id;
    int indice;
    char confirma = 'n';
    char salir = 'n';
    int auxMarca;
    int auxColor;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0)
    {
        printf("    **MODIFICAR AUTO\n");
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
        printf("ingrese id:\n");
        scanf("%d", &id);
        buscarLugarId(&indice, id, autos, tamA);
        if(indice == -1)
        {
            printf("no existe ese id\n");
        }
        else
        {
            mostrarAuto(autos[indice], marcas, tamM, colores, tamC, clientes, tamCl);
                switch(menuModificacion())
                {
                case 1:
                    mostrarMarcas(marcas, tamM);
                    printf("ingrese id de la nueva marca\n");
                    scanf("%d", &auxMarca);
                    printf("confirma modificacion?\n");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma == 's')
                    {
                        autos[indice].idMarca = auxMarca;
                    }
                    else
                    {
                        printf("modificacion cancelada por el usuario\n");
                    }
                    break;
                case 2:
                    mostrarColores(colores, tamC);
                    printf("ingrese nuevo color\n");
                    scanf("%d", &auxColor);
                    printf("confirma modificacion?\n");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma == 's')
                    {
                        autos[indice].IdColor = auxColor;
                    }
                    else
                    {
                        printf("modificacion cancelada por el usuario\n");
                    }
                    break;
                case 3:
                    confirmarSalida(&salir, 's', 'n');
                    break;
                }
        }


        ret = 1;
    }
    return ret;
}

void mostrarCliente(eCliente cliente)
{
    printf("%d\t %s\t %c\n", cliente.id, cliente.nombre, cliente.sexo);
}

int mostrarClientes(eCliente clientes[],int tamC)
{
    int ret = 0;

    if(clientes != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            mostrarCliente(clientes[i]);
        }

        ret =1;
    }
    return ret;
}


int cargarNombreCliente(int id, char nombre[], eCliente clientes[], int tamC)
{
    int ret = 0;
    if(nombre != NULL && clientes != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(clientes[i].id == id)
            {
                strcpy(nombre, clientes[i].nombre);
                break;
            }
        }

        ret = 1;
    }

    return ret;
}
