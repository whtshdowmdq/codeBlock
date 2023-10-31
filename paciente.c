#include "stPaciente.h"

stPaciente cargaUnPaciente (stRegistroMedico registro)
{
    stPaciente paciente;

    paciente.idPaciente = registro.idPaciente;
    strcpy(paciente.nombrePaciente,registro.nombrePaciente);
    strcpy(paciente.apellidoPaciente, registro.apellidoPaciente);
    strcpy(paciente.fechaAtencion,registro.fechaAtencion);
    strcpy(paciente.diagnostico,registro.diagnostico);

    return paciente;
}

void mostrarUnPaciente (stPaciente paciente)
{
    printf("ID paciente: %d\n", paciente.idPaciente);
    printf("Nombre del Paciente: %s\n", paciente.nombrePaciente);
    printf("Apellido del Paciente: %s\n", paciente.apellidoPaciente);
    printf("Fecha de atencion del Paciente: %s\n",paciente.fechaAtencion);
    printf("Diagnostico del paciente: %s\n",paciente.diagnostico);
}
