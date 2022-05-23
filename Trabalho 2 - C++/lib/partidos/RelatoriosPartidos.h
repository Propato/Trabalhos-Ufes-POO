#ifndef RELATORIOSPARTIDOS_H
#define RELATORIOSPARTIDOS_H

#include <list>
#include "../candidatos/Candidato.h"

using namespace std;

class RelatoriosPartidos {
private:
    //=====================================
    //              VARIAVEL
    //=====================================
    list<Partido*> *partidos;

public:
    //=====================================
    //            CONSTRUTOR
    //=====================================
    RelatoriosPartidos(list<Partido*> &partidos);
    //=====================================
    //             DESTRUTOR
    //=====================================
    ~RelatoriosPartidos();

    //=====================================
    //             FUNÇÕES
    //=====================================

    /*
        Descrição: Funções de ordenação dos partidos em multiplas ordens.

        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Nenhuma.

        Pré-condição: Lista preenchida corretamente.

        Pós-condição: Lista ordenado corretamente.

    */
    //Critério: Ordenação com base nos votos totais dos partidos. Em caso de empate, o com menor número partidário terá prioridade
    void ordenarVotosTotais();
    //Critério: Ordenação com base nos votos de legenda dos partidos. Em caso de empate, o partido com mais votos nominais terá prioridade. Em caso de novo empate, o com menor número partidário terá prioridade.
    void ordenarVotosLegenda();
    //Critério: Ordenação com base nos votos totais dos partidos. Em caso de empate, o com menor número partidário terá prioridade. Lembrando que se dois candidatos tiverem o mesmo número de votos, o mais velho terá prioridade.
    void ordenarVotosNominais();

    /*  
        Relatório 6
        Enunciado: Votos totalizados por partido e número de candidatos eleitos;
        
        Descrição: Contabiliza o número total de votos por partido e o número de candidatos eleitos.
        
        Entrada: Nenhuma.
        
        Retorno: Nenhum.

        Saída: Relatório dos votos totais.
        
        Pré-condição: Lista do objeto preenchida corretamente.

        Pós-condição: Lista ordenada corretamente através da função ordenarVotosTotais() e impressão correta das especificação acima.
    */
    void votosTotais();

    /*  
        Relatório 7
        Enunciado: Votos de legenda (com a porcentagem destes votos frente ao total de votos no partido);
        
        Descrição: Contabiliza o numero total de votos de legenda por partido e a fração desses em relação ao total dos votos do partido (ou seja, votos de legenda+votos nominais)
        
        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Relatório dos votos de legenda.
        
        Pré-condição: Lista do objeto preenchida corretamente. 

        Pós-condição: Lista ordenada corretamente através da função ordenarVotosLegenda() e impressão correta das especificação acima.
    */
    void votosLegenda();

    /*  
        Relatório 8
        Enunciado: Primeiro e último colocados de cada partido (com nome da urna, número do candidato e total de votos nominais).
        
        Descrição: Relata informações sobre o primeiro e último colocados (válidos) de cada partido. Partidos sem candidatos válidos são ignorados.
        
        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Relatório dos primeiros e últimos colocados.
        
        Pré-condição: Lista do objeto preenchida corretamente.

        Pós-condição: Lista ordenada corretamente através da função ordenarVotosNominais() e impressão correta das especificação acima.
    */
    void primeiroUltimoColocados();

    /*  
        Relatório 11
        Enunciado: Total de votos, total de votos nominais e total de votos de legenda.
        
        Descrição: Relata informações sobre o total de votos, total de votos nominais (válidos) e total de votos de legenda (válidos) da eleição.
        
        Entrada: Nenhuma.

        Retorno: Nenhum.

        Saída: Relatório dos votos.
        
        Pré-condição: Lista do objeto preenchida corretamente.

        Pós-condição: Impressão correta das especificação acima. 
    */
    void panoramaVotos();
};
#endif