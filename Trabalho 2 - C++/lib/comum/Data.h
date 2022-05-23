#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data{
private:
    //=====================================
    //             VARIAVEIS
    //=====================================
    int dia, mes, ano;

public:
    //=====================================
    //            CONSTRUTORES
    //=====================================
    Data(const int &dia, const int &mes, const int &ano);
    Data(const string &string, char const delimiter = '/');
    Data();

    //=====================================
    //              GETTERS
    //=====================================
    const int &getDia();
    const int &getMes();
    const int &getAno();

    //=====================================
    //              FUNÇÕES
    //=====================================
    /*
        Descrição: escreve data no formato dia, mes e ano utilizado parametro delimiter para intercalar valores
        
        Entrada: string contendo delimitador a ser utilizado
        
        Retorno: string formatada da data
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: texto no formato dia, mes e ano
    */
    const string data_stringfy(const string &delimiter);

    /*
        Descrição: compara o quão distante está a data comparada com a data atual
        
        Entrada: data a ser comparada
        
        Retorno: o número de dias que separam a data comparada à comparadora. Caso ambas sejam iguais, retorna 0

        Saída: 
        
        Pré-condição: ambas as datas devem ser posteriores ao marco de contagem (1/1/1900)

        Pós-condição: 
    */
    const int compare(Data &data_comparada);

    /*
        Descrição: imprime a data no padrão dd/mm/yyyy (utiliza barra como separador)
        
        Entrada: 
        
        Retorno: 

        Saída: impressao na saida padrao da data
        
        Pré-condição: data fornecida deve ser processável pela função data_stringfy

        Pós-condição: 
    */
    void print();

    /*
        Descrição: converte e atribui diretamente strings no formato dd/mm/yyyy para o formato data
        
        Entrada: string a ser convertida para data
        
        Retorno: conversão e cópia da data na string para variável instanciada

        Saída: possível lançamento de invalid_argument em caso da string fornecida não estar no formato adequado
        
        Pré-condição: string deve estar no formato dd/mm/yyyy

        Pós-condição: 
    */
    void operator = (const string &str);

    /*
        Descrição: subtrai duas datas
        
        Entrada: datas a serem subtraidas
        
        Retorno: tempo decorrido no formato dd/mm/yyyy entre ambas as datas

        Saída: possível lançamento de invalid_argument em caso da string fornecida não estar no formato adequado
        
        Pré-condição: string deve estar no formato dd/mm/yyyy

        Pós-condição: 
    */
    const Data operator - (Data &d) const;
};

//=====================================
//            NAMESPACE
//   COM FUNÇÔES UTEIS SOBRE DATAS
//=====================================
namespace DataInfo{ 
    /*
        Descrição: calcula número total de dias (365 ou 366) num ano específico.
        
        Entrada: ano a ser calculado total de dias. (int)
        
        Retorno: 366 para anos bissextos ou 365 caso contrário.

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Número de dias corretos para ano especificado.
    */
    const int totalDiasAno(const int &ano);

    /*
        Descrição:  calcula o número de dias de uma data desde o início de um ano específico
        
        Entrada: dia e mes da data a ser calculada e o ano de sua ocorrência (ints)
        
        Retorno: data convertida em número de dias (int) 

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Número de dias corretos para ano especificado.
    */
    const int numeroDiasData(const int &dias, const int &mes, const int &ano);

    /*
        Descrição: diz se ano é bissexto ou não
        
        Entrada: ano a ser testado (int)
        
        Retorno: true caso seja bissexto, false caso contrário

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: 
    */
    const bool bissexto(const int &ano);
    
    /*
        Descrição:  retorna o número total de dias de um mês a depender do ano
        
        Entrada: mes a ser testado e seu ano
        
        Retorno: 31, 30, 28 ou 29 a depender do mes

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Número de dias corretos para ano especificado.
    */
    const int diasMes(const int &mes, const int &ano);
    
    /*
        Descrição: calcula o numero total de dias desde a data padrão (1/1/1990)
        
        Entrada: dia, mes e ano da data (ints)
        
        Retorno: número total de dias (int)

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Número de dias corretos para ano especificado.
    */
    const int diasSinceOrigin(const int &dia, const int &mes, const int &ano);
    
    /*
        Descrição: calcula o numero total de dias desde a data especificada
        
        Entrada: dia, mes e ano da data (ints) e data de origem (data)
        
        Retorno: número total de dias (int)

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Número de dias corretos para ano especificado.
    */
    const int diasSinceData(const int &dia, const int &mes, const int &ano, Data &d);
    
    /*
        Descrição: converte o total de dias em relação a uma marco temporal numa da data
        
        Entrada: número total de dias desde a data em questão, dia inicial, mes inicial e ano inicial da contagem (ints)
        
        Retorno: data

        Saída: 
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Data correta para ano especificado.
    */
    const Data converterDiasData(int &dias, const int &dia_c = 1, const int &mes_c = 1, const int &ano_c = 1900);
}

#endif