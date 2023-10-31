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

void buscarAnimal (celdaEspecie arreglo[],int validos, char especie[],char animal[])
{
    int pos= buscarPosEspecie(arreglo,validos,especie);

    int encontrado= buscarNOdoEnArbol(arreglo[pos].arbolDeAnimales,animal);
     if(encontrado==0)
    {

        printf("\n No se encontro en la especie ( %s ) el animal %s ",especie,animal);
    }
    else
    {

        printf("\n Se encontro en la especie ( %s ) el animal %s ",especie,animal);
    }
}



int contarAnimalesPorEspecie (celdaEspecie arreglo[], int validos, char especie[])
{
    int pos= buscarPosEspecie(arreglo,validos,especie);

    int cont= contarNodoArbol(arreglo[pos].arbolDeAnimales);

    return cont;
}
int sumarCantidadAnimalEspecie(celdaEspecie arreglo[],int validos,char especie[])
{

    int pos = buscarPosEspecie(arreglo,validos,especie);

    int suma = sumarNodoArbol(arreglo[pos].arbolDeAnimales);

    return suma;

}
void mostrarAnimalesPorEspecie (celdaEspecie arreglo[], int validos)
{
    int i=0, cont =0, suma=0;

    for(i=0; i< validos;i++)
    {
        cont= contarAnimalesPorEspecie(arreglo,validos,arreglo[i].dato.especie);
        suma= sumarCantidadAnimalEspecie(arreglo,validos,arreglo[i].dato.especie);

        printf("\n Contar nombres de animales -> %d",cont);
        printf("\n Sumar cant de animale -> %d",suma);
    }
}

void celdaToArchi (char dirArchi[],celdaEspecie arreglo[],int validos,char especie[])
{
    FILE* archi= fopen(dirArchi,"ab");
    int pos=0;
    if(archi)
    {
        pos= buscarPosEspecie(arreglo,validos,especie);
        inOrderToArchivo(arreglo[pos].arbolDeAnimales,archi);
        fclose(archi);
    }
}

void inOrderToArchivo (nodoArbol* arbol, FILE* archi)
{
    stAnimal ani;

    if(arbol)
    {
        inOrden(arbol->izq);
        ani=arbol->dato;
        fwrite(&ani,sizeof(stAnimal),1,archi);
        inOrden(arbol->der);
    }
}
