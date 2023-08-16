#ifndef ASG_HPP
#define ASG_HPP
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "util.hpp"
/**
* @file asg.hpp
* @brief Classe "Asg" que herda publicamente de "Pessoa" e "Funcionario", aplica as funções virtuais calcularSalario e calcularRecisao de "Funcionario".
*/
class Asg : public Pessoa, public Funcionario {
    float adicionalInsalubridade;
    int diasFalta;
	public:
/**
* @brief Contrutor vazio de "Asg".
*/
    Asg();
/**
* @brief Contrutor parametizado de "Asg".
* @param Recebe nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salario, matricula, dataingresso e adicionalInsalubridade.
*/  
    Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula, Data dataIngresso, float adicionalInsalubridade);

/**
* @brief Função que retorna o adicional de insalubridade.
* @return Retorna o adicional de insalubridade.
*/
    float getAdicional();
/**
* @brief Função para definir o adicional de insalubridade.
* @param Recebe o adicional de insalubridade como float.
*/
    void setAdicional(float adicionalInsalubridade);
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
* @brief Função que para calcular o salario, utiliza o adicional de insalubridade.
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