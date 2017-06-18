
#include<Lista.h>

Lista::Lista(){
    contenido = 0 ;
    longitud = 0 ;
}

Lista::~Lista(){
    liberarMemoria() ;
}

void Lista::eliminaUltimaCelda(){
    Celda *pCelda = contenido ;

    for(int i = 1 ; i <= longitud-2 ; i++)
        pCelda = pCelda->obtenerSiguiente() ;

    delete pCelda->obtenerSiguiente() ;

    pCelda->setSiguiente(0) ;

    longitud-- ;
}

void Lista::liberarMemoria(){
    int tope = longitud ;
    if(contenido != 0){
        for(int i = 0 ; i < tope ; i++)
            eliminaUltimaCelda() ;

        delete contenido ;
    }
}


void Lista::aniadirCelda(const double valor){
    Celda *nueva, *ultima ;
    nueva = new Celda(valor) ;

    ultima = obtenerCelda(longitud) ;

    if(contenido == 0){
        contenido = nueva ;
    }
    else
        ultima->setSiguiente(nueva) ;

    longitud++ ;
}

Celda * Lista::obtenerCelda(const int indice) const{
    assert(indice >= 0 && indice <= longitud) ;

    Celda *pCelda = contenido ;

    for(int i = 0 ; i < indice-1 ; i++)
        pCelda = pCelda->obtenerSiguiente() ;

    return pCelda ;
}

void imprimeLista(Lista &una){
    Celda *pCelda ;

    for(int i = una.obtenerLongitud() ; i > 0 ; i--){
       pCelda = una.obtenerCelda(i) ;
       cout << pCelda->obtenerDato() << " " ;
    }

    cout << endl ;

}

Lista::Lista(const Lista &otra){
    reservarCeldas(otra.longitud) ;
    copiarDatos(otra) ;
}


const Lista & Lista::operator = (const Lista &otra){
    if(this != &otra){
        liberarMemoria() ;
        contenido = reservarCeldas(otra.longitud) ;
        copiarDatos(otra) ;
    }

    return *this ;
}

void Lista::copiarDatos(const Lista &otra){
    Celda *pCelda = obtenerCelda(0) ;
    Celda *pOtra = otra.obtenerCelda(1) ;

    longitud = otra.longitud ;

    for(int i = 1 ; i <= longitud ; i++){
        pCelda->setDato(pOtra->obtenerDato()) ;
        pCelda = pCelda->obtenerSiguiente() ;
        pOtra = pOtra->obtenerSiguiente() ;
    }
}

Celda* Lista::reservarCeldas(const int tamanio){
    Celda *pCelda, *pPrimera, *pCeldaAnterior = 0 ;

    for(int i = 0 ; i < tamanio ; i++){
        pCelda = new Celda(0) ;

        if(pCeldaAnterior == 0)
            pPrimera = pCelda ;
        else
            pCeldaAnterior->setSiguiente(pCelda) ;

        pCeldaAnterior = pCelda ;

    }

    return pPrimera ;
}
