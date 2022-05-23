#ifndef EXCECOES_H
#define EXCECOES_H

#include "../../lib/comum/Excecoes.h"

using namespace std;

//Todas as funções das subclasses seguem o mesmo padrão e lógica das funções da superclasse.

//  ======================================
//               SUPER CLASSE
//  ======================================
class Exception{
public:
    // ===== Construtor =====
    Exception();
    // ===== Retorna informações sobre a exceção =====
    virtual const string what();
};

//  =====================================
//               SUB CLASSES
//  =====================================

class ErroAbertura: public Exception{
    string arquivo;
public:
    ErroAbertura(const string &arquivo);
    const string what();
};

class ErroLeituraArquivo: public Exception{
    string arquivo, nLinha;
public:
    ErroLeituraArquivo(const string &arquivo, const int &nLinha);
    const string what();
};

class ErroLeituraLinhaCandidatos: public Exception{
    string arquivo, linha, nLinha;
public:
    ErroLeituraLinhaCandidatos(const string &arquivo, const int &nLinha);
    const string what();
};

class ErroLeituraLinhaPartidos: public Exception{
    string arquivo, linha, nLinha;
public:
    ErroLeituraLinhaPartidos(const string &arquivo, const int &nLinha);
    const string what();
};

class Nulos: public Exception{
    string classe;
public:
    Nulos(const string &classe);
    const string what();
};

#endif