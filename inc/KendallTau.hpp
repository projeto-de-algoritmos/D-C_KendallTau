#ifndef KENDALLTAU_HPP
#define KENDALLTAU_HPP

#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class KendallTau {
private:
    vector <int> lista;
    vector <int> lista2;
    vector <int> posicoes;
public:
    bool adicionarElemento(int elemento);
    bool temElemento(int elemento, vector<int>lista);
    bool adicionarPosicao(int elemento);
    void imprimirListas(); 
    void gerarEspacos(vector <int> &espacos, vector <bool> &adicionarEspaco); 
    void calcularDistancia();
    void limparDados();
};

#endif
