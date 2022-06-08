#include <cstdlib>
#include "abb.h"
#include "lista.h" //pra usar carros.

using namespace std;

//inicio dos métodos da Árvore de Busca Binária.
ABB::ABB(){
    node = NULL;
    esq = dir = NULL;
}
 
ABB::ABB(No *nod){
    node = nod;
    esq = dir = NULL;
}
 
ABB* ABB::Insert(ABB* raiz, No *node){
    if (!raiz) {
        return new ABB(node);
    }
    if (node->dado->placa > raiz->node->dado->placa) {
        raiz->dir = Insert(raiz->dir, node);
    }
    else {
        raiz->esq = Insert(raiz->esq, node);
    }
    return raiz;
}
 
void ABB::Preordem(ABB* raiz){
    if (!raiz) {
        return;
    }
    cout << raiz->node->dado->placa << endl;
    Preordem(raiz->esq);
    Preordem(raiz->dir);
}
 
ABB* ABB::removeNo(ABB* raiz, string placa){
    if (raiz == NULL){
        return raiz;
    }
    if (raiz->node->dado->placa > placa) {
        raiz->esq = removeNo(raiz->esq, placa);
        return raiz;
    }
    else if (raiz->node->dado->placa < placa) {
        raiz->dir = removeNo(raiz->dir, placa);
        return raiz;
    }
    else{
        //achou valor, tem que remover...
        if (raiz->esq == NULL) {
            ABB* temp = raiz->dir;
            delete raiz;
            return temp;
        }
        else if (raiz->dir == NULL) {
            ABB* temp = raiz->esq;
            delete raiz;
            return temp;
        }
        else {
            //iterativamente encontra o pai do menor valor da subárvore direita, substitui o valor do menor da sub direita pro valor deletado,
            //e rearranja a arvore.
            ABB* paiDoFilhoDireitoMinimo = raiz;
            ABB* filhoDireitoMinimo = raiz->dir;
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
            return raiz;
        }
    }
}

void ABB::destroiArvore(ABB* raiz){  //fiz um destrutor próprio pq a recursividade estava dificil no destrutor padrão do cpp...
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

ABB* ABB::busca(ABB* raiz, string placa){
    //retorna null se o valor não for encontrado
    //caso contrário, retorna o nó contendo o valor
    if(raiz == NULL || raiz->node->dado->placa == placa){
        if (raiz != NULL){
            cout << "\nEM ABB, ENCONTRADO: \n";
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