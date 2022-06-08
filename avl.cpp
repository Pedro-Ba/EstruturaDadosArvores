#include <cstdlib>
#include "avl.h"
#include "lista.h" //pra usar carros.

using namespace std;
//inicio das funcoes Arvore AVL.

AVL::AVL(){
    node = NULL;
    esq = dir = NULL;
    altura = 0;
}
 
AVL::AVL(No *nod){
    node = nod;
    esq = dir = NULL;
    altura = 1; //adiciona em folha primariamente...
}

int AVL::retornaAltura(AVL *Raiz){
    if (Raiz == NULL)
        return 0;
    return Raiz->altura;
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

AVL* AVL::RotacionaDireita(AVL* Raiz){
    AVL *aux = Raiz->esq;
    AVL *aux2 = aux->dir;
    aux->dir = Raiz;
    Raiz->esq = aux2;
    //atualizacao de altura
    Raiz->altura = max(retornaAltura(Raiz->esq), retornaAltura(Raiz->dir)) + 1;
    aux->altura = max(retornaAltura(aux->esq), retornaAltura(aux->dir)) + 1;
    // Return new root
    return aux;
}

AVL* AVL::RotacionaEsquerda(AVL* Raiz){
    AVL *aux = Raiz->dir;
    AVL *aux2 = aux->esq;
    aux->esq = Raiz;
    Raiz->dir = aux2;
    //atualiza alturas
    Raiz->altura = max(retornaAltura(Raiz->esq), retornaAltura(Raiz->dir)) + 1;
    aux->altura = max(retornaAltura(aux->esq), retornaAltura(aux->dir)) + 1;
    return aux;
}

int AVL::fatorBalanceamento(AVL *Raiz){
    if (Raiz == NULL){
        return 0;
    }
    return retornaAltura(Raiz->esq) - retornaAltura(Raiz->dir);
}

AVL* AVL::insert(AVL* Raiz, No* node){
    if (Raiz == NULL){
        return new AVL(node);
    }
    if (node->dado->placa < Raiz->node->dado->placa){
        Raiz->esq = insert(Raiz->esq, node);
    }
    else if (node->dado->placa > Raiz->node->dado->placa){
        Raiz->dir = insert(Raiz->dir, node);
    }
    else{
        return Raiz;
    }
    //atualiza altura...
    Raiz->altura = 1 + max(retornaAltura(Raiz->esq), retornaAltura(Raiz->dir));
    //verifica balanceamento do no
    int fatorBalanceament = fatorBalanceamento(Raiz);
    // roda direita..
    if (fatorBalanceament > 1 && node->dado->placa < Raiz->esq->node->dado->placa)
        return RotacionaDireita(Raiz);
    // roda esquerda..
    if (fatorBalanceament < -1 && node->dado->placa > Raiz->dir->node->dado->placa)
        return RotacionaEsquerda(Raiz);
    // roda esq->dir
    if (fatorBalanceament > 1 && node->dado->placa > Raiz->esq->node->dado->placa)
    {
        Raiz->esq = RotacionaEsquerda(Raiz->esq);
        return RotacionaDireita(Raiz);
    }
    // e roda dir->esq
    if (fatorBalanceament < -1 && node->dado->placa < Raiz->dir->node->dado->placa)
    {
        Raiz->dir = RotacionaDireita(Raiz->dir);
        return RotacionaEsquerda(Raiz);
    }
    return Raiz;
}

void AVL::Preordem(AVL* raiz){
    if (!raiz) {
        return;
    }
    cout << raiz->node->dado->placa << endl;
    Preordem(raiz->esq);
    Preordem(raiz->dir);
}

AVL* AVL::removeNo(AVL* raiz, string placa){
    if (raiz == NULL){
        return raiz;
    }
    if (raiz->node->dado->placa > placa) {
        raiz->esq = removeNo(raiz->esq, placa);
    }
    else if (raiz->node->dado->placa < placa) {
        raiz->dir = removeNo(raiz->dir, placa);
    }
    else{
        if (raiz->esq == NULL && raiz->dir == NULL) {//n tem filho
            AVL* temp = raiz;
            raiz = NULL;
        }
        else if(raiz->esq == NULL){ //filho esquerda é nulo
            AVL* temp = raiz->dir;
            delete raiz;
            return temp;
        }
        else if (raiz->dir == NULL) {
            AVL* temp = raiz->esq;
            delete raiz;
            return temp;
        }
        else {
            AVL* paiDoFilhoDireitoMinimo = raiz;
            AVL* filhoDireitoMinimo = raiz->dir;
            while (filhoDireitoMinimo->esq != NULL) {
                paiDoFilhoDireitoMinimo = filhoDireitoMinimo;
                filhoDireitoMinimo = filhoDireitoMinimo->esq;
            }
            if (paiDoFilhoDireitoMinimo != raiz){
                paiDoFilhoDireitoMinimo->esq = filhoDireitoMinimo->dir;
            }
            else{
                paiDoFilhoDireitoMinimo->dir = filhoDireitoMinimo->dir;
            }
            raiz->node->dado->placa = filhoDireitoMinimo->node->dado->placa;
            delete filhoDireitoMinimo;
        }
    } 
    //se caso base...
    if (raiz == NULL){
        return raiz;
    }
    //recalcula altura
    raiz->altura = 1 + max(retornaAltura(raiz->esq), retornaAltura(raiz->dir));
    int fatorBalanceament = fatorBalanceamento(raiz);
    //verifica o fator balanceamento novo do no atual e o fator dos filhos, o que gera quatro casos:  
    //roda direita
    if (fatorBalanceament > 1 && fatorBalanceamento(raiz->esq) >= 0){
        return RotacionaDireita(raiz);
    }
    // esq->dir roda
    if (fatorBalanceament > 1 && fatorBalanceamento(raiz->esq) < 0){
        raiz->esq = RotacionaEsquerda(raiz->esq);
        return RotacionaDireita(raiz);
    }
    // roda esquerda
    if (fatorBalanceament < -1 && fatorBalanceamento(raiz->dir) <= 0){
        return RotacionaEsquerda(raiz);
    }
    // e roda direta e dps roda esq
    if (fatorBalanceament < -1 && fatorBalanceamento(raiz->dir) > 0){
        raiz->dir = RotacionaDireita(raiz->dir);
        return RotacionaEsquerda(raiz);
    }
    //retorna o nó só dps do rebalanceamento completo.
    return raiz;
}

void AVL::destroiArvore(AVL* raiz){ //fiz um destrutor próprio pq a recursividade estava dificil no destrutor padrão do cpp...
    if(raiz != NULL){
        if(raiz->dir != NULL){
            destroiArvore(raiz->dir);
        }
        if(raiz->esq != NULL){
            destroiArvore(raiz->esq);
        }
        delete raiz;
    }
}

AVL* AVL::busca(AVL* raiz, string placa){
    //retorna null se o valor não for encontrado
    //caso contrário, retorna o nó contendo o valor
    if(raiz == NULL ||raiz->node->dado->placa == placa){
        if(raiz != NULL){ 
            cout << "\nEM AVL, ENCONTRADO: ";
            cout << raiz->node->dado->placa;
        }
        return raiz;
    }
    if(raiz->node->dado->placa > placa){
        return busca(raiz->esq, placa);
    }else{
        return busca(raiz->dir, placa);
    }
}