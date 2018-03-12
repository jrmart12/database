#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <iostream>

class archivo
{
    public:
        archivo(char * nombre, bool nuevo);
        char * read(int posicion, int longitud);
        void write(int posicion, char * data, int longitud);
        void open();
        void close();
        void setTamano(int posicion);
        void Delete();
        FILE * file;
        char * nombre;
    protected:
    private:
};

#endif // ARCHIVO_H
