/* Programa que calcula un círculo con centro en medio de dos círculos y radio la mitad de la distancia. 
   También calcula su área.
   
   Author: Mario Rodríguez Ruiz

   Un ejemplo de ejecución es:
     Introduzca un circulo en formato radio-(x,y): 3-(0,0)
     Introduzca otro circulo: 4-(5,0)
     El círculo que pasa por los dos centros es: 2.5-(2.5,0)
	 Su area es: 19.63
**/
#include"circulo.h"
#include"punto.h"

using namespace std;

// Programa principal
int main()
{
    Circulo c1, c2, c3;

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

/* Fin: circulomedio.cpp */
 
