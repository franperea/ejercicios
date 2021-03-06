// ejemplo_plantillas.cpp: define el punto de entrada de la aplicación de consola.
//pedir este ejercicio-->esta incompleto

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class Punto
{
	double x, y;
public:
	Punto(double x = 0.0, double y = 0.0) :x(x), y(y) {}
	double mod() const {
		return sqrt(x*x+y*y);
	}
	string to_string() {//to_string por defecto (sin plantilla)
		string res;
		stringstream sstr;
		sstr << "[" << x << "," << y << "]";
		sstr >> res;
		return res;
	}
	template <class U>
	string to_string() {//to_string en el que se puede meter cualquier tipo. Con plantilla.
		string res;
		stringstream sstr;
		sstr << "[" << static_cast<U>(x) << "," << static_cast<U>(y) << "]";
		sstr >> res;
		return res;
	}
};

bool operator <(const Punto& lhs, const Punto& rhs)
{
	return(lhs.mod()<rhs.mod());
}

template <class T>
class Swap
{
public:
	//functor
	bool operator()(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
};
template <class T>

class Less {
public:
	//functor
	/*para definir el functor dentro
	bool operator()(T a, T b) {
		return a < b;
	}*/
	bool operator()(T &a, t &b);
};
template<class T>
bool Less<T>::operator()(T &a, t &b)
{
	return a < b;
}

template <typename T>
bool less1(T a, T b) {
	return a < b;
}

int main()
{
	Punto p1(1.1,1.4);
	Punto p2(5,7);
	/*if (less1(3.7, 5.2))//le puedes poner int, float, lo que te de la gana...
	{
		cout << "es menor" << endl;
	}*/
	//para hacer practicas las plantillas, creo un objeto
	//Less<int> l;
	/*if (Less<Punto>()(p1, p2))//le digo el tipo entre <>
	{
		cout << "menor que" << endl;
	}*/
	Swap<Punto>()(p1, p2);
	cout << p1.to_string() << endl;
	system("pause");
    return 0;
}

