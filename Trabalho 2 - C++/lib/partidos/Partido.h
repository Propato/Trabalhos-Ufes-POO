#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Candidato;

class Partido{
private:
    //=====================================
    //              VARIAVEIS
    //=====================================
    int numeroPartido, votosLegenda;
    string siglaPartido;
    list<Candidato*> candidatos;

public:
    //=====================================
    //            CONSTRUTORES
    //=====================================
    Partido();
    Partido(const int &numeroPartido, const int & votosLegenda, const string &siglaPartido);

    //=====================================
    //              SETTER
    //=====================================
    void setCandidato(Candidato &candidato);
    
    //=====================================
    //              GETTERS
    //=====================================
    const int &getVotosLegenda();
    const int &getNumeroPartido();
    const string &getSiglaPartido();
    list<Candidato*> *getCandidatos();

    //=====================================
    //              FUNÇÕES
    //=====================================
    /*        
        Descrição: Soma o total de votos nominais válidos de cada candidato do partido.
        
        Entrada: Nenhuma.

        Retorno: int com o número de votos nominais válidos totais.

        Saída: Nenhuma.

        Pré-condição: Candidatos adicionados corretamente a lista de candidatos do partido.

        Pós-condição: Soma e retorno correto dos votos totais.
    */
    int totalVotosNominaisValidos();

    /*        
        Descrição: Soma o total de votos do partido (votos nominais de cada candidato e votos de legenda).
        
        Entrada: Nenhuma.

        Retorno: int com o número de votos totais.

        Saída: Nenhuma.

        Pré-condição: Função this.totalVotosNominaisValidos() funcionando corretamente.

        Pós-condição: Retorno correto da soma.
    */
    int totalVotos();

    /*        
        Descrição: Soma o número de candidatos eleitos do partido.
        
        Entrada: Nenhuma.

        Retorno: int com a quantidade de eleitos.

        Saída: Nenhuma.

        Pré-condição: Candidatos adicionados corretamente a lista de candidatos do partido.

        Pós-condição: Retorno correto do número de eleitos do partido.
    */
    int candidatosEleitos();

    /*        
        Descrição: Função auxiliar de ordenação dos candidatos do partido em função do número de votos nominais de cada um.
        
        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Nenhuma.

        Pré-condição: Candidatos adicionados corretamente a lista de candidatos do partido.

        Pós-condição: Ordenação correta dos candidatos.
    */
    void ordenarVotosNominais();
};

#endif