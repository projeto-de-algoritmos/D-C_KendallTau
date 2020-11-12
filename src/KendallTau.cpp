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

void contar(vector <int> &array){
     vector <int> esq, dir; 
    for(int i=0;i < (int)array.size()/2; i++)
        esq.push_back(array[i]); 
    for(int i=array.size()/2+1; i< (int)array.size()/2; i++)
        dir.push_back(array[i]); 
    
}

void KendallTau::calcularDistancia(){
    int inversoes = ContarInversoes(posicoes); 
    cout << "A distância tau de Kendall é de " << inversoes << endl; 
}

int KendallTau::ContarInversoes(vector <int> &array){
    int tamanho = array.size(); 
    if(tamanho == 1)
        return 0; 
    vector <int> A,B;
    dividir(A,B,array); 
    
    int invA = ContarInversoes(A); 
    int invB = ContarInversoes(B);
    int inv = mergeAndCount(A,B, array);
    return (inv+invA+invB); 
}

void KendallTau::dividir(vector <int> &A, vector <int> &B, vector <int> &array){
    for(int i = 0; i < (int)array.size()/2; i++){
        A.push_back(array[i]);
    }
    for(int i = array.size()/2; i< (int)array.size(); i++){
        B.push_back(array[i]);
    }
}

int KendallTau::mergeAndCount(vector <int> &array1, vector <int> &array2, vector <int> &array){
    vector <int> aux; 
    int ini1 = 0, ini2 = 0, inv = 0, tamanho = array1.size(); 
    array1.push_back(INT_MAX); 
    array2.push_back(INT_MAX); 
    for(int i=0; i< (int)array.size(); i++){
        if(array1[ini1] <= array2[ini2]){
            aux.push_back(array1[ini1]); 
            ini1++;
        }
        else{
            aux.push_back(array2[ini2]);
            ini2++; 
            inv+= (tamanho - ini1); 
        }
    }
    
    array = aux; 
    return inv; 
}


void KendallTau::limparDados() {
    lista.clear();
    lista2.clear();
    posicoes.clear();
}
