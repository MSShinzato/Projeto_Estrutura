#include <iostream>
#include "Produto.h"
#include "Compras.h"
using namespace std;

int main() {

    int op;

    while (1){
        cout << "Sistema de vendas" << endl;
        cout << "1 - Adicionar produto" << endl;
        cout << "2 - Remover produto" << endl;
        cout << "3 - Buscar produto" << endl;
        cout << "4 - Realizar compra" << endl;
        cout << "5 - Sair" << endl;

        cin >> op;

        switch(op) {
            case 1:

            case 2:

            case 3:

            case 4:
                // arrumar volta
                bool volta;
                Compras c;
                volta = c.Menu();
                if (volta == false){
                    volta = true;
                }
            case 5:
                return 0;
        }
    }
}