/*
 Implementación de los métodos de la clase lista.

 */
#include<lista.h>
#include<assert.h>
#include<iostream>

using namespace std ;

Lista::Lista(){
    contenido = 0 ;
    longitud = 0 ;
}

Lista::~Lista(){
    liberarMemoria() ;
    contenido = 0 ;
    longitud = 0 ;
}

void Lista::liberarMemoria(){
    int tope = longitud ;

    for(int i = 0 ; i < tope ; i++){
        eliminaUltimaCelda() ;
    }

    delete contenido ;
}

void Lista::eliminaUltimaCelda(){
    Celda *pCelda = contenido ;

    for(int i = 1 ; i <= longitud-2 ; i++)
        pCelda = pCelda->getSiguiente() ;

    delete pCelda->getSiguiente() ;

    pCelda->setSiguiente(0) ;
    longitud-- ;
}

void Lista::aniadeCeldaAlfinal(const double valor){
    Celda *ultima, *nueva ;
    nueva = new Celda(valor) ;
    ultima = obtenerCelda(longitud) ;

    if(contenido != 0){
        ultima->setSiguiente(nueva) ;
    }
    else{
        contenido = nueva ;
    }

    longitud++ ;
}

double Lista::obtenerElemento(const int indice) const{
    assert(indice >= 0 && indice < longitud) ;

    Celda *pCelda = contenido ;

    for(int i = 1 ; i <= indice ; i++)
        pCelda = pCelda->getSiguiente() ;

    return pCelda->getInfo() ;
}

void Lista::imprimeObjeto(){
    cout << "\n" ;
    for(int i = 0 ; i < longitud ; i++)
        cout << obtenerElemento(i) << endl ;
}

void Lista::insertaCeldaDetras(const int indice, Celda *nueva){
    assert(indice >= 0 && indice <= longitud) ;

    if(indice == 0){
        Celda *primera = obtenerCelda(1) ;
        nueva->setSiguiente(primera) ;
        contenido = nueva ;
    }
    else{
        Celda *anterior = obtenerCelda(indice) ;
        nueva->setSiguiente(anterior->getSiguiente()) ;
        anterior->setSiguiente(nueva) ;
    }

    longitud++ ;
}

void Lista::insertaCeldaDelante(const int indice, Celda *nueva){
    assert(indice > 0 && indice <= longitud) ;

    if(indice == 1){
        Celda *primera = obtenerCelda(1) ;
        nueva->setSiguiente(primera) ;
        contenido = nueva ;
    }
    else{
        Celda *aAtrasar = obtenerCelda(indice-1) ;
        nueva->setSiguiente(aAtrasar->getSiguiente()) ;
        aAtrasar->setSiguiente(nueva) ;
    }

    longitud++ ;
}

Celda * Lista::obtenerCelda(const int indice) const{
    assert(indice >= 0 && indice <= longitud) ;

    Celda *pCelda = contenido ;

    for(int i = 0 ; i < indice-1 ; i++)
        pCelda = pCelda->getSiguiente() ;

    return pCelda ;
}


void Lista::eliminaCelda(const int indice){
    assert(indice > 0 && indice <= longitud) ;

    Celda *pCelda = obtenerCelda(indice) ;

    if(indice == 1){
        contenido = pCelda->getSiguiente() ;
    }
    else{
        Celda *tmp = obtenerCelda(indice-1) ;
        tmp->setSiguiente(pCelda->getSiguiente()) ;
    }

    delete pCelda ;
    longitud-- ;
}

// Fin métodos
