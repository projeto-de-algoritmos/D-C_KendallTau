#include "InterfacePrincipal.hpp"

#include <limits.h>

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Cadastrar novas listas" << endl;
        cout << "(2) Adicionar novo elemento às listas" << endl;
        cout << "(3) Ver listas" << endl;
        cout << "(4) Calcular a distância tau de Kendall" << endl;
        cout << "(0) Finalizar" << endl;
        int opcao = getInt("", 0, 4);
        if(opcao == 1)
            cadastrarListas();
        else if(opcao == 2)
            adicionarElemento();
        else if(opcao == 3)
            verListas();
        else if(opcao == 4)
            calcularDistancia();
        else
            return;
    }
}

void InterfacePrincipal::cadastrarListas() {
    kendallTau.limparDados();
    int tamanho = getInt("Tamanho do conjunto de elementos: ", 1, INT_MAX);
    cout << "Lista 1" << endl;
    for(int i = 0; i < tamanho; i++) {
        int elemento = getInt("Elemento " + to_string(i + 1) + ": ", INT_MIN, INT_MAX);
        if(!kendallTau.adicionarElemento(elemento)) {
            cout << "Esse elemento já foi incluído nessa lista" << endl;
            i--;
        }
    }
    cout << "Lista 2" << endl;
    for(int i = 0; i < tamanho; i++) {
        int elemento = getInt("Elemento " + to_string(i + 1) + ": ", INT_MIN, INT_MAX);
        if(!kendallTau.adicionarPosicao(elemento, i)) {
            cout << "Esse elemento não faz parte do conjunto ou já foi incluído nessa lista" << endl;
            i--;
        }
    }
}

void InterfacePrincipal::adicionarElemento() {

}

void InterfacePrincipal::verListas() {
    kendallTau.imprimirListas(); 
}

void InterfacePrincipal::calcularDistancia() {

}

int InterfacePrincipal::getInt(string mensagem, int min, int max) {
    int valor;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> valor;
        if(cin.fail() || valor > max || valor < min) {
            cin.clear();
            cout << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return valor;
}
