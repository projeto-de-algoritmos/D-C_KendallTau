#include "KendallTau.hpp"

void KendallTau::adicionarElemento(int elemento) {
    lista.push_back(elemento);
    posicoes.resize(lista.size());
}

void KendallTau::adicionarPosicao(int elemento, int posicao) {
    for(int i = 0; i < (int)lista.size(); i++) {
        if(lista[i] == elemento) {
            posicoes[i] = posicao;
            return;
        }
    }
}

void KendallTau::limparDados() {
    lista.clear();
    posicoes.clear();
}
