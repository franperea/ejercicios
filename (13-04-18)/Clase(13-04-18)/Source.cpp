#include <iostream>

using namespace std;

template <class T> //plantilla T, definimos una cosa y despu�s donde tendr�amos que poner Singleton (nombre de la clase) ponemos T

class Singleton
{
private:
	static T* m_p;
	int a;
	//imcompleto, est� en la presentacion
};

static void delete_single_object()
{
	if(m_p){
		delete m_p;
		m_p=NULL;
	}
}