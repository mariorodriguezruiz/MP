/*
	Escribid un programa que rellene dos arrays a y b con enteros, obtenidos de acuerdo a la siguiente recurrencia:
		a0 = b0 = 1
		an = bn−1
		bn = an−1 + 2bn−1
	El programa debe generar una tabla en la que cada fila tendrá la siguiente información:
	k ak bk ak /bk
*/

#include<iostream>

using namespace std ;

class Tabla{
	private:
		static const int TAMANIO = 100 ;
		double vector_a[TAMANIO] ;
		double vector_b[TAMANIO] ;
		int util_a ;
		int util_b ;
		
	public:
		Tabla(){
			vector_a[0] = 1 ;
			vector_b[0] = 1 ;
			util_a = 1 ;
			util_b = 1 ;
		}
		
		int TotalUtilizados(){
			return util_a ;
		}
		
		int TotalUtilizadosB(){
			return util_b ;
		}
		
		void Aniade(double vector[], int &util, const double valor){
			if(util < TAMANIO){
				vector[util] = valor ;
				util += 1 ;				
			}			
		}
		
		void RellenaVectores(const int k){
			if(k < TAMANIO)
				for(int i = 1 ; i < k ; i++){
					Aniade(vector_a, util_a, vector_b[i-1]) ;
					Aniade(vector_b, util_b, vector_a[i-1] + 2*vector_b[i-1]) ;			
				}		
		}
		
		void MuestaTabla(){
			cout << "\tk\tak\tbk\tak/bk" ;
			for(int i = 0 ; i < util_a ; i++)
				cout << "\n\t" << i << "\t" << vector_a[i]
					<< "\t" << vector_b[i] << "\t" << vector_a[i]/vector_b[i] ;
					
			cout << "\n" ;			
		}
};



int main(){
	Tabla tabla ;
	int k ;
	
	cout << "\nk: " ;
	cin >> k ;
	
	tabla.RellenaVectores(k) ;
	tabla.MuestaTabla() ;	
}
