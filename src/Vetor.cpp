#include <iostream>
#include <vector>
#include <map>
#include "Vetor.hpp"
#include "Documento.hpp"

using std::vector;

Vetor::Vetor(const Documento& doc){
    this->documento = doc;
}

vector<double> Vetor::getVetor(){
    return this->vetor;
}

Documento Vetor::getDocumento() const{
    return this->documento;
}

void Vetor::adicionar(double d){
    vetor.push_back(d);
}

double Vetor::dot(const Vetor& v) const{
    double prodInterno = 0;
    for(unsigned int i = 0; i < this->vetor.size(); i++){
        prodInterno += this->vetor[i] * v.vetor[i];
    }
    
    return prodInterno;
}