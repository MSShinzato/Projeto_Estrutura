#ifndef FILA_H
#define FILA_H
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/*class IFila{
public:
    virtual ~IFila(){};
    virtual bool Enfileira(string valor) = 0;
    virtual void Imprime() = 0;
    virtual T Desenfileira(bool* ok) = 0;
};*/

class Fila{//: public IFila
private:
    string* v;
    int i;
    int f;
    int max;
public:
    //construtor
    Fila(int maximo) {
        v = new string[maximo+1];
        i=f=0;
        max = maximo+1;
    }
    // destrutor
    ~Fila(){
        delete[] v;
    }
    // adiciona na fila
    bool Enfileira(string valor){
        if( (f+1) % max == i)
            return false;

        v[f] = valor;
        f = (f + 1) % max;
        return true;
    }
    // remove o primeiro da fila
    string Desenfileira(bool* ok = NULL){
        if( i == f) {
            if(ok){
                *ok = false;
            }
            return v[i];
        }

        string temp = v[i];
        i = (i + 1) % max;
        if(ok)
            *ok = true;
        return temp;

    }
    // salva no arquivo
    void Imprime(){
        int e;
        ofstream arquivoS;
        arquivoS.open("FuncionarioMes.txt",ios::app);
        arquivoS << "Funcionarios do mes" << endl;
        for(e=i; e != f; e=(e+1)%max){
            arquivoS << "Funcionario: ";
            arquivoS << v[e] << " ";
        }

        arquivoS.close();
        //Ler_arquivo();

    }
    // ler arquivo txt
    void Ler_arquivo(){
        ifstream arquivoE;
        string linha;
        arquivoE.open("FuncionarioMes.txt");
        if(arquivoE.is_open()){
            while(getline(arquivoE,linha)){
            cout << linha << endl;
            }
        }
        arquivoE.close();
    }

};

#endif // FILA_H
