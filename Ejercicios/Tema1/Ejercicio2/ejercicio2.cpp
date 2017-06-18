/*
	un programa que lea una serie de números enteros (como máximo 100), los guarde
	en un array y lo invierta, mostrando el resultado. Si la secuencia introducida es 1, 100,
	34, 48, 53, entonces el resultado final mostrado debe ser 53, 48, 34, 100, 1. Deberá
	contener funciones para: lectura de los elementos del array, mostrar su contenido en la
	salida estándar e invertir sus elementos. Se implementará la función main para probar
	que todo funciona de forma correcta.

*/
#include <iostream>

using namespace std ;

void InvierteCadena(int enteros[], const int total_utilizados){
	int aux ;
	int tope = total_utilizados-1 ;
	
	for(int i = 0 ; i < tope/2 ; i++){
		aux = enteros[i] ;
		enteros[i] = enteros[tope-i] ;
		enteros[tope-i] = aux ;
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
	
	cout << "\n" ;
}

int main(){
	const int TAMANIO = 5 ;
	int vector_enteros[TAMANIO] ;
	int total_utilizados = 0 ;
	
	int tam_leido = LeeEntero("\nTamaño del vector: ", TAMANIO) ;
	LeeVector(tam_leido, vector_enteros, total_utilizados) ;		
	InvierteCadena(vector_enteros, total_utilizados) ;
	
	MuestraCadena(vector_enteros, total_utilizados) ;
	
}
