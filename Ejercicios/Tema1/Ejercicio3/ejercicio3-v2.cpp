/*
	segunda versión de la función para eliminar los elementos repetidos de forma que la
	eliminación se haga sobre el mismo array de entrada, sin usar un segundo array auxiliar.
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

void EliminaValor(int enteros[], int &total_utilizados, const int posicion){
	for(int i = posicion ; i < total_utilizados-1 ; i++)
		enteros[i] = enteros[i+1] ;
	
	total_utilizados-- ;
}

void EliminaRepetidos(int enteros[], int &total_utilizados){
	for(int i = 0 ; i < total_utilizados ; i++)
		if(EsRepetido(enteros[i], enteros, i))
			EliminaValor(enteros, total_utilizados, i) ;		
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
	int total_utilizados = 0 ;
	
	int tam_leido = LeeEntero("\nTamaño del vector: ", TAMANIO) ;
	LeeVector(tam_leido, vector_enteros, total_utilizados) ;	
	
	cout << "\nCadena original:" ;
	MuestraCadena(vector_enteros, total_utilizados) ;	
	
	cout << "\nCadena sin repetidos:" ;
	EliminaRepetidos(vector_enteros, total_utilizados) ;
	MuestraCadena(vector_enteros, total_utilizados) ;
	
	cout << "\n" ;
}
