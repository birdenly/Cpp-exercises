#include <iostream>
#include "gerente.hpp"
using namespace std;
//construtor vazio
Gerente::Gerente(){}
//construtor parametizado
Gerente::Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, string salario, string matricula, Data ingressoEmpresa, float participacaoLucros){
	Gerente::setNome(nome);
	Gerente::setCpf(cpf);
	Gerente::setData(dataNascimento);
	Gerente::setEndereco(enderecoPessoal);
	Gerente::setEstadoCivil(estadoCivil);
	Gerente::setFilhos(qtdFilhos);
	Gerente::setSalario(salario);
	Gerente::setMatricula(matricula);
	Gerente::setIngresso(ingressoEmpresa);
	Gerente::setLucros(participacaoLucros);
  Gerente::setdiasFalta(diasFalta);
}
//metodos gets e sets
char Gerente::getLucros(){
	return this->participacaoLucros;
}

void Gerente::setLucros(float participacaoLucros){
	this->participacaoLucros = participacaoLucros;
}

int Gerente::getdiasFaltas(){
	return this->diasFalta;
}
void Gerente::setdiasFalta(int diasfaltas){
	this->diasFalta = diasfaltas;
  
}
//calcula o salario do gerente
float Gerente::calcularSalario(int diasFalta){
	float salario = ((stof(getSalario()) / 30) * (30 - diasFalta));
	salario += participacaoLucros;
	salario += getFilhos() * 100;
	return salario;
}
//calcula recisao do gerente
float Gerente::calcularRescisao(Data desligamento){
    float salario_base = stof(getSalario());

    float anos_trabalhados;
  
    anos_trabalhados  = (1.0/1.0) * (desligamento.ano - getIngresso().ano);
    anos_trabalhados += (1.0/12.0) * (desligamento.mes - getIngresso().mes);
    anos_trabalhados += (1.0/365.25) * (desligamento.dia - getIngresso().dia);


    return anos_trabalhados * salario_base;
}
