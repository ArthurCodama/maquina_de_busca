#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
#include "Util.hpp"
#include "Documento.hpp"
#include "IndiceInvertido.hpp"
#include "Busca.hpp"


using std::string;
using std::to_string;
using std::ifstream;
using std::map;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;



string Util::toLower(string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string Util::formataTexto(string texto){
  string textoFormatado = Util::toLower(texto);
  //Trecho de código inspirado de https://stackoverflow.com/questions/6319872/how-to-strip-all-non-alphanumeric-characters-from-a-string-in-c
  textoFormatado.erase(std::remove_if(textoFormatado.begin(), textoFormatado.end(), 
    []( auto const& c ) -> bool { 
      return !(std::isalnum(c) || c == ' '); 
    } ), textoFormatado.end()
  );
  return textoFormatado;
}

map<string, int> Util::getPalavrasFromTexto(string texto){
  stringstream ss(texto);
  map<string, int> palavras;
  string palavra;

  while(ss >> palavra){
    palavras[palavra]++;
  }

  return palavras;
}

void Util::adicionaDocumento(vector<Documento>& docs){
  string texto = "";
  string linha;
  string localArquivo;
  bool valido = false;

  do{
    cout << "Digite o local e nome do arquivo: ";
    cin >> localArquivo;

    ifstream arquivo(localArquivo);
    valido = arquivo.is_open();

    if(valido){
      while(!arquivo.eof()){
        std::getline(arquivo, linha);
        texto +=  linha;
      }
      arquivo.close();
      texto = formataTexto(texto);
      map<string, int> palavras = getPalavrasFromTexto(texto);
      docs.push_back(Documento(localArquivo, palavras));

    } else{
      cout << endl << "Local ou nome do arquivo invalido!" << endl;
    }
  }while(!valido);

}

void Util::buscar(vector<Documento> docs){
  string query;
  IndiceInvertido i = IndiceInvertido(docs);
  Busca b = Busca(i);

  cout << "Digite sua pesquisa: ";
  cin >> query;

  b.realizaBusca(query);
}

void Util::imprimeDocumentos(const map<double, vector<Documento>, std::greater<double>>& docs){
  int i = 0;

  for(const auto& pair: docs){
    for(const auto& doc: pair.second){
      cout << "Posicao " << i << " | Arquivo: " << doc.getNome();
      cout << endl;
    }
    i++;
  }
}