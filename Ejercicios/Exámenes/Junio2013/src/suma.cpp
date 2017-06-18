/*
    Examen junio 2013.
    Supongamos que tenemos un archivo con un número indeterminado de
    enteros largos en formato texto, separados por “espacios blancos”.
    Implemente un programa “suma.cpp” que use la clase BigInt para leer
    todos los valores que hay en el fichero y escribir, como resultado
    final, la suma de todos ellos.
    Por ejemplo, si el archivo “datos.txt” contiene los siguientes enteros:
        9347829037470000000000000000
        9327887198348931
    Una posible ejecución del programa podrı́a ser la siguiente:
        % suma datos.txt
        9347829037479327887198348931

 */

#include<iostream>
#include<string>
#include<BigInt.h>
#include<fstream>

int main(int argc, char **argv){
    ifstream input ;
    BigInt uno, otro, suma ;

    if(argc != 2){
        cerr << "\nError en el número de parámetros: % suma datos.txt" << endl ;
        return 1 ;
    }

    input.open(argv[1]) ;

    if(!input){
        cerr << "\nError la apertura del fichero " << argv[1] << endl ;
        return 1 ;
    }

    while(input.peek() != '\n'){
        input >> uno ;
    }

    input.ignore() ;

    while(input.peek() != '\n'){
        input >> otro ;
    }
    input.ignore() ;
    suma = uno + otro ;

    cout << "\nSuma: " << suma << endl ;

    input.close() ;
    return 0 ;
}

