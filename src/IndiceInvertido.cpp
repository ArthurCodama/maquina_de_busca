#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "IndiceInvertido.hpp"
#include "Documento.hpp"

using std::string;
using std::map;
using std::set;
using std::vector;

IndiceInvertido::IndiceInvertido(){
    
}

IndiceInvertido::IndiceInvertido(const vector<Documento> documentos){
    for(Documento documento : documentos) {
        for(string palavra : documento.getPalavras()) {
            indice[palavra].push_back(documento);
        }
    }
    this->documentos = documentos;
    this->numDocumentos = documentos.size();
}

int IndiceInvertido::getNumDocumentos(){
    return this->numDocumentos;
}

vector<Documento> IndiceInvertido::getDocumentos(){
    return this->documentos;
}

int IndiceInvertido::getNumPalavras(){
    return this->indice.size();
}

set<string> IndiceInvertido::getPalavras(){ 
    set<string> palavras;

    for(auto& pair: this->indice){
        palavras.insert(pair.first);
    }

    return palavras;
}

vector<Documento> IndiceInvertido::getDocumentosFromPalavra(string palavra) const{
    return this->indice.at(palavra);
}