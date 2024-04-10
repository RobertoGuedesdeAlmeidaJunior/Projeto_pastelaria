//Roberto Guedes de Almeida Junior
#include<iostream>
#include<locale>
#include<fstream>
using namespace std;

//PS: Dessa vez meu amigo não errou, eu espero.
struct Estoque{
    int queijo = 50000;
    int presunto = 20000;
    int frango = 10000;
};
Estoque estoque;// variavel para chamar a estrutura estoque
struct Pedido {
    int Senha;
    int Sabor;
    int QuantidadePasteis;
    int Refrigerante;
    int QuantidadeRefrigerante;
    Pedido* proximo = NULL;
    Pedido* anterior = NULL;
};
Pedido pedido;//variável para chamar atributos do pedido
struct ListaPedido {
    Pedido* primeiro;
};
//Tentei fugir de criar uma variável ou vetor para guardar cada sabor e refrigerante, mas não achei outra forma simples de criar um relatório.
struct Relatorio {
    int cocaCola = 0;
    int pepsi = 0;
    int pastelVento =0;
    int pastelFrango = 0;
    int pastelQueijo = 0;
    int pastelPizza = 0;
};
Relatorio relatorio;
int tamanhoLista = 0;

void inicializarLista(ListaPedido& lista) {
    lista.primeiro = NULL;
}

void adicionarPedido(ListaPedido& lista, int sabor, int quantidadePasteis, int refrigerante, int quantidadeRefrigerante) {
    int novaSenha = 1;
    
    if (lista.primeiro != NULL) { 
    Pedido* atual = lista.primeiro; 
        while (atual->proximo != NULL) { 
            atual = atual->proximo; 
        }
        novaSenha = atual->Senha + 1; 
    }
    Pedido* novoPedido = new Pedido{novaSenha, sabor, quantidadePasteis, refrigerante, quantidadeRefrigerante};
    if (lista.primeiro == NULL) { 
        lista.primeiro = novoPedido;
    } else {
        Pedido* atual = lista.primeiro;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoPedido;
        novoPedido->anterior = atual;
    }
    tamanhoLista++;
 if (sabor == 1) {
    if (estoque.queijo < 30 * quantidadePasteis || estoque.presunto < 30 * quantidadePasteis) {
        cout << "Faltam ingredientes para fazer " << quantidadePasteis << " pastel(is) de pizza.\n";
        if (lista.primeiro != NULL) {
        Pedido* atual = lista.primeiro;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        if (atual->anterior != NULL) {
            atual->anterior->proximo = NULL;
        } else {
            lista.primeiro = NULL;
        }
        cout << "Pedido com a senha " << atual->Senha << " não foi possível ser feito" << endl;
        delete atual;
        tamanhoLista--;
        }
    } else {
        estoque.queijo = estoque.queijo - 30 * quantidadePasteis;
        estoque.presunto = estoque.presunto - 30 * quantidadePasteis;
    }
 } else if (sabor == 2) {
    if (estoque.queijo < 50 * quantidadePasteis) {
        cout << "Faltam ingredientes para fazer " << quantidadePasteis << " pastel(is) de queijo.\n";
        if (lista.primeiro != NULL) {
            Pedido* atual = lista.primeiro;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        if (atual->anterior != NULL) {
            atual->anterior->proximo = NULL;
        } else {
            lista.primeiro = NULL;
        }
        cout << "Pedido com a senha " << atual->Senha << " não foi possível ser feito" << endl;
        delete atual;
        tamanhoLista--;
        }
    } else {
        estoque.queijo = estoque.queijo - 50 * quantidadePasteis;
    }
 } else if (sabor == 3) {
    if (estoque.frango < 50 * quantidadePasteis) {
        cout << "Faltam ingredientes para fazer " << quantidadePasteis << " pastel(is) de frango.\n";
        if (lista.primeiro != NULL) {
            Pedido* atual = lista.primeiro;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            if (atual->anterior != NULL) {
                atual->anterior->proximo = NULL;
            } else {
                lista.primeiro = NULL;
            }
            cout << "Pedido com a senha " << atual->Senha << " não foi possível ser feito" << endl;
            delete atual;
            tamanhoLista--;
        }
    } else {
    estoque.frango = estoque.frango - 50 * quantidadePasteis;
    }
 }
}
//Fiz essa função para registrar os sabores nas variáveis da struct "relatório".
void adicionarAoRelatorio(int sabor, int quantidadePasteis, int refrigerante, int quantidadeRefrigerante) {
    switch (sabor) {
        case 1: // Pizza, utilizando esse sabor como exemplo, o pastel pizza da estrutura relatório terá o valor do mesmo e a quatidade de pasteis pedidos.
            relatorio.pastelPizza = relatorio.pastelPizza + quantidadePasteis;
            break;
        case 2: // Queijo
            relatorio.pastelQueijo = relatorio.pastelQueijo + quantidadePasteis;
            break;
        case 3: // Frango
            relatorio.pastelFrango = relatorio.pastelFrango + quantidadePasteis;
            break;
        case 4: // Frango
            relatorio.pastelVento = relatorio.pastelVento + quantidadePasteis;
            break;
        default:
            break;
    }
    switch (refrigerante) {
        case 1: // Coca-Cola
            relatorio.cocaCola = relatorio.cocaCola + quantidadeRefrigerante;
            break;
        case 2: // Pepsi
            relatorio.pepsi = relatorio.pepsi + quantidadeRefrigerante;
            break;
        default:
            break;
    }
}

