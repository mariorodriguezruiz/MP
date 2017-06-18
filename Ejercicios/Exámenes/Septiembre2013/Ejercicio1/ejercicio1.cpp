#include<iostream>

using namespace std ;

class Entero {
    int *v;
    public:
        Entero (int i = 0) {
            v= new int;
            *v=i;
        }

        ~Entero () {
            delete v;
        }

        Entero(const Entero &otro){
            v = new int ;
            *v = *otro.v ;
        }

        const Entero & operator = (const Entero &otro) {
            if(this != &otro){
                delete v ;
                v = new int ;
                *v = *otro.v ;
            }
            return *this ;
        }

        void Set(int i) {
            *v = i ;
        }

        int Get() const {
            return *v;
        }

        friend ostream & operator << (ostream &flujo, const Entero &objeto) ;
};

Entero Doble(Entero e)
{
    return e.Get()*2;
}

ostream & operator << (ostream &flujo, const Entero &objeto){
    flujo << *objeto.v ;

    return flujo ;
}

int main()
{
    Entero x(5), y;
    y = Doble(x);
    cout << "Resultado: " << y << endl;
}
