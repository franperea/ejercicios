#pragma once
#include <iostream>
#include <string>

using namespace std;

class _PuntoBase
{
public:	
	enum tipo_t{ESTRELLA=0, CRUZ, CIRCULO};
	enum col_t {AZUL=0, ROJO, NEGRO};
	static string to_string_col(col_t); //no depende de un objeto concreto, es global para todos
	static string to_string_type(tipo_t);
	int get_id() const {return id;}
	ostream & print(ostream&o =cout) {o<<"ID"<<id; return o;}//funcion inline. No ponemos const, por si queremos modificar el flujo.

protected: //puede ser accedido por la clase derivada y ya. Se hereda. Desde el cliente es lo mismo, no lo puede modificar.
	int id;
public:
	_PuntoBase(int id):id(id){}
};

string _PuntoBase::to_string_col(col_t c){
	string res;
	switch (c) //vale porque es un enumerado, hay conversion a const
	{
	case AZUL:
		res="AZUL";
		break;
	case ROJO:
		res="ROJO";
		break;
	case NEGRO:
		res="NEGRO";
		break;
		//aqui habría que poner un default
	}
	return res;
}

string _PuntoBase::to_string_type(tipo_t t){
	string res;
	switch (t) //vale porque es un enumerado, hay conversion a const
	{
	case ESTRELLA:
		res="ESTRELLA";
		break;
	case CRUZ:
		res="CRUZ";
		break;
	case CIRCULO:
		res="CIRCULO";
		break;
		//aqui habría que poner un default
	}
	return res;
}