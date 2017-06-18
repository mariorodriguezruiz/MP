#include "punto.h"

void EscribirPunto(const Punto &p)
{
	cout << "(" << p.x << ", " << p.y << ")" ;
}

Punto LeerPunto()
{
	Punto nuevo ;
	
	cout << "x: " ;
	cin >> nuevo.x ;
	cout << "y: " ;
	cin >> nuevo.y ;
	
	return nuevo ;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)) ;
}

Punto PuntoMedio(const Punto &p1, const Punto &p2)
{
	Punto punto_medio ;
	
	punto_medio.x = (p1.x + p2.x) / 2 ;
	punto_medio.y = (p1.y + p2.y) / 2 ;
	
	return punto_medio ;
}
