#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// produto
template <typename T>
class No1 {
public:
    string nome;
    string tam;
    int quantidade;
    float preco;
    int valor;
    int altura;
    No1<T>* prox;
    No1<T> *pai;
    No1<T> *esq;
    No1<T> *dir;
};
//todas as funções que serão utilizadas
template <typename T> class IArvBinBusca {
public:
    virtual bool Insere(int valor,int quan,float pre,string na) = 0;
    virtual bool Remove(T valor) = 0;
    virtual bool Altera(No1<T>* na,string nome) = 0;
    virtual void Salva(No1<T>* na);
    virtual void Ler_arquivo();
    virtual int Balancear(No1<T>* na);
    virtual bool Alturas(No1<T> * na) {}
    virtual void imprime()=0;
    virtual void ImprimeMenor(No1<T>* na)=0;
    virtual void Viraesquerda(No1<T>* na)=0;
    virtual void Viradireita(No1<T>* na)=0;
    virtual ~IArvBinBusca() {}

};

template <typename T>
class ArvBin {
private:
    int n;
    No1<T>* sucessor(No1<T>* n){
        n = n->dir;
        while(n && n->esq){
            n = n->esq;
        }
        return n;
    }
public:
    No1<T>* raiz;
    string name;
    ArvBin(){
        raiz = NULL;
        n=0;
    };

    bool Insere(int valor,int quan,float pre,string na, string tam) {
        //vai passar oque sera salvo em cada no
        No1<T>* novo = new No1<T>;
        novo->valor = valor;
        novo->quantidade = quan;
        novo->preco = pre;
        novo->nome = na;
        novo->tam = tam;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        novo->altura = 0;
        //a primeira entrada sempre sera a raiz da arvore
        if(raiz==NULL){
            raiz = novo;
            return true;
        }
        No1<T>* atual = raiz;
        No1<T>* anterior = NULL;
        //insere o no deacordo com o seu valor
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
//sempre que alguem for inserido tem que checar denovo a altura da fileira
        altura(anterior);
        while(novo){
            Balancear(novo->pai);
            novo = novo->pai;
        }
        n++;
        return true;
    }
    //arruma a altura da arvore sempre que alguem for inserido
    int altura(No1<T>* na){
        //vai passando por um elemento em cada nivel da arvore
       //que seria a qual teria sido inserido ou removido um valor na fileira
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
    int Balancear(No1<T>* na){
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
    void Salva(No1<T>* na){
//ja salva no arquivo dizendo oque é cada informação
        ofstream arquivoS;
        arquivoS.open("Produtor.txt",ios::app);
        arquivoS << "Nome do produto: ";
        arquivoS << na->nome << endl;
        arquivoS << "Quantidade do produto: ";
        arquivoS << na->quantidade << endl;
        arquivoS << "Preco do produto: RS";
        arquivoS << na->preco << endl;
        arquivoS << "Tamanho";
        arquivoS << na->tam << endl;
        arquivoS << "Prioridade";
        arquivoS << na->valor << endl;
        arquivoS.close();

    }
    //sera utilizada para ler o arquivo de texto e entao mostrar na area de interface os produtos
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
    void imprime(){
        ImprimeMenor(raiz);
    }
    //sera utilizada para passar todos os valores ao arquivo de texto
    void ImprimeMenor(No1<T>* na){
        if(na!=NULL){
            ImprimeMenor(na->esq);
            Salva(na);
            ImprimeMenor(na->dir);
        }
    }
    void Viradireita(No1<T>* na){
        //if(na->pai->pai){
          //  raiz = na;
        //}
        //No<T>* filho = na->dir;
        //No<T>* atual = na;
        //na = na->pai;
        //na->pai = atual;
        //na->dir = filho;


    }
    void Viraesquerda(No1<T>* na){
       // if(na->pai->pai){
         //   raiz = na;
        //}
        //No<T>* filho = na->esq;
        //No<T>* atual = na;
        //na = na->pai;
        //na->pai = atual;
        //na->esq = filho;

    }
    // alterar quantidade do estoque, a arvore utiliza a prioridade para se organizar então não ira desbalanceala
    bool Altera(No1<T>* na,string nome,int quan){
        if(na!=NULL){
            Altera(na->dir,nome,quan);
            if(na->nome==nome){
                na->quantidade=quan;
                //para atualizar o arquivo de texto
                ofstream arquivoS;
                arquivoS.open("Produtor.txt");
                imprime();
                arquivoS.close();
                return true;
            }

            Altera(na->esq,nome,quan);
        }
    }
    void recebeNome(T valor,string s){
        name = s;
        Remove(valor);
    }
    // Remover produtos da arvore
    bool Remove(T valor){
        No1<T>* atual = raiz;
        No1<T>* anterior = NULL;
        while ((atual && atual->valor != valor)&& (atual && atual->nome == name)){
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
            No1<T>* unicoFilho = atual->esq;
            No1<T>* pai = atual->pai;
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

    // destrutor
    virtual ~ArvBin(){};
};


#endif // ARVORE_H
