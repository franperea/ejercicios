
class Punto{
	double x;
	double y;
public:
	Punto (double x, double y):(x(x),y(y);){}
	Punto(const Punto&);
	double get(){return x;};
	double set(){return y;};
	friend double dist_origen(Punto);
};