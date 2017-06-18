/**
 * Concatenación de dos imágenes
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

int main(int argc, char *argv[]){
    Imagen origen1, origen2, suma;
    Lista celdas;
    bool valorTipo ;
    string tipo ;

    if (argc != 5) {
        cerr << "Error en el número de parámetros." << endl;
        cerr << "Uso: " << argv[0] << " <imagen1> <imagen2> <salida>  <tipo>" << endl;
        return 1;
    }

    // Leer la imagen desde fichero
    if (!origen1.leerImagen(argv[1])){
		cerr << "Error leyendo imagen " << argv[1] << endl;
		return 1;
    }

    // Leer la imagen desde fichero
    if (!origen2.leerImagen(argv[2])){
		cerr << "Error leyendo imagen " << argv[2] << endl;
		return 1;
    }

    tipo = argv[4] ;

    // Comprueba si el tipo introducido es correcto.
    if(tipo == "b")
        valorTipo = 1 ;
    else if (tipo == "t")
        valorTipo = 0 ;
    else{
        cerr << "\nEl tipo de archivo para el archivo de salida no es correcto. " << endl ;
        return 1 ;
    }

    suma = origen1 + origen2 ;

    if(suma.escribirImagen(argv[3], valorTipo))
        cout << "Imágenes concatenadas con éxito." << endl;
    else{
        cerr << "Imposible realizar la concatenación." << endl;
        return 1 ;
    }

}
