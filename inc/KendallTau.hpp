#ifndef KENDALLTAU_HPP
#define KENDALLTAU_HPP

#include <iostream>
#include <vector>
#include <iomanip> 

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
    void gerarEspacos(vector <int> &espacos, vector <bool> &adicionarEspaco); 
    void limparDados();
};

#endif
