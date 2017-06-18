/*
	programa que lea un conjunto de números enteros (como máximo 100), los guarde en un array e indique cuál es el mayor de todos. Tanto la lectura de los elementos del array
	como el cálculo del máximo se harán mediante funciones. Debe incluirse un programa
	principal (main) para probar las funciones implementadas.
*/
#include <iostream>

using namespace std ;

int CalculaMayor(const int enteros[]){
	int numero = 0, i = 0;	
	int mayor = enteros[i] ;
	
	for( i = 1; enteros[i]!= '\0' ; i++){
		if(enteros[i] > mayor)
			mayor = enteros[i] ;		
	}
	
	return mayor ;
}

void LeeNumeros(const int TAMANIO, int enteros[]){
	int numero ;
	
	for(int i = 0 ; i < TAMANIO ; i++){
		cin >> numero ;
		enteros[i] = numero ;		
	}	
}


int main(){
	const int TAMANIO = 5 ;
	int vector_enteros[TAMANIO] ;
	
	LeeNumeros(TAMANIO, vector_enteros) ;	
	
	cout << "\nEl mayor es el: " << CalculaMayor(vector_enteros) << endl ;
	
}
