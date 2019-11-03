#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

using namespace std;

class Produto{
public:
    string nome;
    int quant;
    double preco;
    char tam;
    Produto(string nome, int quant, double preco, char tam){
        this->nome = nome;
        this->quant = quant;
        this->preco = preco;
        this->tam = tam;
    }
};

#endif // PRODUTO_H
