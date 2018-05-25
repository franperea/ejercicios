#include <iostream>
#include <string>
#include "PuntoBase.h"
#include "Punto.h"
#include "PuntoCol.h"

using namespace std;
//funcion global--> funcion que gestiona puntos

void foo(Punto & p)//si como cliente le paso a esta funcion un PuntoGordo compila, pero a lo mejor no hace lo que yo quiero
{//si le paso un PuntoGordo hace una conversion hacia arriba (UPCAST) , por tanto puedo utilizar tipos inferiores a punto
	//pero puede no hacer lo que yo quiera
	p.print();
}

int main()
{
	_PuntoBase pb(1);//--> Esto no funcionaría si el constructor de PuntoBase fuera protected.
	Punto p(8, 1.0, 3.0);//si se puede porque el constructor es colega, suponiendo que el constructor de puntobase es protected.

	//pb.id--> No funcionaría porque como id está protegido, no se puede acceder desde el main.
	//p.id--> Tampoco funcionaría por la misma razón.
	//podría poner el constructor en protected para que no pueeda ser accedido desde fuera, pero si desde la clase heredada.

	//pb.print();//id, si protejo print no lo puede utilizar el cliente de la clase base.

	//p.print();//print punto

	//p._PuntoBase::print();//print de _PuntoBase

	//PuntoGordo pg(p, ESTRELLA, AZUL)--> No se puede hacer esto porque ESTRELLA y AZUL no son reconocibles, hay que poner el ambito
	PuntoGordo pg(p, PuntoGordo::ESTRELLA, PuntoGordo::AZUL);//puntogordo hereda ESTRELLA y AZUL


	/////////////////////////////////cosa extra, lo que no se puede heredar, no tiene que ver con el cometido inicial del ej
	//asignar puntos
	PuntoGordo pg1(pg);//como no hay peticion a memoria dinamica, se llama al constructor copia por defecto
	//y se realiza una copia superficial (por niveles)
	pg1.print();
	cout<<""<<endl;
	pg1=pg; //esto lo copia bien, si no hay memoria dinámica, no complicarse la vida


	/////////////////////////////////



	//pg.print(); de una version anterior
	//foo(p);
	foo(pg);//hace conversion al objeto superior en la jerarquía, solo se queda con la parte correspondiente al objeto superior
	//es decir, si le paso un puntogordo, coge los parametros superiores a punto (UPCAST). Commpila, pero no funciona demasiado bien.
	//slicing--> El corte que se hace al hacer el UPCAST. 
	//el DOWNCAST no funciona ni compila.
	//lo ideal seria poder llamar a la funcion del puntogordo y asi no cortamos nada.
	PuntoGordo *pPg=&pg;
	pPg->print();

	Punto *pP=pPg;
	
	system("pause");
}