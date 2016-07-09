#ifndef VIRTUALTURINGMACHINE_H
#define VIRTUALTURINGMACHINE_H
#include "LinkedList.h"
#include "Transicion.h"

/*
Autora: Gabriela Garro
Fecha de creación: 08/11/14

Clase VirtualTuringMachine

Descripción: Sirve de contenedor lógico para los elementos que
describen formalmente a una máquina de Turing

Objetivo: Contener fácilmente en listas enlazadas y en sus atributos
las características de una máquina de Turing
*/
class VirtualTuringMachine
{
private:
    LinkedList<string> estados; //Q
    LinkedList<char> simbolosDeEntrada; //S
    LinkedList<char> simbolosDeMaquina; //G
    LinkedList<Transicion> transiciones; //T
    string estadoInicial; //I
    string caracterBlanco; //B
    LinkedList<string> estadosAceptacion; //F
    LinkedList<string> estadosRechazo; //R
public:
    VirtualTuringMachine(){}

    //agrega un estado de la máquina
    //entrada: un string con el nombre del estado
    void appendEstado(string pEstado){
        estados.append(pEstado);
    }

    //salida: la cantidad de estados almacenados para que sea
    //usado en la clase que grafica
    int getCantidadEstados(){
        return estados.getSize();
    }

    //entrada: un char que representa un símbolo de entrada de la máquina
    void appendSimboloEntrada(char pSimbolo){
        simbolosDeEntrada.append(pSimbolo);
    }

    //entrada: un char que representa un símbolo de la máquina
    void appendSimboloMaquina(char pSimbolo){
        simbolosDeMaquina.append(pSimbolo);
    }

    //entrada: un objeto transicion que se agrega a la lista de transiciones
    void appendTransicion(Transicion pTransicion){
        transiciones.append(pTransicion);
    }

    //entrada: un string que representa el nombre de un estado
    //se agrega a la lista de estados de aceptación
    void appendEstadoAceptacion(string pEstado) {
        estadosAceptacion.append(pEstado);
    }

    //entrada: un string que representa el nombre de un estado
    //se agrega a la lista de estados de rechazo
    void appendEstadoRechazo(string pEstado) {
        estadosRechazo.append(pEstado);
    }

    //salida: retorna la lista de estados
    LinkedList<string> getEstados ( ){
        return estados;
    }

    //salida: retorna la lista de simbolos de entrada
    LinkedList<char> getSimbolosDeEntrada ( ) {
        return simbolosDeEntrada;
    }

    //salida: la lista de simbolos de la máquina
    LinkedList<char> getSimbolosDeMaquina ( ) {
        return simbolosDeMaquina;
    }

    //salida: la lista de transiciones
    LinkedList<Transicion> getTransiciones ( ) {
        return transiciones;
    }

    //entrada: un string del nombre del estado inicial de la máquina
    void setEstadoInicial(string pEstadoInicial) {
        estadoInicial = pEstadoInicial;
    }

    //salida: un string con el nombre del estado inicial
    string getEstadoInicial ( ) {
        return estadoInicial;
    }

    //entrada: toma un string con el caracter en blanco y lo asigna
    void setCaracterBlanco(string pCaracterBlanco) {
        caracterBlanco = pCaracterBlanco;
    }

    //salida: devuelve como char al caracter en blanco
    char getCaracterBlanco ( ) {
        return caracterBlanco.at(0);
    }

    //salida: la lista con los nombres de los estados de aceptación
    LinkedList<string> getEstadosAceptacion ( ) {
        return estadosAceptacion;
    }

    //salida: la lista con los nombres de los estados de rechazo
    LinkedList<string> getEstadosRechazo ( ) {
        return estadosRechazo;
    }

};

#endif // VIRTUALTURINGMACHINE_H
