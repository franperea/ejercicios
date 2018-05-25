#include <iostream>

using namespace std;

class A{
	int dato;
public:
	A():dato(10){}
	friend ostream& print(const A&, ostream&);
};
//global
ostream& print(const A& a, ostream& o=cout){//o=cout--> Se imprime directamente como flujo de salida estandar
	o<<a.dato<<endl;
	return o;
//cuantos menos amigos mejor
}
void main() {

}
