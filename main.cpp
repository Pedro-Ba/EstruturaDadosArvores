#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "lista.h"
#include <string>
#include <vector>
#include <algorithm>
#include "abb.h"
#include "avl.h"

using namespace std;

int main(int argc, char** argv) {
    Lista *carros = new Lista();
    //declaração da arvore binaria de busca, e da raiz
    ABB arvorebb, *rootbb = NULL;
    AVL arvoreavl, *rootavl = NULL;
    ifstream cadastro ("carros.txt");
    if (cadastro.is_open() && !cadastro.eof()){
        int i = 0;
        No *novo = new No();
        carros->inicio = novo;
        carros->fim = novo;
        carros->qtde = 1;
        novo->dado = new Carro();
        //# modelo marca tipo ano km potência_do_motor combustível câmbio direção cor portas placa
        cadastro >> novo->dado->modelo;
        cadastro >> novo->dado->marca;
        cadastro >> novo->dado->tipo;
        cadastro >> novo->dado->ano;
        cadastro >> novo->dado->km;
        cadastro >> novo->dado->potenciamotor;
        cadastro >> novo->dado->combustivel;
        cadastro >> novo->dado->cambio;
        cadastro >> novo->dado->direcao;
        cadastro >> novo->dado->cor;
        cadastro >> novo->dado->portas;
        cadastro >> novo->dado->placa;
        novo->prox = NULL;
        //inicio da ABB : não tem pq esperar terminar de inserir tudo pra aí percorrer a lista e ir inserindo na árvore binária, salva tempo se inserir em conjunto...
        rootbb = arvorebb.Insert(rootbb, novo);
        rootavl = arvoreavl.insert(rootavl, novo);
        //insere o nó inteiro nas árvores (nós não vamos utilizar o .prox do nó
        //então sinceramente seria melhor inserir só o carro mas já que foi assim que o professor pediu...
       //loop pra outros cadastros, inserindo sempre no fim (ou seja, na ordem do arquivo!)
        while (!cadastro.eof() ){
            No *novo = new No();
            carros->qtde++;
            novo->dado = new Carro();
            cadastro >> novo->dado->modelo;
            cadastro >> novo->dado->marca;
            cadastro >> novo->dado->tipo;
            cadastro >> novo->dado->ano;
            cadastro >> novo->dado->km;
            cadastro >> novo->dado->potenciamotor;
            cadastro >> novo->dado->combustivel;
            cadastro >> novo->dado->cambio;
            cadastro >> novo->dado->direcao;
            cadastro >> novo->dado->cor;
            cadastro >> novo->dado->portas;
            cadastro >> novo->dado->placa;
            carros->inserefim(novo, &carros->inicio);
            arvorebb.Insert(rootbb, novo);
            rootavl = arvoreavl.insert(rootavl, novo);
            //mesma coisa acima.
            i++;
        }
        cadastro.close();
    }
    else
        cout << "Arquivo não encontrado."; 

    int escolha;
    string placa, valorstring;
    float valorfloat;
    int preordemarvore = 0;
    Lista *resultadobusca = new Lista();
    Lista *resultadobuscaparcial = new Lista();
    //loop de menu de usuário
    while (escolha != 6){
        escolha = 0;
        cout << "\n\n\n\n\n\n\nBem vindo ao nosso sistema de buscas de carros. ---------------------------------------------------\n";
        cout << "Por favor, escolha uma das seguintes opcoes: \n";
        cout << "1. Buscar por um carro baseado em alguma caracteristica;\n";
        cout << "2. Relatorio total de todos os carros atualmente dispostos no nosso sistema;\n";
        cout << "3. Relatorio das arvores em preordem;\n";
        cout << "4. Inserir um novo carro;\n";
        cout << "5. Remover um carro da lista;\n";
        cout << "6. Saida: \n";
        cin >> escolha;
        if (escolha == 1){
            cout << "Digite a placa do carro que deseja buscar: \n";
            cin >> valorstring;
            arvoreavl.busca(rootavl, valorstring);
            arvorebb.busca(rootbb, valorstring);
            resultadobusca = carros->busca(valorstring, 1, 0, 0, 12);
            cout << "\nNA LISTA:\n";
            resultadobusca->imprimelista(resultadobusca->inicio);
            
        }
        if (escolha == 2){
            //relatório final de todos os carros em ordem.
            carros->imprimelista(carros->inicio);
        }
        if (escolha == 3){
            cout << "Digite 1 para a pre-ordem da arvore binaria de busca, e 2 para a pre-ordem da AVL.\n";
            cout << "Digite qualquer outro valor numerico para voltar para o menu: \n";
            cin >> preordemarvore;
            if (preordemarvore == 1) arvorebb.Preordem(rootbb);
            if (preordemarvore == 2) arvoreavl.Preordem(rootavl);
        }
        if (escolha == 4){
            //inserir novo carro - simples; ver inicio do código para entender.
            No *novo = new No();
            carros->qtde++;
            novo->dado = new Carro();
            cout << "\nPor favor, digite os dados requeridos do carro: ";
            cout << "\nModelo: ";
            cin >> novo->dado->modelo;
            cout << "\nMarca: ";
            cin >> novo->dado->marca;
            cout << "\nTipo: ";
            cin >> novo->dado->tipo;
            cout << "\nAno: ";
            while(!(cin >> novo->dado->ano)){
                cout << "\nEsse valor nao e valido. Insira um valor numerico inteiro.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nAno: ";
            }
            cout << "\nKm: ";
            while(!(cin >> novo->dado->km)){
                cout << "\nEsse valor nao e valido. Insira um valor numerico inteiro.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nKm: ";
            }
            cout << "\nPotencia do motor: ";
            while(!(cin >> novo->dado->potenciamotor)){
                cout << "\nEsse valor nao e valido. Insira um valor numerico.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPotencia do motor: ";
            }
            cout << "\nCombustivel: ";
            cin >> novo->dado->combustivel;
            cout << "\nCambio: ";
            cin >> novo->dado->cambio;
            cout << "\nDirecao: ";
            cin >> novo->dado->direcao;
            cout << "\nCor: ";
            cin >> novo->dado->cor;
            cout << "\nPortas: ";
            while(!(cin >> novo->dado->portas)){
                cout << "\nEsse valor nao e valido. Insira um valor numerico inteiro.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPortas: ";
            }
            cout << "\nPlaca: ";
            cin >> novo->dado->placa;
            carros->inserefim(novo, &carros->inicio);
            arvorebb.Insert(rootbb, novo); //insere o carro na árvore de busca binária...
            rootavl = arvoreavl.insert(rootavl, novo);
        }
        if (escolha == 5){
            //remove um nó da lista pela placa que é a chave principal
            cout << "\nPor favor, digite a placa do carro que deseja excluir: ";
            cin >> placa;
            //como o carro vai ser removido da lista principal, devemos retirá-lo da árvore para não ocorrer erro. Afinal, o nó será excluído
            //da lista principal, e portanto não existirá mais esse nó!
            //Portanto, devemos rebalancear as árvores ANTES de excluir o nó da lista - se não perderemos o acesso daquela posição na memória, pois é o mesmo nó!
            //Então, rebalancearemos a árvore buscando pelo valor da PLACA desse nó, e aí vamos removê-lo. 
            //Após isso, vamos removê-lo da lista, e DELETÁ-LO da memória!
            rootbb = arvorebb.removeNo(rootbb, placa);
            rootavl = arvoreavl.removeNo(rootavl, placa);
            carros->removeno(placa, &carros->inicio);
            //como o carro foi removido da lista principal, devemos retirá-lo da árvore para não ocorrer erro. Afinal, o nó será excluído
            //da lista principal, e portanto não existirá mais esse nó!
        }
    }
    delete carros;
    arvorebb.destroiArvore(rootbb);
    arvoreavl.destroiArvore(rootavl);
    return 0;
}
