#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include "Documento.hpp"
#include "IndiceInvertido.hpp"
#include "Vetor.hpp"
#include "Busca.hpp"
#include "../include/doctest.h"

using namespace std;

class Teste{
  public:
    static IndiceInvertido getIndice(const Busca& b){
        return b.indice;
    }

    static vector<Vetor> getVetores(const Busca& b){
        return b.vetores;
    }

    static int getNumDocumentos(const Busca& b){
        return b.numDocumentos;
    }

    static Documento getDocQuery(const Busca& b, string query){
        return b.getDocQuery(query);
    }

    static Vetor geraVetor(const Busca& b, Documento& d, set<string> p){
        return b.geraVetor(d, p);
    }

    static double idf(const Busca& b, string s){
        return b.idf(s);
    }

    static double sim(const Busca& b, Vetor& v1, Vetor& v2){
        return b.sim(v1, v2);
    }

};


TEST_SUITE("Busca"){
    TEST_CASE("Busca(IndiceInvertido& indice)"){
        string nome = "busca";
        map<string, int> m;
        m["a"] = 1;
        m["c"] = 2;
        m["b"] = 3;
        Documento d(nome, m);
        vector<Documento> docs;
        docs.push_back(d);
        IndiceInvertido i(docs);
        Busca b(i);

        CHECK_EQ(i.getDocumentos(), Teste::getIndice(b).getDocumentos());
        CHECK_EQ(i.getNumPalavras(), Teste::getIndice(b).getNumPalavras());
        CHECK_EQ(i.getPalavras(), Teste::getIndice(b).getPalavras());
        CHECK_EQ(1, Teste::getNumDocumentos(b));
    }

    TEST_CASE("getDocQuery(string query)"){
        string nome = "busca", query = "A b B";
        map<string, int> m;
        m["a"] = 1;
        m["b"] = 2;
        Documento d1(nome, m);
        vector<Documento> docs;
        docs.push_back(d1);
        IndiceInvertido i(docs);
        Busca b(i);

        Documento d2 = Teste::getDocQuery(b, query);
        CHECK_EQ(d1, d2);
    }

    TEST_CASE("geraVetor(const Documento& d, set<string> palavras)"){
        string nome = "busca";
        map<string, int> m;
        m["a"] = 1;
        m["b"] = 2;
        Documento d(nome, m);
        vector<Documento> docs;
        docs.push_back(d);
        IndiceInvertido i(docs);
        Busca b(i);
        auto p = i.getPalavras();
        Vetor v(d);

        CHECK_EQ(Teste::geraVetor(b, d, p).getVetor(), v.getVetor());
    }

    TEST_CASE("idf(string palavra)"){
        string nome = "busca", s = "a";
        map<string, int> m;
        m["a"] = 1;
        m["b"] = 2;
        m["c"] = 3;
        Documento d(nome, m);
        vector<Documento> docs;
        docs.push_back(d);
        IndiceInvertido i(docs);
        Busca b(i);

        CHECK_GT(pow(10, -5), abs(log10(1) - Teste::idf(b, s)));
    }
    
    TEST_CASE("sim(const Vetor& v1, const Vetor& v2)"){
        string nome = "busca", query = "B A a b";
        map<string, int> m;
        m["a"] = 2;
        m["b"] = 2;
        Documento d(nome, m);
        vector<Documento> docs;
        docs.push_back(d);
        IndiceInvertido i(docs);
        Busca b(i);

        auto p = i.getPalavras();
        Vetor v(d);
        auto dq = Teste::getDocQuery(b, query);
        Vetor v1(d);
        Vetor v2(dq);

        CHECK_EQ((double) 1, Teste::sim(b, v1, v2));
    }

}