#include<iostream>

using namespace std ;

struct Tiempo{
	int horas ;
	int minutos ;
	int segundos ;	
};

void actualizaTiempo(Tiempo &T){
	while(T.segundos > 60 || T.minutos > 60){
		if(T.segundos > 60){
			T.minutos = T.minutos + T.segundos/60 ;
			T.segundos = T.segundos % 60 ;
		}
		else {
			T.horas = T.horas + T.minutos / 60 ;
			T.minutos = T.minutos % 60 ;		
		}	
	}
}


int convertirASegundos(const Tiempo &T){
	return T.horas*3600 + T.minutos*60 + T.segundos ;	
}

bool esPosterior(const Tiempo &instante1, const Tiempo &instante2){
	if(convertirASegundos(instante2) >                                                                             	convertirASegundos(instante1))
		return true ;
	else   
		return false ;	
}

Tiempo obtenerNuevoTiempo(const Tiempo &T, int seg){
	Tiempo T2 ;
	T2 = T ;
	
	T2.segundos = T.segundos + seg ;
	actualizaTiempo(T2) ;
	
	return T2 ;
}

Tiempo leeTiempo(){
	Tiempo t ;
			
	cout << "\nHoras: ";
	cin >> t.horas ;
	cout << "Minutos: ";
	cin >> t.minutos ;
	cout << "Segundos: ";
	cin >> t.segundos ;
	
	actualizaTiempo(t) ;
	
	return t ;
}

void muestraTiempo(const Tiempo &t){
	cout << "\nHoras: " << t.horas ;
	cout << "\nMinutos: " << t.minutos ;
	cout << "\nSegundos: " << t.segundos ;
}


int main(){
	Tiempo t ;
	
	cout << "\nPrueba para convertir a segundos. " ;
	t = leeTiempo() ;
	
	cout << "\nTiempo en segundos: " << convertirASegundos(t) << endl ;
	
	cout << "\nComprueba si un instante es posterior a otro. " ;
	Tiempo t1 ;
	Tiempo t2 ;
	
	cout << "\nTiempo1." ;
	t1 = leeTiempo() ;	
	
	cout << "\nTiempo2." ;
	t2 = leeTiempo() ;
	
	if(esPosterior(t1, t2))
		cout << "\nInstante2 es mayor que instante1. " << endl;
	else
		cout << "\nInstante2 no es mayor que instante1. " << endl;
	
	
	cout << "\nObtener un nuevo tiempo." << endl ;
	Tiempo t3 ;
	int segundos ;
	
	t3 = leeTiempo() ;	
	cout << "\nSegundos a añadir: " ;
	cin >> segundos ;
	
	muestraTiempo(obtenerNuevoTiempo(t3, segundos)) ;
	cout << "\n" ;
}
