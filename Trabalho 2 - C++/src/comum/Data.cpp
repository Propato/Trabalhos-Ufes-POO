#include "../../lib/comum/Data.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

//  ==========================================================
//                      NAMESPACE DATAINFO                    
//  ==========================================================

const int DataInfo::diasMes(const int &mes, const int &ano){
    int diasMes[] = {0, 31, bissexto(ano)?29:28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return diasMes[mes];
}

const bool DataInfo::bissexto(const int &ano){
    return ((ano%4==0)&&(ano%100!=0))?true:(((ano%4==0)&&(ano%400==0))?true:false);
}

const int DataInfo::totalDiasAno(const int &ano){
    return DataInfo::bissexto(ano)?365:366;
}

const int DataInfo::numeroDiasData(const int &dias, const int &mes, const int &ano){
    int total = 0;
    for(int i=1;i<mes;i++) total += DataInfo::diasMes(i, ano);
    return total+dias;
}

//contagem a partir de 1/1/1900
const int DataInfo::diasSinceOrigin(const int &dia, const int &mes, const int &ano){
    const int ano_c = 1900;
    int total = 0;
    for(int i=ano_c; i<ano; i++) total += DataInfo::totalDiasAno(i);
    return total + DataInfo::numeroDiasData(dia, mes, ano);
}

const int DataInfo::diasSinceData(const int &dia, const int &mes, const int &ano, Data &d){
    int total_d = diasSinceOrigin(d.getDia(), d.getMes(), d.getAno());
    int total = diasSinceOrigin(dia, mes, ano);
    int diff = total>total_d?total-total_d:total_d-total;
    return diff;
}

//contagem a partir de 1/1/1900
const Data DataInfo::converterDiasData(int &dias, const int &dia_c, const int &mes_c, const int &ano_c){
    int dia = 0, mes = 0, ano = 0;
    for(ano=ano_c;dias>365;ano++) dias -= DataInfo::totalDiasAno(ano);
    for(mes=mes_c;dias>DataInfo::diasMes(mes, ano);mes++) dias-= DataInfo::diasMes(mes, ano);
    dia = dias;
    return Data(dia, mes, ano);
}

//  =========================================================
//                      FUNÇÕES DA CLASSE                    
//  =========================================================
Data::Data(){}

Data::Data(const int &dia, const int &mes, const int &ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

Data::Data(const string &str, char const delimiter){
    stringstream ss;
    string dd, mm, yyyy;

    ss << str;
    if(!(getline(ss, dd, delimiter) && getline(ss, mm, delimiter) && getline(ss, yyyy, delimiter)))
        throw invalid_argument("\nException: Data das eleições com erro no padrão.\nPadrão correto: dd/MM/yyyy");

    try{
    this->dia = stoi(dd);
    this->mes = stoi(mm);
    this->ano = stoi(yyyy);
    }catch(invalid_argument &e){
        throw invalid_argument("\nException: Data das eleições com valores invalidos.");}

    if(!(1 <= this->dia && this->dia <= 31) || !(1 <= this->mes && this->mes <= 12) || !(1900 <= this->ano))
        throw invalid_argument("\nException: Data das eleições com valores invalidos.");
}

const int &Data::getDia(){
    return this->dia;
}

const int &Data::getMes(){
    return this->mes;    
}

const int &Data::getAno(){
    return this->ano;   
}

const string Data::data_stringfy(const string &delimiter){
    string formatted;
    stringstream ss;
    ss << this->getDia() << delimiter << this->getMes() << delimiter << this->getAno() << endl;
    ss >> formatted;
    return formatted;
}

const int Data::compare(Data &data_comparada){
    int comparador = DataInfo::diasSinceOrigin(this->getDia(), this->getMes(), this->getAno());
    int comparado =  DataInfo::diasSinceOrigin(data_comparada.getDia(), data_comparada.getMes(), data_comparada.getAno());
    return comparador - comparado;
}

void Data::print(){
    cout << this->data_stringfy("/") << endl;
}

void Data::operator = (const string &str){
    stringstream ss;
    string dd, mm, yyyy;

    ss << str;
    if(!(getline(ss, dd, '/') && getline(ss, mm, '/') && getline(ss, yyyy, '/')))
        throw invalid_argument("\nException: Data com erro no padrão.\nPadrão correto: dd/MM/yyyy");

    try{
    this->dia = stoi(dd);
    this->mes = stoi(mm);
    this->ano = stoi(yyyy);
    }catch(invalid_argument &e){
        throw invalid_argument("\nException: Data com valores invalidos.");}

    if(!(1 <= this->dia && this->dia <= 31) || !(1 <= this->mes && this->mes <= 12) || !(1900 <= this->ano))
        throw invalid_argument("\nException: Data com valores invalidos.");
}

const Data Data::operator - (Data &d) const{
    int diff = DataInfo::diasSinceData(this->dia, this->mes, this->ano, d);
    return DataInfo::converterDiasData(diff, 0, 0, 0);
}
