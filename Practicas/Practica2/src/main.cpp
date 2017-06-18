
#include "bloqueLed.h"



int main(){
    bloqueLed b;
    int posiciones[8];
    int size;

    apagar(b);
    cout << "\nBloque apagado LEDs: ";
    muestraBloqueLed(b) ;
    // enciendo dos LEDs
    on(b,5); 
    on(b,7);
    cout << "\nEnciendo el 5 y el 7: ";
    muestraBloqueLed(b) ;
    cout << "\nAhora enciendo los LEDs 0, 1 y 2\n";
    on(b,0);
    muestraBloqueLed(b) ;
    on(b,1);
    muestraBloqueLed(b) ;
    on(b,2);
    muestraBloqueLed(b) ;

    cout << "\nLos LEDs encendidos estan en las posiciones: ";
    encendidos(b,posiciones, size); 
    for(int i=0; i< size; i++)
        cout << posiciones[i] << ",";

    cout << endl;

    cout << "\nTodos encendidos: ";
    encender(b);
    muestraBloqueLed(b) ;

    cout << "Todos apagados: ";
    apagar(b);
    muestraBloqueLed(b) ;


    cout << "\nAhora la animacion\nEjemplo 1 \n";
    encender(b);
    muestraBloqueLed(b) ;
    off(b, NUM_POS) ;
    muestraBloqueLed(b) ;
    for(int i = NUM_POS-1 ; i >= 0 ; i--){
        off(b, i) ;
        on(b, i+1) ;
        muestraBloqueLed(b) ;
    }

    cout << "\nEjemplo 2 \n";
    encender(b);
    muestraBloqueLed(b) ;
    for(int i = 0 ; i <= NUM_POS/2 ; i++){
        off(b, i) ;
        off(b, NUM_POS-i) ;
        muestraBloqueLed(b) ;
    }

    for(int i = NUM_POS/2 ; i >= 0 ; i--){
        on(b, i) ;
        on(b, NUM_POS-i) ;
        muestraBloqueLed(b) ;
    }

}
