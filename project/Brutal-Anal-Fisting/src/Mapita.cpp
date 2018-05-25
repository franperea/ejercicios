#include <string>
#include "Mapita.h"



/*Mapita::Mapita()
{
}


Mapita::~Mapita()
{
}*/

void extract_(string line, int &fil, int &col);

bool ** Mapita::read_Dimacs(string nombre)
{
	ifstream f(nombre, ifstream::in);
	string line;
	string aux;
	string aux1;
	char token;
	stringstream sstr;
	int fil = 0, col = 0;

	//falta meter el if en caso de que no se abra bien
	if (!f)
	{
		cout << "No se puede abrir el archivo" << endl;
		return NULL;
	}
	else
	{
		while (!f.eof())
		{
			getline(f, line);
			cout << line << endl;
			token = line[0];

			switch (token)
			{
			case 'c':
			{
				//cout << line << endl;
				break;
			}
			case 'p':
			{
				sstr.str(line);
				sstr >> aux >> aux >> nodes >> edges;
				if (edges == -1 || nodes == -1)
				{
					cout << "ERROR DE PROTOCOLO" << endl;
					return NULL;
				}
				else
				{
					cout << "CREATING MATRIX" << endl;
					create();
				}
				//cout << "AUX: " << aux << " NODES: " << nodes << " EDGES: " << edges << endl;
				break;
			}
			case 'e':
			{
				extract_(line, fil, col);
				//cout << " FIL: " << fil << " COL: " << col << endl;
				vecinos[fil - 1][col - 1] = 1;
				vecinos[col - 1][fil - 1] = 1;
				break;
			}

			default:
			{
				cout << "���ERROR DE PROTOCOLO!!!\n" << endl;
				if (vecinos != NULL)
				{
					cout << "BORRANDO LOS DATOS...";
					erase();
				}

				return vecinos;
				break;
			}
			}
		}
	}

	f.close();
	return vecinos;
}

void extract_(string line, int &fil, int &col)
{
	stringstream sstr(line);
	string aux;
	sstr >> aux >> fil >> col;
}

void Mapita::erase()
{
	if (vecinos != NULL)
	{
		for (int i = 0; i < nodes; i++)
			delete[] vecinos[i];
		delete[] vecinos;
	}
	vecinos = NULL;
}

void Mapita::create()
{
	vecinos = new bool*[nodes];

	for (int i = 0; i < nodes; i++)
		vecinos[i] = new bool;

	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
			vecinos[i][j] = 0;
	}
}

int * Mapita::find_neighbors(int id)//las id deben de ir de 0 a 9
{
	int l = 0;
	int* aux = new int[nodes];

	for (int i = 0; i < nodes; i++)
		if (vecinos[id - 1][i])
		{
			aux[l++] = i + 1;
			cout << "[" << aux[l - 1] << "]";
		}
	cout << endl;
	neighbors = new int[l];
	for (int i = 0; i < l; i++)
		neighbors[i] = aux[i];
	delete[] aux;
	return neighbors;
}

void Mapita::erase_neighbors()
{
	delete[] neighbors;
}

ostream & Mapita::print(ostream & o)
{
	// TODO: insertar una instrucci�n return aqu�
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
			o << "[" << vecinos[i][j] << "]";
		o << "\n";
	}
	return o;
}



