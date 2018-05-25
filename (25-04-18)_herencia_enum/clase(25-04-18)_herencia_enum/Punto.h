#pragma once
#include "PuntoBase.h"

class Punto:public _PuntoBase{//clase que hereda _ClasePunto
	//yo no tengo acceso a id porque es privado, pero si que puedo acceder al constructor y a las otras funciones
	// de _PuntoBase, ya que este es publico
	double x,y;
public:
	Punto(int id, double x=0.0, double y=0.0);//constructor 
	ostream & print_p(ostream&o =cout); //yo heredo una funcion con el mismo nombre, sobrecarga de funciones. ç
	Punto& operator = (const Punto&); 
//Quiero que este print llame al otro y se distingan. 
};

ostream & Punto::print_p(ostream&o )
{
	_PuntoBase::print(o);//tengo que poner esto para que imprima lo de _PuntoBase.
	o<<"["<<x<<","<<y<<"]";
	return o;
}

Punto::Punto(int id, double x, double y):_PuntoBase(id), x(x), y(y) //en la lista de inicializacion, 
{}//aparte de inicializar x e y, tengo que inicializar id con la clase heredada

Punto& Punto::operator = (const Punto& p)
{
	cout<<"LLamando al operador asignacion"<<endl;
	if(this!=&p)
	{
		//asigno p a *this.
		this->x=p.x;
		this->y=p.y;
		this->id=p.id;
	}
	return *this;
}//si yo llamo al operador =  con puntogordo, no coge esta funcion porque el operador = no se hereda.