#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include "IndiceInvertido.hpp"
#include "Documento.hpp"
#include "../include/doctest.h"

using namespace std;

class Teste{
  public:
    static map<string, vector<Documento>> getIndice(const IndiceInvertido& i){
        return i.indice;
    }

    static vector<Documento> getDocumentos(const IndiceInvertido& i){
        return i.documentos;
    }

    static int getNumDocumentos(const IndiceInvertido& i){
        return i.numDocumentos;
    }
};


TEST_SUITE("IndiceInvertido"){

    TEST_CASE("IndiceInvertido(const vector<Documento> documentos)"){
        string nome = "Doc";
        map<string, int> m;
        m["a"] = 1;
        m["c"] = 2;
        m["b"] = 3;
        Documento d(nome, m);
        vector<Documento> docs;
        docs.push_back(d);
        IndiceInvertido i(docs);

        map<string, vector<Documento>> m2;
        m2["a"] = docs;
        m2["b"] = docs;
        m2["c"] = docs;

        CHECK_EQ(m2, Teste::getIndice(i));
        CHECK_EQ(1, Teste::getNumDocumentos(i));
        CHECK_EQ(docs, Teste::getDocumentos(i));
    }

    TEST_CASE("getDocumentosFromPalavra(string palavra)"){
        string nome = "doc";
        map<string, int> m;
        m["a"] = 4;
        m["b"] = 2;
        Documento d1(nome + "1", m);
        m["c"] = 1;
        Documento d2(nome + "2", m);
        vector<Documento> docs;
        docs.push_back(d2);
        docs.push_back(d1);
        IndiceInvertido i(docs);

        CHECK_EQ(docs, i.getDocumentosFromPalavra("a"));
        CHECK_NE(docs, i.getDocumentosFromPalavra("c"));
        docs.pop_back();
        CHECK_EQ(docs, i.getDocumentosFromPalavra("c"));
    }
}