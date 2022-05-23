#ifndef RELATORIOSCANDIDATOS_H
#define RELATORIOSCANDIDATOS_H

#include <iostream>
#include <string>
#include <list>

#include "Candidato.h"

class Partido;

class RelatoriosCandidatos{
private:
    //=====================================
    //              VARIAVEL
    //=====================================
    list<Candidato*> *candidatos;

public:
    //=====================================
    //             CONSTRUTOR
    //=====================================
    RelatoriosCandidatos(list<Candidato*> &candidatos);

    //=====================================
    //             FUNÇÕES
    //=====================================
    /* 
        Descrição: Função que associa cada candidato com seu partido e cada partido com seus candidatos.

        Entrada: list de ponteiros para a classe Partido contendo todos os partidos lidos.

        Retorno: Nenhuma.

        Saída: Nenhuma.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Partidos associados corretamente com seus candidatos e candidatos associados corretamernte com o seu partido.
    */
    void associarPartidosCandidatos(list<Partido*> &partidos);
        
    /*
        Descrição: Ordena os candidatos em ordem decrescente de acordo com o número de votos nominais. Em caso de empate o mais velho tem prioridade.

        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Nenhuma.

        Pré-condição: lista de candidatos preenchida corretamente no objeto.

        Pós-condição: lista ordenado corretamente.

    */
    void ordenarVotosNominais();

    /*
        Relatório 1
        Enunciado: Número de vagas (= número de eleitos);

        Descrição: Imprime e retorna o número de canditados eleitos.

        Entrada: Nenhuma.

        Retorno: int de número de candidatos eleitos (número de vagas).

        Saída: Relatório do número de vagas.

        Pré-condição: Lista do objeto preenchida corretamente.

        Pós-condição: Número de candidatos eleitos retornado correto e impressão correta dos candidato que se encaixam na especificação acima.
    */
    int vagas();

    /*
        Relatório 2
        Enunciado: Candidatos eleitos (nome completo e na urna), indicado partido e número de votos nominais;

        Descrição: Imprime todos os candidatos eleitos.

        Entrada: int com o número de vagas.

        Retorno: Nenhum.

        Saída: Relatório dos eleitos.

        Pré-condição: Lista do objeto e entrada preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    void eleitos (const int &vagas);

    /*
        Relatório 3
        Enunciado: Candidatos mais votados dentro do número de vagas;

        Descrição: Imprime os candidatos com mais votos nominais, com o limite de candidatos impressos sendo o número de vagas.

        Entrada: int com o número de vagas.

        Retorno: Nenhum.

        Saída: Relatório dos mais votados.

        Pré-condição: Lista do objeto e entrada preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    void maisVotados(const int &vagas);

    /*
        Relatório 4
        Enunciado: Candidatos não eleitos e que seriam eleitos se a votação fosse majoritária;

        Descrição: Imprime corretamente os candidatos não eleitos e que seriam eleitos na votação majoritária.

        Entrada: int com o número de vagas.

        Retorno: Nenhum.

        Saída: Relatório dos candidatos quase eleitos.

        Pré-condição: Lista do objeto e entrada preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    void naoEleitos(const int &vagas);

    /*
        Relatório 5
        Enunciado: Candidatos eleitos no sistema proporcional vigente, e que não seriam eleitos se a votação fosse
        majoritária, isto é, pelo número de votos apenas que um candidato recebe diretamente;
        Eleitos, que se beneficiaram do sistema proporcional:

        Descrição: Imprime os candidatos eleitos no sistema proporcional mas que não seriam eleitos na votação majoritária.

        Entrada: int com o número de vagas.

        Retorno: Nenhum.

        Saída: Relatório dos eleitos que se beneficiaram.

        Pré-condição: Lista do objeto e entrada preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    void eleitosBeneficiados(const int &vagas);
        
    /*
        Relatório 9
        Enunciado: Distribuição de eleitos por faixa etária, considerando a idade do candidato no dia da eleição;

        Descrição: Imprime a porcentagem de eleitos em cada faixa etaria (<30, 30< e <40, 40< e <50, 50< e <60, e >60) em razão do total de eleitos.

        Entrada: string com a data das eleições.

        Retorno: Nenhum.

        Saída: Relatório das faixas etaria.

        Pré-condição: Lista do objeto e entrada preenchidas corretamente.

        Pós-condição: Impressão correta das especificações acima.
    */
    void eleitosFaixaEtaria(const string &data);

    /*
        Relatório 10
        Enunciado: Distribuição de eleitos por sexo;

        Descrição: Imprime a porcentagem de eleitos com base no sexo (M ou F).

        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Relatório das porcentagens entre sexos.

        Pré-condição: Lista do objeto preenchida corretamente.

         Pós-condição: Impressão correta das especificação acima.
    */
    void eleitosSexo();
};

#endif