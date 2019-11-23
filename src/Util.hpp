#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <map>
#include <vector>
#include "Documento.hpp"

using std::string;
using std::map;
using std::vector;

class Util{
    public:
        //Formata o texto passando para minusculo e retirando caracteres especiais
        static string formataTexto(string texto);

        //Retorna o mapa de palavras relacionado ao numero de vezes que ela aparece em um texto formatado
        static map<string, int> getPalavrasFromTexto(string texto);
        
        //Cria um documento a partir de um arquivo
        static void adicionaDocumento(vector<Documento>& docs);

        //Realiza uma busca
        static void buscar(vector<Documento> docs);

        //Passa uma string para minusculo
        static string toLower(string s);

        //Imprime os documentos ordenados da busca
        static void imprimeDocumentos(const map<double, vector<Documento>, std::greater<double>>& docs);

    friend class Teste;
};

#endif