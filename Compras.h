//
// Created by Marcelo Shinji on 23/09/2019.
//

#ifndef PROJETO_COMPRAS_H
#define PROJETO_COMPRAS_H

class Compras{
public:
    bool Menu(){
        while (true){
            int op1;
            cout << "1 - Adicionar produto ao carrinho" << endl;
            cout << "2 - Remover produto ao carrinho" << endl;
            cout << "3 - Imprimir lista de compra" << endl;
            cout << "4 - Cancelar" << endl;

            cin >> op1;

            switch(op1) {
                case 1:

                case 2:

                case 3:

                case 4:
                    return false;
            }
        }
    }

    bool Adicionar(){
        return true;
    }
    int Remover(){
        return 0;
    }
    void Imprimir(){

    }
};

#endif //PROJETO_COMPRAS_H
