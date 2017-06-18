/*
     Escribir un programa similar a diff para comparar dos ficheros de texto. El programa imprimirá el número de
    la primera línea en la que difieren y el contenido de éstas.
    Por ejemplo, la ejecución de diff Fich1 Fich2 producirá como resultado:
    (
        20) Fich1: en formato binario. Estos ficheros son especialmente adecuados para
        Fich2: en formato binario. Estos ficheros, aunque no son legibles, son especialmente

*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

bool comparaCadenas(const char *cad1, const char *cad2){
    bool resultado = true ;

    for(int i = 0; (cad1[i] != '\0' || cad2[i] != '\0')&& resultado; i++)
        if(cad1[i] != cad2[i])
            resultado = false ;

    return resultado ;
}

int main(){
    ifstream fentrada1, fentrada2 ;
    string nombref1, nombref2, cadena1, cadena2 ;
    int num_linea = 1 ;
    bool iguales = true;

    cout << "\nFichero entrada 1: ";
	getline(cin, nombref1) ;
    fentrada1.open(nombref1.c_str()) ;

    cout << "\nFichero entrada 2: ";
	getline(cin, nombref2) ;
    fentrada2.open(nombref2.c_str()) ;

    if (!fentrada1){
	   cerr << "\nError de apertura del fichero " << nombref1 << endl ;
	   return 1;
    }
    else if (!fentrada2){
	   cerr << "\nError de apertura del fichero " << nombref2 << endl ;
	   return 1;
    }
    else{
        cadena1 = "" ;
        cadena2 = "" ;
        getline(fentrada1, cadena1) ;
        getline(fentrada2, cadena2) ;
        iguales = comparaCadenas(cadena1.c_str(), cadena2.c_str()) ;
        while((!fentrada1.eof() || cadena1.length() != 0 ||
            !fentrada2.eof() || cadena2.length() != 0) && iguales){
            num_linea++ ;
            cadena2 = "" ;
            cadena1 = "" ;
            getline(fentrada1, cadena1) ;
            getline(fentrada2, cadena2) ;
            iguales = comparaCadenas(cadena1.c_str(), cadena2.c_str()) ;
        }
        fentrada2.close() ;
        fentrada1.close() ;
    }

    if(!iguales){
        cout << "\n{" << num_linea << "}";
        cout << "\tFich1: " << cadena1 ;
        cout << "\n\tFich2: " << cadena2 << endl;
    }
    else
        cout << "\nLos ficheros son iguales." << endl ;


}
