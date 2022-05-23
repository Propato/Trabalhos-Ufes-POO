#include <iostream>
#include <iomanip>
#include <locale>
#include <exception>

#include "../lib/leitura/Leitura.h"
#include "../lib/candidatos/RelatoriosCandidatos.h"
#include "../lib/partidos/RelatoriosPartidos.h"
#include "../lib/comum/Excecoes.h"

using namespace std;

/*  
    Subclasse para correção do padrão esperado do locale pt Br.
*/
class NoSeparatorAndCommaAsDecimalPoint : public numpunct<char>{
protected:
    virtual char do_decimal_point() const {return ',';}
    virtual string do_grouping() const { return "\000"; }
};

int main(int argc, char* argv[]){
    if(argc!=4){
        cout << "Formato invalido de entrada!\n" << "Formato esperado: ./vereadores <candidatos.csv> <partidos.csv> <dd/MM/yyyy>\n";
        return 1;
    }
    
    try{
        locale br = locale(locale("pt_BR.UTF-8"), new NoSeparatorAndCommaAsDecimalPoint);
        cout.imbue(br);
        cout << fixed << setprecision(2);

        Leitura l;
        list<Candidato*> listaCandidatos = l.lerCandidatos(argv[1]);
        list<Partido*> listaPartidos = l.lerPartidos(argv[2]);
        RelatoriosCandidatos relatorioCandidatos(listaCandidatos);
        RelatoriosPartidos relatorioPartidos(listaPartidos);

        relatorioCandidatos.associarPartidosCandidatos(listaPartidos);
        relatorioCandidatos.ordenarVotosNominais();

        int vagas = relatorioCandidatos.vagas();
        relatorioCandidatos.eleitos(vagas);
        relatorioCandidatos.maisVotados(vagas);
        relatorioCandidatos.naoEleitos(vagas);
        relatorioCandidatos.eleitosBeneficiados(vagas);

        relatorioPartidos.votosTotais();
        relatorioPartidos.votosLegenda();
        relatorioPartidos.primeiroUltimoColocados();

        relatorioCandidatos.eleitosFaixaEtaria(argv[3]);
        relatorioCandidatos.eleitosSexo();

        relatorioPartidos.panoramaVotos();

        br.~locale();
        cout.~basic_ostream();
    }
    catch(Exception &e){
        cout << e.what() << endl;
        return 1;
    }
    catch (exception &e){
        cout << e.what() << endl;
        return 1;
    }
    catch(...){
        cout << "Exception: erro desconhecido na execução do programa." << endl;
        return 1;
    }

    return 0;
}