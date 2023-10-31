#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "stPaciente.h"


typedef struct _nodoArbol
{
    stPaciente dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stPaciente dato);
nodoArbol* agregarEnArbol(nodoArbol* arbol, nodoArbol* nuevo);
void mostrarUnPaciente (stPaciente paciente);


#endif // ARBOL_H_INCLUDED
