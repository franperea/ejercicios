#pragma once

class global_var{
public:
	double d1;
	double d2;
	double d3;
};


//es recomendable no inicializar los elementos en esta parte, mejor en el cpp, para evitar que se incluyan

namespace globals{ //globals es una etiqueta
	extern double d1; //las variables están declaradas en otro sitio
	extern double d2;
	extern double d3;
}