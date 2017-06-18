/*
    Mario Rodríguez Ruiz
    15 de marzo de 2016
    pida al usuario el nombre de un fichero de texto (por ejemplo
    ?grises.txt?) conteniendo distintos conjuntos de caracteres. El formato del
    fichero que contenga los conjuntos de caracteres sera? el siguiente: la pri-
    mera l??nea sera? un comentario que se ignorara?; la siguiente l??nea tendra? el
    nu?mero de cadenas que contiene el fichero; y finalmente cada una de las
    restantes l??neas correspondera? a una cadena que se usara? para convertir
    la imagen a arte ASCII. El programa debera? pedir tambie?n un nombre de
    fichero de salida. Luego, para cada cadena del fichero que contiene los
    conjuntos de caracteres, se generara? un fichero de salida de la siguiente
    forma: ?nombredesalidaX.txt?donde X es el nu?mero orden de la cadena
    (1,2,..,n) en el fichero de caracteres.
*/

#include<iostream>
#include<imagen.h>
#include<string>
#include<fstream>

using namespace std;

int main(){
    string ficheroCaracteres, ficheroSalida;
    string nombreImagen, basura ;
    string grises, nombreFiSalida ;
    char *arteASCII ;
    int tope, num_cadenas ;
    ifstream fentrada ;
    ofstream fsalida ;
       
    Imagen origen;

    // Lee el nombre de la imagen
    cout << "\nImagen de entrada: " ;
    getline(cin, nombreImagen) ;

    if (!origen.leerImagen(nombreImagen.c_str())){
	   cerr << "error leyendo " << nombreImagen << endl ;
	   return 1;
    }

    // Al tope hay que sumarle una columna más por el '\n'
    tope = origen.filas()*(origen.columnas()+1) + 1 ;
    arteASCII = new char[tope] ;

    // Lee el nombre del fichero con el conjunto de caracteres.
    cout << "\nFichero de cadenas: " ;
    getline(cin, ficheroCaracteres) ;
    fentrada.open(ficheroCaracteres.c_str()) ;
    if (!fentrada){
	   cerr << "error leyendo " << ficheroCaracteres << endl ;
	   return 1;
    }

    // Lee el nombre del fichero de salida.
    cout << "\nFichero de salida: " ;
    getline(cin, nombreFiSalida) ;

    if(fentrada){
        getline(fentrada, basura) ;
        fentrada >> num_cadenas ;
        getline(fentrada, basura) ;
        getline(fentrada, grises) ;
        if(!fentrada)
            cerr << "\nError de lectura del fichero." << endl ;
        else
        {
            for(int i = 1 ; i <= num_cadenas ; i++){
                ficheroSalida = nombreFiSalida + to_string(i) + ".txt" ;
                fsalida.open(ficheroSalida.c_str()) ;
                fsalida << "\nLa imagen en arte ASCII es:\n";

                if(origen.aArteASCII(grises.c_str(), arteASCII, tope))
                    fsalida << arteASCII ;
                else
                    cerr << "La conversión no ha sido posible." << endl;

                fsalida.close() ;
                getline(fentrada, grises) ;
            }
        }
        fentrada.close() ;
    }
    else
        cerr << "\nError de apertura del fichero." << endl ;
}
