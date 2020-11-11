#include "InterfacePrincipal.hpp"

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Cadastrar novas listas" << endl;
        cout << "(2) Adicionar novo elemento às listas" << endl;
        cout << "(3) Calcular a distância tau de Kendall" << endl;
        cout << "(0) Finalizar" << endl;
        int opcao = getInt("", 0, 3);
        if(opcao == 1)
            cadastrarListas();
        else if(opcao == 2)
            adicionarElemento();
        else if(opcao == 3)
            calcularDistancia();
        else
            return;
    }
}

void InterfacePrincipal::cadastrarListas() {

}

void InterfacePrincipal::adicionarElemento() {

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
