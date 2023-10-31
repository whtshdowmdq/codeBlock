#include "stEspecialidadMedica.h"

stEspecialidad agarrarUnaEspecialidad (stRegistroMedico registro)
{
    stEspecialidad especialidad;

    especialidad.idEspecialidad = registro.idEspecialidad;
    strcpy(especialidad.especialidadMedica,registro.especialidadMedica);
    strcpy(especialidad.nombreDoctor,registro.nombreDoctor);

    return especialidad;
}

void mostrarUnaEspecialidad (stEspecialidad especialidad)
{
    printf("Id de la especialidad: %d\n",especialidad.idEspecialidad);
    printf("Especialidad medica: %s:\n", especialidad.especialidadMedica);
    printf("Nombre del Doctor: %s\n",especialidad.nombreDoctor);
}
