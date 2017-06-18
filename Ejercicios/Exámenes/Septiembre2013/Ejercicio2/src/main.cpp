/*
    Examen septiembre 2012.

 */

#include<Menu.h>

int main(int argc, char **argv){
    Menu uno ;
    int entero ;

    uno.SetTitulo("EJERCICIOOOOOOO") ;
    uno.AddOpcion("Una opcion") ;
    //uno.AddOpcion("Otra opcion") ;

    uno >> entero ;

    cout << "\nEnterooooooooo: " << entero << endl ;
}

