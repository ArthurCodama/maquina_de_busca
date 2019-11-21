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
  string query, diretorio = "baseDeDados/";
  cout << "TESTE1";
  Documento d1 = Util::documentoFromArquivo(diretorio+"d1.txt"), 
  d2 = Util::documentoFromArquivo(diretorio+"d2.txt"),
  //d3 = Util::documentoFromArquivo(diretorio+"d3.txt"), 
  d4 = Util::documentoFromArquivo(diretorio+"d4.txt");
  vector<Documento> docs;
  
  cout << "TESTE";
  docs.push_back(d1);
  cout << "TESTE";
  docs.push_back(d2);
  //docs.push_back(d3);
  docs.push_back(d4);
  IndiceInvertido i = IndiceInvertido(docs);
  Busca b = Busca(i);
  cout << "Digite sua pesquisa: ";
  cin >> query;
  b.realizaBusca(query);

  system("pause");
}