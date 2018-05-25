#pragma once
#include "Punto.h"

class PuntoGordo:public Punto
{
	tipo_t forma;
	col_t color;
public:
	PuntoGordo(Punto&, tipo_t, col_t);//constructor
	ostream & print (ostream &o =cout);
	PuntoGordo& operator = (const PuntoGordo& p);

	//constructor copia
	PuntoGordo(const PuntoGordo&);//si el constructor copia por defecto no sirve.

};

PuntoGordo::PuntoGordo (const PuntoGordo&p):Punto(p) //lista inicializacion, la pongo porque se tiene que haber construido lo de arriba (punto)
{
	//construir lo mio
	//aqui hay que poner lo que sea
}

PuntoGordo::PuntoGordo(Punto& p, tipo_t f, col_t c):Punto(p)
{
	this->forma=f;
	this->color=c;
}


ostream & PuntoGordo::print (ostream &o)
{
	Punto::print(o);
	o<<to_string_type(this->forma)<<"";
	o<<to_string_col(this->color)<<"";
	return o;
}

PuntoGordo& PuntoGordo::operator = (const PuntoGordo& p)
{
	cout<<"LLamando al operador asignacion de PuntoGordo"<<endl;
	if(this!=&p)
	{
		//asigno p a *this.
		Punto::operator=(p);//se hace el UPCAST, o sea que se convierte a la clase base y el slicing, se queda unicamente
		//con lo que queremos de la clase Punto.
		this->forma=p.forma;
		this->color=p.color;
	}
	return *this;
}