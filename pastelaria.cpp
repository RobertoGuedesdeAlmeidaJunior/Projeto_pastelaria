#include <iostream>

using namespace std;

struct pedido{
  int sabores[3];
  int refrigenarte[1];
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
  no_pedido *proximo = nullptr;
};
void adicionar_pedido(){
no_pedido *proximo= new no_pedido;
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
