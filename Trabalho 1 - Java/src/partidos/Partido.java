package partidos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import candidatos.Candidato;

public class Partido implements Comparable<Partido>{
    /* 
        =========================================
                        VARIAVEIS
        =========================================
    */
    int numeroPartido, votosLegenda;
    String nomePartido, siglaPartido;
    ArrayList<Candidato> candidatos = new ArrayList<Candidato>();

    /* 
        =========================================
                        INICIALIZAÇÃO
        =========================================
    */
    Partido(){}

    public Partido(int numeroPartido, int votosLegenda, String nomePartido, String siglaPartido){
        
        this.numeroPartido = numeroPartido;
        this.votosLegenda = votosLegenda;
        this.nomePartido = nomePartido;
        this.siglaPartido = siglaPartido;
    }

    /* 
        =========================================
                        SETTERS
        =========================================
    */

    public void setCandidato(Candidato candidato){
        candidatos.add(candidato);
    }
    
    /* 
        =========================================
                        GETTERS
        =========================================
    */
    
    public int getNumeroPartido(){ return numeroPartido; }
    public String getSiglaPartido(){ return siglaPartido; }
    
    /* 
        =========================================
                        FUNÇÕES
        =========================================
    */

    /*        
        Descrição: Soma o total de votos nominais válidos de cada candidato do partido.
        
        Entrada: Nenhuma.

        Retorno: int com o número de votos nominais válidos totais.

        Saída: Nenhuma.

        Pré-condição: Candidatos adicionados corretamente ao ArrayList de candidatos do partido.

        Pós-condição: Soma e retorno correto dos votos totais.
    */
    public int totalVotosNominaisValidos(){
        int total=0;
        for(Candidato v: this.candidatos){
                total+=v.getVotosNominais();
        }
        return total;
    }

    /*        
        Descrição: Soma o total de votos do partido (votos nominais de cada candidato e votos de legenda).
        
        Entrada: Nenhuma.

        Retorno: int com o número de votos totais.

        Saída: Nenhuma.

        Pré-condição: Função this.totalVotosNominaisValidos() funcionando corretamente.

        Pós-condição: Retorno correto da soma.
    */
    public int totalVotos(){
        return this.totalVotosNominaisValidos()+this.votosLegenda;
    }

    /*        
        Descrição: Soma o número de candidatos eleitos do partido.
        
        Entrada: Nenhuma.

        Retorno: int com a quantidade de eleitos.

        Saída: Nenhuma.

        Pré-condição: Candidatos adicionados corretamente ao ArrayList de candidatos do partido.

        Pós-condição: Retorno correto do número de eleitos do partido.
    */
    public int candidatosEleitos(){
        int quantidade=0;
        for(Candidato v:this.candidatos){
            if(v.getSituacao().compareTo("Eleito")==0){
                quantidade++;
            }
        }
        return quantidade;
    }

   /*        
        Descrição: (comparable) compara dois partidos de acordo com os seguintes critérios (já em ordem de prioridade): total de votos do partido (ordem decrescente) e menor número partidário.
        
        Entrada: Uma variavel da classe Partido.

        Retorno: Retorna a diferença entre o total de votos dos dois partidos comparados. Em caso da diferença ser nula, retorna a diferença do numero do partido comparador ao comparado
        
        Pré-condição: Cada partido da lista deve ter sua lista de candidatos preenchida  

        Pós-condição: Retorno correto do resultado.
    */
    public int compareTo(Partido p){
        int resultado = p.totalVotos()-this.totalVotos();
        if(resultado==0){
            resultado = this.numeroPartido - p.numeroPartido;
        }
        return resultado;
    }

   /*        
        Descrição: (comparator) compara dois partidos de acordo com os seguintes critérios (já em ordem de prioridade): votos de legenda do partido, total de votos nominais do partido e menor número partidário.
        
        Entrada: Duas variaveis da classe Partido.

        Retorno: Retorna a diferença entre os votos de legenda dos dois partidos comparados. Em caso da diferença ser nula, retorna a diferença entre os votos nominais válidos dos partidos .Em caso da diferença ser novamente nula, retorna a diferença do numero do partido comparador ao comparado

        Pré-condição: Cada partido da lista deve ter sua lista de candidatos preenchida  

        Pós-condição: Retorno correto do resultado.
    */
    public static class comparadorVotosLegenda implements Comparator<Partido>{
        @Override
        public int compare(Partido p0, Partido p1) {
            int resultado = p1.votosLegenda - p0.votosLegenda;
            if(resultado==0){
                resultado = p1.totalVotosNominaisValidos() - p0.totalVotosNominaisValidos();
                if(resultado==0){
                    resultado = p0.numeroPartido - p1.numeroPartido;
                }
            }
            return resultado;
        }
    }

   /*        
        Descrição: (comparator) compara dois partidos de acordo com os seguintes critérios (já em ordem de prioridade): votos nominais do candidato mais votado de cada partido e menor número partidário.
        
        Entrada: Duas variaveis da classe Partido.

        Retorno: Retorna a diferença entre os votos nominais do candidato mais votado dos partidos comparados. Em caso da diferença ser novamente nula, retorna a diferença do numero do partido comparador ao comparado.
        
        Pré-condição: Cada partido da lista deve ter sua lista de candidatos preenchida  

        Pós-condição: Retorno correto do resultado.
    */
    public static class comparadorVotosNominais implements Comparator<Partido>{
        @Override
        public int compare(Partido p0, Partido p1){
            Collections.sort(p1.candidatos);
            Collections.sort(p0.candidatos);
            
            if(p1.candidatos.size() == 0 && p0.candidatos.size() == 0){ return p0.numeroPartido - p1.numeroPartido; }
            if(p1.candidatos.size() == 0 && p0.candidatos.size() != 0){ return -p0.candidatos.get(0).getVotosNominais(); }
            if(p1.candidatos.size() != 0 && p0.candidatos.size() == 0){ return p1.candidatos.get(0).getVotosNominais(); }

            int resultado = p1.candidatos.get(0).getVotosNominais() - p0.candidatos.get(0).getVotosNominais();
            if(resultado==0){
                resultado = p0.numeroPartido - p1.numeroPartido;
            }
            return resultado;
        }
    }
}
