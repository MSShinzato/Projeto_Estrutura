#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;

template <typename T, int MAX>

class Heap{
private:
    T v[MAX];
    int n;
    int pai(int i){
        return (i+1)/2;
    }
    int fe(int i){
        return 2*i+1;
    }
    int fd(int i){
        return 2*i+2;
    }
    int ultPai(){
        return pai(n-1);
    }

    void swift(int idx){
        if(idx > ultPai()){
            return;
        }
        int idxMenorFilho = fe(idx);
        if(fd(idx) < n && v[idxMenorFilho] > v[fd(idx)]){
            idxMenorFilho = fd(idx);
        }

        if(v[idxMenorFilho] < v[idx]){
            //faz a troca

            T temp = v[idxMenorFilho];
            v[idxMenorFilho] = v[idx];
            v[idx] = temp;
            swift(idxMenorFilho);

        }
    }

    void constroiHeap(){
        for(int i = ultPai();i >= 0 ; i--){
            swift(i);
        }
    }


public:
    Heap(): n(0){

    }
    Heap(T v[], int n){
        this->n = 0;
        if(n >= MAX){
            return;
        }
        for(int i=0;i<n;i++){
            this->v[i] = v[i];
        }
        this->n = n;
        constroiHeap();
    }

    bool insere(T x){
        if(n < MAX){
            return false;

        }

        v[n] = x;

        n++;

        for(int i=ultPai(); i>= 0; i = pai(i)){
            swift(i);
        }
    }

    T remove(bool ok){
        if(n == 0){
            if(ok){
                ok = false;
            }
            return v[0];
        }

        T temp = v[0];
        v[0] = v[n-1];
        v[n-1] = temp;
        n--;
        for(int i=ultPai(); i>= 0; i = pai(i)){
            swift(i);
        }
        return temp;

    }
};

/*int main(){

    Heap<int,10> h;
    h.insere(5);
    h.insere(8);
    h.insere(1);
    h.insere(2);
    h.insere(9);

    bool ok = true;
        do{
            int s = h.insere(ok);

            if(ok)
                cout << " - "<< s << endl;
        }while(ok);

    return 0;
}*/
#endif // HEAP_H
