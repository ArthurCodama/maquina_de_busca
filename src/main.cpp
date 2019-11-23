#include <iostream>
#include <string>
#include "Documento.hpp"
#include "IndiceInvertido.hpp"
#include "Busca.hpp"
#include "Util.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
  string aux, query, diretorio = "baseDeDados/";
  char opcao;
  vector<Documento> docs;
  do{
  cout << "Selecione uma opcao:" << endl
       << "1 - Adicionar arquivo a base de dados" << endl
       << "2 - Fazer Pesquisa" << endl
       << "0 - Sair" << endl;
  cin >> opcao;
  cout << endl;
  switch (opcao){
  case '1':
    Util::adicionaDocumento(docs);
    break;
  case '2':
    if(docs.size() > 0){
      Util::buscar(docs);
    } else{
      cout << "Operacao bloqueada! Deve ser adicionado um arquivo antes de realizar a pesquisa"
    }
    
    break;
  case '0':
    return 0;
    break;
  default:
    cout << "Entrada invalida!" << endl;
    break;
  }
  cout << endl;
  } while(true);

  system("pause");
}