void removerPedido(ListaPedido& lista) {
    if (lista.primeiro == NULL) {//Se a lista estiver vazia então aparecerá aquela mensagem.
        cout << "Não há pedidos para remover." << endl;
        return;
    }

    int senhaRemover; // variável auxiliar para remover item.
    cout << "Digite a senha do pedido que deseja remover: ";
    cin >> senhaRemover;

    Pedido* atual = lista.primeiro;// a criação do ponteiro atual.

    //Estrutura de Repetição para achar o pedido a ser removido
    while (atual != NULL && atual->Senha != senhaRemover) {//Enquanto o ponteiro for difererente nulo, ou seja a pilha estar vazia ou não há a senha escolhida, e a senha for diferete da senha que tu quer remover
        atual = atual->proximo; //então o atual vai ser percorrido até achar o Senha = senhaRemover
    }

    //Condição caso não achar a senha
    if (atual == NULL) {// Mas caso ocorra do atual ser igual a nulo, então aparecerá que o pedido não foi encontrado
        cout << "Pedido com a senha " << senhaRemover << " não encontrado." << endl;
        return;
    }
    //Aqui chamamos a função "adicionar ao relatório" para todo pedido que for "removido" da lista, logo entregre, ser adicionado ao relatório
    adicionarAoRelatorio(atual->Sabor, atual->QuantidadePasteis, atual->Refrigerante, atual->QuantidadeRefrigerante);

    //Condição para excluir pedidos com exceção do primeiro, e corrigir o ponteiro próximo.
    if (atual->anterior != NULL) {//Caso não for o primeiro da lista, então:
        atual->anterior->proximo = atual->proximo;//vou desenhar isso no caderno, mas para ficar claro o ponteiro atual(o que deseja remover) aponta para o anterior (penultimo)
    //e o ponteiro próximo do pedido antecessor aponta para o próximo do atual, interligando novamente o os ponteiros excluindo o atual.
    } else {
        //Já este else serve para deletar o primeiro item da lista, e como não há um pedido anterior não faz sentido alterar o ponteiro próximo, ao contrário do if a cima.
        lista.primeiro = atual->proximo;//mas se o atual for o primeiro da lista então o primeiro da lista passa a ser o próximo.
    }
    //Condição para excluir pedidos com exceção do ultimo, e corrigir o ponteiro anterior.
    if (atual->proximo != NULL) {// caso o pedido a ser excluido não for o ultimo então:
        atual->proximo->anterior = atual->anterior;// O proximo do atual, no caso o pedido sucessor, terá seu pedido apontado para o ponteiro anterior ao atual.
        //religando a lista e deletando o atual.
    }//nesse if não tem else pois com o if anterior já será apagado o ultimo de maneira correta

    delete atual;
    tamanhoLista--;

    cout << "Pedido com a senha " << senhaRemover << " removido com sucesso." << endl;
}


