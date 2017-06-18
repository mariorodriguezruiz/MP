/*
 Implementación de los métodos de la clase Matriz.

 */
#include<Menu.h>

Menu::Menu(){
    titulo = 0 ;
    opc = 0 ;
    nopc = 0 ;
}

Menu::~Menu(){
    liberarMemoria() ;
}

Menu::Menu(const Menu &otro){
    copiarDatos(otro) ;
}

void Menu::liberarMemoria(){
    if(nopc > 0){
        for(int i = 0 ; i < nopc ; i++)
            delete []opc[i] ;

        delete []opc ;
        nopc = 0 ;
    }

    if(titulo != 0)
        delete []titulo ;
}

void Menu::copiarDatos(const Menu &otro){
    SetTitulo(otro.titulo) ;

    nopc = otro.nopc ;

    opc = new char *[nopc] ;

    for(int i = 0 ; i < nopc ; i++){
        opc[i]= new char[strlen(otro.opc[i])] ;
        strcpy(opc[i], otro.opc[i]) ;
    }

}

const Menu & Menu::operator = (const Menu &otro){
    if(this != &otro){
        liberarMemoria() ;
        copiarDatos(otro) ;
    }
    return *this ;
}

void Menu::SetTitulo(char *nuevo){
    if(titulo != 0){
        delete []titulo ;
    }
    titulo = new char[strlen(nuevo)] ;

    strcpy(titulo, nuevo) ;
}

int Menu::GetNumeroOpciones(){
    return nopc ;
}

void Menu::AddOpcion(char *nueva){
    char **nuevoOpc ;

    int nopcNuevo = nopc+1;

    nuevoOpc = new char *[nopcNuevo] ;

    for(int i = 0 ; i < nopc ; i++){
        nuevoOpc[i] = opc[i] ;
    }

    nuevoOpc[nopc] = new char[strlen(nueva)] ;
    strcpy(nuevoOpc[nopc], nueva) ;

    delete []opc ;

    opc = nuevoOpc ;

    nopc = nopcNuevo ;

}

void Menu::operator >> (int &entero){
    do{
        cout << *this ;
        cout << "\nElija una opción: " ;
        cin >> entero ;
    }while(entero < 0 || entero > nopc) ;
}

// Fin métodos.
