/*
    Examen Junio 2015.


 */

#include<iostream>
#include<string>
#include<Lista.h>


int main(int argc, char **argv){
    Lista una, otra ;

    una.aniadirCelda(1.0) ;
    una.aniadirCelda(2.2) ;
    una.aniadirCelda(3.0) ;
    una.aniadirCelda(4.0) ;

    imprimeLista(una) ;

    otra = una ;

    imprimeLista(otra) ;

    return 0 ;
}

