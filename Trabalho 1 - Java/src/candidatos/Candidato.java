package candidatos;

import java.io.PrintStream;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import partidos.Partido;

public class Candidato implements Comparable<Candidato>{
    /* 
        =========================================
                        VARIAVEIS
        =========================================
    */
    String nome, situacao, nomeUrna, destinoVoto, genero;
    int numero, numeroPartido, votosNominais;
    LocalDate dataNasc;
    Partido partido;

    /* 
        =========================================
                        INICIALIZAÇÃO
        =========================================
    */
    public Candidato() {}
    public Candidato(int numero, int votosNominais, String situacao, String nome, String nomeUrna, String Genero, String dataNasc, String destinoVoto, int numeroPartido){
        
        this.numero = numero;
        this.votosNominais = votosNominais;
        this.situacao = situacao;
        this.nome = nome;
        this.nomeUrna = nomeUrna;
        this.genero = Genero;
        this.destinoVoto = destinoVoto;
        this.numeroPartido = numeroPartido;
        try{
        this.dataNasc = LocalDate.parse(dataNasc, DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        }catch (DateTimeParseException e){
            System.out.println("Erro no padrão da data de nascimento do candidato "+nome+", corrigir no arquivo fonte...");
            e.printStackTrace();
        }
    }

    /* 
        =========================================
                        SETTER
        =========================================
    */

    public void setPartido(Partido partido){ this.partido = partido; }

    /*
        =========================================
                        GETTERS
        =========================================
    */
    public int getVotosNominais(){ return this.votosNominais; }
    public String getSituacao(){ return this.situacao; }
    public String getNomeUrna(){ return this.nomeUrna; }
    public String getDestinoVoto(){ return this.destinoVoto; }
    public int getNumero(){ return this.numero; }

    /* 
        =========================================
                        FUNÇÕES
        =========================================
    */

    /*
        Descrição: Imprime dados do candidato (nome, nome na urna, sigla do partida e número de votos nominais) na saída padrão. 
        
        Entrada: PrintStream da saída.
        
        Retorno: Nenhum.

        Saída: Imprime os dados do candidato.
        
        Pré-condição: Arquivo de saída correto.

        Pós-condição: Impressão correta dos dados.
    */
    public void imprime(PrintStream saida){

            saida.print(nome+" / "+nomeUrna+" ("+partido.getSiglaPartido()+", "+votosNominais+" votos)");
    }

   /*        
        Descrição: (comparable) Compara dois candidatos de acordo com os seguintes critérios (já em ordem de prioridade): destino do voto, votos nominais do candidato (ordem crescente) e candidato mais velho.
        
        Entrada: Uma variavel da classe candidato.

        Retorno: Retorna a diferença entre as strings de destino de voto. Em caso da diferença ser nula, retorna a diferença do numero de votos nominais entre os candidatos. Em caso da diferença ser novamente nula, retorna a diferença entre as datas de nascimento dos candidatos.
        
        Pré-condição: Cada candidato deve ter os campos comparados preenchidos.

        Pós-condição: Comparação correta dos candidatos.
    */
    public int compareTo(Candidato v){
        int resultado = v.destinoVoto.compareTo(this.destinoVoto);
        if(resultado==0){
            resultado = v.votosNominais - this.votosNominais;
            if(resultado==0){
                resultado = this.dataNasc.compareTo(v.dataNasc);
            }
        }
        return resultado;
    }
}
