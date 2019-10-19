#include <iostream>

using namespace std;
// minha IDE deu um problema e eu ainda não consegui testar, resolverei o mais rapido possivel para testar

template <typename T>
class ILista {
public:
  virtual void Insere (T) = 0;
  virtual bool Busca (T) = 0;
  virtual bool Remove (int) = 0;
  virtual ~ILista (){};
};

template <typename T>
class LES;

template <typename T>
class LES : public ILista<T> {
private:
    int cont;
    int backup;
    int c;
    int x = 10;
    int vetor[x];
public:
    LES (){
        cont = 0;
        for(int a = 0; a < x; a++){
            vetor[a] = 0;
        }
    }
    void Insere(int a){

        int temp = 0;
        
        //se a lista estiver vazia ele insere logo de cara
        if(cont == 0){
            vetor[temp] = a;
            cout << "inserido" << endl;
            cont++;
        }else{
            //busca do lugar para inserir
            while(a>vetor[temp] && temp !=(cont-1)){
                temp ++;
            }
            //se o numero que vc quiser inserir for o maior de todos 
            if(vetor[temp] == 0){
                vetor[temp] = a;
                cont++;
                cout << "inserido" << endl;
            }
            //se tiver algum numero para "puxar pra direita"
            if(vetor[temp] != 0){
                backup=vetor[temp];
                vetor[temp] = a;
                //recursividade
                Insere(backup);
                cout<<"inserido"<<endl
                cont++;
            }
        }
    }
    bool Busca(a){
        // se voce tentar buscar na lista vazia
        if(cont == 0){
            cout << "sua lista esta vazia" endl;
            return false;
        }else{
            //busca
            //o c esta declaro la no private para usar ele na remoção
            for(c = 0;c<x;c++){
                if(vetor[c] == a){
                    cout << "achou" << endl;
                    return true;
                }
            }
        }


    }

    bool Remove(a){
        // me utilizo da busca para achar o valor que quero remover
        if(Busca(a)){
            for(d=c;d<x;d++){
                vetor[d] = vetor[d+1];
                cout<<"removido"<<endl;
                return true;
            }
        }else{
            cout << "não existe esse valor para remover" << endl;
            return false;
        }
    }

