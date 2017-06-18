/*
	Haz un programa que lea una serie de números enteros (como máximo 100) y que elimine
	los elementos repetidos guardándolos en un nuevo array. Debe contener funciones para
	leer los elementos de un array, imprimirlo y eliminar los elementos repetidos. 
*/
#include <iostream>

using namespace std ;

bool EsRepetido(const int numero, const int enteros[], const int total_utilizados){
	bool repetido = false ;
	
	for(int i = 0 ; i < total_utilizados && !repetido; i++)
		if(enteros[i] == numero )
			repetido = true ;
	
	return repetido ;
}

void EliminaRepetidos(const int enteros[], const int total_utilizados, int nueva[], int &util_nueva){
	for(int i = 0 ; i < total_utilizados ; i++){
		if(!EsRepetido(enteros[i], nueva, util_nueva)){
			nueva[util_nueva] = enteros[i] ;
			util_nueva++ ;
		}
	}	
}

int LeeEntero(const char mensaje[], const int superior){
	int numero ;
	
	do{
		cout << mensaje ;
		cin >> numero ;
		
	}while((numero < 1)||(numero > superior)) ;
	
	return numero ;
}

void LeeVector(const int tamanio, int enteros[], int &total_utilizados){
	int numero ;
	
	for(int i = 0 ; i < tamanio ; i++){
		cin >> numero ;
		enteros[i] = numero ;
		total_utilizados++ ;
	}	
}

void MuestraCadena(const int enteros[], const int total_utilizados){
	cout << "\n" ;
	for(int i = 0 ; i < total_utilizados ; i++)
		cout << enteros[i] << ", " ;		
}

int main(){
	const int TAMANIO = 100 ;
	int vector_enteros[TAMANIO] ;
	int sin_repetidos[TAMANIO] ;
	int total_utilizados = 0, util_nueva = 0 ;
	
	int tam_leido = LeeEntero("\nTamaño del vector: ", TAMANIO) ;
	LeeVector(tam_leido, vector_enteros, total_utilizados) ;		
	EliminaRepetidos(vector_enteros, total_utilizados, sin_repetidos, util_nueva) ;
	
	cout << "\nCadena original:" ;
	MuestraCadena(vector_enteros, total_utilizados) ;
	
	cout << "\nCadena sin repetidos:" ;
	MuestraCadena(sin_repetidos, util_nueva) ;
	
	cout << "\n" ;
}
