#include"circulo.h"

void EscribirCirculo(const Circulo &p)
{
	cout << p.radio << "-" ;
	EscribirPunto(p.centro) ;	
}

Circulo LeerCirculo()
{	
	Circulo nuevo ;
	
	cout << "\nRadio: " ;
	cin >> nuevo.radio ;	
	nuevo.centro = LeerPunto() ;
	
	return nuevo ;
}

double AreaCirculo(const Circulo &c)
{
	return M_PI * c.radio * c.radio ;
}
