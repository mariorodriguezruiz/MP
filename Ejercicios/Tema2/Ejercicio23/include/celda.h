#ifndef CELDA_H
#define CELDA_H

class Celda{
    private:
        double info;
        Celda *sig;
    public:
        Celda() ;

        Celda(double inf) ;

        void setSiguiente(Celda *siguiente) ;

        void setInfo(double valor) ;

        inline Celda * getSiguiente() const{
            return sig ;
        }

        inline double getInfo() const{
            return info ;
        }
    //.........
};

#endif /* CELDA_H */
