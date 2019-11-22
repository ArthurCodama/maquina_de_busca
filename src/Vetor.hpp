#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <vector>
#include "Documento.hpp"

using std::string;
using std::vector;

class Vetor{
  public:

    Vetor(const Documento& doc);

    vector<double> getVetor();

    Documento getDocumento() const;

    //Adiciona um valor ao vetor
    void adicionar(double d);
    
    //Produto interno entre dois vetores de mesma dimensao
    double dot(const Vetor& v) const;

  private:
    vector<double> vetor;
    Documento documento;

};

#endif