#ifndef INDICEINVERTIDO_H
#define INDICEINVERTIDO_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "Documento.hpp"

using std::string;
using std::map;
using std::set;
using std::vector;

class IndiceInvertido{
  public:
    IndiceInvertido();

    IndiceInvertido(const vector<Documento>& documentos);

    set<string> getPalavras();

    vector<Documento> getDocumentos();

    int getNumDocumentos();

    int getNumPalavras();

    //Retorna os documentos que uma palavra aparece
    vector<Documento> getDocumentosFromPalavra(string palavra) const;

  private:
    map<string, vector<Documento>> indice;
    vector<Documento> documentos;
    int numDocumentos;
};

#endif