#include "../../lib/partidos/Partido.h"
#include "../../lib/candidatos/Candidato.h"

using namespace std;

Candidato::Candidato(){ }

Candidato::Candidato(const int &numero, const int &votosNominais, bool situacao, const string &nome, const string &nomeUrna, const string &genero, const string &dataNasc, const int &numeroPartido){
    this->numero = numero;
    this->votosNominais = votosNominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nomeUrna = nomeUrna;
    this->genero = genero;
    this->numeroPartido = numeroPartido;
    this->dataNasc = dataNasc;
}

void Candidato::setPartido(Partido &partido){ this->partido = &partido; }

const string &Candidato::getNome(){ return this->nome; }
const string &Candidato::getNomeUrna(){ return this->nomeUrna; }
const string &Candidato::getGenero(){ return this->genero; }
const bool &Candidato::getSituacao(){ return this->situacao; }
const int &Candidato::getNumero(){ return this->numero; }
const int &Candidato::getNumeroPartido(){ return this->numeroPartido; }
const int &Candidato::getVotosNominais(){ return this->votosNominais; }
Data &Candidato::getData(){ return this->dataNasc; }
Partido* Candidato::getPartido(){ return this->partido; }


void Candidato::imprime(){
    cout << this->getNome()<<" / " << this->getNomeUrna()<< " (" << this->getPartido()->getSiglaPartido()<< ", " << this->getVotosNominais() << " votos)";
}