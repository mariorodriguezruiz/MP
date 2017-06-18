/**
@file main.cpp
@brief 
Universidad de Granada
Metodología de la Programación I
Examen de laboratorio 

Por favor, rellene las funciones que se indican
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(string *v, int n)  {
	cout << n << " elementos" << endl;
	for (int i=0; i<n; i++)
		cout << "["<<i<<"] = " << v[i] << endl;
}

void escribeFicheroEnVector(ifstream &entrada, string *&v, const int tam){
    string *nuevo= NULL ;

    delete []v ;
    nuevo = new string[tam] ;
    for(int i = 0 ; i < tam ; i++)
        entrada >> nuevo[i] ;

    v = nuevo ;
}

void eliminaDatoPorPosicion(string *v, int &tam, const int pos){
    int tope = tam-1 ;

    for(int i = pos ; i < tope ; i++)
        v[i] = v[i+1] ;

    tam-- ;
}

void calculaComplementario(const string *vA, const int tamA, const string *vB, const int tamB, string *vRes, int &tamRes){
    bool continua ;

    tamRes = tamA ;
    for(int i = 0 ; i < tamA ; i++)
        vRes[i] = vA[i] ;

    for(int i = 0 ; i < tamB ; i++){
        continua = true ;
        for(int j = 0 ; j < tamRes && continua; j++){
            if(vB[i] == vRes[j]){
                eliminaDatoPorPosicion(vRes, tamRes, j) ;
                continua = false ;
            }
            else if(j+1 == tamRes){
                vRes[j+1] = vB[i] ;
                tamRes++ ;
                continua = false ;
            }
        }
    }
}

int main()  {
	string *A=NULL, *B=NULL, *Resultado=NULL;
	int elemA, elemB, elemResultado;
	ifstream FichA, FichB;
    ofstream FichResultado ;
	
	/// Examen: Leer fichero en vector A
    FichA.open("mod5A.txt") ;
    if(!FichA){
        cerr << "\nError al abrir fichero. " << endl ;
        return 1 ;
    }

    FichA >> elemA ;
    escribeFicheroEnVector(FichA, A, elemA);
	imprimirVector(A, elemA);

	/// Examen: Leer fichero en vector B
    FichB.open("mod5B.txt") ;
    if(!FichB){
        cerr << "\nError al abrir fichero. " << endl ;
        return 1 ;
    }

    FichB >> elemB ;
    escribeFicheroEnVector(FichB, B, elemB);
	imprimirVector(B, elemB);

	/// Examen: Calcular resultado
    Resultado = new string[elemA+elemB] ;
    calculaComplementario(A, elemA, B, elemB, Resultado, elemResultado) ;

	/// Examen: Mostrar resultado
    FichResultado.open("resultado.txt") ;
    FichResultado << elemResultado << endl;
    for(int i = 0; i < elemResultado ; i++)
        FichResultado << Resultado[i] << endl;
	imprimirVector(Resultado, elemResultado);

	/// Examen: Terminación del programa
    FichA.close() ;
    FichB.close() ;
    FichResultado.close() ;
    delete []A ;
    delete []B ;
    delete []Resultado ;

	return 0;
}
 
