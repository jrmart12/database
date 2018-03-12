#ifndef TABLA_H
#define TABLA_H
#include <string.h>
#include <iostream>
#include "archivo.h"
using namespace std;

class tabla
{
    public:
        tabla(int pos,int cantidad, char * nombre, char * key, int empieza, int termina, archivo *arch);
        bool borrado;
        int cantidadcolumna;
        char * nombre;
        char * key;
        int posicion;
        int empieza;
        int termina;
        int numero;
        void Initfromchar(char * datos);
        void cargar(int longitud, int posicion);
        char** nombres;
        int * tipos;
        archivo *arch;
        char *ToChar();
        void guardar();
        void agregarColumna( char * nombre, int tipo);
    protected:

    private:
};

#endif // TABLA_H
