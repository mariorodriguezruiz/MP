
#include<Frecuencias.h>

Frecuencias::Frecuencias(){
    parejas = 0 ;
    npares = 0;
}

Frecuencias::~Frecuencias(){
    liberarMemoria() ;
}

Frecuencias::Frecuencias(const Frecuencias &otro){
    reservarMemoria(otro.npares) ;
    copiarDatos(otro) ;
}

const Frecuencias & Frecuencias::operator = (const Frecuencias &otro){
    if(this != &otro){
        liberarMemoria() ;
        reservarMemoria(otro.npares) ;
        copiarDatos(otro) ;
    }
    return *this ;
}

void Frecuencias::copiarDatos(const Frecuencias &otro){
    npares = otro.npares ;

    for(int i = 0 ; i < npares ; i++)
        parejas[i] = otro.parejas[i] ;
}

void Frecuencias::reservarMemoria(const int tam){
    parejas = new Pareja[tam] ;
}

void Frecuencias::liberarMemoria(){
    if(parejas != 0){
        delete []parejas ;
        npares = 0 ;
    }
}

bool Frecuencias::compruebaSiEstaAniadido(const int entero, int &posicion){
    bool resultado = false ;

    for(int i = 0 ; i < npares && !resultado ; i++){
        if(parejas[i].dato == entero){
            posicion = i ;
            resultado = true ;
        }
    }

    return resultado ;
}

int Frecuencias::devuelvePosicionDeInsertado(const int entero){
    int resultado = 0;
    bool parada = false ;

    for(int i = 1 ; i < npares-1 && !parada ; i++)
        if(parejas[i-1].dato > entero){
            resultado = i ;
            parada = true ;
        }
        else if(parejas[i-1].dato < entero && parejas[i+2].dato > entero){
            resultado = i+1 ;
            parada = true ;
        }
        else{
            resultado = npares ;
        }

    return resultado ;
}

void Frecuencias::Add(const int entero){
    int posicion = 0 ;

    if(npares == 0){
        reservarMemoria(1) ;
        parejas[npares].dato = entero ;
        parejas[npares].nveces = 1 ;
        npares++ ;
    }
    else if(compruebaSiEstaAniadido(entero, posicion)){
        parejas[posicion].nveces++ ;
    }
    else{
        Pareja *nueva = new Pareja[npares+1] ;
        int posicionInsertar = devuelvePosicionDeInsertado(entero) ;
        int nparesNueva = npares+1 ;
        int posNueva = 0, posOld = 0 ;

        while(posNueva < nparesNueva || posOld < npares){
            if(posNueva = npares-1){
                nueva[npares].dato = entero ;
                nueva[npares].nveces = 1 ;
                posNueva++ ;
            }
            if(posicionInsertar == posNueva){
                nueva[posNueva].dato = entero ;
                nueva[posNueva].nveces = 1 ;
                posNueva++ ;
            }
            else{
                nueva[posNueva] = parejas[posOld] ;
                posOld++ ;
                posNueva++;
            }
        }

        liberarMemoria() ;
        reservarMemoria(nparesNueva) ;
        parejas = nueva ;
        npares = nparesNueva ;
    }
}

const Frecuencias & Frecuencias::operator+=(const int entero){
    Add(entero) ;
    return *this ;
}

ostream & operator << (ostream &flujo, Frecuencias &objeto){
    flujo << endl ;
    for(int i = 0 ; i < objeto.getNpares() ; i++)
        flujo << objeto.parejas[i].dato << " " << objeto.parejas[i].nveces << endl;

    return flujo ;
}
