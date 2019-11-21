#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include "Busca.hpp"
#include "IndiceInvertido.hpp"
#include "Documento.hpp"
#include "Vetor.hpp"
#include "Util.hpp"

using std::string;
using std::set;
using std::vector;

Busca::Busca(IndiceInvertido& indice){
    this->indice = indice;
    this->numDocumentos = indice.getNumDocumentos();
}

void Busca::realizaBusca(string query){
    vector<Vetor> vetores = this->geraVetores();
    Documento docQuery = this->getDocQuery(query);
    Vetor vetorQuery = this->geraVetor(docQuery, this->indice.getPalavras());
    map<double, vector<Documento>, std::greater<double>> simDocXQuery;

    for(const Vetor& vetor: vetores){
        simDocXQuery[this->sim(vetor, vetorQuery)].push_back(vetor.getDocumento());
    }

    Util::imprimeDocumentos(simDocXQuery);
}

vector<Vetor> Busca::geraVetores(){
    vector<Vetor> vetores;
    vector<Documento> docs = this->indice.getDocumentos();
    set<string> palavras = this->indice.getPalavras();

    for(const Documento doc: docs){
        vetores.push_back(this->geraVetor(doc, palavras));
    }

    return vetores;
}

Vetor Busca::geraVetor(const Documento& d, set<string> palavras){
    Vetor v = Vetor(d);

    for(string s: palavras){
        v.adicionar(this->idf(s) * d.ocorrencias(s));
    }

    return v;
}

double Busca::idf(string palavra) const{
    int nx = this->indice.getDocumentosFromPalavra(palavra).size();

    return log10(this->numDocumentos/nx);
}

Documento Busca::getDocQuery(string query) const{
    map<string, int> mapa;
    string aux = Util::formataTexto(query);

    mapa = Util::getPalavrasFromTexto(aux);

    return Documento("", mapa);
}

double Busca::sim(const Vetor& v1, const Vetor& v2){
    double numerador;
    double denominador1, denominador2;

    numerador = v1.dot(v2);
    denominador1 = sqrt(v1.dot(v1));
    denominador2 = sqrt(v2.dot(v2));

    if(denominador1 * denominador2 != 0){
        return numerador / (denominador1 * denominador2);
    } else{
        return 0;
    }
}