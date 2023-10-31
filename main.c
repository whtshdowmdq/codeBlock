#include <stdio.h>
#include <stdlib.h>
#include "stEspecialidadMedica.h"
#include "stPaciente.h"
#include "celda.h"

int main()
{
        char dirArchi[]={"registroMedico.dat"};
        stRegistroMedico registro;
        int validos=0,dim=200;
        celda arreglo[dim];
        validos= archivoToArreglo(dirArchi,arreglo,dim);

        mostrarCelda(arreglo, validos);

    return 0;
}

int archivoToArreglo (char dirArchi[],celda arreglo[],int dim)
{
    FILE* archi= fopen(dirArchi,"rb");

    stEspecialidad especialidad;
    stPaciente paciente;
    stRegistroMedico registro;

    int validos=0, i=0;

    if(archi)
    {
        while (i < dim && fread(&registro,sizeof(stRegistroMedico),1,archi)> 0)
        {
            especialidad=agarrarUnaEspecialidad(registro);
            paciente=cargaUnPaciente(registro);

            validos=altaEspecialidad(arreglo,validos,especialidad,paciente);
        }
        fclose(archi);
    }
    return validos;
}

/*int encontrarPacientePorEspecialidad ()*/
