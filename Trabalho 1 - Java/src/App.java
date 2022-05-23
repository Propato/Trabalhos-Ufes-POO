import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Locale;
import candidatos.*;
import partidos.*;

public class App {

    public static void main(String[] args)
    {   
        Locale.setDefault(new Locale("pt", "BR"));
        
        if(args.length!=3){
            System.out.println("Erro na execução do programa:\nParametros esperados = 3 : Parametros recebidos = "+args.length);
            System.out.println("Padrão: java App <candidatos.csv> <partidos.csv> <dd/mm/yyyy>");
            System.exit(1);
        }

        Leitura Entrada = new Leitura();

        ArrayList<Candidato> vs = Entrada.lerCandidatos(args[0]);
        ArrayList<Partido> ps = Entrada.lerPartidos(args[1]);

        PrintStream Saida = System.out;

        DadosCandidatos dadosCandidato = new DadosCandidatos();
        DadosPartidos dadosPartidos = new DadosPartidos();

        dadosCandidato.ordenaCandidatos(vs);
        dadosCandidato.associarPartidosCandidatos(vs, ps);
        dadosPartidos.ordenaPartidos(ps);
        
        int vagas = dadosCandidato.vagas(vs, Saida);
        dadosCandidato.eleitos(vs, vagas, Saida);
        dadosCandidato.maisVotados(vs, vagas, Saida);
        dadosCandidato.naoEleitos(vs, vagas, Saida);
        dadosCandidato.eleitosBeneficiados(vs, vagas, Saida);
        dadosPartidos.votosTotais(ps, Saida);
        dadosPartidos.votosLegenda(ps, Saida);
        dadosPartidos.primeiroUltimoColocados(ps, Saida);
        dadosCandidato.eleitosFaixaEtaria(vs, Saida, args[2]);
        dadosCandidato.eleitosSexo(vs, Saida);
        dadosPartidos.panoramaVotos(ps, Saida);

        Saida.close();
    }
}