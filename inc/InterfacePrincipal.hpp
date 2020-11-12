#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "KendallTau.hpp"

#include <iostream>

using namespace std;

class InterfacePrincipal {
private:
    KendallTau kendallTau;
public:
    void menuPrincipal();
    void cadastrarListas();
    void verListas();
    void gerarListas();
    void calcularDistancia();
    void spam(string mensagem); 
    int getInt(string mensagem, int min, int max);
};

#endif
