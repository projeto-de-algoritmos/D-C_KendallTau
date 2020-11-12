#include "KendallTau.hpp"

#include <limits.h>

using namespace std; 

bool KendallTau::adicionarElemento(int elemento) {
    if(temElemento(elemento, lista))
        return false;
    lista.push_back(elemento);
    return true;
}

bool KendallTau::temElemento(int elemento, vector <int> listaX) {
    for(int i = 0; i < (int)listaX.size(); i++) {
        if(listaX[i] == elemento)
            return true;
    } 
    return false;
}

bool KendallTau::adicionarPosicao(int elemento) {
    for(int i = 0; i < (int)lista.size(); i++) {
        if(lista[i] == elemento) {
            if(temElemento(elemento, lista2))
                return false; 
            posicoes.push_back(i);
            lista2.push_back(elemento);
            return true;
        }
    }
    return false;
}

void KendallTau::imprimirListas(){
    if(lista.empty()){
        cout << "lista vazia" << endl; 
        return;
    }
    vector <bool> adicionarEspaco(lista.size(), false); 
    vector <int> espacos; 
    gerarEspacos(espacos, adicionarEspaco); 
    for(int i = 0; i< (int)lista.size(); i++){
        if(adicionarEspaco[i])
            cout << setw(espacos[i] + to_string(lista[i]).length());
        cout << lista[i] << " "; 
    }
    cout << endl; 
    for(int i = 0; i< (int)lista.size(); i++){
        if(!adicionarEspaco[i])
            cout << setw(espacos[i] + to_string(lista2[i]).length());
        cout << lista2[i] << " "; 
    }
    cout << endl;
}

void KendallTau::gerarEspacos(vector <int> &espacos, vector <bool> &adicionarEspaco){
     for(int i = 0; i< (int)lista.size(); i++){
        int tam1 = to_string(lista[i]).length();
        int tam2 = to_string(lista2[i]).length();
        if(tam2 > tam1){
            adicionarEspaco[i] = true;
            espacos.push_back((tam2-tam1));
        }
        else
            espacos.push_back(tam1 - tam2); 
    }
}

void KendallTau::limparDados() {
    lista.clear();
    lista2.clear();
    posicoes.clear();
}

int KendallTau::obterDistancia() {
    qtDeInversoes = 0;
    listaOrdenada = lista;
    posicoesOrdenadas = posicoes;
    mergesort(0, listaOrdenada.size() - 1);
    return qtDeInversoes;
}

void KendallTau::mergesort(int inicio, int fim) {
    if(fim > inicio) {
        mergesort(inicio, (fim + inicio) / 2);
        mergesort((fim + inicio) / 2 + 1, fim);
        mergeCount(inicio, (fim + inicio) / 2, (fim + inicio) / 2 + 1, fim);
    }
}

void KendallTau::mergeCount(int inicioA, int fimA, int inicioB, int fimB) {
    vector <int> listaOrdenada;
    vector <int> posicoesOrdenadas;
    int indiceA = inicioA, indiceB = inicioB;
    int total = fimB - inicioA + 1;
    for(int i = 0; i < total; i++) {
        if(indiceA > fimA) {
            listaOrdenada.push_back(this->listaOrdenada[indiceB]);
            posicoesOrdenadas.push_back(this->posicoesOrdenadas[indiceB]);
            indiceB++;
        } else if(indiceB > fimB) {
            listaOrdenada.push_back(this->listaOrdenada[indiceA]);
            posicoesOrdenadas.push_back(this->posicoesOrdenadas[indiceA]);
            indiceA++;
        } else if(this->posicoesOrdenadas[indiceA] < this->posicoesOrdenadas[indiceB]) {
            listaOrdenada.push_back(this->listaOrdenada[indiceA]);
            posicoesOrdenadas.push_back(this->posicoesOrdenadas[indiceA]);
            indiceA++;
        } else {
            listaOrdenada.push_back(this->listaOrdenada[indiceB]);
            posicoesOrdenadas.push_back(this->posicoesOrdenadas[indiceB]);
            indiceB++;
            qtDeInversoes += fimA - indiceA + 1;
        }
    }
    int indice = inicioA;
    for(int i = 0; i < (int)listaOrdenada.size(); i++) {
        this->listaOrdenada[indice] = listaOrdenada[i];
        this->posicoesOrdenadas[indice] = posicoesOrdenadas[i];
        indice++;
    }
}
