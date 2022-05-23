#include "../../lib/candidatos/RelatoriosCandidatos.h"
#include "../../lib/candidatos/Candidato.h"
#include "../../lib/partidos/Partido.h"
#include "../../lib/comum/Data.h"
#include "../../lib/comum/Excecoes.h"
    
using namespace std;

RelatoriosCandidatos::RelatoriosCandidatos(list<Candidato*> &candidatos){
    if(candidatos.empty()){
        throw Nulos("candidatos");
        return ;
    }
    this->candidatos = &candidatos;
}

void RelatoriosCandidatos::associarPartidosCandidatos(list<Partido*> &partidos){
    
    for(Partido *p: partidos){
        for(Candidato *c: *this->candidatos){
            if(p->getNumeroPartido() == c->getNumeroPartido()){
                c->setPartido(*p);
                p->setCandidato(*c);
            }
        }
    }
}

bool compareVotosNominais(Candidato *comparador, Candidato *comparado){     
    int resultado = comparador->getVotosNominais() - comparado->getVotosNominais();
    if(!resultado){
        Data d = comparador->getData();
        resultado = comparado->getData().compare(d);
    }
    return resultado>0?true:false;
}

void RelatoriosCandidatos::ordenarVotosNominais(){
    this->candidatos->sort(compareVotosNominais);
}

int RelatoriosCandidatos::vagas(){
    
    int vagas=0;
    for(Candidato *c:*this->candidatos)if(c->getSituacao()) vagas++;
    cout << "Número de vagas: " << vagas;
    return vagas;
}

void RelatoriosCandidatos::eleitos (const int &vaga){
    
    int classificacao = 0;
    this->ordenarVotosNominais();

    cout << "\n\nVereadores eleitos:";

    for(Candidato *c:*this->candidatos){
        if(c->getSituacao()){
            cout << "\n" << ++classificacao << " - ";
            c->imprime();
            if(classificacao > vaga) break;
        }
    }
}

void RelatoriosCandidatos::maisVotados(const int &vagas){
    
    int classificacao = 1;
    this->ordenarVotosNominais();

    cout << "\n\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):";

    for(Candidato *c: *candidatos){
        cout << "\n" << classificacao << " - ";
        c->imprime();
        classificacao++;
        if(classificacao>vagas) break;
    }
}

void RelatoriosCandidatos::naoEleitos(const int &vagas){
    
    int votos_de_corte=0, classificacao=0;
    this->ordenarVotosNominais();
    
    for(Candidato *c: *candidatos){
        if(classificacao>vagas) break;
        if(c->getSituacao()){
            votos_de_corte = c->getVotosNominais();
            classificacao++;    
        }
    }

    cout<<"\n\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)";
    
    classificacao=0;
    for(Candidato *c: *candidatos){
        classificacao++;
        
        if((c->getVotosNominais() > votos_de_corte) && !c->getSituacao()){
            cout<< "\n" << classificacao << " - ";
            c->imprime();
        }
        if(classificacao == vagas) break;
    }
}

void RelatoriosCandidatos::eleitosBeneficiados(const int &vagas){
    
    int classificacao = 0;
    this->ordenarVotosNominais();

    cout << "\n\nEleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)";

    for(Candidato *c: *candidatos){
        classificacao++;

        if(classificacao>vagas)
            if(c->getSituacao()){
                cout << "\n" << classificacao << " - ";
                c->imprime();
            }
    }
}

void RelatoriosCandidatos::eleitosFaixaEtaria(const string &data){
    
    cout << "\n\nEleitos, por faixa etária (na data da eleição):";
    try{
        int menor30=0, entre3039=0, entre4049=0, entre5059=0, maior60=0, anos=0;
        double total=0;
        Data dataHoje(data), idade;
        for(Candidato* v:*this->candidatos){
            if(v->getSituacao()){
                idade = (v->getData() - dataHoje);
                anos = idade.getAno();
                if(anos<30) menor30++;
                else if(anos<40) entre3039++;
                else if(anos<50) entre4049++;
                else if(anos<60) entre5059++;
                else maior60++;
            }
        }
        total = menor30+entre3039+entre4049+entre5059+maior60;
        cout << "\n      Idade < 30: " <<  menor30 << " (" << 100*menor30/total << "%)";
        cout << "\n30 <= Idade < 40: " << entre3039 << " (" << 100*entre3039/total << "%)";
        cout << "\n40 <= Idade < 50: " << entre4049 << " (" << 100*entre4049/total << "%)";
        cout << "\n50 <= Idade < 60: " << entre5059 << " (" << 100*entre5059/total << "%)";
        cout << "\n60 <= Idade     : " << maior60 << " (" << 100*maior60/total << "%)";
    }
    catch(invalid_argument &e){
       cout << e.what();
    }
    catch(exception &e){
        cout << "\nExcpetion: erro desconhecido na execução do programa.";
    }
    catch(...){
        cout << "\nExcpetion: erro desconhecido na execução do programa.";
    }
}

void RelatoriosCandidatos::eleitosSexo(){
    
    int m=0, f=0;
    double total=0;

    cout << "\n\nEleitos, por sexo:";
    
    for(Candidato* v:*this->candidatos) if(v->getSituacao()) v->getGenero()=="M"?m++:f++;
    total = f+m;
    cout << "\nFeminino:  "<< f << " (" << 100*f/total << "%)";
    cout << "\nMasculino: "<< m << " (" << 100*m/total << "%)";
}