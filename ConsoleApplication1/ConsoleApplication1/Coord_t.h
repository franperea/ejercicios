#include <iostream>

using namespace std;

struct Coord_t 
{
	double x;
	double y;
	double z;

	Coord_t(double x, double y, double z):x(x), y(y), z(z) {}
	ostream& print(ostream &);
};

ostream& Coord_t::print(ostream &c)
{
	c<<x<<y<<z;
	return c;
}