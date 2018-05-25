//pedir apuntes 18-04-18
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Punto
{
public:
	double x,y;
	string to_string();
	istream& to_punto(istream &, Punto &);
	bool is_valid(); //no la hemos definido
	double modulo() const;
	Punto& operator += (const Punto &);
	Punto & operator ++();
	Punto operator ++(int);
};

string Punto::to_string() //convertir punto a string
{
	stringstream sstr;
	string res;
	sstr<<"["<<x<<","<<y<<"]"; //meto las variables x e y en un flujo de string
	string res(sstr.str()); //guardo dicho flujo en el string res
	return res;
}

//caso punto-> flujo

istream& Punto::to_punto(istream &is, Punto &p)
{
	char token;
	is>>token>>p.x>>token>>p.y>>token;
	if(!p.is_valid())
		is.setstate(ios::failbit); //algo ha ido mal
	return is;
}
//istream para leer
//ostream para escribir

//Con esto podemos escribir y leer en un fichero
//Mirar sintaxis de Friend 

//punto mayor que otro:

double Punto::modulo() const
{
	return sqrt(x*x+ y*y);
}

bool operator == (const Punto& lhs, const Punto& rhs)
{
	return (lhs.x==rhs.x && lhs.y==rhs.y);
}

bool operator != (const Punto& lhs, const Punto& rhs)
{
	return !operator==(rhs, lhs);
}

bool operator <(const Punto & lhs, const Punto& rhs)
{
	return (lhs.modulo()<rhs.modulo);
}

bool operator >(const Punto & lhs, const Punto& rhs)
{
	return (rhs.modulo()<lhs.modulo);
}

Punto& Punto::operator += (const Punto & rhs)
{
	//pedir codigo de esta funcion y de +
}

Punto & Punto::operator ++() //postincremento
{
	Punto p;
	p.x++;
	p.y++;
	return p;
}

Punto Punto::operator ++(int k)
{

}


