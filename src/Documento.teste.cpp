#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include "Documento.hpp"
#include "../include/doctest.h"

using namespace std;

class Teste{
  public:
    static string getNome(const Documento& d){
        return d.nome;
    }

    static map<string, int> getPalavras(const Documento& d){
        return d.palavras;
    }

    static int getNumPalavras(const Documento& d){
        return d.numPalavras;
    }

    static int getId(const Documento& d){
        return d.__id;
    }
};


TEST_SUITE("Documento"){

    TEST_CASE("Documento(string nome, map<string, int>& palavras)"){
        string nome = "teste";
        map<string, int> m;
        m["a"] = 2;
        m["b"] = 1;
        Documento doc(nome, m);
        CHECK_EQ(nome, Teste::getNome(doc));
        CHECK_EQ(3, Teste::getNumPalavras(doc));
        CHECK_EQ(1, Teste::getPalavras(doc).count("b"));
        CHECK_EQ(2, Teste::getPalavras(doc).at("a"));
    }

    TEST_CASE("operator=(const Documento& d)"){
        string nome = "doc";
        map<string, int> m;
        m["a"] = 4;
        m["b"] = 2;
        Documento d1(nome + "1", m);
        m["c"] = 1;
        Documento d2(nome + "2", m);
        d2 = d1;
        CHECK_EQ(Teste::getNome(d1), Teste::getNome(d2));
        CHECK_EQ(Teste::getNumPalavras(d1), Teste::getNumPalavras(d2));
        CHECK_EQ(Teste::getPalavras(d1), Teste::getPalavras(d2));
        CHECK_EQ(Teste::getId(d1), Teste::getId(d2));
    }

    TEST_CASE("operator==(Documento& d1)"){
        string nome = "doc";
        map<string, int> m;

        m["a"] = 4;
        m["b"] = 2;
        Documento d1(nome, m);
        Documento d2(nome, m);
        CHECK_EQ(d1, d2);
        m["b"]++;
        Documento d3(nome, m);
        CHECK_NE(d1, d3);
        CHECK_NE(d2, d3);
    }

    TEST_CASE("getPalavras()"){
        string nome = "d";
        map<string, int> m;
        m["a"] = 1;
        m["b"] = 2;
        m["c"] = 10;
        set<string> s;
        s.insert("a");
        s.insert("b");
        s.insert("c");
        Documento d(nome, m);
        CHECK_EQ(s, d.getPalavras());
        CHECK_EQ(3, d.getPalavras().size());
    }
}