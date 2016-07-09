#ifndef VTM_INDETERMINATION_ERROR_H
#define VTM_INDETERMINATION_ERROR_H

using std::runtime_error;

/*
Autor: Daniel Ulate
creado: 12/11/14
*/

//se lanzaen el caso en el que se reciba un símbolo con el que
//no se sabe que hacer en el estado actual de la máquina
class vtm_indetermination_error : public std::runtime_error
{
    public:
        vtm_indetermination_error(string msg) : runtime_error(msg) {
        }
};

#endif // VTM_INDETERMINATION_ERROR_H
