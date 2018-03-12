#include "tabla.h"

void tabla::agregarColumna(char* nombre, int tipo)
{
    nombres[numero]=nombre;
    tipos[numero]=tipo;
    numero++;
}

void tabla::guardar()
{
    int po=posicion;
    char *datos=ToChar();
    this->arch->write(po,datos,57);
    po+=57;
    int tam=4*cantidadcolumna;
    int poz=0;
    char * datos3= new char[tam];
    for(int pos = 0; pos<cantidadcolumna; pos++){
        memcpy(&(datos3[poz]),&(tipos[pos]),4);
        poz+=4;
    }
    this->arch->write(po,datos3,tam);
    po+=4*cantidadcolumna;
    tam=30*cantidadcolumna;
    poz=0;
    char * datos2= new char[tam];
    for(int pos = 0; pos<cantidadcolumna; pos++)
    {
    	memcpy(&(datos2[poz]),nombres[pos],29);
    	poz+=30;

    }
    this->arch->write(po,datos2,tam);
}

char* tabla::ToChar()
{
    int posicio=0;
    char *datos= new char[57];
    memcpy(&(datos[posicio]),&borrado,1);
    posicio+=1;
    memcpy(&(datos[posicio]),&posicion,4);
    posicio+=4;
    memcpy(&(datos[posicio]),&cantidadcolumna,4);
    posicio+=4;
    memcpy(&(datos[posicio]),nombre,20);
    posicio+=20;
    memcpy(&(datos[posicio]),key,20);
    posicio+=20;
    memcpy(&(datos[posicio]),&empieza,4);
    posicio+=4;
     memcpy(&(datos[posicio]),&termina,4);
    posicio+=4;
    return datos;
}

void tabla::cargar(int posicion, int longitud)
{
    Initfromchar(this->arch->read(posicion,longitud));
}

void tabla::Initfromchar(char* datos)
{
    int posicio=0;
    memcpy(&borrado,&(datos[posicio]),1);
    posicio+=1;
    memcpy(&cantidadcolumna,&(datos[posicio]),4);
    posicio+=4;
    memcpy(&posicion,&(datos[posicio]),4);
    posicio+=4;
    memcpy(&nombre,&(datos[posicio]),20);
    posicio+=20;
    memcpy(&key,&(datos[posicio]),20);
    posicio+=20;
    memcpy(&empieza,&(datos[posicio]),4);
    posicio+=4;
    memcpy(&termina,&(datos[posicio]),4);
    posicio+=4;
}

tabla::tabla(int pos,int cantidad, char* nombre, char* key, int empieza, int termina, archivo* arch)
{
        borrado=false;
        this->cantidadcolumna=cantidad;
        this->nombre=nombre;
        this->key=key;
        this->posicion=pos;
        this->empieza=empieza;
        this->termina=termina;
        this->numero=0;
        nombres= new char *[cantidad];
        for (int i=0; i<cantidad;++i)
        {
            nombres[i]=new char[30];
        }
        this->tipos=new int[cantidad];
        this->arch=arch;
}


