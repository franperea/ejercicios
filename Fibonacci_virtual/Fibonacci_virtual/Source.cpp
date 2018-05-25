#include <iostream>

using namespace std;

class IFibo//clase interfaz
{
	public:
	virtual int fibo(int n)=0;//funcion virtual pura.
};

class FiboA:public IFibo
{
	int fibo(int n){cout<<"Soy fibo A"<<endl; return 0;}
};

class FiboB:public IFibo
{
	int fibo(int n){cout<<"Soy fibo B"<<endl; return 0;}
};

class FiboEngine
{
	IFibo *pf;//puntero a la clase base, tenemos acceso a toda la jerarquuía. 
public:
	FiboEngine(IFibo *p):pf(p){}
	int fibo(int n);
};

int FiboEngine::fibo(int n)
{
	return pf->fibo(n);
}

void main()
{
	FiboEngine f= new FiboA;
	f.fibo(10);

	FiboEngine f1= new FiboA;
	f1.fibo(10);

}