bool editarPedido(ListaPedido& lista, int Senha, int Sabor, int QuantidadePasteis, int Refrigerante, int QuantidadeRefrigerante) {
    Pedido* atual = lista.primeiro; //Criação do ponteiro auxiliar atual
    while (atual != NULL) {//Estrutura de repetição para o atual circular pela fila
        if (atual->Senha == Senha) { //Se a senha do do ponteiro atual for igual a senha do pedido, então:
            atual->Sabor = Sabor; //O sabor do atual recebe o novo sabor, e assim por diante
            atual->QuantidadePasteis = QuantidadePasteis;
            atual->Refrigerante = Refrigerante;
            atual->QuantidadeRefrigerante = QuantidadeRefrigerante;
            return true;  // Pedido editado com sucesso
        }
        atual = atual->proximo;
    }
    return false;  // Pedido não encontrado
}

void exibirPedido( ListaPedido& lista) {
    if (lista.primeiro == NULL) {//caso não houver pedidos na lista
        cout << "Não há pedidos para exibir." << endl;
        return;
    }

    Pedido* atual = lista.primeiro;//Novamente fazendo um ponteiro auxiliar.

    while (atual != NULL) { //Enquanto a fila não acabar é exibibo a senha o sabor e etc.
        cout << "Senha " << atual->Senha << ": Numero do Sabor:" << atual->Sabor << "; Quantidade de Pasteis:" << atual->QuantidadePasteis
             << "; Numero do Refrigerante:" << atual->Refrigerante << "; Quantidade de Refrigerante:" << atual->QuantidadeRefrigerante
             << " Tamanho da fila:" << tamanhoLista << endl;
        atual = atual->proximo;
    }
}

