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
        if(i==0){
            return -1;
        }
        return (i-1)/2;
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
    //Heap(): n(0){

    //}
    Heap(){
        cout<<"heap construida"<<endl;
        this->n= 0;
        if(n >= MAX){
            return;
        }
        for(int i=0;i<MAX;i++){
            this->v[i] = v[i];
        }
        this->n = n;

        cout<<"heap construida2"<<endl;
        constroiHeap();
        cout<<"heap construida3"<<endl;

    }

    bool insere(T x,string na){
      cout<<"elemento inserido1"<<endl;
        if(n >= MAX){
            return false;

        }
        cout<<"elemento inserido"<<endl;
        v[n] = x;
        cout<<"elemento inserido2"<<endl;
        n++;
        cout<< n <<endl;
        cout<<"elemento inserido3"<<endl;

        for(int i=ultPai(); i >= 0; i = pai(i)){

            swift(i);
             cout << i << endl;
        }
        cout<<"elemento inserid4"<<endl;
        return true;

        cout<<"elemento inserido"<<endl;
    }

    T remove(){
        if(n==0){
          cout<<"não tem nenhum elemento na heap"<<endl;
          return v[0];
        }
        /*if(n == 0){
            if(ok){
                *ok = false;
            }
            return v[0];
        }*/

        T temp = v[0];
        cout<<"igualo o temp"<<endl;
        v[0] = v[n-1];
        cout<<"v[0]=v[n-1]"<<endl;
        v[n-1] = temp;
        cout<<"v[n-1]=temp"<<endl;
        n--;
        cout<<"v[n-1]=temp"<<endl;
        for(int i=ultPai(); i>= 0; i = pai(i)){
            swift(i);
            cout<<"swift aplicado"<<endl;

        }
        cout<<"retorna temp"<<endl;
        return temp;


    }




};
Heap<int,50>*h;
#endif // HEAP_H
