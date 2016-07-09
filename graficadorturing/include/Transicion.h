#ifndef TRANSICION_H
#define TRANSICION_H

/*
Autora: Gabriela Garro
Fecha de creación: 06/11/14

Clase Transicion

Objetivo: Servir de contenedor lógico para los elementos
que forman una transición

*/
class Transicion
{
private:
    //mejor que todos sean string
    string estadoOrigen;
    string caracterLeido;
    string estadoDestino;
    string caracterEscrito;
    string movimientoCabeza; //puede ser < o >

public:
    Transicion() {}

    ~Transicion(){}


    string getTransicion()
    {
        string res = estadoOrigen + ", " ;
        res += caracterLeido + ", ";
        res += estadoDestino + ", ";
        res += caracterEscrito + ", ";
        res += movimientoCabeza;
        return res;
    }

    //entrada: un string con el nombre del estado de origen
    void setEstadoOrigen (string pEstadoOrigen) {
        estadoOrigen = pEstadoOrigen;
    }

    string getEstadoOrigen () {
        return estadoOrigen;
    }

    void setCaracterLeido (string pCaracterLeido) {
        caracterLeido = pCaracterLeido;
    }

    string getCaracterLeido () {
        return caracterLeido;
    }

    void setEstadoDestino(string pEstadoDestino) {
        estadoDestino = pEstadoDestino;
    }

    string getEstadoDestino () {
        return estadoDestino;
    }

    void setCaracterEscrito (string pCaracterEscrito) {
        caracterEscrito = pCaracterEscrito;
    }

    string getCaracterEscrito () {
        return caracterEscrito;
    }

    void setMovimientoCabeza (string pMovimientoCabeza) {
        //se puede agregar la validacion de que si no es < o > esta malo
        movimientoCabeza = pMovimientoCabeza;
    }

    int getMovimientoCabeza () {
        if (movimientoCabeza == "<") {
            return -1;
        }
        else if  (movimientoCabeza == ">"){
            return 1;
        }
        else{
            return 0;
        }
    }



};

#endif // TRANSICION_H
