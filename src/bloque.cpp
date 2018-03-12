#include "bloque.h"

bloque::bloque(char * nombre, char * contenido, int primerbloque,int ultimobloque,archivo * arch)
{
    this->tamanonombre=strlen(nombre);
    this->nombre=nombre;
    this->tamanocontenido=strlen(contenido);
    this->contenido=contenido;
    this->primerbloque=primerbloque;
    this->ultimobloque=ultimobloque;
    this->tamanobloque=20+tamanonombre+tamanocontenido;
    this->arch=arch;
}

void bloque::guardar()
{
char * data = BloquetoChar();
this->arch->write(primerbloque*4096,data,4096);
}
char* bloque::BloquetoChar()
{
    int posicion=0;
    char *datos=new char[4096];
    posicion+=4;
    memcpy(&(datos[posicion]), nombre,20);
    posicion+=20;
    memcpy(&(datos[posicion]),contenido, 500);
    posicion+=500;
    memcpy(&(datos[posicion]),&primerbloque,4);
    posicion+=4;
    memcpy(&(datos[posicion]),&ultimobloque,4);
    posicion+=4;
    return datos;
}
void bloque::initfromchar(char * datos)
{
    int pos=0;
    nombre=new char[tamanonombre];
    memcpy(nombre,&(datos[pos]),20);
    pos+=20;
    contenido=new char[tamanocontenido];
    memcpy(contenido,&(datos[pos]),500);
    pos+=500;
    memcpy(&primerbloque,&(datos[pos]),4);
    pos+=4;
    memcpy(&ultimobloque,&(datos[pos]),4);
    pos+=4;
}

