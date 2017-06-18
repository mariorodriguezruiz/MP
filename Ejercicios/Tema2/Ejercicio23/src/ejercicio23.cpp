/*
    Ejercicio 23.
    Listas enlazadas.
 */

#include<iostream>
#include<string>
#include<lista.h>

using namespace std ;

int main(){
    Lista lista ;

    lista.aniadeCeldaAlfinal(1.17) ;
    lista.aniadeCeldaAlfinal(3.4) ;
    lista.aniadeCeldaAlfinal(0.56) ;

    cout << "\nLongitud de la lista: " << lista.getLongitud() << endl ;



    lista.eliminaCelda(3) ;

    lista.imprimeObjeto() ;

    return 0 ;
}

