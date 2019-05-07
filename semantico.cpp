#include <stdio.h>
#include <iostream>
#include <string.h>
#include "semantico.h"
using namespace std;

void insertar (tipo_tabla &TS, tipo_datoTS identificador)
{
 bool encontrado = false;
 int pos;
 for(int i=0;i<TS.max && !encontrado;i++)
 {
  if(TS.tabla[i].nombre == identificador.nombre)
  {
   encontrado = true;
   pos = i;
  }
 }
 if(!encontrado)
 {
  TS.tabla[TS.max] = identificador;
  TS.max++;
 }
 else
 {
  if(TS.tabla[pos].tipo == identificador.tipo)
  {
   if(identificador.tipo == 0)
    TS.tabla[pos].valor.valor_entero = identificador.valor.valor_entero;
   if(identificador.tipo == 1)
    TS.tabla[pos].valor.valor_real = identificador.valor.valor_real;
   if(identificador.tipo == 2)
    strcpy(TS.tabla[pos].valor.valor_cad, identificador.valor.valor_cad);
   if(identificador.tipo == 3)
    TS.tabla[pos].valor.valor_bol = identificador.valor.valor_bol;
  }
  else
   printf("ERROR DE TIPO");
 }
}

bool buscar (tipo_tabla TS, tipo_cadena nombre, tipo_datoTS &identificador)
{
 bool encontrado = false;
 for(int i=0;i<TS.max && !encontrado;i++)
 {
  if(TS.tabla[i].nombre == nombre)
  {
   encontrado = true;
   identificador = TS.tabla[i];
  }
 }
 return encontrado;
}

void mostrar(tipo_tabla TS)
{
 cout<<endl<<endl;
 for(int i=0;i<TS.max;i++)
 {
  if(TS.tabla[i].tipo == 0)
   cout<<"[NOMBRE: "<<TS.tabla[i].nombre<<" TIPO: "<<TS.tabla[i].tipo<<" VALOR: "<<TS.tabla[i].valor.valor_entero<<"]"<<endl;
  if(TS.tabla[i].tipo == 1)
   cout<<"[NOMBRE: "<<TS.tabla[i].nombre<<" TIPO: "<<TS.tabla[i].tipo<<" VALOR: "<<TS.tabla[i].valor.valor_real<<"]"<<endl;
  if(TS.tabla[i].tipo == 2)
   cout<<"[NOMBRE: "<<TS.tabla[i].nombre<<" TIPO: "<<TS.tabla[i].tipo<<" VALOR: "<<TS.tabla[i].valor.valor_cad<<"]"<<endl;
  if(TS.tabla[i].tipo == 3)
   cout<<"[NOMBRE: "<<TS.tabla[i].nombre<<" TIPO: "<<TS.tabla[i].tipo<<" VALOR: "<<TS.tabla[i].valor.valor_bol<<"]"<<endl;
 }
 cout<<endl;
}

void insertarVariables(tipo_variables &vars, tipo_cadena cadena, int tipo, bool end, tipo_tabla &TS)
{
 if(!end)
 {
  strcpy(vars.variables[vars.max], cadena);
  vars.max++;
 }
 else
 {
  //strcpy(vars.variables[vars.max], cadena);
  //vars.max++;
  tipo_datoTS id;
  for(int i=0;i<vars.max;i++)
  { 
   strcpy(id.nombre, vars.variables[i]);
   id.tipo = tipo;
   //VALOR NO SE INSERTA YA QUE SOLO SE DEFINE, NO SE ASIGNA
   insertar(TS, id);
  }
  vars.max = 0;
 }
}

/*
int main()
{
 tipo_tabla tabla;
 tipo_datoTS id;
 strcpy(id.nombre, "x");
 id.tipo = 0;
 id.valor.valor_entero = 3;
 insertar(tabla, id);
 strcpy(id.nombre, "joserra");
 id.tipo = 0;
 id.valor.valor_entero = 4;
 insertar(tabla, id);
 strcpy(id.nombre, "y");
 id.tipo = 0;
 id.valor.valor_entero = 123;
 insertar(tabla, id);
 mostrar(tabla);
 return 0;
}
*/
