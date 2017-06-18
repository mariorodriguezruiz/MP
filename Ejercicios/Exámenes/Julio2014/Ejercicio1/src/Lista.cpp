
#include<Lista.h>

Lista::Lista(){
    contenido = 0 ;
    longitud = 0 ;
}

void Lista::aniadirCelda(const int valor){
    Celda *nueva, *ultima ;

    nueva = new Celda(valor) ;
    ultima = obtenerCelda(longitud) ;

    if(contenido != 0)
        ultima->setSiguiente(nueva) ;
    else
        contenido = nueva ;

    longitud++ ;
}

Celda * Lista::obtenerCelda(const int indice){
    assert(indice >= 0 && indice <= longitud) ;

    Celda *pCelda = contenido ;

    for(int i = 0 ; i < indice-1 ; i++)
        pCelda = pCelda->getSiguiente() ;

    return pCelda ;
}

Lista * devuelveVectorListas(Lista &una, const int t){
    Lista *resultado ;
    Celda *pCeldaUna ;
    int tamLista = una.getLongitud()/t + 1 ;
    int oldLong = 1;

    resultado = new Lista[tamLista] ;

    pCeldaUna = una.obtenerCelda(1) ;

    for(int i = 1 ; i <= tamLista ; i++){
        resultado[i-1].setContenido(pCeldaUna) ;
        resultado[i-1].setLongitud(resultado[i-1].getLongitud()+1) ;
        for(int j = 1 ; j < t && pCeldaUna->getSiguiente() != 0; j++){
            pCeldaUna = pCeldaUna->getSiguiente() ;
            resultado[i-1].obtenerCelda(j)->setSiguiente(pCeldaUna) ;
            resultado[i-1].setLongitud(resultado[i-1].getLongitud()+1) ;
            if(j == t-1){
                pCeldaUna = pCeldaUna->getSiguiente() ;
                resultado[i-1].obtenerCelda(t)->setSiguiente(0) ;
            }
        }
    }

    return resultado ;
}
