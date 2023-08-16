#include <iostream>
#include "funcionario.hpp"

using namespace std;
//metodos gets e sets 
string Funcionario::getSalario(){
	return this->salario;
}

void Funcionario::setSalario(std::string salario){
	this->salario = salario;
}

string Funcionario::getMatricula(){
	return this->matricula;
}

void Funcionario::setMatricula(std::string matricula){
	this->matricula = matricula;
}

Data Funcionario::getIngresso(){
	return this->ingressoEmpresa;
}

void Funcionario::setIngresso(Data ingressoEmpresa){
	this->ingressoEmpresa = ingressoEmpresa;
}