#ifndef KENDALLTAU_HPP
#define KENDALLTAU_HPP

#include <iostream>
#include <vector>


using namespace std;

class KendallTau {
private:
    vector <int> lista;
    vector <int> posicoes;
public:
    bool adicionarElemento(int elemento);
    bool temElemento(int elemento);
    bool adicionarPosicao(int elemento, int posicao);
    void imprimirListas(); 
    void limparDados();
};

#endif
