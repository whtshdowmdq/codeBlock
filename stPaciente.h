#ifndef STPACIENTE_H_INCLUDED
#define STPACIENTE_H_INCLUDED
#include "stRegistroMedico.h"
typedef struct{
int idPaciente;
char nombrePaciente[30];
char apellidoPaciente[30];
char diagnostico[100];
char fechaAtencion[11]; /// formato: AAAA-mm-DD
}stPaciente;

stPaciente cargaUnPaciente (stRegistroMedico registro);
void mostrarUnPaciente (stPaciente paciente);
#endif // STPACIENTE_H_INCLUDED
