#include <iostream>
#include "asg.hpp"
#include <string>

using namespace std;

// construtor vazio e parametrizado
Asg::Asg() {}

Asg::Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, string salario, string matricula, Data ingressoEmpresa, float adicionalInsalubridade){
	Asg::setNome(nome);
	Asg::setCpf(cpf);
	Asg::setData(dataNascimento);
	Asg::setEndereco(enderecoPessoal);
	Asg::setEstadoCivil(estadoCivil);
	Asg::setFilhos(qtdFilhos);
	Asg::setSalario(salario);
	Asg::setMatricula(matricula);
	Asg::setIngresso(ingressoEmpresa);
  Asg::setAdicional(adicionalInsalubridade);
  Asg::setdiasFalta(diasFalta);

  
}

//Gets e Sets do asg
float Asg::getAdicional() {
    return adicionalInsalubridade;
}

void Asg::setAdicional(float adicionalInsalubridade) {
    this->adicionalInsalubridade = adicionalInsalubridade;
}

int Asg::getdiasFaltas(){
	return this->diasFalta;
}
void Asg::setdiasFalta(int diasfaltas){
	this->diasFalta = diasfaltas;
  
}

//calculo do salario do asg
float Asg::calcularSalario(int diasFalta) {
	float salario = ((stof(getSalario()) / 30) * (30 - diasFalta));
	salario += salario * getAdicional();
	salario += getFilhos() * 100;
    return salario;
}

//calculo da rescisao do asg
float Asg::calcularRescisao(Data desligamento) {
  // as variaveis para contar o tempo que o asg trabalhou na empresa
    int anosTrabalhados = desligamento.ano - getIngresso().ano;
    int mesesTrabalhados = desligamento.mes - getIngresso().mes;
    int diasTrabalhados = desligamento.dia - getIngresso().dia;
  
// analisa se obteve um número negativo, se sim significa que não trabalhou um ano completo e então decrementamos a variavel que guarda os anos trabalhados inteiros
    if (mesesTrabalhados < 0 || (mesesTrabalhados == 0 && diasTrabalhados < 0)){
        anosTrabalhados--;
		mesesTrabalhados += 12;
    }
  
	// calculo de tempo liquido em anos
    float anosFracionados = anosTrabalhados + (mesesTrabalhados / 12.0f) + (diasTrabalhados / 365.0f);

  //salario minimo por ano
  
    float salarioBasePorAno = calcularSalario(0) * 12;
  // calculo da rescisao do contrato do asg
  
    float rescisao = salarioBasePorAno * anosFracionados;

    return rescisao;
}