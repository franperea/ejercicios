#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct datos_t
{
	string nombre;
	string curso;
	int num_mat;
	int grupo;
};

stringstream & format_string(datos_t & d, stringstream& o);
void print_string(string str);
void read_data_from_keyboard(datos_t& d);
void to_file(string filename, string str);

int main() 
{
	
	return 0;
}

void read_data_from_keyboard(datos_t& d)
{
	getline(cin,d.nombre);
	getline(cin,d.curso);
	cin>>d.num_mat;
	cin>>d.grupo;
}

stringstream & format_string(datos_t & d, stringstream& o)
{
	string nombre(d.nombre);
	string asignatura(d.curso);
	read_data_from_keyboard(d);
	o<<"Nombre:"<<d.nombre<<endl;
	o<<"Asignatura:"<<d.curso<<endl;
	o<<"Num Mat:"<<d.num_mat<<endl;
	o<<"Grupo:"<<d.grupo<<endl;
	return o;
}
void print_string(string str);

void to_file(string filename, string str);