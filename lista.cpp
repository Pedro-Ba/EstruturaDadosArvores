#include <cstdlib>
#include "lista.h"

using namespace std;

Carro::Carro(){
  modelo = "";
  marca = "";
  tipo = "";
  ano = 0;
  km = 0;
  potenciamotor = 0;
  combustivel = "";
  cambio = "";
  direcao = "";
  cor = "";
  portas = 0;
  placa = "";
}

//construtor
Carro::Carro(string model, string marc, string tip, int an, int kms, float potencia, string combustive, string cambi, string direca, string corr, int porta, string plac){
  modelo = model;
  marca = marc;
  tipo = tip;
  ano = an;
  km = kms;
  potenciamotor = potencia;
  combustivel = combustive;
  cambio = cambi;
  direcao = direca;
  cor = corr;
  portas = porta;
  placa = plac;
}

//deconstrutor
Carro::~Carro(){
  modelo = "";
  marca = "";
  tipo = "";
  ano = 0;
  km = 0;
  potenciamotor = 0;
  combustivel = "";
  cambio = "";
  direcao = "";
  cor = "";
  portas = 0;
  placa = "";
}

No::No(){
    dado = NULL;
    prox = NULL;
}

//o dado do nó é um carro, importante lembrar.
No::No(Carro* d, No* p){
    dado = d;
    prox = p;    
}

No::~No(){
}

/**
 * Inicializa os campos do cabeçalho da lista
 * @return valor do endereço da struct do cabeçalho
 */
Lista::Lista(){
    inicio = NULL;
    fim = NULL;
    qtde = 0;
}

//Desaloca tudo
Lista::~Lista(){
    No *p = inicio, *r;
    while (p != NULL){
        r = p;
        p = p->prox;
        free(r->dado);
        free(r);
    }
    qtde = 0;
    inicio = NULL;
    fim = NULL;
}


//Hora de fazer a busca. vamos retornar uma lista
Lista * Lista::busca(string valorstring, int tipobusca, float valorfloat, int valorint, int caracteristica){
    Lista *resultadobuscalocal = new Lista();
    //cout << "Entrou busca";
    if (qtde > 0){
        //cout << "Entrou qtdd"; 
        No *p = inicio;
        while(p != NULL){
            //cout << "Tem inicio";
            //obs: Insere inicio insere no inicio da lista, como um push de uma pilha.
            //inserefim insere no fim da lista, simulando a enqueue de uma fila.
            //ao retornar pro programa principal, imprimimos o resultado da busca do inicio ao fim - 
            // se foi fila, como estamos acessando linearmente, é FIFO. O primeiro que inseriu será o primeiro a sair.
            // caso tenha sido pilha, será LIFO - O último inserido está na cabeça, então será o primeiro a sair.
            //Isto faz com que seja simulado com sucesso uma pilha e uma lista sem a necessidade de modificar o restante do programa.
            if (caracteristica == 1){
                if (p->dado->modelo == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 2){
                if (p->dado->marca == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 3){
                if (p->dado->tipo == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 4){
                if (p->dado->ano == valorint){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 5){
                if (p->dado->km == valorint){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 6){
                if (p->dado->potenciamotor == valorfloat){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 7){
                if (p->dado->combustivel == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 8){
                if (p->dado->cambio == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 9){
                if (p->dado->direcao == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 10){
                if (p->dado->cor == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 11){
                if (p->dado->portas == valorint){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            if (caracteristica == 12){
                if (p->dado->placa == valorstring){
                    if (tipobusca == 1){
                        resultadobuscalocal->insereinicio(p, &resultadobuscalocal->inicio);
                    }
                    else{
                        resultadobuscalocal->inserefim(p, &resultadobuscalocal->inicio);
                    }
                }
            }
            p = p->prox;
        }
    }
    return resultadobuscalocal;
}

//nao utilizado
Carro * Lista::buscaord(int valor){
    return NULL;
}

//push
void Lista::insereinicio(No* novo, No** iniciolista){
    No* novono = new No();
    novono->dado = novo->dado;
    novono->prox = (*iniciolista);
    (*iniciolista) = novono;
    this->qtde++;
}

//append
void Lista::inserefim(No* novo, No** iniciolista){
    No* novono = new No();
    No *ultimo = *iniciolista;
    novono->dado = novo->dado; 
    novono->prox = NULL; 
    if (*iniciolista == NULL) { 
        *iniciolista = novono; 
        return; 
    } 
    while (ultimo->prox != NULL){
        ultimo = ultimo->prox; 
    }
    ultimo->prox = novono; 
    this->qtde++;
}

//ordem baseada na placa do veículo alfabeticamente.
void Lista::insereord(No* novo, No** iniciolista){
    No* current;
    if (*iniciolista == NULL || (*iniciolista)->dado->placa >= novo->dado->placa) {
        novo->prox = *iniciolista;
        *iniciolista = novo;
    }
    else {
        current = *iniciolista;
        while (current->prox != NULL && current->prox->dado->placa < novo->dado->placa) {
            current = current->prox;
        }
        novo->prox = current->prox;
        current->prox = novo;
    }
}

//remove no por chave (placa)
void Lista::removeno(string placa, No** iniciolista){
    No* temp = *iniciolista;
    No* prev = NULL;
    //caso de ser o primeiro dado q é nulo (cabeça da lista)
    if (temp != NULL && temp->dado->placa == placa){
        *iniciolista = temp->prox; 
        delete temp;            
        return;
    }
    else{
        while (temp != NULL && temp->dado->placa != placa){
            prev = temp;
            temp = temp->prox;
        }
        if (temp == NULL){ 
            return;
        }
        prev->prox = temp->prox;
        delete temp;
    }
}

//imprime a lista do inicio ao fim.
void Lista::imprimelista(No* iniciolista){
    No* temp = iniciolista;
    int contador = 1;
    while (temp != NULL) {
        cout << "\n\nCarro :\n";
        cout << "Placa do carro: " << temp->dado->placa << " \n";
        cout << "Modelo do carro: " << temp->dado->modelo << " \n";
        cout << "Marca do carro: " << temp->dado->marca << " \n";
        cout << "Tipo do carro: " << temp->dado->tipo << " \n";
        cout << "Ano do carro: " << temp->dado->ano << " \n";
        cout << "Km do carro: " << temp->dado->km << " \n";
        cout << "Potencia do motor do carro: " << temp->dado->potenciamotor << " \n";
        cout << "Combustivel do carro: " << temp->dado->combustivel << " \n";
        cout << "Cambio do carro: " << temp->dado->cambio << " \n";
        cout << "Tipo de direcao do carro: " << temp->dado->direcao << " \n";
        cout << "Cor do carro: " << temp->dado->cor << " \n";
        cout << "Numero de portas do carro: " << temp->dado->portas << " \n";
        temp = temp->prox;
        contador++;
    }
}