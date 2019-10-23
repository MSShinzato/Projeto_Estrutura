#ifndef LDE_H
#define LDE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*class ILista{
public:
    virtual bool Insere (int,int,float,string) = 0;
    virtual bool Remove (int) = 0;
    virtual void Imprime () = 0;
    virtual ~ILista (){};
};*/

class LDE;

class No {
private:

public:
    string nome;
    int quantidade;
    double preco;
    string tamanho;
    No* prox;
    friend class LDE;

};

class LDE{ // class LDE : public ILista<T>
private:
    //T sentinela;
    void limpa () {
        while(this->Remove(0));
    }

    void copia (const LDE& other) {
    }

public:
    No* primeiro;
    int n;
    typedef struct Produto prod;
    LDE () {
        primeiro = NULL;
        n = 0;
    }

    bool Insere(string nome, double preco,string tam, int quant){

        No* novo = new No;

        novo->nome = nome;
        novo->preco = preco;
        novo->tamanho = tam;
        novo->quantidade = quant;
        novo->prox = NULL;

        No* atual = primeiro;
        No* anterior = NULL;

        if(anterior == NULL){
            primeiro = novo;
        }else{
            anterior->prox = novo;
        }

        novo->prox = atual;

        n++;
        return true;

    }


    void Imprime(){
        No* atual = primeiro;
        for(int i=0; i<n;i++){
            cout << "Nome do produto: ";
            cout << atual->nome << " \n ";
            cout << "Quantidade do produto: ";
            cout << atual->quantidade << " \n ";
            cout << "Tamanho do produto: ";
            cout << atual->tamanho << " \n ";
            cout << "Preco do produto: RS";
            cout << atual->preco << " \n ";
            cout << "=======================" << endl;
            atual = atual->prox;
        }
        cout << endl;
    }

    //O remover eu deixei so por eu nao estar querendo me preoculpar com o limpar depois tera que ver isto
    bool Remove (int idx){
        int v2=0;
        No* atual = primeiro;
        No* anterior = NULL;
        int i = idx;
        if(idx<0||idx>=n){
            return false;
        }
        while(atual && i--){
            anterior = atual;
            atual = atual->prox;
        }
        if(anterior){
            anterior->prox=atual->prox;
        } else{
            primeiro=atual->prox;
        }
        n--;
        delete atual;
    }

    ~LDE () {
        limpa ();
    }


};

#endif // LDE_H
