#include "Coord_t.h"
#include "Esfera.h"

ostream& Esfera::print(ostream&c)
{
	c<<a.print(c);
	c<<r;
	return c;
}