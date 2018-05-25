#include "Coord_t.h"
#include "Esfera.h"

class Mundo
{
	Esfera e;
public:
	ostream& print(ostream&);
	Mundo (Esfera e): e(e) {}
}m1,m2;