#include <iostream>
#include <string>
#include "vendedor.hpp"
using namespace std;


Vendedor::Vendedor() {}

Vendedor::Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, string salario, string matricula, Data ingressoEmpresa, char tipoVendedor){
	Vendedor::setNome(nome);
	Vendedor::setCpf(cpf);
	Vendedor::setData(dataNascimento);
	Vendedor::setEndereco(enderecoPessoal);
	Vendedor::setEstadoCivil(estadoCivil);
	Vendedor::setFilhos(qtdFilhos);
	Vendedor::setSalario(salario);
	Vendedor::setMatricula(matricula);
	Vendedor::setIngresso(ingressoEmpresa);
	Vendedor::setTipo(tipoVendedor);
  Vendedor::setdiasFalta(diasFalta);
}

char Vendedor::getTipo(){
	return this->tipoVendedor;
}

void Vendedor::setTipo(char tipoVendedor){
	this->tipoVendedor = tipoVendedor;
}

int Vendedor::getdiasFaltas(){
	return this->diasFalta;
}
void Vendedor::setdiasFalta(int diasfaltas){
	this->diasFalta = diasfaltas;
  
}

//calcula o salario 
float Vendedor::calcularSalario(int diasFalta){
	float salario = ((stof(getSalario()) / 30) * (30 - diasFalta));
  //identifica o tipo de vendedor
	if (getTipo() == 'A'){
		salario += salario * 0.25;
	}
	else if (getTipo() == 'B'){
		salario += salario * 0.10;
	}
	else if(getTipo() == 'C'){
		salario += salario * 0.05;
	}

	salario += getFilhos()*100;
		
	return salario;
}
//calcula recisao do funcionario
float Vendedor::calcularRescisao(Data desligamento){
  // as variaveis para contar o tempo que o vendedor trabalhou na empresa
	int anosTrabalhados = desligamento.ano - getIngresso().ano;
    int mesesTrabalhados = desligamento.mes - getIngresso().mes;
    int diasTrabalhados = desligamento.dia - getIngresso().dia;

  		//Analisa se obteve um número negativo, se sim significa que não trabalhou um ano completo e então decrementamos a variavel que guarda os anos trabalhados inteiros
    if (mesesTrabalhados < 0 || (mesesTrabalhados == 0 && diasTrabalhados < 0)){
        anosTrabalhados--;
		mesesTrabalhados += 12;
    }
  //calculo de tempo liquido em anos
    float anosFracionados = anosTrabalhados + (mesesTrabalhados / 12.0f) + (diasTrabalhados / 365.0f);

  //salario minimo por ano
    float salarioBasePorAno = calcularSalario(0) * 12;
  //calculo da rescisao do contrato do asg
    float rescisao = salarioBasePorAno * anosFracionados;

    return rescisao;
}