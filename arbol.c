#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(stPaciente dato)
{
    nodoArbol* nuevo= (nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->dato= dato;
    nuevo->izq= inicArbol();
    nuevo->der= inicArbol();

    return nuevo;
}

nodoArbol* agregarEnArbol(nodoArbol* arbol, nodoArbol* nuevo)/// nodoArbol* arbol, stAnimal dato
{
    if(!arbol)
    {
        arbol= nuevo;
    }else
    {
        if(nuevo->dato.idPaciente < arbol->dato.idPaciente)
        {
            arbol->izq= agregarEnArbol(arbol->izq, nuevo);
        }else
        {
            arbol->der= agregarEnArbol(arbol->der,nuevo);
        }
    }
    return arbol;
}

void mostrarInOrder (nodoArbol* arbol)
{
  if(arbol)
  {
    mostrarInOrder(arbol->izq);
    mostrarUnPaciente(arbol->dato);
    mostrarInOrder(arbol->der);
  }

}
