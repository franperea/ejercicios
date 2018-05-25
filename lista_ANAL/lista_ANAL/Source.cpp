#include <iostream>

using namespace std;

int main() 
{
	listaNum f1(5, 3);
	f1.push_back(20);
	f1.push_back(30);
	listaNum f2(f1);
	f2.print();
	f2.set_capacity(10); 
}