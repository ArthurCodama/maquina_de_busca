#include <iostream>
#include <vector>
#include <map>
#include "Documento.hpp"

using std::map;

int Documento::num = 0;

Documento::Documento(){
    this->nome = "";
}

Documento::Documento(string nome, map<string, int>& palavras){
    this->__id = this->num++;
    this->nome = nome;
    this->palavras = palavras;

    for(auto i: palavras){
        this->numPalavras += i.second;
    }
}

bool Documento::operator==(Documento& d) const{
    return this->__id == d.__id;
}

Documento Documento::operator=(const Documento& d) {
    this->__id = d.__id;
    this->nome = d.nome;
    this->palavras = d.palavras;
    this->numPalavras = d.numPalavras;

    return *this;
}

int Documento::getId() const{
    return this->__id;
}

int Documento::ocorrencias(string encontrar) const{
    if(palavras.count(encontrar) == 1){
        return palavras.at(encontrar);
    } else{
        return 0;
    }
}

int Documento::getNumPalavras() const{
    return this->numPalavras;
}

string Documento::getNome() const{
    return this->nome;
}

set<string> Documento::getPalavras() const{
    set<string> palavras;

    for(auto& pair: this->palavras){
        palavras.insert(pair.first);
    }

    return palavras;
}