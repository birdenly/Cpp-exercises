#include <iostream>
#include "pessoa.hpp"

using namespace std;
//construtor vazio
Pessoa::Pessoa(){};
//construtor parametizado
Pessoa::Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos){
	setNome(nome);
	setCpf(cpf);
	setData(dataNascimento);
	setEndereco(enderecoPessoal);
	setEstadoCivil(estadoCivil);
	setFilhos(qtdFilhos);
}
//metodos gets e sets para atributos
string Pessoa::getNome(){
     return this->nome;
}

void Pessoa::setNome(string nome){
	this->nome = nome;
}

string Pessoa::getCpf(){
	return this->cpf;
}

void Pessoa::setCpf(string cpf){
	this->cpf = cpf;
}

Data Pessoa::getData(){
	return this->dataNascimento;
}

void Pessoa::setData(Data dataNascimento){
	this->dataNascimento = dataNascimento;
}
	
Endereco Pessoa::getEndereco(){
	return this->enderecoPessoal;
}
	
void Pessoa::setEndereco(Endereco enderecoPessoal){
	this->enderecoPessoal = enderecoPessoal;
}
	
string Pessoa::getEstadoCivil(){
	return this->estadoCivil;
}
	
void Pessoa::setEstadoCivil(std::string estadoCivil){
	this->estadoCivil = estadoCivil;
}
	
int Pessoa::getFilhos(){
	return this->qtdFilhos;
}
	
void Pessoa::setFilhos(int qtdFilhos){
	this->qtdFilhos = qtdFilhos;
}