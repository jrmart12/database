#include "Gestor.h"


Gestor::Gestor(char * nombre, int tamano)
{
    bitmap= new bool[((tamano*1024*1024)/4096)];
    this->nombre= nombre;
    this->tamano=tamano;
    this->arch= new archivo(nombre,true);
    arch->setTamano(tamano);
    this->tempb= new BaseDeDatos(tamano,this->arch);
    tempb->guardar();
    key= new char[20];
}

void Gestor::IniciarBD()
{
    this->tempb->cargar();
}

void Gestor::CargarTablas()
{
        list<tabla*> Tablas2;
        list<int> Types2;
        list<char*> Nombres2;
        Tablas=Tablas2;
        Types=Types2;
        Nombres=Nombres2;
        int t=0;
        int v=14;
        cout<<"Tablas: "<<tempb->cantidadTablas<<endl;
        char * datos= new char[53];
        bool borrado=0;
        int cantcol=0;
        char * no =new char[20];
        char * ke=new char[20];
        int empieza=0;
        int termina=0;
        int pos=0;
    tabla *tab=new tabla(0,0,"","",0,0,arch);
    for (int i=0; i<tempb->cantidadTablas;i++)
    {
    int xy=t+14;
    v=0;
    datos=new char[53];
    datos=arch->read(xy,53);
    borrado=0;
    memcpy(&borrado,&(datos[v]),1);
    t+=1;
    v+=1;
    pos=0;
    memcpy(&pos,&(datos[v]),4);
    t+=4;
    v+=4;
    cantcol=0;
    memcpy(&cantcol,&(datos[v]),4);
    cout<<"cantidad columna:"<<cantcol<<endl;
    t+=4;
    v+=4;
    no=new char[20];
    memcpy(no,&(datos[v]),20);
    t+=20;
    v+=20;
    ke=new char[20];
    memcpy(ke,&(datos[v]),20);
    t+=20;
    v+=20;
    empieza=0;
    memcpy(&empieza,&(datos[v]),4);
    t+=4;
    v+=4;
    termina=0;
     memcpy(&termina,&(datos[v]),4);
    t+=4;
    v+=4;
    if(borrado==false)
    {
    tab= new tabla(pos,cantcol,no,ke,empieza,termina,arch);
    this->Tablas.push_back(tab);
    char * datos2= new char[4*cantcol];
    xy=t+14;
    datos2=arch->read(xy,4*cantcol);
    int lugar=0;
        for(int x=0;x<4*cantcol;x+=4)
        {   int y=0;
            memcpy(&y,&(datos2[x]),4);
            t+=4;
            tab->tipos[lugar]=y;
            this->Types.push_back(y);
            lugar++;
        }
    xy=t+14;
    char * datos3= new char[30*cantcol];
    datos3=arch->read(xy,30*cantcol);
    lugar=0;
        for(int x=0;x<30*cantcol;x+=30)
        {   char *y=new char[30];
            memcpy(y,&(datos3[x]),30);
            t+=30;
            tab->nombres[lugar]=y;
            lugar++;
            this->Nombres.push_back(y);
        }
    }
    else
        {
            t+=((4*cantcol)+(30*cantcol));
            break;
        }
    }
}

void Gestor::ImprimirTablas()
{

    for(list<tabla*>::iterator l=Tablas.begin();l!=Tablas.end();l++)
    {
        tabla *t=*l;
                cout<<"Nombre:"<<t->nombre<<endl;
        for(int i=0; i<t->cantidadcolumna;i++){
        cout<<"Tipo: "<<t->tipos[i]<<"Nombre: "<<t->nombres[i]<<endl;
        }

    }
}
int Gestor::BuscarBit()
{
    for (int i = 0; i < tempb->cantidadBloques; i++)
  {
      if (bitmap[i]==0)
      {     return i;

      }
  }
  return -1;
}
tabla* Gestor::BuscarTabla(char * nom)
{
    tabla *tab=new tabla(0,0,"","",0,0,arch);
     for(list<tabla*>::iterator l=Tablas.begin();l!=Tablas.end();l++){
        tabla *t=*l;
        if(strcmp(t->nombre, nom) == 0)
        {
            tab=t;
            return tab;
        }

    }
}
void Gestor::CargarBloques()
{
    int p=4097;
      for (int i = 0; i < tempb->cantidadBloques; i++)
  {
      char * d= arch->read(p,1);
    memcpy(&(this->bitmap[i]),&d,1);
  }
}
void Gestor::IniciarBloques()
{   int y=20480;
    for(int i=0;i<tempb->cantidadBloques;i++)
    {
        char *nume = reinterpret_cast<char*>(&i);
        arch->write(y,nume,4);
        y+=4094;
        arch->write(y,"0",4);
        y+=4;
    }

}
void Gestor::CargarBits()
{
    int pos=0;
    char * da=new char[tempb->cantidadBloques];
    da=arch->read(4096,tempb->cantidadBloques);
    for(int i=0;i<tempb->cantidadBloques;i++)
    {bool x=false;
     memcpy(&x,&(da[i]),1);
     bitmap[i]=x;
    }
}

void Gestor::IniciarBit()
{
    char * da=new char[tempb->cantidadBloques];
    bitmap[0]=1;
    memcpy(&(da[0]),&(bitmap[0]),1);
    bitmap[1]=1;
    memcpy(&(da[1]),&(bitmap[1]),1);
    bitmap[2]=1;
    memcpy(&(da[2]),&(bitmap[2]),1);
    bitmap[3]=1;
    memcpy(&(da[3]),&(bitmap[3]),1);
    bitmap[4]=1;
    memcpy(&(da[4]),&(bitmap[4]),1);
  for (int i = 5; i < tempb->cantidadBloques; i++)
  {
        this->bitmap[i]=0;
        memcpy(&(da[i]),&(bitmap[i]),1);
  }
    arch->write(4096,da,tempb->cantidadBloques);
}


void Gestor::CrearTabla(int cant, char * nom, char * k)
{
    int x=BuscarBit();
    temp= new tabla(tempb->index,cant,nom,k,x,x,arch);
    this->bitmap[x]=1;
    GuardarBits();
    tempb->cantidadTablas=tempb->cantidadTablas+1;
    tempb->guardar();
cout<<"tabla creada correctamente"<<endl;
}
void Gestor::GuardarBits()
{
        char * da=new char[tempb->cantidadBloques];

  for (int i = 0; i < tempb->cantidadBloques; i++)
  {
        memcpy(&(da[i]),&(bitmap[i]),1);
  }
    arch->write(4096,da,tempb->cantidadBloques);
}
void Gestor::GuardarTabla()
{
    temp->guardar();
    tempb->index=tempb->index+57+(4*temp->cantidadcolumna)+(30*temp->cantidadcolumna);
    tempb->guardar();


}
void Gestor::AgregarColumna(int t, char * n)
{
    temp->agregarColumna(n,t);
}
void Gestor::BorrarTabla(char* nom)
{
     tabla * t=BuscarTabla(nom);
     t->borrado=true;
     t->guardar();
     CargarTablas();
}

void Gestor::eliminar(char *nombre)
{
    remove(nombre);
}
