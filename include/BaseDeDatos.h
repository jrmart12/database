#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include "BitArray.h"
#include <iostream>
using namespace std;

class BaseDeDatos
{
    public:
        BaseDeDatos(int tamanoArchivo, archivo *arch);
        virtual ~BaseDeDatos();
        int index;
        int cantidadBloques;
        int cantidadTablas;
        archivo *arch;
        char *MasterBlockToChar();
        void guardar();
        void initfromchar(char *datos);
        void cargar();
    protected:
    private:
};

#endif // BASEDEDATOS_H
