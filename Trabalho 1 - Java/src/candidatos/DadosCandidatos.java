package candidatos;

import java.io.PrintStream;
import java.text.NumberFormat;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Collections;

import partidos.Partido;

public class DadosCandidatos {
    
    /* 
        Descrição: Função que associa cada candidato com seu partido e cada partido com seus candidatos.

        Entrada: ArrayList da classe candidato contendo todos os candidatos lidos e ArrayList da classe Partido contendo todos os partidos lidos.

        Retorno: Nenhuma.

        Saída: Nenhuma.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Partidos associados corretamente com seus candidatos e candidatos associados corretamernte com o seu partido.
    */
    public void associarPartidosCandidatos(ArrayList<Candidato> candidatos, ArrayList<Partido> partidos){
        for(Partido p: partidos){
            for(Candidato c: candidatos){
                if(p.getNumeroPartido() == c.numeroPartido){
                    c.setPartido(p);
                    p.setCandidato(c);
                }
            }
        }
    }

    /*
        Descrição: Ordena os candidatos em ordem decrescente do número de votos nominais, em caso de empate, o mais velho tem prioridade.

        Entrada: ArrayList da classe candidato.

        Retorno: Nenhuma.

        Saída: Nenhuma.

        Pré-condição: Entrada preenchida corretamente.

        Pós-condição: ArrayList ordenado corretamente.

    */
    public void ordenaCandidatos(ArrayList<Candidato> candidatos){
        Collections.sort(candidatos);
    }

    /*
         Relatório 1
         Enunciado: Número de vagas (= número de eleitos);

        Descrição: Imprime o número de canditados eleitos.

        Entrada: ArrayList da classe candidato e PrintStream da saída padrão.

        Retorno: int de número de candidatos eleitos (número de gavas).

        Saída: Relatório do número de vagas.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Número de candidatos eleitos retornado correto e impressão correta dos candidato que se encaixam na especificação acima.
    */
    public int vagas(ArrayList<Candidato> candidatos, PrintStream saida){
        int vagas=0;
        for(Candidato c:candidatos){
            if(c.situacao.compareTo("Eleito")==0){
                vagas++;
            }
        }
            saida.print("Número de vagas: "+vagas);

        return vagas;
    }

    /*
        Relatório 2
        Enunciado: Candidatos eleitos (nome completo e na urna), indicado partido e número de votos nominais;

        Descrição: Imprime todos os candidatos eleitos.

        Entrada: ArrayList da classe candidato, int com o número de vagas e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos eleitos.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    public void eleitos (ArrayList<Candidato> candidatos, int vagas, PrintStream saida){
            saida.print("\n\nVereadores eleitos:");

            for(int i=0, classificacao = 1; i<candidatos.size(); i++){
                if(candidatos.get(i).situacao.compareTo("Eleito")==0){

                    saida.print("\n"+classificacao+" - ");
                    candidatos.get(i).imprime(saida);
                    classificacao++;
                    if(classificacao > vagas){ break; }
                }
            }
    }

    /*
        Relatório 3
        Enunciado: Candidatos mais votados dentro do número de vagas;

        Descrição: Imprime os candidatos com mais votos nominais, com o limite de candidatos impressos sendo o número de vagas.

        Entrada: ArrayList da classe candidato, int com o número de vagas e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos mais votados.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    public void maisVotados(ArrayList<Candidato> candidatos, int vagas, PrintStream saida){

            saida.print("\n\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
            for(int i=0; i<vagas ;i++){
                saida.print("\n"+(i+1)+" - ");
                candidatos.get(i).imprime(saida);
            }
    }

    /*
        Relatório 4
        Enunciado: Candidatos não eleitos e que seriam eleitos se a votação fosse majoritária;

        Descrição: Imprime corretamente os candidatos não eleitos e que seriam eleitos na votação majoritária.

        Entrada: ArrayList da classe Candidato, int com o número de vagas e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos candidatos quase eleitos.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    public void naoEleitos(ArrayList<Candidato> candidatos, int vagas, PrintStream saida){

        int votos_de_corte = candidatos.get(vagas-1).votosNominais;

        for(int i=vagas; i<candidatos.size(); i++){
            if(candidatos.get(i).situacao.compareTo("Eleito")==0){
                votos_de_corte = candidatos.get(i).votosNominais;
            }
        }

            saida.print("\n\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)");

            for(int i=0; i<vagas; i++){
                if(candidatos.get(i).votosNominais > votos_de_corte && candidatos.get(i).situacao.compareTo("Eleito")!=0){
                        saida.print("\n"+(i+1)+" - ");
                        candidatos.get(i).imprime(saida);
                }
            }
    }

    /*
        Relatório 5
        Enunciado: Candidatos eleitos no sistema proporcional vigente, e que não seriam eleitos se a votação fosse
        majoritária, isto é, pelo número de votos apenas que um candidato recebe diretamente;
        Eleitos, que se beneficiaram do sistema proporcional:

        Descrição: Imprime os candidatos eleitos no sistema proporcional mas que não seriam eleitos na votação majoritária.

        Entrada: ArrayList da classe Candidato, int com o número de vagas e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório dos eleitos que se beneficiaram.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta dos candidato que se encaixam na especificação acima.
    */
    public void eleitosBeneficiados(ArrayList<Candidato> candidatos, int vagas, PrintStream saida){

            saida.print("\n\nEleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)");
            for(int i=vagas; i<candidatos.size(); i++){
                if(candidatos.get(i).situacao.compareTo("Eleito")==0){
                    saida.print("\n"+(i+1)+" - ");
                    candidatos.get(i).imprime(saida);
                }
            }
    }

