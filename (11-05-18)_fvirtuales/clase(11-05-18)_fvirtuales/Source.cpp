#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Una función virtual pura se declara en la clase base. Obliga a redefinir la funcion en las clases derivadas o se hereda la funcion
//virtual pura.
//La diferencia entre una funcion virtual normal y una pura consiste en que la clase virtual pura (=0) no se tiene que rellenar
//(definir), se puede dejar en blanco.

class Objeto //clase abstracta porque tiene al menos un elemento puro (get_name()). Tiene dos elementos puros. 
	//porque hemos ddefinidos dos funciones virtuales que no tienen definición. 
	//interfaz, solo actua para que las clases derivdas la hereden-.
{
	int size;
	int prize;
public:
	virtual string get_name() =0;//no hay nombre, asi que no queremos rellenarla, por tanto ponemos virtual delante.
//función virtual y además pura porque la hemos igualado a 0. Clase Abstracta.
	virtual int get_grosor() =0; //Definimos enlace virtual.
};
//get_name no tiene porque estar en todos los miembros de la jerarquía. Enlace virtual/dinámico.

class Armas:public Objeto//Clase abstracta, no posee el get_name().
{
	//como es enlace virtual no hay que poner get_name() en todas las clases. -->Compila.
	int grosor;
public:
	int get_grosor(){return grosor;}
};

class Espada: public Armas
{
	//si pregunto en el main por el get_name, como en la clase objeto la función es virtual pura, se llama
	//al get_name de la clase Espada.
	string name;
	
public:
	Espada(string str="tizona"):name(str){}
	string get_name(){return name;}
	string foo(Objeto *o);
};

string foo(Objeto *o){//
	return (o->get_name());
}

void main()
{
	Espada e;
	cout<<foo(&e)<<endl;
	Objeto *po= new Espada("Excalibur");
	cout<<po->get_name()<<endl;
	system("pause");
}