#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10

typedef struct{
int dia;
int mes;
int anio;
}eFecha;
/*
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
int idMarca;
int IdColor;
char caja;
int isEmpty;
}eAuto;
*/
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

int hardcodearAutos(int* pId, eAuto vec[], int tam, int cant);

int menu();
int confirmarSalida(char* pVariable, char confirma, char rechaza);


int listarxMarcaYcaja(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
int listarMarcas(eAuto autos[], int tamA, eMarca marcas[], int tam);
int listarColores(eAuto autos[], int tamA, eColor colores[], int tamC);
int listarServicios(eAuto autos[], int tamA, eServicio servicios[], int tamS);


int inicializarTrabajo(eTrabajo trabajo[], int tamTr);
int buscarLibreTrabajo(int* pIndice, eTrabajo trabajo[], int tamTr);

void mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio servicios[], int tamS);

int cargarTrabajo (eTrabajo* pTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
int cargarDescripcionServicio(int id, char descripcion[], eServicio servicios[], int tamS);
int mostrarTrabajo(eTrabajo t, eAuto autos[], int tamA, eServicio servicios[], int tamS);
int mostrarTrabajos(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS);

int altaTrabajo(int* pId, eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);



int main()
{
    char salir = 'n';
    int nextIdA = 1;
    int nextIdT = 100;

    eAuto autos[TAM_A];
    eTrabajo trabajos[TAM_T];

    eMarca marcas[TAM] = {
        {1000, "renault"},
        {1001, "ford"},
        {1002, "fiat"},
        {1003, "chevrolet"},
        {1004, "peugeot"}
    };

    eColor colores[TAM] = {
        {5000, "negro"},
        {5001, "blanco"},
        {5002, "rojo"},
        {5003, "verde"},
        {5004, "azul"}
    };

    eServicio lavados[TAM_S] = {
        {2000, "lavado", 450},
        {2001, "pulido", 500},
        {2002, "encerado", 600},
        {2003, "completo", 900}
    };

    inicializarAuto(autos, TAM_A);
    inicializarTrabajo(trabajos, TAM_T);
    hardcodearAutos(&nextIdA, autos, TAM_A, 2);

    do{
    switch(menu())
    {
    case 1:
        altaAuto(&nextIdA ,autos, TAM_A, marcas, TAM, colores, TAM);
        break;
    case 2:
        modificarAuto(autos, TAM_A, marcas, TAM, colores, TAM);
        break;
    case 3:
        bajaAuto(autos, TAM_A, marcas, TAM, colores, TAM);
        break;
    case 4:
        listarxMarcaYcaja(autos, TAM_A, marcas, TAM, colores, TAM);
        break;
    case 5:
        listarMarcas(autos, TAM_A ,marcas, TAM);
        break;
    case 6:
        listarColores(autos, TAM_A, colores, TAM);
        break;
    case 7:
        listarServicios(autos, TAM_A, lavados, TAM_S);
        break;
    case 8:
        altaTrabajo(&nextIdT ,trabajos, TAM_T, autos, TAM_A, lavados, TAM_S,  marcas, TAM, colores, TAM );
        break;
    case 10:
        confirmarSalida(&salir, 's', 'n');
        break;
    }
    }while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    printf("1-alta\n");
    printf("2-modificar\n");
    printf("3-baja\n");
    //printf("4-mostrar\n");
    printf("4-listar por caja y marca\n");
    printf("5-listar marcas\n");
    printf("6-listar colores\n");
    printf("7-listar servicios\n");
    printf("8-alta trabajo\n");
    printf("10-salir");

    //printf("6-mostrar viajes\n");
    //printf("7-salir\n");
    scanf("%d", &opcion);

    return opcion;
}

int confirmarSalida(char* pVariable, char confirma, char rechaza)
{
    int ret = 0;
    char resp;
    if(pVariable != NULL)
    {
       printf("confirma salir?\n");
       fflush(stdin);
       resp = getchar();
       if(resp == 's')
       {
           *pVariable = confirma;
       }
       else
       {
           *pVariable = rechaza;
       }
        ret = 1;
    }

    return ret;
}


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
/////////////////////////

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


int cargarTrabajo (eTrabajo* pTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int ret =  0;

    if(pTrabajo != NULL && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("ingresa el id del auto que desea: \n");
        scanf("%d", &pTrabajo->idAuto);

        mostrarServicios(servicios, tamS);
        printf("ingresa el id del servicio que desea: \n");
        scanf("%d", &pTrabajo->IdServicio);

        printf("ingrese la fecha:\n");
        scanf("%d/%d/%d", &pTrabajo->fecha.dia, &pTrabajo->fecha.mes, &pTrabajo->fecha.anio);
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

int mostrarTrabajo(eTrabajo t, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    int ret = 0;
    char desServicio[20];
    //char descTipo[20];

    if(autos != NULL && tamA > 0 && servicios != NULL && tamS > 0)
    {
        cargarDescripcionServicio(t.IdServicio, desServicio, servicios, tamS);

        printf("%s\t %d/%d/%d\n", desServicio, t.fecha.dia, t.fecha.mes, t.fecha.anio);

        ret =1;
    }
    return ret;
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    int ret = 0;
    int flag = 1;

    if(trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0)
    {
        system("cls");
        printf("    **TRABAJOS\n");
        printf("SERVICIOS\t FECHA\n");
        for(int i = 0; i < tamTr; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
                flag = 0;
            }
        }

        if(flag)
        {
            printf("no hay viajes para mostrar\n");
        }

        ret = 1;
    }
    return ret;
}


int altaTrabajo(int* pId, eTrabajo trabajos[], int tamTr, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int ret = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pId != NULL && trabajos != NULL && tamTr > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0 )
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
            cargarTrabajo(&auxTrabajo, autos, tamA, servicios, tamS, marcas, tamM, colores, tamC);

            auxTrabajo.id = *pId;

            (*pId)++;

            trabajos[indice] = auxTrabajo;
        }
        ret = 1;
    }
    return ret;
}
