#include<BigInt.h>

/**
* Sobrescritura del oprador <<
*/

ostream & operator << (ostream &flujo, const BigInt &objeto){
    for(int i = objeto.numeroDigitos-1 ; i >= 0 ; i--)
        flujo << objeto.datos[i] ;
    flujo << endl ;
    return flujo ;
}

/**
* Sobrescritura del oprador >>
*/
istream & operator >> (istream &flujo, BigInt &objeto){
    string cadena;
    int num, digitos = 0 ;
    flujo >> cadena ;

    for(int i = cadena.size()-1 ; i >= 0 ; i--){
        num = (cadena[i] - '0') ;
        if(num >= 0 && num <= 9)
            digitos++ ;
    }

    objeto.liberarMemoria() ;
    objeto.reservarMemoria(digitos) ;

    for(unsigned i = 0 ; i < cadena.size() ; i++){
        num = (cadena[i] - '0') ;
        if(num >= 0 && num <= 9){
            objeto.datos[digitos-1] = num ;
            digitos-- ;
        }
    }

    return flujo ;
}
