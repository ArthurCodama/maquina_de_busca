#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
#include "Util.hpp"
#include "Documento.hpp"

using std::string;
using std::to_string;
using std::ifstream;
using std::map;
using std::stringstream;
using std::cout;
using std::endl;

string Util::toLower(string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string Util::formataTexto(const string texto){
  string textoFormatado = Util::toLower(texto);
  auto it(
    remove_if(textoFormatado.begin(), textoFormatado.end(), [](char c){
        int i = (int)c;
        return ( i != 32 && (i < 97 || i > 122) && (i < 48 || i > 57) );
      }
    )
  );
  
  textoFormatado.erase(it);
  cout << texto << "formataTexto" << endl;
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

Documento Util::documentoFromArquivo(string localArquivo){
  string texto = "";
  string linha;
  ifstream arquivo(localArquivo);

  if(arquivo.is_open()){
    while(!arquivo.eof()){
      std::getline(arquivo, linha);
      texto +=  linha;
    }
    arquivo.close();
    texto = formataTexto(texto);
    map<string, int> palavras = getPalavrasFromTexto(texto);
    cout << texto << "documentoFromArquivo" << endl;
    return Documento(localArquivo, palavras);

  } else{
    return Documento();
  }

}

void Util::imprimeDocumentos(const map<double, vector<Documento>, std::greater<double>>& docs){
  int i = 0;
  for(const auto& pair: docs){
    for(const auto& doc: pair.second){
      cout << i << "º Arquivo: " << doc.getNome() << endl;
    }
  }
}