#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
class ILista {
public:
    virtual bool Insere (int,int,float,string) = 0;
    virtual bool Remove (int) = 0;
    virtual void Imprime () = 0;
    virtual ~ILista (){};
};

template <typename T>
class LDE;

template <typename T>
class No {
private:
	string nome;
    int quantidade;
    float preco;
	int valor;    
    No<T>* prox;

public:
    template <typename>
    friend class LDE;

};

template <typename T>
class LDE : public ILista<T> {
private:
    No<T>* primeiro;
    int n;
    T sentinela;
    void limpa () {
        while(this->Remove(0));
    }

    void copia (const LDE& other) {
    }

public:
    LDE () {
        primeiro = NULL;
        n = 0;
    }


    bool Insere(int valor,int quan,float pre,string na){
      
        No<T>* novo = new No<T>;
        
        novo->valor = valor;
        novo->quantidade = quan;
        novo->preco = pre;
        novo->nome = na;
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
    

    void Imprime(){
        No<T>* atual = primeiro;
        while(atual){
        	cout << "Nome do produto: ";
        	std::cout << atual->nome << " \n ";
            cout << "Quantidade do produto: ";
            std::cout << atual->quantidade << " \n ";
            cout << "Preco do produto: RS";
            std::cout << atual->preco << " \n ";
            cout << "=======================" << endl;
            atual = atual->prox;
        }
        std::cout << std::endl;
    };
    
    //O remover eu deixei so por eu nao estar querendo me preoculpar com o limpar depois tera que ver isto
	bool Remove (int idx){
        int v2=0;
        No<T>* atual = primeiro;
        No<T>* anterior = NULL;
        int i = idx;
        if(idx<0||idx>=n){
            return false;
        }
        while(atual && i--){
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
        limpa ();
    };


};


int main () {

    LDE<int> l;
    int n=1;
    int m=0;
    int valor;
	int quan;
	float pre;
	string na;
    while(n!=0){
	
    cout << "Digite o numero para a area que deseja:" << endl;
	cout << "1-INSERIR NOVO PRODUTO" << endl;
	cout << "2-MOSTRAR PRODUTOS JA CADASTRADOS" << endl;
	cout << "3-ALTERAR PRODUTOS" << endl;
	cout << "4-EXIT" << endl;
	cin >> m; 
	
	if(m==1){
	cout << "INSERIR NOVO PRODUTO" << endl;	
	cout << "ENTRE COM O NOME DO PRODUTO:" << endl;	
	cin >> na;
	cout << "ENTRE COM A QUANTIDADE DE ESTOQUE:" << endl;
	cin >> quan;
	cout << "INSIRA SEU PRECO:" << endl;
	cin >> pre;
	cout << "QUAL SEU NUMERO DE VENDAS ESTIMADO POR SEMANA(CASO NAO HAJA ENTRE COM 0):" << endl;
	cin >> valor;
	l.Insere (valor,quan,pre,na);
	}
	
	if(m==2){
	cout << "LISTA DE PRODUTOS" << endl;
	l.Imprime ();
	}
	if(m==3){
		cout << "1-ALTERAR TOTALMENTE O PRODUTO" << endl;	
		cout << "2-ATUALIZAR SUAS VENDAS" << endl;	
		cin >> m; 
		if(m==1){	
			//ainda nao adicionado alterar ultima variavel valor 0
		}
		if(m==2){
			while(m==2){
				cout << "ENTRE COM O NOME E A QUANTIDADE VENDIDA" << endl;
				//ainda nao adicionado alterar ultima variavel valor 1
				cout << "DESEJA CONTINUAR DIGITE 2, SE NAO QUALQUER OUTRA COISA" << endl;
				cin >> m; 
			}			
		}
	}
    if(m==4){
	cout << "finalizando" << endl;
	n=0;
	}


	}
    return 0;
}
