#include "Coord_t.h"

class Esfera 
{
	Coord_t a;
	double r;
public:
	ostream& print(ostream&);
	Esfera(Coord_t a, double rad):a(a), r(rad) {}
};