void exibirEstoque(Estoque& estoque) {
    cout << "||||||||||||||||||||||||\n";
    cout << "|Queijo: " << estoque.queijo << " gramas   |\n";
    cout << "|Presunto: " << estoque.presunto << " gramas|\n";
    cout << "|Frango: " << estoque.frango << " gramas   |\n";
    cout << "||||||||||||||||||||||||\n";
}
void exibirRelatorio() {//OBS: Não foi possível concatenar a função adicionar com exibir relatório, tive que separa-los.
    cout << "BEBIDAS\n========\n";
    cout << "Coca-cola     " << relatorio.cocaCola << " vendidas\n";
    cout << "Pepsi          " << relatorio.pepsi << " vendidas\n";
    cout << "PASTEL\n========\n";
    cout << "Pastel de Frango:  " << relatorio.pastelFrango << " pedidos no dia\n";
    cout << "Pastel de Queijo:   " << relatorio.pastelQueijo << " pedidos no dia\n";
    cout << "Pastel de Pizza:     " << relatorio.pastelPizza << " pedidos no dia\n";
    cout << "Pastel de vento:     " << relatorio.pastelVento << " pedidos no dia\n";
}
void exibirRelatoriotxt() {//OBS: Não foi possível concatenar a função adicionar com exibir relatório, tive que separa-los.
    ofstream arquivo;
    arquivo.open("relatorio.txt");
    arquivo << "BEBIDAS\n========\n";
    arquivo << "Coca-cola     " << relatorio.cocaCola << " vendidas\n";
    arquivo << "Pepsi          " << relatorio.pepsi << " vendidas\n";
    arquivo << "PASTEL\n========\n";
    arquivo << "Pastel de Frango:  " << relatorio.pastelFrango << " pedidos no dia\n";
    arquivo << "Pastel de Queijo:   " << relatorio.pastelQueijo << " pedidos no dia\n";
    arquivo << "Pastel de Pizza:     " << relatorio.pastelPizza << " pedidos no dia\n";
    arquivo << "Pastel de vento:     " << relatorio.pastelVento << " pedidos no dia\n";
    arquivo << "Estoque: ";
    arquivo << "|Queijo: " << estoque.queijo << " gramas   |\n";
    arquivo << "|Presunto: " << estoque.presunto << " gramas|\n";
    arquivo << "|Frango: " << estoque.frango << " gramas   |\n";
    arquivo.close();
}
int main() {
    setlocale(LC_ALL,"portuguese");
    ListaPedido lista;
    inicializarLista(lista);
    int opcao_menu;

    do {
        cout << "||||||||||||||||||||||||||" << endl;
        cout << "|" << " O que deseja fazer? " << "   |" << endl;
        cout << "|" << " 0) Sair  " << "              |" << endl;
        cout << "|" << " 1) Adicionar Pedido" << "    |" << endl;
        cout << "|" << " 2) Excluir Pedido" << "      |" << endl;
        cout << "|" << " 3) Editar Pedido" << "       |" << endl;
        cout << "|" << " 4) Exibir pedidos" << "      |" << endl;
        cout << "|" << " 5) Exibir Estoque" << "      |" << endl;
        cout << "|" << " 6) Exibir Relatório" << "   |" << endl;
        cout << "|" << " 7) Exibir Relatório.txt" << "|" << endl;
        cout << "||||||||||||||||||||||||||" << endl;
        cout << "Digite o numero correspondente ao pedido \n";
        cin >> opcao_menu;

        switch (opcao_menu) {
            case 0:
                    while (tamanhoLista != 0){
                    cout << "Remova as senhas restantes\n";
                    removerPedido(lista);
                    }
                    system("cls");
                    exibirRelatoriotxt();
                    cout << "Programa finalizado com sucesso!";
                break;
            case 1:
                int sabor, quantidadePasteis, refrigerante, quantidadeRefrigerante;
        cout << "||||||||||||||||||||" << endl;
        cout << "|" << " 1)  Pizza" << "        |" << endl;
        cout << "|" << " 2)  Queijo" << "        |" << endl;
        cout << "|" << " 3) Frango" << "        |" << endl;
        cout << "|" << " 4) Vento" << "         |" << endl;
        cout << "||||||||||||||||||||" << endl;
        cout << "Digite o sabor desejado \n";
                cin >> sabor;
                cout << "Digite a quantidade de pasteis desejada: ";
                cin >> quantidadePasteis;
        cout << "||||||||||||||||||||||||||" << endl;
        cout << "Digite o numero do sabor:" << "|" << endl;
        cout << "|" << " 1)Coca-Cola  " << "          |" << endl;
        cout << "|" << " 2) Pepsi " << "              |" << endl;
        cout << "||||||||||||||||||||||||||" << endl;
                cout << "Digite o numero do refrigerante: ";
                cin >> refrigerante;
                cout << "Digite a quantidade de refrigerante desejada: ";
                cin >> quantidadeRefrigerante;

                adicionarPedido(lista, sabor, quantidadePasteis, refrigerante, quantidadeRefrigerante);
                exibirPedido(lista);
                break;
            case 2:
                if (tamanhoLista != 0) {
                    removerPedido(lista);
                } else {
                    cout << "Nao ha nenhum pedido \n";
                }
                break;
           case 3:
                if (tamanhoLista != 0) {
                    int senhaEditar, novoSabor, novaQuantidadePasteis, novoRefrigerante, novaQuantidadeRefrigerante;
                    cout << "Digite a senha do pedido que deseja editar: ";
                    cin >> senhaEditar;
                    cout << "Digite o novo numero do sabor: ";
                    cin >> novoSabor;
                    cout << "Digite a nova quantidade de pasteis desejada: ";
                    cin >> novaQuantidadePasteis;
                    cout << "Digite o novo numero do refrigerante: ";
                    cin >> novoRefrigerante;
                    cout << "Digite a nova quantidade de refrigerante desejada: ";
                    cin >> novaQuantidadeRefrigerante;

                    editarPedido(lista , senhaEditar, novoSabor, novaQuantidadePasteis, novoRefrigerante, novaQuantidadeRefrigerante);//colocando os parametros parao editar pedido
                } else {
                    cout << "Não há nenhum pedido\n";
                }
            case 4:
                if (tamanhoLista != 0) {
                    exibirPedido(lista);
                } else {
                    cout << "Não há nenhum pedido\n";
                }
                break;
           case 5:
                exibirEstoque(estoque);
                break;

            case 6:
                exibirRelatorio();
                exibirEstoque(estoque);
                break;
            case 7:
            exibirRelatoriotxt();
            break;
            default:
             break;
        }

    } while (opcao_menu != 0);

    return 0;
}
