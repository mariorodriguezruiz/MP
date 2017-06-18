#ifndef MATRIZBS_H
#define MATRIZBS_H

#include<iostream>
#include<string.h>
#include<fstream>
#include<assert.h>

using namespace std ;

class MatrizBS{
    private:
        int *datos ;
        int nfil ;
        int valorDefecto ;

        void liberarEspacio() ;

        void reservarEspacio(const int tam) ;

        void copiarDatos(const MatrizBS &otra) ;
    public:

        MatrizBS () ;

        ~MatrizBS() ;

        MatrizBS(const int n, int *enteros, const int defecto = 0) ;

        const MatrizBS & operator = (const MatrizBS &otra) ;

};

#endif /* MATRIZBS_H */
