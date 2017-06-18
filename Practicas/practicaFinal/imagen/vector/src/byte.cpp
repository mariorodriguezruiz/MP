/*
    Mario Rodríguez Ruiz
    15 de marzo de 2016
    Implementación de las funciones de manejo de bytes
*/

#include "byte.h"

// Enciende el bit pos del byte b
void on(byte &b, int pos){
    if(esCorrectaLaPosicion(pos)){
        byte tmp = 1 << (NUM_POS-pos) ;
        b = tmp | b ;
    }
}

// Apaga el bit pos del byte b
void off(byte &b, int pos){
    if(esCorrectaLaPosicion(pos)){
        byte tmp = 1 << (NUM_POS-pos) ;
        tmp = ~tmp ;
        b = tmp & b ;
    }
}

// Devuelve el estado del bit (encendido = true, apagado = false) en la posición pos
bool getbit(byte b, int pos){
    byte tmp = 1 << pos ;

    if((tmp & b) != 0)
        return true ;
    else
        return false ;
}

// Enciende todos los leds
void encender(byte &b){
    for(int i = 0 ; i <= NUM_POS ; i++)
        on(b, i) ;
}

// Apaga todos los leds
void apagar(byte &b){
    for(int i = 0 ; i <= NUM_POS ; i++)
        off(b, i) ;
}

// Enciende los bits según la configuración de v
void asignar(byte &b, const bool v[]){
    for(int i = 0 ; i <= NUM_POS ; i++)
        if(v[i] != 0)
            on(b, v[i]) ;
        else
            off(b, v[i]) ;
}

// Vuelca en v la configuración de bits contenida en b.
void volcar(byte b, bool v[]){
    for(int i = 0 ; i <= NUM_POS ; i++)
        v[i] = getbit(b, i) ;
}

// Devuelve las posiciones de los bits encendidos.
void encendidos(byte b, int posic[], int &cuantos){
    cuantos = 0 ;
    for(int i = NUM_POS ; i >= 0 ; i--)
        if(getbit(b, i)){
            posic[cuantos] = NUM_POS-i ;
            cuantos++ ;
        }
}

// devuelve un s t r i n g con una secuencia de 0 ? s y 1 ? s
// c o r r e s p o n d i e n t e a l estado de cada bit . Se debe
// implementar u t i l i z a n d o l a f u n c i o?n ? g e t ?
/*string byteToString ( byte b ){
    string cadena = "";

    for(int i = 0 ; i <= NUM_POS ; i++){
        cadena = cadena + to_string(getbit(b, i)) ;
    }

    return cadena ;
}*/

// Comprueba que una posición se encuentra en el rango de la máscara.
bool esCorrectaLaPosicion(const int pos){
    if(pos >= 0 && pos <= NUM_POS)
        return true ;
    else
        return false ;
}

// Muestra por pantalla el bloque de led completo.
/*void muestraBloqueLed(byte b){
    cout << byteToString(b) << endl;
}*/
