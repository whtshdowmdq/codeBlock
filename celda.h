#ifndef CELDA_H_INCLUDED
#define CELDA_H_INCLUDED
#include "stEspecialidadMedica.h"
#include "arbol.h"
#include "stRegistroMedico.h"

typedef struct
{
    stEspecialidad dato;
    nodoArbol* paciente;
}celda;

int agregarEnAda(celda especialidad[], int validos, stEspecialidad espe);
int buscarPosEspecialidad (celda especilidad[], int validos, int idEspecialidad);
int altaEspecialidad(celda especialidad[],int validos, stEspecialidad espe, stPaciente paciente);

#endif // CELDA_H_INCLUDED
