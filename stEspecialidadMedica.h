#ifndef STESPECIALIDADMEDICA_H_INCLUDED
#define STESPECIALIDADMEDICA_H_INCLUDED
#include "stRegistroMedico.h"
typedef struct
{
    int idEspecialidad;
    char especialidadMedica[30];
    char nombreDoctor[30];
}stEspecialidad;

stEspecialidad agarrarUnaEspecialidad (stRegistroMedico registro);
void mostrarUnaEspecialidad (stEspecialidad especialidad);

#endif // STESPECIALIDADMEDICA_H_INCLUDED
