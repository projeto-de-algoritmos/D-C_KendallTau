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

void KendallTau::ContarInversoes(){
}

void KendallTau::limparDados() {
    lista.clear();
    lista2.clear();
    posicoes.clear();
}
