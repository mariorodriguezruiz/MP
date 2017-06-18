/*
    Examen Julio 2014.


 */

#include<iostream>
#include<string>
#include<Lista.h>


int main(int argc, char **argv){
    Lista una ;
    Lista *lista ;

    una.aniadirCelda(1) ;
    una.aniadirCelda(7) ;
    una.aniadirCelda(2) ;
    una.aniadirCelda(4) ;
    una.aniadirCelda(3) ;

    lista = devuelveVectorListas(una, 2) ;


    return 0 ;
}

