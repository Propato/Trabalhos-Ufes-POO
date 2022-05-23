#ifndef LEITURA_H
#define LEITURA_H

#include "../candidatos/Candidato.h"
#include "../partidos/Partido.h"

using namespace std;

class Leitura { 

public:

    //=====================================
    //              FUNÇÕES
    //=====================================

    /* 
        Descrição: Realiza a abertura do arquivo de entrada e sua leitura, criando uma lista da classe Candidato e para cada linha lida um candidato é iniciado usando a função lerCandidato() e inserido na lista.
        
        Entrada: Uma string com o nome do arquivo a ser lido.

        Retorno: Uma lista dos candidatos lidos.
        
        Pré-condição: Que o arquivo lido apresente a primeira linha sendo um cabeçalho igual à "numero,votos_nominais,situacao,nome,nome_urna,sexo,data_nasc,destino_voto,numero_partido" e que suas demais linhas sigam o padrão do cabeçalho.

        Pós-condição: Instancias de Candidato ainda não completamente preenchidas. Necessário proceder com a setagem do campo Partido.
    */
    list<Candidato*> lerCandidatos(const string &arquivo);

    /* 
        Descrição: Realiza a abertura do arquivo de entrada e sua leitura, criando um list da classe Partido e para cada linha lida um partido é iniciado usando a função lerPartido() e inserido no list.
        
        Entrada: Uma string com o nome do arquivo a ser lido.

        Retorno: Um list dos partidos lidos.
        
        Pré-condição: Que o arquivo lido apresente a primeira linha sendo um cabeçalho igual à "numero_partido,votos_legenda,nome_partido,sigla_partido" e que suas demais linhas sigam o padrão do cabeçalho.

        Pós-condição: Realize a abertura e leitura do arquivo e a criação do list da classe Partido corretamente.
    */
    list<Partido*> lerPartidos(const string &arquivo);
};


#endif