#ifndef STREGISTROMEDICO_H_INCLUDED
#define STREGISTROMEDICO_H_INCLUDED

typedef struct{
int idRegistro;
int idPaciente;
int idEspecialidad;
char nombrePaciente[30];
char apellidoPaciente[30];
char diagnostico[100];
char fechaAtencion[11]; /// formato: AAAA-mm-DD
char especialidadMedica[30];
char nombreDoctor[30];
}stRegistroMedico;


#endif // STREGISTROMEDICO_H_INCLUDED
