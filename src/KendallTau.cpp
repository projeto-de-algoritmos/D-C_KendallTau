#include "KendallTau.hpp"

using namespace std; 

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

void KendallTau::imprimirListas(){

    if(lista.empty()){
        cout << "lista vazia" << endl; 
        return;
    }
        vector <bool> adicionarEspaco(lista.size(), false); 
        vector <int> espacos; 
        for(int i = 0; i< (int)lista.size(); i++){
            int tam1 = to_string(lista[i]).length();
            int tam2 = to_string(lista[posicoes[i]]).length();
            if(tam2 > tam1){
                adicionarEspaco[i] = true;
                espacos.push_back((tam2-tam1));
            }
            else
                espacos.push_back(tam1 - tam2); 
        }
        for(int i = 0; i< (int)lista.size(); i++){
            if(adicionarEspaco[i]){
                cout << setw(espacos[i] + to_string(lista[i]).length());
            }
            cout << lista[i] << " "; 
        }
        cout << endl; 
        for(int i = 0; i< (int)lista.size(); i++){
            if(!adicionarEspaco[i])
                cout << setw(espacos[i] + to_string(lista[posicoes[i]]).length());
            cout << lista[posicoes[i]] << " "; 
        }
        cout << endl; 
}

void KendallTau::limparDados() {
    lista.clear();
    posicoes.clear();
}
