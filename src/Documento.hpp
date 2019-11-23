#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <iostream>
#include <map>
#include <set>

using std::string;
using std::map;
using std::set;

class Documento{
  public:

    Documento();

    Documento(string nome, map<string, int>& palavras);

    // Número de vezes que uma string aparece no texto do documento
    int ocorrencias(string encontrar) const;

    string getNome() const;

    int getNumPalavras() const;

    int getId() const;

    bool operator==(Documento& d1) const;

    Documento operator=(const Documento& d);

    set<string> getPalavras() const;

  private:
    static int num;
    int __id;
    string nome;
    int numPalavras;

    //Mapa com a key igual a palavra e o conteudo igual a quantidade de vezes que essa palavra aparece no texto
    map<string, int> palavras;
  friend class Teste;
};

#endif