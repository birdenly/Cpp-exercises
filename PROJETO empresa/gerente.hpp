#ifndef GERENTE_HPP
#define GERENTE_HPP
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"
/**
* @file gerente.hpp
* @brief Criação da classe "Gerente" que herda publicamente de "Pessoa" e "Funcionario", aplica as funções virtuais calcularSalario e calcularRecisao de "Funcionario".
*/
class Gerente : public Pessoa, public Funcionario{
	float participacaoLucros;
  int diasFalta;

	public:
/**
* @brief Contrutor vazio de "Gerente".
*/
	Gerente();
/**
* @brief Contrutor parametizado de "Gerente".
* @param Recebe nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salario, matricula, ingressoEmpresa e participacaoLucros
*/
	Gerente(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula, Data ingressoEmpresa, float participacaoLucros);
/**
* @brief Função que retorna lucro do gerente.
* @return Retorna o lucro do gerente.
*/
	char getLucros();
/**
* @brief Função para definir o lucro do gerente.
* @param Recebe o lucro do gerente como float.
*/
    void setLucros(float participacaoLucros);
/**
* @brief Função que retorna a quantidade de dias de falta.
* @return Retorna a quantidade de dias de falta.
*/
int getdiasFaltas();
/**
* @brief Função para definir a quantidade de dias de falta.
* @param Recebe a quantidade de dias de falta como int.
*/
  void setdiasFalta(int diasFalta);
/**
* @brief Função que para calcular o salario, utiliza do lucro do gerente.
* @param Recebe a quantidade de dias que faltou.
* @return Retorna o salario.
*/
	float calcularSalario(int diasFalta);
/**
* @brief Função que para calcular a recisão.
* @param Recebe o dia que foi desligado da empresa.
* @return Retorna o valor da recisão.
*/
    float calcularRescisao(Data desligamento);
};

#endif
