/*
@file 
@author Mario Rodríguez Ruiz
@date 15 de marzo de 2016
@brief Implementación de las funciones de manejo de bloqueLeds

*/

#include "bloqueLed.h"

// Enciende el LED pos del bloqueLed b
void on(bloqueLed &b, int pos){
    if(esCorrectaLaPosicion(pos)){
        bloqueLed tmp = 1 << (NUM_POS-pos) ;
        b = tmp | b ;
    }
}

// Apaga el LED pos del bloqueLed b
void off(bloqueLed &b, int pos){
    if(esCorrectaLaPosicion(pos)){
        bloqueLed tmp = 1 << (NUM_POS-pos) ;
        tmp = ~tmp ;
        b = tmp & b ;
    }
}

// Devuelve el estado del LED (encendido = true, apagado = false) en la posición pos
bool get(bloqueLed b, int pos){
    bloqueLed tmp = 1 << pos ;

    if((tmp & b) != 0)
        return true ;
    else
        return false ;
}

// Enciende todos los leds
void encender(bloqueLed &b){
    for(int i = 0 ; i <= NUM_POS ; i++)
        on(b, i) ;
}

// Apaga todos los leds
void apagar(bloqueLed &b){
    for(int i = 0 ; i <= NUM_POS ; i++)
        off(b, i) ;
}

// Enciende los LEDs según la configuración de v
void asignar(bloqueLed &b, const bool v[]){
    for(int i = 0 ; i <= NUM_POS ; i++)
        if(v[i] != 0)
            on(b, v[i]) ;
        else
            off(b, v[i]) ;
}

// Vuelca en v la configuración de LEDs contenida en b.
void volcar(bloqueLed b, bool v[]){
    for(int i = 0 ; i <= NUM_POS ; i++)
        v[i] = get(b, i) ;
}

// Devuelve las posiciones de los LEDs encendidos.
void encendidos(bloqueLed b, int posic[], int &cuantos){
    cuantos = 0 ;
    for(int i = NUM_POS ; i >= 0 ; i--)
        if(get(b, i)){
            posic[cuantos] = NUM_POS-i ;
            cuantos++ ;
        }
}

// devuelve un s t r i n g con una secuencia de 0 ? s y 1 ? s
// c o r r e s p o n d i e n t e a l estado de cada LED . Se debe
// implementar u t i l i z a n d o l a f u n c i o?n ? g e t ?
string bloqueLedToString ( bloqueLed b ){
    string cadena = "";

    for(int i = 0 ; i <= NUM_POS ; i++){
        cadena = cadena + to_string(get(b, i)) ;
    }

    return cadena ;
}

// Comprueba que una posición se encuentra en el rango de la máscara.
bool esCorrectaLaPosicion(const int pos){
    if(pos >= 0 && pos <= NUM_POS)
        return true ;
    else
        return false ;
}

// Muestra por pantalla el bloque de led completo.
void muestraBloqueLed(bloqueLed b){
    cout << bloqueLedToString(b) << endl;
}
