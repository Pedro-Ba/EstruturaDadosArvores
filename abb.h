/* 
 * File:   abb.h
 * Author: Pedro Barraza
 *
 * Created on 09 de Abril de 2022, 15:50
 */

#ifndef ABB_H
#define ABB_H

#include <iostream>
#include "lista.h" //pra pegar o carro sem ter que declarar novamente, não faz mal.

using namespace std;
//ABB = Árvore de Busca Binária. Header.

class ABB{ //no da arvore busca binaria
    No *node; //como pedido no trabalho, inseriremos o NÓ DA LISTA, e não apenas o CARRO
    ABB *esq, *dir;
    
public:
    ABB();
    ABB(No *n);
    
    ABB* Insert(ABB* root, No *node);
    void Preordem(ABB* Raiz);
    ABB* removeNo(ABB* root, string placa);
    void destroiArvore(ABB* raiz);
    ABB* busca(ABB* raiz, string placa);
};


#endif /* ABB_H */

