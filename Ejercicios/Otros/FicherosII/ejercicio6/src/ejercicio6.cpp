/*
    Se dispone de ficheros de texto que contienen un número indeterminado de líneas, cada una de ellas con los
    datos correspondientes a una serie de grupos de valores reales.
    Por ejemplo, una línea de entrada podría ser la siguiente:
    3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
    donde puede observar que se distinguen tres grupos de datos (indicado por el primer número de la línea) y
    cada grupo empieza por un valor entero (2, 5 y 2) seguido por tantos valores reales como indique el valor
    entero que encabeza cada grupo.
    Escribir un programa que escriba en la salida estándar una línea de resultado por cada línea de entrada, y en
    cada línea mostrará las sumas de los valores de cada grupo que la componen.

*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

void imprimirVector(double *v, int n)  {
	for (int i=0; i<n; i++)
		cout << v[i] << " " ;
}

void copiaLineaSinEspacios(const string linea, double *&v, int &util){
    double *nuevoVector ;
    char espacio = ' ' ;
    int tamVector ;
    string cadena ;
    unsigned i = 0 ;
    double numero ;
    util = 0 ;

    tamVector = linea.length() - (linea.length()/2) ;
    delete []v ;
    nuevoVector = new double[tamVector] ;


    while(i < linea.length()){
        if(linea[i] != espacio && linea[i+1] == espacio){
            nuevoVector[util] = linea[i] - 48 ;
            util++ ;
            i += 2 ;
        }else{
            cadena= "" ;
            while(linea[i] != espacio && linea[i] != '\0'){
                cadena += linea[i] ;
                i++ ;
            }
            numero = atof(cadena.c_str()) ;
            nuevoVector[util] = numero;
            util++ ;
            i++ ;
        }
    }

    v = nuevoVector ;
}


void calculaSumas(const string linea, double *&sumaV, int &util){
    double *nuevaSuma ;
    double *lineaV = NULL;
    int totalLinea ;
    int pos, tope;
    double suma ;
    unsigned i ;

    util = 0 ;
    delete []sumaV ;

    tope = linea[0] - 48 ;
    copiaLineaSinEspacios(linea, lineaV, totalLinea) ;
    nuevaSuma = new double[tope] ;

    pos = 1 ;
    suma = 0 ;
    i = 0 ;
    while(i < (lineaV[0])){
        tope = lineaV[pos] + pos;
        pos++ ;
        while(pos <= tope){
            suma += lineaV[pos] ;
            pos++ ;
        }

        nuevaSuma[util] = suma ;
        util++ ;
        i++ ;
        suma = 0 ;
    }

    sumaV = nuevaSuma ;
    delete []lineaV ;
}

int main(){
    ifstream fentrada ;
    string linea ;
    double *suma = NULL ;
    int utilSuma ;

    fentrada.open("entrada.txt");
    if(!fentrada){
        cerr << "\nError al abrir el fichero. " << endl ;
        return 1 ;
    }

    linea = "" ;
    getline(fentrada, linea) ;
    while(!fentrada.eof()){
        calculaSumas(linea, suma, utilSuma) ;
        imprimirVector(suma, utilSuma) ;

        linea = "" ;
        getline(fentrada, linea) ;
        cout << "\n" ;
    }

    delete []suma ;
}
