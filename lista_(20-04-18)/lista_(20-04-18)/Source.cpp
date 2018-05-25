#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Lista{
	int size;
	int capacity;
	int *buffer;
public:
	Lista (int size):size(size), capacity(size) {
	buffer=new int[size];
	}
	??- Lista(){delete buffer;};
	// operator []

	int & operator [] (int pos){return buffer[pos];}
	const int & operator[] (int pos) const{return buffer[pos];}

};

int main()
{
	Lista l(10);
	l[0]=8; //Curiosidad: En la clase "array" de c++, los corchetes están sobrecargados
	std::vector<int> l; //?
	l.push_back(10); //falta por declarar esta funcion
	cout<<l[0];
}