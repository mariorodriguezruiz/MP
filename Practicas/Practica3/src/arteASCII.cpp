/*
    Mario Rodríguez Ruiz
    15 de marzo de 2016
    Pide al usuario el nombre de la imagen de entrada, el conjunto
    de caracteres para realizar la conversio?n y escriba en
    pantalla la imagen convertida a arte ASCII.
*/

#include<iostream>
#include<imagen.h>
#include<string>

using namespace std;

int main(){
    string grises;
    string nombreImagen ;
    char *arteASCII ;
    int tope ;
       
    Imagen origen;

    // Lee el nombre de la imagen
    cout << "\nNombre de la imagen: " ;
    getline(cin, nombreImagen) ;

    if (!origen.leerImagen(nombreImagen.c_str())){
	   cerr << "error leyendo " << nombreImagen << endl ;
	   return 1;
    }

    // Al tope hay que sumarle una columna más por el '\n'
    tope = origen.filas()*(origen.columnas()+1) + 1 ;
    arteASCII = new char[tope] ;

    // Lee el conjunto de caracteres.
    cout << "\nCaracteres ASCII: " ;
    getline(cin, grises) ;

    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises.c_str(), arteASCII, tope))
        cout << arteASCII << endl ;
    else
        cout << "La conversión no ha sido posible" << endl;
}
