
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class Carro{
public:
    Carro();
    Carro(string model, string marc, string tip, int an, int kms, float potencia, string combustive, string cambi, string direca, string corr, int porta, string plac); //construtor
    ~Carro(); // Destrutor
    string placa;  //chave
    string modelo, marca, tipo, combustivel, cambio, direcao, cor;
    int ano, km, portas;
    float potenciamotor;
};

class No{
public:
    No();  // Construtor
    No(Carro *d, No *p);  // Construtor
    ~No(); // Destrutor
    Carro *dado;
    No *prox;
};

class Lista {
public:
    Lista();
    ~Lista();
    Lista * busca(string valor, int tipobusca, float valorfloat, int valorint, int caracteristicaum);
    void removeno(string placa, No** iniciolista);
    Carro * buscaord(int valor);
    void insereord(No* novo, No** iniciolista);
    Carro * removeord(int cpf);
    void insereinicio(No* novo, No** iniciolista);
    void inserefim(No* novo, No** iniciolista);
    Carro * removeinicio();
    Carro * removefim();
    No *inicio, *fim;
    int qtde;
    void imprimelista(No* iniciolista);
};

#endif /* LISTA_H */

