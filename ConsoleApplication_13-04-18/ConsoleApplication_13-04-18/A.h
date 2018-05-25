//ejemplo tonto para probar que cuando una clase es amiga que otra solo hay que poner friend (no include la otras clase), cuando incluye objetos de B, si hay que incluir B.
class A{
	friend class B;
	B *myb;//si no incluimos B esto es una forward declaration 
	/* para las referencias y los punteros, no es necesario incluir B, porque al fin y al cabo dichos elementos 
	son direcciones de memoria, si incluyo otro tipo de variables, no queda otra*/
	int sumar(B *y, double a);
};