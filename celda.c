#include <stdio.h>
#include <stdlib.h>
#include "celda.h"
#include <string.h>

int agregarEnAda(celda especialidad[], int validos, stEspecialidad espe)
{
    especialidad[validos].dato.idEspecialidad = espe.idEspecialidad;
    strcpy(especialidad[validos].dato.especialidadMedica,espe.especialidadMedica);
    strcpy(especialidad[validos].dato.nombreDoctor, espe.nombreDoctor);

    especialidad[validos].paciente= inicArbol();
    validos++;

    return validos;
}

int buscarPosEspecialidad (celda especilidad[], int validos, int idEspecialidad)
{
    int pos=-1, i=0;

    while (i < validos && pos == -1)
    {
        if(especilidad[i].dato.idEspecialidad == idEspecialidad)
        {
            pos=i;
        }
        i++;
    }
    return pos;
}

int altaEspecialidad(celda especialidad[],int validos, stEspecialidad espe, stPaciente paciente)
{
    nodoArbol* nuevo= crearNodoArbol(paciente);
    int pos=0;
    pos=buscarPosEspecialidad(especialidad,validos,espe.idEspecialidad);
    if (pos== -1)
    {
        validos=agregarEnAda(especialidad,validos,espe);
        pos= validos - 1;
    }
    especialidad[pos].paciente= agregarEnArbol(especialidad[pos].paciente,nuevo);

    return validos;
}

void mostrarCelda (celda arreglo[], int validos)
{
    int i=0;

    for(i=0;i<validos;i++)
    {
        mostrarUnaEspecialidad(arreglo[i].dato);
        mostrarInOrder(arreglo[i].paciente);
    }
}
