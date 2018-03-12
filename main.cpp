#include <iostream>
#include <stdio.h>
#include <string>
#include "BaseDeDatos.h"
#include "archivo.h"
#include "tabla.h"
#include "Gestor.h"
using namespace std;
int main()
{

Gestor *g= new Gestor("jose",20);
g->IniciarBloques();
g->CargarBits();
/*
Gestor *r;
r->eliminar("jose");
*/
return 0;
}
