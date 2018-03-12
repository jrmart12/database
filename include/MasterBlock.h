#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class MasterBlock
{
    public:
        MasterBlock(int tamanoArchivo, int tamanoBloque, archivo *arch);
        int tamanoBloque;
        int cantidadBloques;
        int siguienteBloqueDisponible;
        archivo *arch;
        char *MasterBlockToChar();
        void guardar();
        void initfromchar(char *datos);
        void cargar();
    protected:
    private:
};

#endif // MASTERBLOCK_H