    /*
        Relatório 9
        Enunciado: Distribuição de eleitos por faixa etária, considerando a idade do candidato no dia da eleição;

        Descrição: Imprime a porcentagem de eleitos em cada faixa etaria (<30, 30< e <40, 40< e <50, 50< e <60, e >60) em razão do total de eleitos.

        Entrada: ArrayList da classe Candidato, PrintStream da saída padrão e String com a data das eleições.

        Retorno: Nenhum.

        Saída: Relatório das faixas etaria.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta das especificações acima.
    */
    public void eleitosFaixaEtaria(ArrayList<Candidato> candidatos, PrintStream saida, String data){

            saida.println("\nEleitos, por faixa etária (na data da eleição):");
            try{

            NumberFormat fn = NumberFormat.getPercentInstance();
            fn.setMinimumFractionDigits(2);
            
            int menor30=0, entre3039=0, entre4049=0, entre5059=0, maior60=0, anos=0;
            double total=0;
            LocalDate dataHoje = LocalDate.parse(data, DateTimeFormatter.ofPattern("dd/MM/yyyy"));
            Period periodo = null;
            for(Candidato v:candidatos){
                if(v.situacao.compareTo("Eleito")==0){
                    periodo = Period.between(v.dataNasc, dataHoje);
                    anos = periodo.getYears();
                    if(anos<30){
                        menor30++;
                    }
                    else if(anos<40){
                        entre3039++;
                    }
                    else if(anos<50){
                        entre4049++;
                    }
                    else if(anos<60){
                        entre5059++;
                    }
                    else{
                        maior60++;
                    }
                }
            }
            total = menor30+entre3039+entre4049+entre5059+maior60;
            saida.println("      Idade < 30: "+menor30+" ("+fn.format(menor30/total)+")");
            saida.println("30 <= Idade < 40: "+entre3039+" ("+fn.format(entre3039/total)+")");
            saida.println("40 <= Idade < 50: "+entre4049+" ("+fn.format(entre4049/total)+")");
            saida.println("50 <= Idade < 60: "+entre5059+" ("+fn.format(entre5059/total)+")");
            saida.println("60 <= Idade     : "+maior60+" ("+fn.format(maior60/total)+")");

            }catch (DateTimeParseException e){
                System.out.println("Erro no padrão da data das eleições, executar o programa novamente com a data no padrão correto <dd/MM/yyyy>...");
                e.printStackTrace();
            }
    }

    /*
        Relatório 10
        Enunciado: Distribuição de eleitos por sexo;

        Descrição: Imprime a porcentagem de eleitos com base no sexo (M ou F).

        Entrada: ArrayList da classe Candidato e PrintStream da saída padrão.

        Retorno: Nenhum.

        Saída: Relatório das porcentagens entre sexos.

        Pré-condição: Entradas preenchidas corretamente.

        Pós-condição: Impressão correta das especificação acima.
    */
    public void eleitosSexo(ArrayList<Candidato> candidatos, PrintStream saida){

            saida.println("\nEleitos, por sexo:");

            NumberFormat fn = NumberFormat.getPercentInstance();
            fn.setMinimumFractionDigits(2);
            int m=0, f=0;
            double total=0;
            for(Candidato v:candidatos){
                if(v.situacao.compareTo("Eleito")==0){
                    if(v.genero.compareTo("M")==0){
                        m++;
                    }
                    else{
                        f++;
                    }
                }
            }
            total = f+m;
            saida.println("Feminino:  "+f+" ("+fn.format(f/total)+")");
            saida.println("Masculino: "+m+" ("+fn.format(m/total)+")");
    }
}