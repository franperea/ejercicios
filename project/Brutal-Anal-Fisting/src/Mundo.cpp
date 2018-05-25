#include "Mundo.h"
#include "glut.h"
#include "ETSIDI.h"

using namespace ETSIDI;

Mundo::Mundo()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

							 //aqui es donde hay que poner el codigo de dibujo
//	regi.getTexture(const char* Texturepath);
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
	{

		break;
	}
	case '1':

		break;
	case '2':

		break;
	case '3':

		break;
	case '4':

		break;
	}

}
/*void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		map.posicion.x -= 0.5;
		break;
	case GLUT_KEY_RIGHT:
		map.posicion.x += 0.5;
		break;
	case GLUT_KEY_UP:
		map.posicion.y += 0.5;
		break;
	case GLUT_KEY_DOWN:
		map.posicion.y -= 0.5;
		break;
	}
}*/