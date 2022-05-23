#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>
#include <string>

#include "../comum/Data.h"

using namespace std;

class Partido;

class Candidato{
private:
    //=====================================
    //              VARIAVEIS
    //=====================================
    string nome, nomeUrna, genero;
    int numero, numeroPartido, votosNominais;
    bool situacao;
    Data dataNasc;
    Partido *partido;

public:
    //=====================================
    //            CONSTRUTORES
    //=====================================
    Candidato();
    Candidato(const int &numero, const int &votosNominais, bool situacao, const string &nome, const string &nomeUrna, const string &genero, const string &dataNasc, const int &numeroPartido);

    //=====================================
    //              SETTER
    //=====================================
    void setPartido(Partido &partido);

    //=====================================
    //              GETTERS
    //=====================================
    const string &getNome();
    const string &getNomeUrna();
    const string &getGenero();
    const bool &getSituacao();
    const int &getNumero();
    const int &getNumeroPartido();
    const int &getVotosNominais();
    Data &getData();
    Partido* getPartido();

    //=====================================
    //              FUNÇÃO
    //=====================================
    /*
        Descrição: Imprime dados do candidato (nome, nome na urna, sigla do partida e número de votos nominais) na saída padrão. 
        
        Entrada: Nenhuma.
        
        Retorno: Nenhum.

        Saída: Imprime os dados do candidato.
        
        Pré-condição: Objeto deve apresentar todos seus campos preenchidos.

        Pós-condição: Impressão correta dos dados.
    */
    void imprime();
};
#endif