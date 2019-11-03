#ifndef LDE_H
#define LDE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


template <typename T>
class ILista {
public:
    virtual bool Insere (int,string) = 0;
    virtual bool Altera (string,int,int) = 0;
    virtual void Salvar() = 0;
    virtual bool Remove (int) = 0;
    virtual void Imprime () = 0;
    virtual ~ILista (){};
};

template <typename T>
class LDE;

template <typename T>
class No {
public:
    string nome;
    int quantidade;
    float preco;
    int valor;
    No<T>* prox;
    No<T> *pai;
    No<T> *esq;
    No<T> *dir;
    T altura;
};
template <typename T>
class LDE;

template <typename T>
class LDE : public ILista<T> {
private:
    string *x;
    int *y;
    No<T>* primeiro;
    int n;
    T sentinela;
    void limpa () {
        while(this->Remove(0));
    }

    void copia (const LDE& other) {
    }

public:
    LDE () {
        primeiro = NULL;
        n = 0;
    }

    void Salvar(){
        No<T>* atual = primeiro;
        ofstream arquivoS;
        arquivoS.open("Funcionario.txt",ios::app);

        while(atual){
            arquivoS << "Nome funcionario: ";
            arquivoS << atual->nome << endl;
            arquivoS << "Numero de vendas do funcionario: ";
            arquivoS << atual->quantidade << endl;
            atual = atual->prox;
        }

        arquivoS.close();

    }
    bool Insere(int quan, string na){

        No<T>* novo = new No<T>;

        novo->quantidade = quan;
        novo->nome = na;
        novo->prox = NULL;

        No<T>* atual = primeiro;
        No<T>* anterior = NULL;

        if(anterior == NULL){
            primeiro = novo;
        }else{
            anterior->prox = novo;
        }

        novo->prox = atual;

        n++;
        return true;
    };
    bool Altera(string na,int i,int x){
        No<T>* atual = primeiro;
        int e=0;
        while(atual){
            if(atual->nome == na){
            cout << "FUNCIONARIO ENCONTRADO DIGITE:" << endl;
            cout << "1-ALTERAR NUMERO DE VENDAS" << endl;
            cout << "2-REMOVELO" << endl;
            if(i==1){
                cout <<"NOVO NUMERO DE VENDAS?" << endl;
                atual->quantidade = x;
            }
            if(i==2){
                Remove(e);
                cout <<"REMOVIDO" << endl;
            }
            // ja encontrou o funcionario entao retorna true
            return true;
            }
        e++;
        atual = atual->prox;
        }
        cout <<"FUNCIONARIO NAO ENCONTRADO" << endl;
        return false;
    }

    void Imprime(){
        No<T>* atual = primeiro;
        int imp = 0;
        this->x = new string[n];
        this->y = new int[n];
        while(imp<n){
            x[imp]=atual->nome;
            y[imp]=atual->quantidade;
            imp++;
            atual = atual->prox;
        }
    }
    bool Remove (int idx){
        int v2=0;
        No<T>* atual = primeiro;
        No<T>* anterior = NULL;
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
    int getN(){
        return n;
    }

    string getX(int a){
        return x[a];
    }
    int getY(int a){
        return y[a];
    }

    ~LDE () {
        limpa ();
    }
};

LDE<int> *lde;
#endif // LDE_H
