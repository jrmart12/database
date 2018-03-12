#include "archivo.h"

archivo::archivo(char * nombre, bool nuevo)
{
    this->nombre = nombre;
    if(nuevo){
        file = fopen(nombre, "w");
        fclose(file);
    }
}

void archivo::setTamano(int posicion)
{
    open();
    fseek(file, posicion, SEEK_SET);
    fputc('\0', file);
    close();
}
void archivo::close()
{
    fclose(file);
}
void archivo::open()
{
    file = fopen(nombre, "r+");
}
void archivo::write(int posicion, char * data, int longitud)
{
    open();
    fseek(file, posicion, SEEK_SET);
    fwrite(data, sizeof(char), longitud, file);
    close();
}
char* archivo::read(int posicion, int longitud)
{
    open();
    char * data = new char[longitud];
    fseek(file, posicion, SEEK_SET);
    fread(data, sizeof(char), longitud, file);
    close();
    return data;
}

void archivo::Delete()
{

}

