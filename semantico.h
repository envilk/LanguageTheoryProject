#ifndef SEMANTICO_H_
#define SEMANTICO_H_

typedef char tipo_cadena[50];

struct tipo_variables {
 int max = 0;
 tipo_cadena variables[50];
};

union tipo_valor{
 int valor_entero;	//TIPO 0
 float valor_real;	//TIPO 1
 tipo_cadena valor_cad; //TIPO 2
 int valor_pos[2];	//TIPO 3
 };

struct tipo_datoTS{
 tipo_cadena nombre;
 int tipo;
 tipo_valor valor;
 int pos[2];
 tipo_cadena alias;
};

struct tipo_tabla{
 int max = 0;
 tipo_datoTS tabla[100];
};

void insertar (tipo_tabla &TS, tipo_datoTS identificador);

bool buscar (tipo_tabla TS, tipo_cadena nombre, tipo_datoTS &identificador);

void insertarVariables(tipo_variables &vars, tipo_cadena cadena, int tipo, bool end, tipo_tabla &TS);

void mostrar(tipo_tabla TS);

#endif /* SEMANTICO_H_ */

