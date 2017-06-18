/*
    Examen junio 2012.


 */

#include<iostream>
#include<string>
#include<Polilinea.h>


int main(int argc, char **argv){
    Polilinea una, otra, resultado ;

    if(argc != 2){
        cerr << "\nError en el número de parámetros." << endl ;
        cerr << "\nUso: % main entrada.txt" << endl ;
        return 1 ;
    }

    una.LeerPolilinea(argv[1]) ;
    otra.LeerPolilinea("datos1.txt") ;

    resultado = otra[0] + una ;

    //resultado.EscribirPolilinea("salida.txt") ;

    if(una == otra)
        cout << "\nLas polilineas son iguales." ;
    else
        cout << "\nLas polilineas son distintas." ;


    return 0 ;
}

