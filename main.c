#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "listas.h"
#include "trabajo.h"
#include "informes.h"

#define TAM_A 10
#define TAM 5
#define TAM_S 4
#define TAM_T 10



int menu();
int confirmarSalida(char* pVariable, char confirma, char rechaza);
int flagALtaAuto(eAuto autos[], int tam);
int flagALtaTrabajo(eTrabajo trabajos[], int tam);



int main()
{
    char salir = 'n';
    int nextIdA = 1;
    int nextIdT = 100;
    //int flagALtaAuto = 0;
    //int flagALtaTrabajo = 0;

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
        {20000, "lavado", 450},
        {20001, "pulido", 500},
        {20002, "encerado", 600},
        {20003, "completo", 900}
    };

    eCliente clientes[TAM]= {
        {3000, "marisa", 'f'},
        {3001, "manuel", 'm'},
        {3002, "juan", 'm'},
        {3003, "carlos", 'm'},
        {3004, "lucia", 'f'}
    };

    inicializarAuto(autos, TAM_A);
    inicializarTrabajo(trabajos, TAM_T);
    hardcodearAutos(&nextIdA, autos, TAM_A, 5);
    hardcodearTrabajo(&nextIdT, trabajos, TAM_T, 5);

    do{
    switch(menu())
    {
    case 1:
        altaAuto(&nextIdA ,autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
        break;
    case 2:
        if(flagALtaAuto(autos, TAM_A))
        {
            modificarAuto(autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un auto\n");
        }
        break;
    case 3:
        if(flagALtaAuto(autos, TAM_A))
        {
            bajaAuto(autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un auto\n");
        }
        break;
    case 4:
        if(flagALtaAuto(autos, TAM_A))
        {
            listarxMarcaYcaja(autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un auto\n");
        }
        break;
    case 5:
        if(flagALtaAuto(autos, TAM_A))
        {
            listarMarcas(autos, TAM_A ,marcas, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un auto\n");
        }
        break;
    case 6:
        if(flagALtaAuto(autos, TAM_A))
        {
            listarColores(autos, TAM_A, colores, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un auto\n");
        }
        break;
    case 7:
        if(flagALtaTrabajo(trabajos, TAM_T))
        {
            listarServicios(trabajos, TAM_T, lavados, TAM_S);
        }
        else
        {
            printf("primero tenes que dar de alta un trabajo\n");
        }
        break;
    case 8:
        if(flagALtaAuto(autos, TAM_A))
        {
            altaTrabajo(&nextIdT ,trabajos, TAM_T, autos, TAM_A, lavados, TAM_S,  marcas, TAM, colores, TAM,clientes, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un auto\n");
        }
        break;
    case 9:
        if(flagALtaTrabajo(trabajos, TAM_T))
        {
            mostrarTrabajos(trabajos, TAM_T, autos, TAM_A, lavados, TAM_S, marcas, TAM);
        }
        else
        {
            printf("primero tenes que dar de alta un trabajo\n");
        }
        break;
    case 10:
        if(flagALtaAuto(autos, TAM_A) && flagALtaTrabajo(trabajos, TAM_T))
        {
            switch(menuInformes())
            {

                case 1:
                mostrarAutosDeUnColor(autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
                break;
                case 2:
                mostrarAutosDeUnaMarca(autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
                break;
                case 3:
                porcentajeCajas(autos, TAM_A, marcas, TAM, colores, TAM);
                break;
                case 4:
                listaAutosPorCaja(autos, TAM_A, marcas, TAM, colores, TAM, clientes, TAM);
                break;
                case 5:
                contadorAutosColorYmarca(autos, TAM_A, marcas, TAM, colores, TAM);
                break;
                case 6:
                marcaMasElegida(autos, TAM_A, marcas, TAM, colores, TAM);
                break;
                case 7:
                trabajosDeUnAuto(trabajos, TAM_T, autos, TAM_A, lavados, TAM_S,  marcas, TAM, colores, TAM, clientes, TAM);
                break;
                case 8:
                importesDeUnAuto(trabajos, TAM_T, autos, TAM_A, lavados, TAM_S,  marcas, TAM, colores, TAM, clientes, TAM);
                break;
                case 9:
                mostrarAutosYfechasDeUnServicio(trabajos, TAM_T, autos, TAM_A, lavados, TAM_S,  marcas, TAM, colores, TAM);
                break;
                case 10:
                mostrarServiciosEnUnaFecha(trabajos, TAM_T, autos, TAM_A, lavados, TAM_S,  marcas, TAM, colores, TAM);
                break;
            }
        }
        else
        {
            printf("primero debes realizar almenos un alta de auto y trabajo\n");
        }
        break;
    case 11:
        confirmarSalida(&salir, 's', 'n');
        break;
    }
    fflush(stdin);
    }while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    printf("1-alta\n");
    printf("2-modificar\n");
    printf("3-baja\n");
    printf("4-listar por caja y marca\n");
    printf("5-listar marcas\n");
    printf("6-listar colores\n");
    printf("7-listar servicios\n");
    printf("8-alta trabajo\n");
    printf("9-listar trabajos\n");
    printf("10-informes\n");
    printf("11-salir\n");

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

int flagALtaAuto(eAuto autos[], int tam)
{
    int ret = 0;

    if(autos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!autos[i].isEmpty)
            {
                ret = 1;
            }
        }
    }
    return ret;
}

int flagALtaTrabajo(eTrabajo trabajos[], int tam)
{
    int ret = 0;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                ret = 1;
            }
        }
    }
    return ret;
}
