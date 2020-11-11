#ifndef KENDALLTAU_HPP
#define KENDALLTAU_HPP

#include <vector>

using namespace std;

class KendallTau {
private:
    vector <int> lista;
    vector <int> posicoes;
public:
    void adicionarElemento(int elemento);
    void adicionarPosicao(int elemento, int posicao);
    void limparDados();
};

#endif
