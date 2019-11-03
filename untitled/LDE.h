#ifndef LDE_H
#define LDE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

/*
class ILista {
public:
    virtual bool Insere (int,string) = 0;
    virtual bool Altera (string) = 0;
    virtual void Salvar() = 0;
    virtual bool Remove (int) = 0;
    virtual void Imprime () = 0;
    virtual ~ILista (){};
};*/

// funcionario
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
};
template <typename T>
class LDE;

template <typename T>
class LDE{ //: public ILista<T>
private:
    No<T>* primeiro;
    int n;
    T sentinela;
    /*void limpa () {
        while(this->Remove());
    }*/

    void copia (const LDE& other) {
    }

public:
    LDE () {
        primeiro = NULL;
        n = 0;
    }
    //sera utilizada para salvar no arquivo de texto oque futuramente sera mostrado no qt
    void Salvar(){
        No<T>* atual = primeiro;
        ofstream arquivoS;
        arquivoS.open("Funcionario.txt",ios::app);
        //arquivoS.open("demonio.txt",ios::app);

        while(atual){
            arquivoS << "Nome funcionario: ";
            arquivoS << atual->nome << endl;
            arquivoS << "Numero de vendas do funcionario: ";
            arquivoS << atual->quantidade << endl;
            atual = atual->prox;
        }

        arquivoS.close();
        //Ler_arquivo();
    }
    void Ler_arquivo(){
        ifstream arquivoE;
        string linha;
        arquivoE.open("Funcionario.txt");
        if(arquivoE.is_open()){
            while(getline(arquivoE,linha)){
            cout << linha << endl;
            }
        }
        arquivoE.close();
    }
    //É inserido o funcionario e o seu numero atual de vendas
    bool Insere(string na,int quan){

        No<T>* novo = new No<T>;

        novo->nome = na;
        novo->quantidade = quan;
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
    bool Altera(string na, int quant){
        No<T>* atual = primeiro;
                while(atual){
                    if(atual->nome == na){
                        // ja encontrou o funcionario entao retorna true
                        atual->quantidade = quant;
                        ofstream arquivoS;
                        // vai sobreescrever o conteúdo do arquivo
                        arquivoS.open("Funcionario.txt");
                        //arquivoS.open("demonio.txt");
                        arquivoS.close();
                        Salvar();
                        return true;
                    }
                atual = atual->prox;
                }
                return false;
    };

    void Imprime(){
        No<T>* atual = primeiro;
        while(atual){
            cout << "Nome funcionario: ";
            std::cout << atual->nome << " \n ";
            cout << "Numero de vendas do funcionario: ";
            std::cout << atual->quantidade << " \n ";
            cout << "=======================" << endl;
            atual = atual->prox;
        }
        std::cout << std::endl;
    };
     //sera utilizado para remover um funcionario
    bool Remove (string na){
        //int v2=0;
        int flag=0;
        int e=0;
        No<T>* atual = primeiro;
        No<T>* anterior = NULL;

        while(atual || flag!=1){
            if(atual->nome == na){
                flag = 1;
            }
            e++;
            atual = atual->prox;
        }

        int idx = e;
        if(idx<0||idx>=n){
            return false;
        }
        while(atual && idx--){
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
    };

    ~LDE () {
        //limpa ();
    };
};

#endif // LDE_H
