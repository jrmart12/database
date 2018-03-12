#ifndef GESTOR_H
#define GESTOR_H
#include <iostream>
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include "tabla.h"
#include "BaseDeDatos.h"
#include <vector>
#include "list"

class Gestor
{
    public:
        Gestor(char * nombre, int tamano);
        char* nombre;
        int tamano;
        archivo *arch;
        tabla * temp;
        BaseDeDatos * tempb;
        char * key;
        list<tabla*> Tablas;
        list<int> Types;
        list<char*> Nombres;
        bool * bitmap;
        void CargarTablas();
        void IniciarBit();
        int BuscarBit();
        void ImprimirTablas();
        tabla* BuscarTabla(char * nombre);
        void CargarBloques();
        void CargarBits();
        void GuardarBloques();
        void GuardarBits();
        void IniciarBD();
        void CrearTabla(int cantidad, char * nombre, char * key);
        void GuardarTabla();
        void AgregarColumna(int t, char * n);
        void IniciarBloques();
        void BorrarTabla(char * nom);
        void eliminar (char *nombre);
    protected:

    private:
};

#endif // GESTOR_H
