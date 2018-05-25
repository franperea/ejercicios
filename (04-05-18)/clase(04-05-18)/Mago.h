#pragma once
#include <iostream>
#include "Espada.h"
#include "Personaje.h"

using namespace std;

class Mago:private Espada, public Personaje//herencia multiple
{
	int sombrero;
public:
	Mago(int s):sombrero(s){}

};