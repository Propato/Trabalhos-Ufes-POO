#include "../../lib/partidos/Partido.h"
#include "../../lib/candidatos/Candidato.h"
#include "../../lib/candidatos/RelatoriosCandidatos.h"

using namespace std;

Partido::Partido(){ }

Partido::Partido(const int &numeroPartido, const int &votosLegenda, const string &siglaPartido){
    this->numeroPartido = numeroPartido;
    this->votosLegenda = votosLegenda;
    this->siglaPartido = siglaPartido;
}

void Partido::setCandidato(Candidato &candidato){ this->candidatos.push_back(&candidato); }

const int &Partido::getVotosLegenda(){ return this->votosLegenda; }
const int &Partido::getNumeroPartido(){ return this->numeroPartido; }
const string &Partido::getSiglaPartido(){ return this->siglaPartido; }
list<Candidato*> *Partido::getCandidatos(){ return &this->candidatos; }

int Partido::totalVotosNominaisValidos(){
    int total=0;
    for(Candidato *v: this->candidatos) total += v->getVotosNominais();
    return total;
}

int Partido::totalVotos(){
    return this->totalVotosNominaisValidos()+this->votosLegenda;
}

int Partido::candidatosEleitos(){
    int quantidade=0;
    for(Candidato *v: this->candidatos) if(v->getSituacao()) quantidade++;
    return quantidade;
}

void Partido::ordenarVotosNominais(){
    RelatoriosCandidatos relatorio(this->candidatos);
    relatorio.ordenarVotosNominais();
}