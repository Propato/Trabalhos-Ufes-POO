package partidos;

import java.io.PrintStream;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Collections;

import candidatos.Candidato;

public class DadosPartidos {
    /*  
        Descrição: Ordena os partidos em ordem decrescente de acordo com o número de votos nominais. Em caso de empate, os mais velhos tem prioridade.
        
        Entrada: ArrayList da classe Partido.
        
        Retorno: Nenhum.
        
        Saída: Nenhuma.

        Pré-condição: Entrada preenchida corretamente.
        
        Pós-condição: ArrayList ordenado corretamente.
    */
    public void ordenaPartidos(ArrayList<Partido> partidos){
        Collections.sort(partidos);
    }

    /*  Relatório 6
        Enunciado: Votos totalizados por partido e número de candidatos eleitos;
        O Relatório 6 deve estar em ordem decrescente de acordo com o total de votos do partido (nominais
        mais de legenda). Em caso de empate, o com menor número partidário terá prioridade.
        
        Descrição: Contabiliza o numero total de votos por partido e o numero de candidatos eleitos.
        
        Entrada: ArrayList da classe Partido e PrintStream da saída padrão.
        
        Retorno: Nenhum.

        Saída: Relatório dos votos totais.
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta das especificação acima. 
    */
    public void votosTotais(ArrayList<Partido> partidos, PrintStream saida){

            saida.println("\n\nVotação dos partidos e número de candidatos eleitos:");
            int classificacao=1;
            for(Partido p: partidos){
                saida.println(classificacao+" - "+p.siglaPartido+" - "+p.numeroPartido+", "+p.totalVotos()+(p.totalVotos()<2?" voto (":" votos (")+p.totalVotosNominaisValidos()+(p.totalVotosNominaisValidos()<2?" nominal e ":" nominais e ")+p.votosLegenda+" de legenda), "+ p.candidatosEleitos() + (p.candidatosEleitos()<2?" candidato eleito":" candidatos eleitos"));
                classificacao++;
            }
    }
 
    /*  Relatório 7
        Enunciado: Votos de legenda (com a porcentagem destes votos frente ao total de votos no partido);
        O Relatório 7 deve estar em ordem decrescente de acordo com o número de votos de legenda do partido.
        Em caso de empate, o partido com mais votos nominais terá prioridade. Em caso de novo empate, o
        com menor número partidário terá prioridade.
        
        Descrição: Contabiliza o numero total de votos de legenda por partido e a fração desses em relação ao total dos votos do partido (ou seja, votos de legenda+votos nominais)
        
        Entrada: ArrayList da classe Partido e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos votos de legenda.
        
        Pré-condição: Entradas preenchidas corretamente. 

        Pós-condição: ArrayList em ordem decrescente de acordo com os seguintes critérios (já em ordem de prioridade): total de votos de legenda do partido, total de votos nominais do partido e menor número partidário.
    */
    public void votosLegenda(ArrayList<Partido> partidos, PrintStream saida){
            Collections.sort(partidos, new Partido.comparadorVotosLegenda());
            saida.println("\nVotação dos partidos (apenas votos de legenda):");
            int classificacao=1;
            double porcentagem = 0;
            NumberFormat formatacao = new DecimalFormat("#0.00%");
            for(Partido p: partidos){
                porcentagem = (p.totalVotos()>0?((double)p.votosLegenda/p.totalVotos()):0);
                saida.println(classificacao+" - "+p.siglaPartido+" - "+p.numeroPartido+", "+p.votosLegenda+(p.votosLegenda<2?" voto de legenda (":" votos de legenda (")+(p.totalVotos()>0?(formatacao.format(porcentagem)+" do total do partido)"):"proporção não calculada, 0 voto no partido)"));
                classificacao++;
            }
    }

    /*  Relatório 8
        Enunciado: Primeiro e último colocados de cada partido (com nome da urna, número do candidato e total de votos nominais). Partidos que não possuírem candidatos com um número positivo de votos válidos devem ser ignorados;
        O Relatório 8 deve estar em ordem decrescente de acordo com o total de votos nominais do candidato
        mais votado do partido. Em caso de empate, o com menor número partidário terá prioridade. Lembrando
        que se dois candidatos tiverem o mesmo número de votos, o mais velho terá prioridade.
        
        Descrição: Relata informações sobre o primeiro e último colocados (válidos) de cada partido. Partidos com apenas com candidatos não válidos são ignorados.
        
        Entrada: ArrayList da classe Partido e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos primeiros e últimos colocados.
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: ArrayList em ordem decrescente de acordo com os seguintes critérios (já em ordem de prioridade): total de votos nominais do partido, menor número partidário e candidato mais velho.
    */
    public void primeiroUltimoColocados(ArrayList<Partido> partidos, PrintStream saida){
            Collections.sort(partidos, new Partido.comparadorVotosNominais());
            saida.println("\nPrimeiro e último colocados de cada partido:");

            int classificacao = 1;
            Candidato primeiro = null, ultimo = null;

            for(Partido p: partidos){

                if(p.candidatos.size()>0 && p.candidatos.get(0).getVotosNominais()>0){
                primeiro = p.candidatos.get(0);
                ultimo = p.candidatos.get(p.candidatos.size()-1);
                    
                saida.print(classificacao+" - "+p.siglaPartido+" - "+p.numeroPartido+", ");
                saida.print(primeiro.getNomeUrna()+" ("+primeiro.getNumero()+", " + primeiro.getVotosNominais()+(primeiro.getVotosNominais()>1?" votos":" voto"));
                saida.println(") / "+ultimo.getNomeUrna()+" ("+ultimo.getNumero()+", " + ultimo.getVotosNominais()+(ultimo.getVotosNominais()>1?" votos":" voto")+")");
                classificacao++;
                }
            }
    }

   /*   Relatório 11
        Enunciado: Total de votos, total de votos nominais e total de votos de legenda.
        
        Descrição: Relata informações sobre o total de votos, total de votos nominais (válidos) e total de votos de legenda (válidos) da eleição.
        
        Entrada: ArrayList da classe Partido e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos votos.
        
        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta das especificação acima. 
    */
    public void panoramaVotos(ArrayList<Partido> partidos, PrintStream saida){
            NumberFormat fn = NumberFormat.getPercentInstance();
            fn.setMinimumFractionDigits(2);
            int votosNominais = 0, votosLegenda=0;
            double total =0;
            for(Partido v:partidos){
                votosNominais+=v.totalVotosNominaisValidos();
                votosLegenda+=v.votosLegenda;
            }
            total = votosNominais+votosLegenda;

            saida.println("\nTotal de votos válidos:    "+(votosNominais+votosLegenda));
            saida.println("Total de votos nominais:   "+votosNominais+" ("+fn.format(votosNominais/total)+")");
            saida.println("Total de votos de legenda: "+votosLegenda+" ("+fn.format(votosLegenda/total)+")\n");
    }
}