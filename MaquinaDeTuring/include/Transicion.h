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


    string toString()
    {
        return estadoOrigen + ", "
        + caracterLeido + ", "
        + estadoDestino + ", "
        + caracterEscrito + ", "
        + movimientoCabeza;
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

    char getCaracterLeido () {
        return caracterLeido.at(0);
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

    char getCaracterEscrito () {
        return caracterEscrito.at(0);
    }

    void setMovimientoCabeza (string pMovimientoCabeza) {
        //se puede agregar la validacion de que si no es < o > esta malo
        movimientoCabeza = pMovimientoCabeza;
    }

    int getMovimientoCabeza () {
        if (movimientoCabeza == "<") {
            return -1;
        }
        else {
            return 1;
        }
    }



};

#endif // TRANSICION_H
