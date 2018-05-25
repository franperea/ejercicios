#include <iostream>

using namespace std;

class Personaje
{
	int altura;
public:
	Personaje (int altura=10):altura(altura){}
	//virtual int atacar()//a partir de esto todas las funciones de la clase tienen dynamic bind.
	virtual int atacar()//si quito virtual, ataca como personaje -->UPCAST
		//virtual tiene un coste 
	{
		cout<<"Ataco como personaje"<<endl;
		return 10;
	}

	virtual ostream& print(ostream &o) const{o<<"Soy personaje"<<endl; return o;}
	
};

class Guerrero:public Personaje
{
	int atacar()
	{
		cout<<"Ataco como un guerrero"<<endl;
		return 10;
	}
	ostream& print(ostream&o) const{cout<<"Soy guerrero"<<endl; return o;}
};

class Mago:public Personaje 
{
public:
	int atacar()
	{
		cout<<"ataco como mago"<<endl;
		return 100;
	}//si no existe esta funcion, se llama a la función justo arriba (en la jerarquía) cuando hay virtual.
	ostream& print(ostream&o) const{cout<<"Soy mago"<<endl; return o;}
};

//funcion independiente que permite atacar a cualquier tipo de la jeraraquia

void atacar (Personaje &p)
{
	p.atacar();
}

ostream& operator <<(ostream& o, const Personaje &p)
{
	p.print(o);
	return o;
}

void main()
{
	Mago m;
	atacar(m);//ejeciutamos el programa y ataca como mago, debido a que no hay upcast
	Guerrero g;

	
	cout<<m;
	cout<<g;
	system("pause");
}