#include <iostream>
using namespace std;

class listaNum
{
	int capacity;
	int size;
	int *lista;
public:
	listaNum(int  size, int val_init); 
	listaNum(const listaNum & ); 
	~listaNum(); 
	ostream& print (ostream&); 
	int push_back (int dato); 
	int set_capacity(int val);
};

