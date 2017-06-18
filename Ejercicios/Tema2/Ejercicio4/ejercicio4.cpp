/*
    Declare una variable v como un vector de 1000 enteros. Escriba un trozo de código que
    recorra el vector y modifique todos los enteros negativos cambiándolos de signo. No
    se permite usar el operador [], es decir, el recorrido se efectuará usando aritmética de
    punteros y el bucle se controlará mediante un contador entero.
*/

#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std ;

void muestraVector(const int *vector, const int total_utilizados){
    for(int i = 0 ; i < total_utilizados ; i++){
        cout << *(vector + i) << ", " ;
    }
    cout << "\n" ;
}

int main(){
    const int TAM = 1000 ;
    int v[TAM] ;
    int aux, tope ;

    // Queremos valores -50<=n<=50
    const int MY_MAX_RAND = 50;
    time_t t;
    // Inicializa el generador con el reloj
    // del sistema
    srand ((int) time(&t));

    for (int i=0; i<TAM; i++)
        *(v + i) = (int)(1.0*(MY_MAX_RAND+MY_MAX_RAND+1)*rand()/(RAND_MAX+1.0) - MY_MAX_RAND ) ;

    cout << "\nVector original: " << endl ;
    muestraVector(v, TAM) ;

    for(int i = 0 ; i < TAM ; i++){
        if(*(v + i) < 0)
            *(v + i) *= -1 ;
    }

    cout << "\nVector invertido: " << endl ;
    muestraVector(v, TAM) ;

}
