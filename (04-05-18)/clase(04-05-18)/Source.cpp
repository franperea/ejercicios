#include "Objeto.h"
#include "Espada.h"
#include "Mago.h"
#include "Conjugador.h"
#include <iostream>

using namespace std;

void foo(Objeto &o){cout<<"Soy un objeto";}

void main()
{
	Conjurador c(10,20);
	Espada e(30,100);

	//foo(e);
	//foo(c);

	
}