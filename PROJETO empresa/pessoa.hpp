#ifndef PESSOA_HPP
#define PESSOA_HPP
#include "util.hpp"
#include "funcionario.hpp"
/**
* @file pessoa.hpp
* @brief Criação da classe "Pessoa" que será utilizada para guardar dados dos funcionarios da empresa.
*/
class Pessoa{
	std::string nome;
	std::string cpf;
	Data dataNascimento;
	Endereco enderecoPessoal;
	std::string estadoCivil;
	int qtdFilhos;

	public:
/**
* @brief Contrutor vazio de "Pessoa".
*/
	Pessoa();
/**
* @brief Contrutor parametizado de "Pessoa".
* @param Recebe nome, cpf, dataNascimento, enderecoPessoal, estadoCivil e qtdFilhos.
*/
	Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);
/**
* @brief Função que retorna o nome.
* @return Retorna o tipo de vendedor.
*/
	std::string getNome();
/**
* @brief Função para definir o nome.
* @param Recebe o nome como string.
*/
    void setNome(std::string nome);
/**
* @brief Função que retorna o cpf.
* @return Retorna o cpf.
*/
    std::string getCpf();
/**
* @brief Função para definir o cpf.
* @param Recebe o cpf como string.
*/
    void setCpf(std::string cpf);
/**
* @brief Função que retorna a data de nascimento.
* @return Retorna a data de nascimento.
*/
	Data getData();
/**
* @brief Função para definir a data de nascimento.
* @param Recebe a data de nascimento como Data.
*/
	void setData(Data dataNascimento);
/**
* @brief Função que retorna o endereço.
* @return Retorna o endereço.
*/
	Endereco getEndereco();
/**
* @brief Função para definir o endereço.
* @param Recebe o endereço como Endereco.
*/
	void setEndereco(Endereco enderecoPessoal);
/**
* @brief Função que retorna o estado civil.
* @return Retorna o estado civil.
*/
	std::string getEstadoCivil();
/**
* @brief Função para definir o estado civil.
* @param Recebe o estado civil como string.
*/
	void setEstadoCivil(std::string estadoCivil);
/**
* @brief Função que retorna a quantidade de filhos.
* @return Retorna a quantidade de filhos.
*/
	int getFilhos();
/**
* @brief Função para definir a quantidade de filhos.
* @param Recebe a quantidade de filhos como int.
*/
	void setFilhos(int qtdFilhos);
	
};

#endif
