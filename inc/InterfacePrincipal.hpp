#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include <iostream>

using namespace std;

class InterfacePrincipal {
public:
    void menuPrincipal();
    void cadastrarListas();
    void adicionarElemento();
    void calcularDistancia();
    int getInt(string mensagem, int min, int max);
};

#endif
