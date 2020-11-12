#ifndef KENDALLTAU_HPP
#define KENDALLTAU_HPP

#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class KendallTau {
private:
    vector <int> posicoes;
    vector <int> lista;
    vector <int> lista2; 
    vector <int> listaOrdenada;
    vector <int> posicoesOrdenadas;
    int qtDeInversoes;
public:
    bool adicionarElemento(int elemento);
    bool temElemento(int elemento, vector<int> listaX);
    bool adicionarPosicao(int elemento);
    void imprimirListas(); 
    void gerarEspacos(vector <int> &espacos, vector <bool> &adicionarEspaco); 
    void limparDados();
    int obterDistancia();
    void mergesort(int first, int last);
    void mergeCount(int inicioA, int fimA, int inicioB, int fimB);
    int getElemento(int i); 
};

#endif
