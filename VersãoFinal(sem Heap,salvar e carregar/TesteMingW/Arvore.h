#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

#include <string>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
class No2 {
public:
    string nome;
    int quantidade;
    float preco;
    int valor;
    No2<T>* prox;
    No2<T> *pai;
    No2<T> *esq;
    No2<T> *dir;
    T altura;
};

template <typename T> class IArvBinBusca {
public:
    virtual bool Insere(int valor,int quan,float pre,string na) = 0;
    virtual bool Remove(T valor) = 0;
    virtual bool Busca(T valor)=0;
    virtual int getN() = 0;
    virtual bool Altera(No2<T>* na,string nome) = 0;
    virtual void Salva(No2<T>* na);
    virtual void Ler_arquivo();
    virtual int Balancear(No2<T>* na);
    virtual bool Alturas(No2<T> * na) {}
    virtual void ImprimeMenor(No2<T>* na)=0;
    virtual void ImprimeMaior(No2<T>* na)=0;
    virtual void Viraesquerda(No2<T>* na)=0;
    virtual void Viradireita(No2<T>* na)=0;
    virtual ~IArvBinBusca() {}

};
template <typename T> class ArvBin {
private:
    int n;
    string out;
    int out2;
    int out3;
    int out4;
    No2<T>* sucessor(No2<T>* n){
        n = n->dir;
        while(n && n->esq){
            n = n->esq;
        }
        return n;
    }

public:

    No2<T>* raiz;
    ArvBin(

    ){
        raiz = NULL;
        n=0;
    };

    bool Insere(int valor,int quan,float pre,string na) {
        No2<T>* novo = new No2<T>;
        novo->valor = valor;
        novo->quantidade = quan;
        novo->preco = pre;
        novo->nome = na;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        novo->altura = 0;
        if(raiz==NULL){
            raiz = novo;
            return true;
        }
        No2<T>* atual = raiz;
        No2<T>* anterior = NULL;
        while (atual){
            anterior = atual;
            if(valor<atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }

        novo->pai = anterior;
        if(valor <  anterior->valor)
            anterior->esq = novo;
        else
            anterior->dir = novo;

        altura(anterior);
        while(novo){
            Balancear(novo->pai);
            novo = novo->pai;
        }
        n++;
        return true;
    }
    int altura(No2<T>* na){
       while(na){

            if(na->esq && na->dir){
                na->altura = max(na->esq->altura, na->dir->altura)+1;
            }
            if(na->esq == NULL && na->dir){
                na->altura = na->dir->altura +1;
            }
            if(na->dir == NULL && na->esq){
                na->altura = na->esq->altura +1;
            }
            na = na->pai;
        }

    }
    int Balancear(No2<T>* na){
        //int a=na->esq->altura;
       // int b=na->dir->altura;
        //    a=a-b;
        //    if(a >= 2 ){
         //       if(na->prox->altura<0){

        //            Viradireita(na);
         //           }
         //     Viraesquerda(na);
         //   }
         //   if(a <= -2 ){
         //       if(na->prox->altura>0) {
         //           Viraesquerda(na);
          //      }
          //      Viradireita(na);
          //  }

    }
    void Salva(No2<T>* na){

        ofstream arquivoS;
        arquivoS.open("Produtor.txt",ios::app);
        arquivoS << "Nome do produto: ";
        arquivoS << na->nome << endl;
        arquivoS << "Quantidade do produto: ";
        arquivoS << na->quantidade << endl;
        arquivoS << "Preco do produto: RS";
        arquivoS << na->preco << endl;
        arquivoS << "Prioridade";
        arquivoS << na->valor << endl;
        arquivoS.close();

    }
    void Ler_arquivo(){
        ifstream arquivoE;
        string linha;
        arquivoE.open("Produtor.txt");
        if(arquivoE.is_open()){
            while(getline(arquivoE,linha)){
            cout << linha << endl;
            }
        }
        arquivoE.close();
    }
    void ImprimeMenor(No2<T>* na){
        if(na!=NULL){
            ImprimeMenor(na->esq);
            out = na->nome;
            out2= na->preco;
            out3= na->quantidade;
            out4 = na->valor;
            Salva(na);
            ImprimeMenor(na->dir);
        }
    }
    void ImprimeMaior(No2<T>* na){

        if(na!=NULL){
            ImprimeMaior(na->dir);
            cout << na->valor << endl;
            ImprimeMaior(na->esq);
        }
    }
    void Viradireita(No2<T>* na){
      /*  if(na->pai->pai){
            raiz = na;
        }
        No<T>* filho = na->dir;
        No<T>* atual = na;
        na = na->pai;
        na->pai = atual;
        na->dir = filho;
        */

    }
    void Viraesquerda(No2<T>* na){
       /* if(na->pai->pai){
            raiz = na;
        }
        No<T>* filho = na->esq;
        No<T>* atual = na;
        na = na->pai;
        na->pai = atual;
        na->esq = filho;
        */
    }
    // alterar quantidade do estoque, a arvore utiliza a prioridade para se organizar então não ira desbalanceala
    bool Altera(No2<T>* na,string nome){
        if(na!=NULL){
            Altera(na->dir,nome);
            if(na->nome==nome){
                int quan;
                cout << "Qual a nova quantidade?" << endl;
                cin >> quan;
                na->quantidade=quan;
                return true;
            }

            Altera(na->esq,nome);
        }
    }
    bool Remove(T valor){
        No2<T>* atual = raiz;
        No2<T>* anterior = NULL;
        while (atual && atual->valor != valor){
            anterior = atual;
            if(valor<atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        if (atual == NULL)
            return false;

        int filhos = 0;
        filhos = (atual->esq!=NULL) + (atual->dir!=NULL);

        if (filhos == 0){
            if (atual->pai){
                if(atual == atual->pai->esq){
                    atual->pai->esq = NULL;
                }
                else{
                    atual->pai->dir = NULL;
                }
            }
            else{
                raiz = NULL;
            }
            delete atual;
            n--;
        }
        else if(filhos == 1){
            No2<T>* unicoFilho = atual->esq;
            No2<T>* pai = atual->pai;
            if(!unicoFilho)
                unicoFilho = atual->dir;
            unicoFilho->pai = pai;
            if(pai){
                if(unicoFilho->valor < pai->valor)
                    pai->esq = unicoFilho;
                else
                    pai->dir = unicoFilho;
            }
            else{
                raiz = unicoFilho;
            }
            delete atual;
            n--;
        }
        else{
            T valorSuc = sucessor(atual)->valor;
            this->Remove(valorSuc);
            atual->valor = valorSuc;
        }

    }
    bool Busca(T valor){
        No2<T>* atual = raiz;
        No2<T>* anterior = NULL;
        while (atual && atual->valor != valor){
            anterior = atual;
            if(valor<atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        if (atual == NULL){

        }
        out = atual->nome;
        out2= atual->preco;
        out3= atual->quantidade;
        return true;
    }
    int getN(){
       return n;
    }

    string getOut(){
        return out;
    }
    int getOut2(){
        return out2;
    }
    int getOut3(){
        return out3;
    }
    int getOut4(){
        return out4;
    }


    virtual ~ArvBin(){



    };
};

ArvBin<int> *arv;
#endif // ARVORE_H
