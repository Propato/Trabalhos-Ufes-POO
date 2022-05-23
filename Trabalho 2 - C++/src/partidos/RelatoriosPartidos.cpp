#include "../../lib/partidos/Partido.h"
#include "../../lib/partidos/RelatoriosPartidos.h"
#include "../../lib/candidatos/RelatoriosCandidatos.h"
#include "../../lib/comum/Excecoes.h"

bool compareVotosTotais(Partido *comparador, Partido *comparado){
    int comp = comparado->totalVotos() - comparador->totalVotos();
    comp = !comp?(comparador->getNumeroPartido() - comparado->getNumeroPartido()):comp;
    return comp<0?true:false;
}

bool compareVotosLegenda(Partido *comparador, Partido *comparado){
    int comp = comparado->getVotosLegenda() - comparador->getVotosLegenda();
    comp = !comp?(comparado->totalVotosNominaisValidos() - comparador->totalVotosNominaisValidos()):comp;
    comp = !comp?(comparador->getNumeroPartido()-comparado->getNumeroPartido()):comp;
    return comp<0?true:false;
}

bool compareVotosNominais(Partido *comparador, Partido *comparado){
    if(!comparador->getCandidatos()->size() && !comparado->getCandidatos()->size()) return (comparador->getNumeroPartido() - comparado->getNumeroPartido())<0?true:false;
    if(!comparador->getCandidatos()->size() && comparado->getCandidatos()->size()) return false;
    if(comparador->getCandidatos()->size() && !comparado->getCandidatos()->size()) return true;

    Candidato *c1 = 0, *c2 = 0;
    c1 = *comparador->getCandidatos()->begin();
    c2 = *comparado->getCandidatos()->begin();

    int resultado = c2->getVotosNominais() - c1->getVotosNominais();
    if(!resultado) resultado = comparador->getNumeroPartido() - comparado->getNumeroPartido();
    return resultado<0?true:false;
}

RelatoriosPartidos::RelatoriosPartidos(list<Partido*> &partidos){
    if(partidos.empty()){
        throw Nulos("partidos");
        return ;
    }
    this->partidos = &partidos;
}

RelatoriosPartidos::~RelatoriosPartidos(){
    for(Partido* p:*this->partidos){
        for(Candidato* c: *p->getCandidatos()){
            delete c;
        }
        delete p;
    }
}

void RelatoriosPartidos::ordenarVotosTotais(){
    this->partidos->sort(compareVotosTotais);
}

void RelatoriosPartidos::ordenarVotosLegenda(){
    this->partidos->sort(compareVotosLegenda);
}

void RelatoriosPartidos::ordenarVotosNominais(){
    this->partidos->sort(compareVotosNominais);
}

void RelatoriosPartidos::votosTotais(){

    this->ordenarVotosTotais();
    cout << "\n\nVotação dos partidos e número de candidatos eleitos:";
    int classificacao=1;
    for(Partido *p: *this->partidos)
        cout << endl<< classificacao++ << " - " << p->getSiglaPartido() << " - " << p->getNumeroPartido() << ", " << p->totalVotos() << (p->totalVotos()<2?" voto (":" votos (") << p->totalVotosNominaisValidos() << (p->totalVotosNominaisValidos()<2?" nominal e ":" nominais e ") << p->getVotosLegenda() << " de legenda), " <<  p->candidatosEleitos()  <<  (p->candidatosEleitos()<2?" candidato eleito":" candidatos eleitos");
}

void RelatoriosPartidos::votosLegenda(){

    int classificacao=1;
    double porcentagem = 0;
    ordenarVotosLegenda();

    cout << "\n\nVotação dos partidos (apenas votos de legenda):";
    for(Partido *p: *this->partidos){
        porcentagem = 100*(p->totalVotos()>0?((double)p->getVotosLegenda()/p->totalVotos()):0);
        cout << "\n" << classificacao << " - " << p->getSiglaPartido().c_str() << " - " << p->getNumeroPartido() << ", " << p->getVotosLegenda();
        p->getVotosLegenda()<2? cout << " voto de legenda (": cout << " votos de legenda (";
        p->totalVotos()>0? cout << porcentagem << "% do total do partido)": cout << "proporção não calculada, 0 voto no partido)";
        classificacao++;
    }
}

void RelatoriosPartidos::primeiroUltimoColocados(){

    cout << "\n\nPrimeiro e último colocados de cada partido:";
    int classificacao = 1;
    Candidato *primeiro = 0, *ultimo = 0;

    for(Partido *p: *this->partidos) if(!p->getCandidatos()->empty()) p->ordenarVotosNominais();
    this->ordenarVotosNominais();

    for(Partido *p: *this->partidos){
        primeiro = *p->getCandidatos()->begin();

        if(p->getCandidatos()->size() && primeiro && primeiro->getVotosNominais()>0){
            ultimo = *p->getCandidatos()->rbegin();
            cout << endl << classificacao << " - " << p->getSiglaPartido() << " - " << p->getNumeroPartido() << ", ";
            cout << primeiro->getNomeUrna() << " (" << primeiro->getNumero() << ", " << primeiro->getVotosNominais() << (primeiro->getVotosNominais()>1?" votos":" voto");
            cout << ") / " << ultimo->getNomeUrna() << " (" << ultimo->getNumero() << ", " << ultimo->getVotosNominais() << (ultimo->getVotosNominais()>1?" votos":" voto") << ")";
            classificacao++;
        }
    }
}

void RelatoriosPartidos::panoramaVotos(){
    
    int votosNominais = 0, votosLegenda=0;
    double total =0;

    for(Partido *v:*this->partidos){
        votosNominais+=v->totalVotosNominaisValidos();
        votosLegenda+=v->getVotosLegenda();
    }
    total = votosNominais+votosLegenda;

    cout << "\n\nTotal de votos válidos:    " << votosNominais+votosLegenda;    
    cout << "\nTotal de votos nominais:   " << votosNominais;
    cout << " (" << 100*votosNominais/total << "%)";
    cout << "\nTotal de votos de legenda: " << votosLegenda;
    cout << " (" << 100*votosLegenda/total << "%)\n\n";
}
