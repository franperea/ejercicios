#include "Jugadores.h"
#define N_jug 10
Jugadores p[N_jug];

Jugadores::Jugadores()
{
	casa = Casas::Stark;
	nombre = "Robb";
	titulo = "King in the North";
}

Jugadores::Jugadores(const Jugadores &j)
{
	ataque = j.ataque;
	comida = j.comida;
	oro = j.oro;
	diplomacia = j.diplomacia;
	defensa = j.defensa;
	casa = j.casa;
	nombre = j.nombre;
	titulo = j.titulo;
}


Casas Jugadores::stringtoCasas(string e)
{
	stringstream sstr;
	int r;
	sstr << e << endl;
	sstr >> r;
	Casas res = static_cast<Casas>(r);
	return res;
}

ostream& Jugadores::print(ostream& o = cout)
{
	o << "Casa:" << casa << endl;
	o << "Region:" << Regiones::reg << endl;
	o << "Nombre:" << nombre << endl;
	o << "Titulo:" << titulo << endl;
	return o;
}

void Jugadores::read_file()
{
	ifstream f("Jugadores.txt", istream::in);
	if (!f)
	{
		cout << "el fichero no se ha abierto correctamente" << endl;
		return;
	}
	for (int i = 0; i<10; i++)
	{
		string aux, aux2;
		ostream &o = cout;
		getline(f, aux, '\n');
		getline(f, aux2, '\n');
		p[i].casa = stringtoCasas(aux);
		p[i].reg = Regiones::stringtoRegion(aux2);
		getline(f, p[i].nombre, '\n');//getline(f,nombre);
		getline(f, p[i].titulo, '\n');
		p[i].print(o);
		p[i].Recursos::read_file();
	}
	f.close();

}

