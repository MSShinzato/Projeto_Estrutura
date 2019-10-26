#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T> class No {
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
template <typename T> class IArvBinBusca {
public:
    virtual bool Insere(int valor,int quan,float pre,string na) = 0;
    virtual bool Remove(T valor) = 0;
    virtual bool Alturas(No<T> * na) {}
    virtual void Imprime(No<T>* na)=0;
    virtual void Imprime2(No<T>* na)=0;
    virtual void Viraesquerda(No<T>* na)=0;
    virtual void Viradireita(No<T>* na)=0;
    virtual No<T> *Busca(T valor) = 0;
    virtual ~IArvBinBusca() {}
private:

};
template <typename T> class ArvBin {
private:
    int n;
    No<T>* sucessor(No<T>* n){
        n = n->dir;
        while(n && n->esq){
            n = n->esq;
        }
        return n;
    }
public:
    No<T>* raiz;
    ArvBin(

    ){
        raiz = NULL;
        n=0;
    };

    bool Insere(int valor,int quan,float pre,string na) {
        No<T>* novo = new No<T>;
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
        No<T>* atual = raiz;
        No<T>* anterior = NULL;
        while (atual){
            anterior = atual;
            if(quan<atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }

        novo->pai = anterior;
        if(valor <  anterior->valor)
            anterior->esq = novo;
        else
            anterior->dir = novo;

        while(anterior){

            if(anterior->esq && anterior->dir){
                anterior->altura = max(anterior->esq->altura, anterior->dir->altura)+1;
            }
            if(anterior->esq == NULL && anterior->dir){
                anterior->altura = anterior->dir->altura +1;
            }
            if(anterior->dir == NULL && anterior->esq){
                anterior->altura = anterior->esq->altura +1;
            }
            anterior = anterior->pai;
        }

        n++;
        return true;
    }
    int altura(No<T>* na){
        int a=0;
        int b=0;
        while(na){
            a=na->pai->dir;
            b=na->pai->esq;
            a=a-b;
            if(a>= 2 ){
                a=na->dir;
                if(a<0){
                    Viradireita( na);
                    Viraesquerda( na);
                }
                Viraesquerda(na);
            }
            if(a <= -2){
                a=na->dir;
                if(a>0){
                    Viraesquerda( na);
                    Viradireita( na);
                }
                Viradireita( na);
            }

            na = na->pai;

        }

    }
    void Imprime(No<T>* na){
        if(na!=NULL){
            Imprime(na->esq);
            cout << "Nome do produto: ";
            cout << na->nome << endl;
            cout << "Quantidade do produto: ";
            cout << na->quantidade << endl;
            cout << "Preco do produto: RS";
            cout << na->preco << endl;
            cout << "Prioridade";
            cout << na->valor << endl;
            cout << "=======================" << endl;
            Imprime(na->dir);
        }
    }
    void Imprime2(No<T>* na){

        if(na!=NULL){
            Imprime(na->dir);
            cout << na->valor << endl;
            Imprime(na->esq);
        }
    }
    void Viradireita(No<T>* na){
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
    void Viraesquerda(No<T>* na){
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
    bool Remove(T valor){
        No<T>* atual = raiz;
        No<T>* anterior = NULL;
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
            No<T>* unicoFilho = atual->esq;
            No<T>* pai = atual->pai;
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


    No<T> *Busca(T valor) {
        No<T>* novo = new No<T>;

        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;

        No<T>* atual = raiz;
        No<T>* anterior = NULL;
        while(atual && atual->valor!=valor){
            anterior=atual;
            if(valor>atual->valor){
                atual=atual->dir;
            }
            else
                atual=atual->esq;
        }
        while(anterior){

            if(anterior->esq && anterior->dir){
                anterior->altura = max(anterior->esq->altura, anterior->dir->altura)-1;
            }
            if(anterior->esq == NULL && anterior->dir){
                anterior->altura = anterior->dir->altura -1;
            }
            if(anterior->dir == NULL && anterior->esq){
                anterior->altura = anterior->esq->altura -1;
            }
            anterior = anterior->pai;
        }
        altura(novo);
        return atual;

    }

    virtual ~ArvBin(){



    };
};
int main(int argc, char *argv[]) {
    ArvBin<int> arv;
    //l.Insere (valor,quan,pre,nome);
    arv.Insere(1,2,2.5,"Carta");
    arv.Insere(3,3,2.5,"Caneta");
    arv.Insere(5,4,2.5,"Pizza sadia");
    arv.Insere(4,5,2.5,"Nestle");
    arv.Insere(20,6,2.5,"Carrinho-de-Compras");
    arv.Insere(9,7,2.5,"Caixas");
    
    arv.Imprime(arv.raiz);
   // arv.Imprime2(arv.raiz);
   // arv.Remove(9);
   // arv.Remove(1);
   // arv.Remove(3);
  //  arv.Imprime(arv.raiz);

	system("pause");
    return 0;
}
