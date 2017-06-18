/* Programa que calcula un círculo con centro en medio de dos círculos y radio la mitad de la distancia. 
   También calcula su área.
   
   Author: Mario Rodríguez Ruiz

   Un ejemplo de ejecución es:
     Introduzca un circulo en formato radio-(x,y): 3-(0,0)
     Introduzca otro circulo: 4-(5,0)
     El círculo que pasa por los dos centros es: 2.5-(2.5,0)
	 Su area es: 19.63
**/

#include <iostream>
#include <cmath> 
using namespace std;

// Definición de las estructuras
struct Punto {
    double x; 
    double y; 
};

struct Circulo {
    Punto centro; 
    double radio; 
};

// Prototipos de las funciones
void EscribirPunto(const Punto &p); 
Punto LeerPunto(); 
double DistanciaPuntos(const Punto &p1, const Punto &p2);
Punto PuntoMedio(const Punto &p1, const Punto &p2);

void EscribirCirculo(const Circulo &c); 
Circulo LeerCirculo(); 
double AreaCirculo(const Circulo &c);

// Programa principal
int main()
{
    Circulo c1,c2, c3;

    do {
        cout << "Introduzca un circulo en formato radio-(x,y): ";
        c1 = LeerCirculo();
        
        cout << "Introduzca otro circulo: ";
        c2 = LeerCirculo();
    } while ( DistanciaPuntos (c1.centro,c2.centro) == 0 );

    c3.centro = PuntoMedio( c1.centro, c2.centro );
    
    c3.radio = DistanciaPuntos( c1.centro, c2.centro ) / 2;
	
    cout << "El circulo que pasa por los dos centros es: ";
	EscribirCirculo( c3 );
    cout << endl << "Su area es: " << AreaCirculo( c3 ) << endl;
}

// Implementación de las funciones
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
/* Fin: circulomedio.cpp */
 
