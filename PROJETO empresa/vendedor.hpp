#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"
/**
* @file vendedor.hpp
* @brief Classe "Vendedor" que herda publicamente de "Pessoa" e "Funcionario", aplica as funções virtuais calcularSalario e calcularRecisao de "Funcionario".
*/

class Vendedor : public Pessoa, public Funcionario{
	char tipoVendedor;
  int diasFalta;

	public:
/**
* @brief Contrutor vazio de "Vendedor".
*/
	Vendedor();
/**
* @brief Contrutor parametizado de "Vendedor".
* @param Recebe nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salario, matricula, ingressoEmpresa e tipoVendedor
*/
	Vendedor(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula, Data ingressoEmpresa, char tipoVendedor);

/**
* @brief Função que retorna o tipo de vendedor.
* @return Retorna o tipo de vendedor.
*/
	char getTipo();
/**
* @brief Função para definir o tipo de vendedor.
* @param Recebe o tipo do vendedor como char.
*/
  void setTipo(char tipoVendedor);
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
* @brief Função que para calcular o salario, utiliza do tipo de vendedor.
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
