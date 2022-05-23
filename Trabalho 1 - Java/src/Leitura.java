import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;

import java.util.NoSuchElementException;
import java.io.FileNotFoundException;
import java.io.IOException;

import java.util.ArrayList;
import java.util.Scanner;

import candidatos.Candidato;
import partidos.Partido;

public class Leitura {
    
    /* 
        ==========================================
                        CANDIDATOS
        ==========================================
    */

    /*
        Descrição: Realiza a leitura de uma String que contém as informações de um candidato lido no arquivo de entrada, criando e retornando uma variavel da classe Candidato.
        
        Entrada: Uma String da linha lida.

        Retorno: Uma variável da classe Candidato.
        
        Pré-condição: Linha lida e preenchida corretamente no padrao CSV contendo numero, votos_nominais, situacao, nome, nome_urna, sexo, data_nasc, destino_voto e numero_partido.

        Pós-condição: Candidato iniciado corretamente e retornado.
    */
    private Candidato lerCandidato(String linha, int nLinha, String arquivo)
    {   
        try {
        Scanner CSV = new Scanner(linha);
        CSV.useDelimiter(",");

        String numero, votosNominais, situacao, nome, nomeUrna, sexo, dataNasc, destinoVoto, numeroPartido;
        int intNumero, intVotosNominais, intNumeroPartido;

        numero = CSV.next().stripTrailing();
        intNumero = Integer.parseInt(numero);
        votosNominais = CSV.next().stripTrailing();
        intVotosNominais = Integer.parseInt(votosNominais);
        situacao = CSV.next().stripTrailing();
        nome = CSV.next().stripTrailing();
        nomeUrna = CSV.next().stripTrailing();
        sexo = CSV.next().stripTrailing();
        dataNasc = CSV.next().stripTrailing();
        destinoVoto = CSV.next().stripTrailing();
        numeroPartido = CSV.next().stripTrailing();
        intNumeroPartido = Integer.parseInt(numeroPartido);

        Candidato candidato = new Candidato(intNumero, intVotosNominais, situacao, nome, nomeUrna, sexo, dataNasc, destinoVoto, intNumeroPartido);

        CSV.close();
        return candidato;
        }
        catch (NoSuchElementException e){
            System.out.println("Erro na linha "+nLinha+" do arquivo "+arquivo+": Necessário corrigir padrão da linha...");
            e.printStackTrace();
            return null;
        }
        catch (NumberFormatException e){
            System.out.println("Erro na linha "+nLinha+" do arquivo "+arquivo+":\nNecessário corrigir padrão -- checar se Número, Votos nominais e Número do partido apresentam apenas números (0-9) em seus espaços...");
            e.printStackTrace();
            return null;
        }
    }

    /* 
        Descrição: Realiza a abertura do arquivo de entrada e sua leitura, criando um ArrayList da classe Candidato e para cada linha lida um candidato é iniciado usando a função lerCandidato() e inserido no ArrayList.
        
        Entrada: Uma String com o nome do arquivo a ser lido.

        Retorno: Um ArrayList dos candidatos lidos.
        
        Pré-condição: Que o arquivo lido apresente a primeira linha sendo um cabeçalho igual à "numero,votos_nominais,situacao,nome,nome_urna,sexo,data_nasc,destino_voto,numero_partido" e que suas demais linhas sigam o padrão do cabeçalho.

        Pós-condição: Realize a abertura e leitura do arquivo e a criação do Arraylist da classe Candidato corretamente.
    */
    public ArrayList<Candidato> lerCandidatos(String arquivo)
    {
        ArrayList<Candidato> candidatos = new ArrayList<Candidato>();
        try (FileInputStream entrada = new FileInputStream(arquivo))
        {
            InputStreamReader ISR = new InputStreamReader(entrada, "UTF-8");
            BufferedReader BR = new BufferedReader(ISR);
            String linha = BR.readLine();
            int nLinhas = 1;
            Candidato aux;
            while((linha = BR.readLine())!=null){
                nLinhas++;
                aux = lerCandidato(linha, nLinhas, arquivo);
                if(aux.getDestinoVoto().compareTo("Válido") == 0)
                  candidatos.add(aux);
            }            
        }
        catch (FileNotFoundException e){
            System.out.println("\nArquivo de vereadores não encontrado ou inexistente...");
            e.printStackTrace();
        }
        catch (SecurityException e){
            System.out.println("\nErro de permissão na leitura do arquivo de vereadores...");
            e.printStackTrace();
        }
        catch (IOException e){
            System.out.println("\nErro desconhecido ao ler arquivo de vereadores...");
            e.printStackTrace();
        }
        return candidatos;
    }

