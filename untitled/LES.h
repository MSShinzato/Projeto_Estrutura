#ifndef LES_H
#define LES_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
/*
class ILista2{

public:
    virtual bool Insere(string)=0;
    virtual int  busca(string) = 0;
    virtual bool Remove(string) = 0;
    virtual void Imprime()=0;
    virtual void Salva()=0;
    virtual ~ILista2(){};
};*/

// Fornecedor
class LES{ //: public ILista2

private:
    int M;
    int n;
    string *v;
public:
    //construtor
    LES(int M){
        this->M = M;
        this->n = 0;
        this->v = new string[M];
    }
    //destrutor
    ~LES(){
        delete[] this->v;
    }
    /*void Imprime(){
        for (int i = 0; i < n; ++i) {
            cout << v[i] <<  endl;
        }
        cout << endl;
        Salva();
    }*/
    //sera utilizada para salvar no arquivo de texto oque futuramente sera mostrado no qt
    void Salva(){

        ofstream arquivoS;
        // o ios::app faz com que não seja apagado oque ja estava no arquivo de texto
        arquivoS.open("Fornecedor.txt",ios::app);
        for (int i = 0; i < n; ++i) {
            arquivoS << "Nome do Fornecedor: ";
            arquivoS << v[i] << endl;
        }

        arquivoS.close();
        //Ler_arquivo();
    }
    //sera utilizada para mostrar oque esta dentro do arquivo de texto no qt
    void Ler_arquivo(){
        ifstream arquivoE;
        string linha;
        arquivoE.open("Fornecedor.txt");
        if(arquivoE.is_open()){
            while(getline(arquivoE,linha)){
            cout << linha << endl;
            }
        }
        arquivoE.close();
    }
    //A insersao sera simples pois so salvara na proxima posicao do v[], o fornecedor(nao tem que se preoculpar com ordenação)
    bool Insere(string x){
        if (n == M){
            return false;
        }
        v[n] = x;
        n++;
        return true;
    }
    //o remove ira usar o busca para emcontrar a posição da variavel e para saber se ela esta inserida
    //depois disso arruma as posições do vetor por ter tido uma posição removida
    bool Remove(string x){
        int posi = busca(x);
        if (posi == -1){
            return false;
        }
        int i;
        for (i = posi; i < n-1; i++) {
            v[i] = v[i + 1];
        }
            n--;
            return true;
    }
    int busca(string x){

        for (int i = 0; i < n; i++) {
            if ( v[i] == x ){
                return i;
            }
        }
        return -1;
    }
};
#endif // LES_H
