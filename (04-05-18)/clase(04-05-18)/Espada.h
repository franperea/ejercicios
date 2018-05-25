#pragma once
#include <iostream>
#include "Objeto.h"

using namespace std;

class Espada:public Objeto
{
	bool filo;
public:	
	Espada(int pos, int filo): Objeto(pos), filo(filo){}
	Espada():Objeto(0),filo(1000){}
	ostream& print(ostream& o){cout<<"Soy una espada"<<endl;}
};

