#include "BaseDeDatos.h"


void BaseDeDatos::cargar()
{

}
void BaseDeDatos::initfromchar(char *datos)
{
    int posicion=0;
    memcpy(&index,&(datos[posicion]),4);
    posicion+=4;
    memcpy(&cantidadBloques,&(datos[posicion]),4);
    posicion+=4;
    memcpy(&cantidadTablas,&(datos[posicion]),4);
    posicion+=4;

}
void BaseDeDatos::guardar()
{

}
char* BaseDeDatos::MasterBlockToChar()
{
    int posicion=0;
    char * datos= new char[12];
    memcpy(&(datos[posicion]),&index,4);
    posicion+=4;
    memcpy(&(datos[posicion]),&cantidadBloques,4);
    posicion+=4;
    memcpy(&(datos[posicion]),&cantidadTablas,4);
    posicion+=4;
}
 BaseDeDatos::~BaseDeDatos()
 {

 }
 BaseDeDatos::BaseDeDatos(int tamanoArchivo, archivo *arch)
 {
    this->index=13;
    this->cantidadBloques=((tamanoArchivo*1024*1024)/4096);
    this->arch=arch;
    this->cantidadTablas=0;
 }
