#ifndef VIRTUALTURINGMACHINE_H
#define VIRTUALTURINGMACHINE_H
#include "LinkedList.h"
#include "Transicion.h"
#include "Tira.h"
#include "vtm_indetermination_error.h"
#include <stdexcept>
/*
Autora: Gabriela Garro
Fecha de creación: 08/11/14

Clase VirtualTuringMachine

Descripción: Sirve de contenedor lógico para los elementos que
describen formalmente a una máquina de Turing

Objetivo: Contener fácilmente en listas enlazadas y en sus atributos
las características de una máquina de Turing
*/
using namespace std;

class Graph;

class VirtualTuringMachine
{
private:
    LinkedList<string> estados; //Q
    LinkedList<string> simbolosDeEntrada; //S
    LinkedList<string> simbolosDeMaquina; //G
    LinkedList<Transicion> transiciones; //T
    string estadoInicial; //I
    string caracterBlanco; //B
    LinkedList<string> estadosAceptacion; //F
    LinkedList<string> estadosRechazo; //R
    string estadoActual;
    Tira* tira;
    Graph* grafo;

public:
    VirtualTuringMachine();

    void dibujar();

    //termina el funcionamiento de la máquina
    void stop(string, string) throw (vtm_indetermination_error, runtime_error);

    //incializa el grafo una vez que se han cargado todos los datos del
    //archivo en la maquina de turing
    void init();

    //se encarga de "dar un paso" en la máquina de VirtualTuringMachine
    //lee el caracter, escribe, se mueve y pasa de estado
    void step() throw (std::runtime_error);

    //inicializa el atributo tira de la maquina.
    void cargarTira(Tira* pTira) throw (std::runtime_error);

    //retorna un string con el estado actual de la máquina
    //y el símbolo actual en la tira.
    void getCurrentStatus();

    //agrega un estado de la máquina
    //entrada: un string con el nombre del estado
    void appendEstado(string pEstado);

    //salida: la cantidad de estados almacenados para que sea
    //usado en la clase que grafica
    int getCantidadEstados();

    //entrada: un char que representa un símbolo de entrada de la máquina
    void appendSimboloEntrada(string pSimbolo);

    //entrada: un char que representa un símbolo de la máquina
    void appendSimboloMaquina(string pSimbolo);

    //entrada: un objeto transicion que se agrega a la lista de transiciones
    void appendTransicion(Transicion pTransicion);

    //entrada: un string que representa el nombre de un estado
    //se agrega a la lista de estados de aceptación
    void appendEstadoAceptacion(string pEstado) throw (runtime_error);

    //entrada: un string que representa el nombre de un estado
    //se agrega a la lista de estados de rechazo
    void appendEstadoRechazo(string pEstado) throw (runtime_error);

    //salida: retorna la lista de estados
    LinkedList<string>* getEstados ( );

    //salida: retorna la lista de simbolos de entrada
    LinkedList<string> getSimbolosDeEntrada ( );

    //salida: la lista de simbolos de la máquina
    LinkedList<string> getSimbolosDeMaquina ( );

    //salida: la lista de transiciones
    LinkedList<Transicion>* getTransiciones ( );

    //entrada: un string del nombre del estado inicial de la máquina
    void setEstadoInicial(string pEstadoInicial) throw (runtime_error);

    //salida: un string con el nombre del estado inicial
    string getEstadoInicial ( );

    //entrada: toma un string con el caracter en blanco y lo asigna
    void setCaracterBlanco(string pCaracterBlanco);

    //salida: devuelve como char al caracter en blanco
    string getCaracterBlanco ( );

    //salida: la lista con los nombres de los estados de aceptación
    LinkedList<string>* getEstadosAceptacion ( );

    //salida: la lista con los nombres de los estados de rechazo
    LinkedList<string>* getEstadosRechazo ( );

    //retorna el estado actual en el que se ecnuentra la maquina
    string getEstadoActual ( );

    //valida que todos los datos de la transicion
    //sean validos
    void validarTransicion(Transicion* transicion) throw (runtime_error);

    void validarTira(string text) throw (std::runtime_error);

    Transicion* getTransicionEntre(string, string);

    string getTira();

};

#endif // VIRTUALTURINGMACHINE_H
