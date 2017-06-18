/*
 Implementación de los métodos de la clase celda.

 */
#include<celda.h>

Celda::Celda(){
    info = 0 ;
    sig = 0 ;
}

Celda::Celda(double inf){
    info = inf ;
    sig = 0 ;
}

void Celda::setSiguiente(Celda *siguiente){
    sig = siguiente ;
}

void Celda::setInfo(double valor){
    info = valor ;
}

// Fin métodos.
