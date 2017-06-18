/*
 Implementación de los métodos de la clase Lista.

 */
#include<Lista.h>

Lista::Lista(){
    contenido = 0 ;
    longitud = 0 ;
}

Lista::~Lista(){
    liberarMemoria() ;
}

Celda * Lista::obtenerCelda(const int indice) const{
    assert(indice >= 0 && indice <= longitud) ;

    Celda *pCelda = contenido ;

    for(int i = 0 ; i < indice-1 ; i++)
        pCelda = pCelda->siguiente ;

    return pCelda ;
}

void Lista::eliminaUltimaCelda(){
    Celda *pCelda = contenido ;

    for(int i = 1 ; i <= longitud-2 ; i++)
        pCelda = pCelda->siguiente ;

    delete pCelda->siguiente ;
    pCelda->siguiente = 0 ;

    longitud-- ;
}

void Lista::liberarMemoria(){
    int tope = longitud ;

    for(int i = 0 ; i < tope ; i++)
        eliminaUltimaCelda() ;

    delete contenido ;
}

void Lista::aniadirCelda(const int valor){
    Celda *ultima, *nueva ;
    nueva = new Celda ;

    nueva->dato = valor ;
    nueva->siguiente = 0 ;

    ultima = obtenerCelda(longitud) ;

    if(contenido == 0){
        contenido = nueva ;
    }
    else{
        ultima->siguiente = nueva ;
    }

    longitud++ ;
}

int Lista::obtenerLongitud() const {
    return longitud ;
}

int Lista::obtenerDato(const int indice) const{
    assert(indice > 0 && indice <= longitud) ;
    Celda *pCelda = obtenerCelda(indice) ;

    return pCelda->dato ;
}

void Lista::insertarCelda(const int indice, Celda *nueva){
    assert(indice >= 0 && indice <= longitud) ;

    Celda *detras, *delante ;

    if(indice == 0){
        detras = contenido ;
        contenido = nueva ;
        nueva->siguiente = detras->siguiente ;
    }
    else{
        detras = obtenerCelda(indice-1) ;
        delante = obtenerCelda(indice) ;
        detras->siguiente = nueva ;
        nueva->siguiente = delante ;
    }

    longitud++ ;
}

void Lista::insertaCeldaOrdenada(const int entero){
    Celda *nueva = new Celda ;
    nueva->dato = entero ;

    int datoDelantero, datoTrasero ;
    bool insertada = false ;

    for(int i = 1 ; i <= longitud-1 && !insertada; i++){
        datoDelantero = obtenerDato(i+1) ;
        datoTrasero = obtenerDato(i) ;
        if(i == 1 && entero < datoTrasero){
            insertarCelda(0, nueva) ;
            insertada = true ;
        }
        else if((entero < datoTrasero) || (entero >= datoTrasero && entero < datoDelantero)){
            insertarCelda(i+1, nueva) ;
            insertada = true ;
        }
        else if(i == longitud-1){
            aniadirCelda(entero) ;
            insertada = true ;
        }
    }
}

void Lista::eliminaCelda(const int indice){
    assert(indice > 0 && indice <= longitud) ;

    Celda *pCelda, *anterior;

    if(indice == 1){
        pCelda = obtenerCelda(indice) ;
        contenido = pCelda->siguiente ;
        delete pCelda ;
    }
    else{
        pCelda = obtenerCelda(indice) ;
        anterior = obtenerCelda(indice-1) ;
        anterior->siguiente = pCelda->siguiente ;
        delete pCelda ;
    }

    longitud-- ;
}

void Lista::eliminaEnteroRepetido(const int entero){
    bool encontrado = false ;

    for(int i = 1 ; i <= longitud && !encontrado; i++){
        if(obtenerDato(i) == entero){
            eliminaCelda(i) ;
            encontrado = true ;
        }
    }
}

// Fin métodos.
