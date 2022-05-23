#include "../../lib/leitura/Leitura.h"
#include "../../lib/comum/Excecoes.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//Foções para remoção de white spaces no inicio e final das palavras.
const string WHITESPACE = " \n\r\t\f\v";

string removeBegin(const string &palavra){
    size_t start = palavra.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : palavra.substr(start);
}
string removeEnd(const string &palavra){
    size_t end = palavra.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : palavra.substr(0, end + 1);
}
string remove(const string &palavra){
    return removeBegin(removeEnd(palavra));
}

 
Candidato* lerCandidato(stringstream &strm, const int &nLinha, const string &arquivo){
    string numero_s, votosNominais_s, auxSituacao, nome, nomeUrna, sexo, dataNasc, destinoVoto, numeroPartido_s;
    int numero, votosNominais, numeroPartido;
    bool situacao=false;
    try{
        if(!(getline(strm, numero_s, ',') && getline(strm, votosNominais_s, ',') && getline(strm, auxSituacao, ',') && getline(strm, nome, ',') && getline(strm, nomeUrna, ',') && getline(strm, sexo, ',') && getline(strm, dataNasc, ',') && getline(strm, destinoVoto, ',') && getline(strm, numeroPartido_s)))
            throw ErroLeituraLinhaCandidatos(arquivo, nLinha);

        if(auxSituacao == "Eleito") situacao = true;
        if(destinoVoto!="Válido") return NULL;

        numero = stoi(numero_s);
        votosNominais = stoi(votosNominais_s);
        numeroPartido = stoi(numeroPartido_s);

        Candidato *c = new Candidato(numero, votosNominais, situacao, remove(nome), remove(nomeUrna), remove(sexo), remove(dataNasc), numeroPartido);
        return c;
    }
    catch(invalid_argument &e){
        cout << "Exception: erro nos números ou na data do candidato no arquivo < " << arquivo << " >, na linha " << nLinha << "." << endl;
        cout << "Linha " << nLinha << " ignorada.\n" <<  endl;    
        return NULL;
    }
    catch(bad_alloc &e){
        cout << "Exception: erro ao alocar memoria para candidato do arquivo < " << arquivo << " >, na linha " << nLinha << "." << endl;
        cout << "Linha " << nLinha << " ignorada.\n" <<  endl;  
        return NULL;
    }
    catch(Exception &e){
        cout << e.what() << endl;
        return NULL;
    }
    catch(exception &e){
        cout << e.what() << endl;
        cout << "\nException: erro desconhecido ao gerar candidato de "<< arquivo << ", na linha " << nLinha << "...\n";
        return NULL;
    }
    catch(...){
        cout << "\nException: erro desconhecido ao gerar candidato de "<< arquivo << ", na linha " << nLinha << "...\n";
        cout << "Linha ignorada.\n" <<  endl; 
        return NULL; 
    }
}

Partido* lerPartido(stringstream &strm, const int &nLinha, const string &arquivo){
    string nomePartido, siglaPartido, numeroPartido_s, votosLegenda_s;
    int numeroPartido, votosLegenda;

    try{
        if(!(getline(strm, numeroPartido_s, ',') && getline(strm, votosLegenda_s, ',') && getline(strm, nomePartido, ',') && getline(strm, siglaPartido, ',')))
            throw ErroLeituraLinhaPartidos(arquivo, nLinha);
        
        numeroPartido = stoi(numeroPartido_s);
        votosLegenda = stoi(votosLegenda_s);
        
        Partido *p = new Partido(numeroPartido, votosLegenda, remove(siglaPartido));

        return p;
    }
    catch(invalid_argument &e){
        cout << "Exception: erro nos números do partido no arquivo < " << arquivo << " >, na linha " << nLinha << "." << endl;
        throw ErroLeituraLinhaPartidos(arquivo, nLinha);
    }
    catch(bad_alloc &e){
        cout << "\nException: erro ao alocar memoria  para partido do "<< arquivo << ", na linha " << nLinha << "...\n";
        throw e;
    }
    catch(Exception &e){
        throw ErroLeituraLinhaPartidos(arquivo, nLinha);
    }
    catch(exception &e){
        cout << "\nException: erro desconhecido ao gerar partido de "<< arquivo << ", na linha " << nLinha << "...\n";
        throw e;
    }
}

list<Candidato*> Leitura::lerCandidatos(const string &arquivo){
    ifstream inputstream(arquivo);
    stringstream strm;
    string linha;
    list<Candidato*> candidatos;
    int nLinha = 1;

    if(!inputstream.is_open())
        throw ErroAbertura(arquivo);
    if(!getline(inputstream, linha))
        throw ErroLeituraArquivo(arquivo, nLinha);

    while(getline(inputstream, linha)){
        if(linha.empty())
            throw ErroLeituraArquivo(arquivo, nLinha);

        strm << linha;
        Candidato *c = lerCandidato(strm, ++nLinha, arquivo);
        if(c) candidatos.push_back(c);
        strm.clear();
    }
    inputstream.close();
    return candidatos;
}

list<Partido*> Leitura::lerPartidos(const string &arquivo){
    ifstream inputstream(arquivo);
    stringstream strm;
    string linha;
    list<Partido*> partidos;
    int nLinha = 1;

    if(!inputstream.is_open())
        throw ErroAbertura(arquivo);
    if(!getline(inputstream, linha))
        throw ErroLeituraArquivo(arquivo, nLinha);

    while(getline(inputstream, linha)){
        if(linha.empty())
            throw ErroLeituraArquivo(arquivo, nLinha);

        strm << linha;
        Partido *p = lerPartido(strm, ++nLinha, arquivo);
        if(p) partidos.push_back(p);
        strm.clear();
    }
    inputstream.close();
    return partidos; 
}