#include "MasterBlock.h"


MasterBlock::MasterBlock(int tamanoArchivo, int tamanoBloque, archivo *arch)
{
    this->tamanoBloque=tamanoBloque;
    this->cantidadBloques=((1024*1024)/tamanoBloque);
    //tengo una cantidad de 256 bloques
    //1048576 bits en cada sector para un bit array
    this->siguienteBloqueDisponible=1;
    this->arch=arch;
}

void MasterBlock::cargar()
{
    initfromchar(this->arch->read(0,tamanoBloque));
}
void MasterBlock::initfromchar(char *datos)
{
    int pos=0;
    memcpy(&tamanoBloque,&(datos[pos]),4);
    pos+=4;
    memcpy(&cantidadBloques,&(datos[pos]),4);
    pos+=4;
    memcpy(&siguienteBloqueDisponible,&(datos[pos]),4);
    pos+=4;
}
void MasterBlock::guardar()
{
    char *datos=MasterBlockToChar();
    this->arch->write(0,datos,tamanoBloque);
}
char* MasterBlock::MasterBlockToChar()
{
    int posicion=0;
    char * datos= new char[tamanoBloque];
    memcpy(&(datos[posicion]),&tamanoBloque,4);
    posicion+=4;
    memcpy(&(datos[posicion]),&cantidadBloques,4);
    posicion+=4;
    memcpy(&(datos[posicion]),&siguienteBloqueDisponible,4);
    posicion+=4;
    return datos;
}
