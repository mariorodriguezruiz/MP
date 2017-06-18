/*
    Escribir un programa que reciba el nombre de dos ficheros. El programa copiará, en el mismo orden, los
    números que contiene el fichero de entrada en el fichero de salida.
        -El primer fichero (entrada) contiene una serie indefinida de números enteros. Es un fichero de texto y
        puede contener espacios, tabuladores o saltos de línea (en cualquier número y combinación) separando
        dos números enteros consecutivos.
        -El segundo fichero (salida) es un fichero binario.
        -El programa leerá los números y los copiará de uno en uno.


*/

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std ;

typedef struct{
    int posInicioMarca ;
    int longMarca ;
    char *marca ;
    char comentario[100] ;

} TipoCabecera ;

int main(){
    ifstream fentrada ;
    ofstream fsalida ;
    string nombreEntrada, nombreSalida ;

    /*cout << "\nFichero entrada: " ;
    getline(cin, nombreEntrada) ;
    fentrada.open(nombreEntrada.c_str()) ;

    if(!fentrada){
        cerr << "\nError en la apertura del fichero " << nombreEntrada << endl ;
        return 1 ;
    }*/

    TipoCabecera ejemplo ;

    ejemplo.posInicioMarca = 0 ;
    ejemplo.longMarca = 2 ;
    strcpy(ejemplo.marca, "P5") ;
    strcpy(ejemplo.comentario, "Datos Científicos");


    cout << "\nFichero salida: " ;
    getline(cin, nombreSalida) ;
    fsalida.open(nombreSalida.c_str(), ios::out | ios::binary) ;

    fsalida.write((const char *)&ejemplo, sizeof(TipoCabecera));

    fsalida.close() ;
}
