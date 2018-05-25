#pragma once 
#include <iostream>
#include "Mago.h"

using namespace std;

class Conjurador:public Mago
{
	int conjuro;
public: 
	Conjurador(int sombrero, int conj):Mago(sombrero), conjuro(conj){}
	
};