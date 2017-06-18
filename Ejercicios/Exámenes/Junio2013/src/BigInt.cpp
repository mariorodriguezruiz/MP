/*
 Implementación de los métodos de la clase BigInt.

 */
#include<BigInt.h>

BigInt::BigInt(){
    reservarMemoria(1) ;
    datos[0] = 0 ;
}

BigInt::BigInt(const char *cadena){
    const int tamanio = strlen(cadena) ;

    reservarMemoria(tamanio) ;

    for(int i = 0 ; i < tamanio ; i++)
        datos[tamanio-i-1] = cadena[i] - '0' ;
}

BigInt::BigInt(const unsigned int numero){
    unsigned int tmp = numero ;
    int tamanio = 0 ;

    while(tmp > 0){
        tmp = tmp/10 ;
        tamanio++ ;
    }

    reservarMemoria(tamanio) ;
    tmp = numero ;

    for(int i = 0 ; i < tamanio ; i++){
        datos[i] = tmp%10 ;
        tmp = tmp/10 ;
    }

}

BigInt::BigInt(const BigInt &otro){
    reservarMemoria(otro.numeroDigitos) ;
    copiarDatos(otro) ;
}

BigInt::~BigInt(){
    liberarMemoria() ;
}



const BigInt &BigInt::operator=(const BigInt &otro){
    if(this != &otro){
        liberarMemoria() ;
        reservarMemoria(otro.numeroDigitos) ;
        copiarDatos(otro) ;
    }

    return *this ;
}

const BigInt & BigInt::operator+(const BigInt &otro) const{
    int tamanioSuma = 0, acarreo = 0, operacion = 0 ;
    bool nueves = false ;
    char *suma = 0;
    // Se comprueba cuál de ambos tiene mayor numeroDigitos
    if(numeroDigitos > otro.numeroDigitos)
        tamanioSuma = numeroDigitos ;
    else
        tamanioSuma = otro.numeroDigitos ;

    for(int i = 0 ; i < numeroDigitos && i < otro.numeroDigitos && !nueves; i++){
        if(datos[i] + otro.datos[i] >= 10){
            nueves = compruebaSiRestoSonNueves(i) || otro.compruebaSiRestoSonNueves(i);
        }
    }

    if(nueves)
        tamanioSuma++ ;

    suma = new char[tamanioSuma] ;

    for(int i = 0 ; i < tamanioSuma ; i++){
        if(i < numeroDigitos && i < otro.numeroDigitos){
            operacion = (datos[i] + otro.datos[i] + acarreo) ;
            suma[tamanioSuma-i-1] = operacion%10 + '0';
            acarreo = 0 ;
            if(operacion >= 10)
                acarreo = 1 ;
        }
        else if(i < numeroDigitos && i >= otro.numeroDigitos){
            operacion = (datos[i] + acarreo) ;
            suma[tamanioSuma-i-1] = operacion%10  + '0';
            acarreo = 0 ;
            if(operacion >= 10)
                acarreo = 1 ;
        }
        else if(i >= numeroDigitos && i < otro.numeroDigitos){
            operacion = (otro.datos[i] + acarreo) ;
            suma[tamanioSuma-i-1] = operacion%10  + '0';
            acarreo = 0 ;
            if(operacion >= 10)
                acarreo = 1 ;
        }
        else
            suma[tamanioSuma-i-1] = acarreo  + '0';
    }

    BigInt *resultado = new BigInt(suma) ;

    delete []suma ;

    return *resultado ;
}

bool BigInt::compruebaSiRestoSonNueves(const int indice) const{
    bool resultado = true ;
    for(int i = indice ; i < numeroDigitos && resultado ; i++)
        if(datos[i] != 9)
            resultado = false ;

    return resultado ;
}

void BigInt::copiarDatos(const BigInt &otro){
    for(int i = 0 ; i < numeroDigitos ; i++)
        datos[i] = otro.datos[i] ;
}

void BigInt::liberarMemoria(){
    if(numeroDigitos != 0){
        delete []datos ;
        numeroDigitos = 0 ;
    }
}

void BigInt::reservarMemoria(const int tamanio){
    if(tamanio > 0){
        datos = new int[tamanio] ;
    }

    numeroDigitos = tamanio ;
}



void BigInt::imprimeEntero(){
    cout << endl ;
    for(int i = numeroDigitos-1 ; i >= 0 ; i--)
        cout << datos[i] ;
    cout << endl ;
}

// Fin métodos.
