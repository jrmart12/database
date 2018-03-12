#ifndef BLOQUE_H
#define BLOQUE_H
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


class bloque
{
    public:
        bloque(char * nombre, char * contenido, int primerbloque,int ultimobloque,archivo * arch);
        int tamanobloque;
        int tamanonombre;
        char * nombre;
        int tamanocontenido;
        char * contenido;
        int primerbloque;
        int ultimobloque;
        archivo *arch;
        void initfromchar(char * datos);
        char * BloquetoChar();
        void guardar();
    protected:
    private:
};

#endif // BLOQUE_H