    /* 
        ========================================
                        PARTIDOS
        ========================================
    */

    /*
        Descrição: Realiza a leitura de uma String que contém as informações de um partido lido no arquivo de entrada, criando e retornando uma variavel da classe Partido.
        
        Entrada: Uma String da linha lida.

        Retorno: Uma variável da classe Partido.
        
        Pré-condição: Linha lida e preenchida corretamente no padrao CSV contendo numero_partido, votos_legenda, nome_partido e sigla_partido.

        Pós-condição: Partido iniciado corretamente e retornado.
    */
    private Partido lerPartido(String linha, int nLinha, String arquivo)
    {
        try{
        Scanner CSV = new Scanner(linha);
        CSV.useDelimiter(",");

        String numeroPartido, votosLegenda, nomePartido, siglaPartido;
        int intNumeroPartido, intVotosLegenda;

        numeroPartido = CSV.next().stripTrailing();
        intNumeroPartido = Integer.parseInt(numeroPartido);
        votosLegenda = CSV.next().stripTrailing();
        intVotosLegenda = Integer.parseInt(votosLegenda);
        nomePartido = CSV.next().stripTrailing();
        siglaPartido = CSV.next().stripTrailing();

        Partido partido = new Partido(intNumeroPartido, intVotosLegenda,nomePartido, siglaPartido);
        CSV.close();
        return partido;
        }
        catch (NoSuchElementException e){
            System.out.println("Erro na linha "+nLinha+" do arquivo "+arquivo+": Necessário corrigir padrão da linha...");
            e.printStackTrace();
            return null;
        }
        catch (NumberFormatException e){
            System.out.println("Erro na linha "+nLinha+" do arquivo "+arquivo+":\nNecessário corrigir padrão -- checar se Número do partido e Votos de legenda apresentam apenas números (0-9) em seus espaços...");
            e.printStackTrace();
            return null;
        }
    }

    /* 
        Descrição: Realiza a abertura do arquivo de entrada e sua leitura, criando um ArrayList da classe Partido e para cada linha lida um partido é iniciado usando a função lerPartido() e inserido no ArrayList.
        
        Entrada: Uma String com o nome do arquivo a ser lido.

        Retorno: Um ArrayList dos partidos lidos.
        
        Pré-condição: Que o arquivo lido apresente a primeira linha sendo um cabeçalho igual à "numero_partido,votos_legenda,nome_partido,sigla_partido" e que suas demais linhas sigam o padrão do cabeçalho.

        Pós-condição: Realize a abertura e leitura do arquivo e a criação do Arraylist da classe Partido corretamente.
    */
    public ArrayList<Partido> lerPartidos(String arquivo)
    {
        ArrayList<Partido> partidos = new ArrayList<Partido>();
        try (FileInputStream entrada = new FileInputStream(arquivo))
        {
            InputStreamReader ISR = new InputStreamReader(entrada, "UTF-8");
            BufferedReader BR = new BufferedReader(ISR);
            String linha = BR.readLine();
            int nLinhas = 1;
            while((linha = BR.readLine())!=null){
                nLinhas++;
                partidos.add(lerPartido(linha, nLinhas, arquivo));
            }            
        }
        catch (FileNotFoundException e){
            System.out.println("\nArquivo de partidos não encontrado ou inexistente...");
            e.printStackTrace();
        }
        catch (SecurityException e){
            System.out.println("\nErro de permissão na leitura do arquivo de partidos...");
            e.printStackTrace();
        }
        catch (IOException e)
        {       
            System.out.println("\nErro desconhecido ao ler arquivo de partidos...");
                e.printStackTrace();
        }
        return partidos;
    }
}
