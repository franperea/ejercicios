#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream f("file.txt",ofstream::out);
	string pene;
	string pamela;
	cout<<"Introduzca una cadena de caracteres"<<endl;
	getline(cin,pene);
	f<<pene<<endl;
	f.close();
	ifstream g("file.txt", ifstream::in);
	getline(g,pamela);
	g.close();
	cout<<pamela<<endl;
	system("pause");
	return 0;
}