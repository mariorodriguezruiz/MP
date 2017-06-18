/*
	programa que obtenga la mayor secuencia monótona creciente de un array de
	enteros, guardándola en otro array (mediante una función). El array se inicializará de
	forma explı́cita en la función main. El programa contendrá además una función para
	imprimir un array y ası́ poder ver el resultado.
 
*/
#include <iostream>

using namespace std ;

bool ExisteSecuenciaMayor(const int original[], const int util_original,  int pos_inicial, int &pos_final, const int max_secuencia){
	int secuencia_tmp = 0 ;
	bool continua = true ;
	pos_inicial += 1 ;
	
	while(secuencia_tmp <= max_secuencia && continua && pos_inicial < util_original){
		if(original[pos_inicial] == original[pos_inicial-1]+1){
			secuencia_tmp += 1 ;
			pos_final = pos_inicial ;
			pos_inicial += 1 ;			
		}
		else 
			continua = false ;
	}
	
	if(secuencia_tmp > max_secuencia)
		return true ;
	else
		return false ;
}

void AlmacenaNuevaSecuencia(const int original[], const int pos_inicial, const int pos_final, int nueva[], int &util_nueva){
	util_nueva = 0 ;
	for(int i = pos_inicial ; i <= pos_final ; i++){
		nueva[util_nueva] = original[i] ;
		util_nueva++ ;
	}
}

void ObtieneMayorSecuenciaMonotona(const int original[], const int util_original, int nueva[], int &util_nueva){
	int max_secuencia = 0 ;
	int pos_inicial = 0 ;
	int pos_final = 0 ;
	
	while(pos_inicial < util_original){
		if(ExisteSecuenciaMayor(original, util_original, pos_inicial, pos_final, max_secuencia)){
			AlmacenaNuevaSecuencia(original, pos_inicial, pos_final, nueva, util_nueva) ;
			pos_inicial = pos_final+1 ;
			max_secuencia = util_nueva+1 ;
		}
		else{
			pos_inicial += 1 ;			
		}		
	}	
}

void MuestraCadena(const int enteros[], const int tam){
	cout << "\n" ;

	for(int i = 0 ; i < tam ; i++)
		cout << enteros[i] << ", " ;		
}

int main(){
	const int TAM = 21 ;
	int resultado[TAM] ;
	int vector_enteros[] = {1, 2, 0, 3, 4, 5, 6, 7, 2, 1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 3, 4} ;
	int util_resultado = 0 ;	
	
	cout << "\nCadena original:" ;
	MuestraCadena(vector_enteros, TAM) ;
	
	ObtieneMayorSecuenciaMonotona(vector_enteros, TAM, resultado, util_resultado) ;
	
	cout << "\nMáxima secuencia monótona creciente:" ;
	MuestraCadena(resultado, util_resultado) ;
	
	cout << "\n" ;
}
