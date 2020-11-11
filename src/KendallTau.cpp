#include "KendallTau.hpp"

bool KendallTau::adicionarElemento(int elemento) {
    if(temElemento(elemento))
        return false;
    lista.push_back(elemento);
    posicoes.resize(lista.size(), -1);
    return true;
}

bool KendallTau::temElemento(int elemento) {
    for(int i = 0; i < (int)lista.size(); i++) {
        if(lista[i] == elemento)
            return true;
    }
    return false;
}

bool KendallTau::adicionarPosicao(int elemento, int posicao) {
    for(int i = 0; i < (int)lista.size(); i++) {
        if(lista[i] == elemento) {
            if(posicoes[i] == -1) {
                posicoes[i] = posicao;
                return true;
            } else
                return false;
        }
    }
    return false;
}

void KendallTau::limparDados() {
    lista.clear();
    posicoes.clear();
}
