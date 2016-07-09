#include "VirtualTuringMachine.h"
#include "Transicion.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Autora: Gabriela Garro
Fecha de creación: 08/11/14

Clase LectorDeArchivos

Descripción: Toma el nombre de un archivo de texto, lo lee
línea por línea y dependiendo del primer caracter de ésta,
delega a sus otros métodos el manejo de esa línea.

Objetivo: Introducir de una forma lógica las características
que conforman la definición formal de una máquina de Turing
en la clase VirtualTuringMachine.
*/
class LectorDeArchivos
{
private:
    VirtualTuringMachine maquinaTuring;

    //Carga los estados de la maquina en una lista enlazada dentro
    //del objeto maquinaTuring
    //entrada: Un string con los estados separados por coma (,)
    void cargarEstados(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2); //quita los primeros 2 caracteres
        string estado;
        for (unsigned int i=0; i < laLinea.length(); i++) {
            char caracterLeido = laLinea.at(i);
            if (caracterLeido != ',') {
                estado += caracterLeido;
            }
            else {
                maquinaTuring.appendEstado(estado);
                estado = "";
            }
        }
        maquinaTuring.appendEstado(estado);
    }

    //asume que los simbolos son un solo caracter, separados por comas
    //carga en maquinaTuring los simbolos de entrada
    //entrada: un string con los simbolos separados por coma
    void cargarSimbolosEntrada(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2);
        char caracterLeido;
        for (unsigned int i=0; i < laLinea.length(); i++) {
            caracterLeido = laLinea.at(i);
            if (caracterLeido != ',') {
                maquinaTuring.appendSimboloEntrada(caracterLeido);
            }
        }
    }

    //asume que los simbolos son de un caracter
    //carga en maquinaTuring los simbolos que usará la máquina
    //entrada: un string con los simbolos separados por coma
    void cargarSimbolosMaquina(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2);
        char caracterLeido;
        for (unsigned int i=0; i < laLinea.length(); i++) {
            caracterLeido = laLinea.at(i);
            if (caracterLeido != ',') {
                maquinaTuring.appendSimboloMaquina(caracterLeido);
            }
        }
    }

    //agrega una transicion a la lista de transiciones de maquinaTuring
    //entrada: un string que define una transición, con sus 5 elementos
    //en el siguiente orden: una: estado origen, carácter leído, estado
    //destino, carácter escrito, movimiento de la cabeza
    void cargarTransicion(string pLinea) {
        Transicion transicion = Transicion();
        string laLinea = pLinea;
        laLinea.erase(0,2);
        char caracterLeido;
        int asignadorDeMetodo = 0;
        string elemento = "";
        for (unsigned int i=0; i < laLinea.length(); i++) {
            caracterLeido = laLinea.at(i);
            if (caracterLeido != ',') {
                elemento += caracterLeido;
            }
            else {
                //TO DO: crear un enum {estadoOrigen = 0, estadoDestino = 1, etc}
                //y cambiar esta estructura por un switch case
                if (asignadorDeMetodo == 0) {
                    transicion.setEstadoOrigen(elemento);
                }
                else if (asignadorDeMetodo == 2) {
                    transicion.setEstadoDestino(elemento);
                }
                else if (asignadorDeMetodo == 1) {
                    transicion.setCaracterLeido(elemento);
                }
                else if (asignadorDeMetodo == 3) {
                    transicion.setCaracterEscrito(elemento);
                }
                /*else if (asignadorDeMetodo == 4) {
                    transicion.setMovimientoCabeza(elemento);
                }*/
                //else: esta malo el texto
                elemento = "";
                asignadorDeMetodo++;
            }
            transicion.setMovimientoCabeza(elemento);
        }
        maquinaTuring.appendTransicion(transicion);
    }

    //define en maquinaTuring el estado inicial
    //entrada: un string con el nombre del estado inicial
    void cargarEstadoInicial(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2);
        maquinaTuring.setEstadoInicial(laLinea);
    }

    //define en maquinaTuring el caracter en blanco de la maquina
    //entrada: un string que contiene sin comas el caracter en blanco
    void cargarCaracterBlanco(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2);
        maquinaTuring.setCaracterBlanco(laLinea);
    }

    //agregar un estado de aceptacion a maquinaTuring
    //entrada: un string con los estados de aceptación separados por comas
    void cargarEstadosAceptacion(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2);
        char caracterLeido;
        string estado = "";
        for (unsigned int i = 0; i < laLinea.length(); i++) {
            caracterLeido = laLinea.at(i);
            if (caracterLeido == ',') {
                maquinaTuring.appendEstadoAceptacion(estado);
                estado = "";
            }
            else {
                estado += caracterLeido;
            }
        }
        maquinaTuring.appendEstadoAceptacion(estado);
    }


    //agregar un estado de rechazo a maquinaTuring
    //entrada: un string con los estados de rechazo separados por comas
    void cargarEstadosRechazo(string pLinea) {
        string laLinea = pLinea;
        laLinea.erase(0,2);
        char caracterLeido;
        string estado = "";
        for (unsigned int i = 0; i < laLinea.length(); i++) {
            caracterLeido = laLinea.at(i);
            if (caracterLeido != ',') {
                estado += caracterLeido;
            }
            else {
                maquinaTuring.appendEstadoRechazo(estado);
                estado = "";
            }
        }
        maquinaTuring.appendEstadoRechazo(estado);
    }

public:
    LectorDeArchivos(){}

    //lee el archivo y delega llenar las características de la máquina de Turing
    //a sus métodos privados.
    //entrada: un string con el nombre del archivo, sin extensión
    void leerArchivo(string pFileName) throw (runtime_error){
        ifstream file(pFileName.c_str());
        file.open((pFileName+".txt").c_str());
        string linea;
        while (getline(file,linea)) { //pone los contenidos de esa linea en linea
            char primerCaracter = linea.at(0);
            switch (primerCaracter) {
                case 'Q':
                    cargarEstados(linea);
                    break;
                case 'S':
                    cargarSimbolosEntrada(linea);
                    break;
                case 'G':
                    cargarSimbolosMaquina(linea);
                    break;
                case 'T':
                    cargarTransicion(linea);
                    break;
                case 'I':
                    cargarEstadoInicial(linea);
                    break;
                case 'B':
                    cargarCaracterBlanco(linea);
                    break;
                case 'F':
                    cargarEstadosAceptacion(linea);
                    break;
                case 'R':
                    cargarEstadosRechazo(linea);
                    break;
                default:
                    throw runtime_error("Encabezado de linea incorrecto en el archivo");
            }
        }
        file.close();
    }

    //salida: devuelve el objeto de maquinaTuring
    VirtualTuringMachine* getVirtualMachine(){
        return &maquinaTuring;
    }
};
