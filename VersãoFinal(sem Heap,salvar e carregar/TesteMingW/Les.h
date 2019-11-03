#ifndef LES_H
#define LES_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
class ILista2{

public:
    virtual bool Insere(string)=0;
    virtual int  busca(string) = 0;
    virtual bool Remove(string) = 0;
    virtual void Imprime()=0;
    virtual void Salva()=0;
    virtual ~ILista2(){};
};
template <typename T>
class LES: public ILista2<T>{

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
    void Imprime(){
        for (int i = 0; i < n; ++i) {
            cout << v[i] <<  endl;
        }
        cout << endl;
    }
    void Salva(){

        ofstream arquivoS;
        arquivoS.open("Fornecedor.txt",ios::app);
        for (int i = 0; i < n; ++i) {
            arquivoS << "Nome do Fornecedor: ";
            arquivoS << v[i] << endl;
        }

        arquivoS.close();

    }
    bool Insere(string x){
        if (n == M){
            return false;
        }
        v[n] = x;
        n++;
        return true;
    }
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
    int getN(){
        return n;
    }
    string getV(int i){
        return v[i];
    }
};
LES<string>*les;
#endif // LES_H
