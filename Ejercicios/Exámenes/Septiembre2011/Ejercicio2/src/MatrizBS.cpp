/*
 Implementación de los métodos de la clase Lista.

 */
#include<MatrizBS.h>


MatrizBS::MatrizBS(){
    valorDefecto = 0 ;
    nfil = 4 ;
    reservarEspacio(nfil) ;

    for(int i = 0 ; i < nfil ; i++)
        datos[i] = 1 ;
}

MatrizBS::MatrizBS(const int n, int *enteros, const int defecto){
    nfil = n ;
    valorDefecto = defecto ;
    reservarEspacio(nfil) ;

    for(int i = 0 ; i < nfil ; i++)
        datos[i] = enteros[i] ;
}

MatrizBS::~MatrizBS(){
    liberarEspacio() ;
}

void MatrizBS::liberarEspacio(){
    if(datos != 0){
        delete []datos ;
        nfil = 0 ;
        valorDefecto = 0 ;
    }
}

void MatrizBS::reservarEspacio(const int tamanio){
    if(tamanio > 0){
        datos = new int[tamanio] ;
    }
}

void MatrizBS::copiarDatos(const MatrizBS &otra){
    nfil = otra.nfil ;
    valorDefecto = otra.valorDefecto ;

    for(int i = 0 ; i < nfil ; i++)
        datos[i] = otra.datos[i] ;
}


const MatrizBS & MatrizBS::operator = (const MatrizBS &otra){
    if(this != &otra){
        liberarEspacio() ;
        reservarEspacio(otra.nfil) ;
        copiarDatos(otra) ;
    }

    return *this ;
}
// Fin métodos.
