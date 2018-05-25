#include "Mundo.h"

ostream& Mundo::print(ostream&c)
{
	c<<e.print(c);
	return c;
}

