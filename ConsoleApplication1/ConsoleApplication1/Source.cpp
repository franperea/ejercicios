#include <iostream>
#include "Mundo.h"

using namespace std;



int main()
{
	Esfera e(Coord_t(4.5,5.1,6.2),3.2);
	Mundo m1(e);
	Mundo m2(m1);
	m1.print(cout);
	m1.print(cout);
	

}