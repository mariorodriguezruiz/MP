
#include<Polilinea.h>

Polilinea::Polilinea(){
    p = 0 ;
    num = 0 ;
}

Polilinea::Polilinea(const Polilinea &otra){
    reservarMemoria(otra.num) ;
    copiarDatos(otra) ;
}

Polilinea::~Polilinea(){
    liberarMemoria() ;
}

void Polilinea::liberarMemoria(){
    if(p != 0){
        delete []p ;
        num = 0 ;
    }
}

void Polilinea::reservarMemoria(const int tamanio){
    p = new Punto[tamanio] ;
}

void Polilinea::copiarDatos(const Polilinea &otra){
    num = otra.num ;

    for(int i = 0 ; i < num ; i++)
        p[i] = otra.p[i] ;
}

void Polilinea::aniadePunto(const Punto &nuevo){
    Punto *aux = new Punto[num+1] ;

    for(int i = 0 ; i < num ; i++)
        aux[i] = p[i];

    aux[num] = nuevo ;

    delete []p ;

    num = num+1 ;

    p = aux ;
}

void Polilinea::aniadePuntoCoordenadas(const int valorX, const int valorY){
    Punto *aux = new Punto(valorX, valorY) ;
    aniadePunto(*aux) ;

    delete aux ;
}



const Polilinea & Polilinea::operator = (const Polilinea & otra){
    if(this != &otra){
        liberarMemoria() ;
        reservarMemoria(otra.num) ;
        copiarDatos(otra) ;
    }

    return *this ;
}


Punto & Polilinea::operator [](int indice) const{
    assert(indice >= 0 && indice <= num) ;

    return p[indice] ;
}

/*Punto & Polilinea::operator [](int indice){
    assert(indice < 0 || indice >= num) ;

    return p[indice] ;
}*/

bool Polilinea::igualesMismoOrden(const Polilinea & otra)const {
    bool resultado = true ;

    for(int i = 0 ; i < num && resultado ; i++){
        if(p[i].getX() != otra.p[i].getX()
            || p[i].getY() != otra.p[i].getY())
            resultado = false ;
    }

    return resultado ;
}

bool Polilinea::igualesOrdenINverso(const Polilinea & otra)const {
    bool resultado = true ;

    for(int i = 0 ; i < num && resultado ; i++){
        if(p[i].getX() != otra.p[num-i-1].getX()
            || p[i].getY() != otra.p[num-i-1].getY())
            resultado = false ;
    }

    return resultado ;
}

bool Polilinea::operator == (const Polilinea &otra) const {
        if(num != otra.num)
            return false ;
        else if(igualesMismoOrden(otra) || igualesOrdenINverso(otra))
            return true ;
        else
            return false ;
}

Polilinea & Polilinea::operator + (const Punto &punto){
    Polilinea *nueva = this;

    nueva->aniadePunto(punto) ;

    return *nueva;
}


Polilinea & operator + (const Punto &punto, const Polilinea &poli){
    Polilinea *resultado = new Polilinea ;

    resultado->p = new Punto[poli.num+1] ;

    resultado->p[0] = punto ;

    for(int i = 0 ; i < poli.num ; i++){
        resultado->p[i+1] = poli.p[i] ;
    }

    resultado->num = poli.num + 1 ;

    return *resultado ;
}

void Polilinea::LeerPolilinea (const char *nombre){
    ifstream fichero ;
    const string titulo= "POLILINEA" ;
    string tituloLeido ;
    char c ;
    int puntoX, puntoY ;
    int tam ;

    fichero.open(nombre) ;

    if(!fichero){
        cerr << "\nError en la apertura de " << nombre << endl ;
    }
    else{
        fichero >> tituloLeido ;
        if(titulo.compare(tituloLeido) != 0){
            cerr << "\nEl fichero no tiene formato POLILINEA." << endl ;
        }
        fichero.ignore() ;
        if(fichero.peek() == '#'){
            do{
                c = fichero.get() ;
            }while(c != '\n') ;
        }

        fichero >> tam ;

        for(int i = 0 ; i < tam ; i++){
            fichero >> puntoX >> puntoY ;
            aniadePuntoCoordenadas(puntoX, puntoY) ;
        }
    }

    fichero.close() ;
}


void Polilinea::EscribirPolilinea (const char *nombre, const char *comentario){
    ofstream fichero ;

    fichero.open(nombre) ;

    if(!fichero){
        cerr << "\nError en la apertura de " << nombre << endl ;
    }
    else{
        fichero << "POLILINEA" << endl;

        if(comentario != 0)
            fichero << comentario << endl;

        fichero << num << endl;
        fichero << *this << endl ;
    }

    fichero.close() ;
}

ostream & operator << (ostream &flujo, const Polilinea &objeto){

    for(int i = 0 ; i < objeto.num ; i++){
        flujo << objeto.p[i].getX() << " " << objeto.p[i].getY() << endl ;
    }

    return flujo ;
}



