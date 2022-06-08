/* 
 * File:   avl.h
 * Author: PedroBarraza
 *
 * Created on 10 de Abril de 2022, 16:23
 */

#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "lista.h" //pra pegar o carro sem ter que declarar novamente, não faz mal.

using namespace std;

class AVL{ //o no total da arvore AVL
    No* node; //o no da lista principal q vamos inserir...
    AVL *esq, *dir;
    int altura;
    
public:
    AVL();
    AVL(No *n);
    int retornaAltura(AVL *Raiz);
    AVL *RotacionaDireita(AVL *Raiz);
    AVL *RotacionaEsquerda(AVL *Raiz);
    int fatorBalanceamento(AVL *Raiz);
    AVL* insert(AVL* Raiz, No* node);
    void Preordem(AVL* Raiz);
    AVL* removeNo (AVL* raiz, string placa);
    void destroiArvore(AVL* raiz);
    AVL* busca(AVL* raiz, string placa);
};

#endif /* AVL_H */

