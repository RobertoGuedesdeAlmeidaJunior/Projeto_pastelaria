#include <iostream>

using namespace std;

struct pedido{
  int sabores;
  int refrigenarte;
  int senha = 0;
};
struct no_pedido
{
  pedido pedido;
  no_pedido *proximo;
  no_pedido *anterior;
};
struct estoque
{
  int queijo = 50000;
  int presunto = 20000;
  int frango = 10000;
};
  int tamanho_lista=0;
void inicializar(){
  no_pedido *proximo = nullptr;
  no_pedido *anterior = nullptr;
};
void adicionar_pedido(){
no_pedido *proximo= new no_pedido;
no_pedido -> pedido;
pedido->senha = pedido.senha ++;
tamanho_lista ++;
}
void remover_pedido(){
  if(tamanho_lista !=0 ){
    int senha_removida;
     senha_removida -> anterior;
  }
}

int main(int argc, char const *argv[])
{
  inicializar();
  int opcao;
  cout << "|||||||||||||||||||||||||||||||";
  cout << "||1)Realizar um pedido       ||";
  cout << "||2)Remover um pedido        ||";
  cout << "||3)Editar um pedido         ||";
  cout << "||4)Mostrar os pedidos       ||";
  cout << "||5)Mostrar estoque          ||";
  cout << "||6)Fazer Relatório          ||";
  cout << "||7)Fazer Relatório.txt      ||";
  cout << "||0)sair                     ||";
  cout << "|||||||||||||||||||||||||||||||";
  switch(opcao){
    case 0:

    break;
    case 1:
      adicionar_pedido();
    break;
  }
  return 0;
}

