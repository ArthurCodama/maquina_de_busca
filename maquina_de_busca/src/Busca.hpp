#ifndef BUSCA_H
#define BUSCA_H

#include <iostream>
#include <set>
#include <vector>
#include "Documento.hpp"
#include "Vetor.hpp"
#include "IndiceInvertido.hpp"

using std::string;
using std::set;
using std::vector;

class Busca{
  public:
    Busca(IndiceInvertido& indice);

    //Realiza busca e retorna um vector, ordenado pela ordem de similaridade, com os documentos
    void realizaBusca(string query);

  private:
    IndiceInvertido indice;
    vector<Vetor> vetores;
    int numDocumentos;

    //Gera um vetor para repreentar cada documento
    vector<Vetor> geraVetores();

    //Gera um vetor para representar um documento ou query
    Vetor geraVetor(const Documento& d, set<string> palavras);

    //Importancia da palavra em um documento
    double idf(string palavra) const;

    //Monta um documento a partir de uma string
    Documento getDocQuery(string query) const;

    //Calcula a similaridade entre dois documentos utilizando o 'Cosine Ranking'
    double sim(const Vetor& v1, const Vetor& v2);

};

#endif