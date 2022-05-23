#include <iostream>
#include <sstream>

#include "../../lib/comum/Excecoes.h"

using namespace std;

Exception::Exception(){ }
const string Exception::what(){ return "\nException:\n"; }

ErroAbertura::ErroAbertura(const string &arquivo)
    { this->arquivo = arquivo; }

const string ErroAbertura::what(){
    return "\nException: erro na abertura do arquivo < " + arquivo + " >.";
}


ErroLeituraArquivo::ErroLeituraArquivo(const string &arquivo, const int &nLinha)
{   this->arquivo = arquivo;
    this->nLinha = to_string(nLinha); }
const string ErroLeituraArquivo::what(){
    return "\nException: erro na leitura do arquivo < " + arquivo + " >, na linha " + nLinha + ".\n";
}


ErroLeituraLinhaCandidatos::ErroLeituraLinhaCandidatos(const string &arquivo, const int &nLinha)
{   this->arquivo = arquivo;
    this->nLinha = to_string(nLinha); }
const string ErroLeituraLinhaCandidatos::what(){
    return "\nException: erro no padrão do arquivo < " + arquivo + " >, na linha " + nLinha + ".\n" + "Padrão correto: numero,votos_nominais,situacao,nome,nome_urna,sexo,data_nasc,destino_voto,numero_partido\n" + "Linha ignorada.\n";
}


ErroLeituraLinhaPartidos::ErroLeituraLinhaPartidos(const string &arquivo, const int &nLinha)
{   this->arquivo = arquivo;
    this->nLinha = to_string(nLinha); }

const string ErroLeituraLinhaPartidos::what(){
    return "\nException: erro no padrão do arquivo < " + arquivo + " >, na linha " + nLinha + ".\n" + "Padrão correto: numero_partido,votos_legenda,nome_partido,sigla_partido\n";
}


Nulos::Nulos(const string &classe)
    { this->classe = classe; }
const string Nulos::what(){
    return "\nException: erro, lista de " + classe + " nulos.";
}