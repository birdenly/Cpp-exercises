#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <vector>
#include "pessoa.hpp"
#include "funcionario.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
/**
* @file empresa.hpp
* @brief Classe "Empresa", aqui sera feito a maioria das funções importantes para o projeto.
*/
class Empresa{
    float faturamentoMensal;
    std::string nomeEmpresa;
    std::string cnpj;
	Pessoa dono;
	std::vector<Asg> asgs;
	std::vector<Vendedor> vendedores;
	std::vector<Gerente> gerentes;
    
	public:
/**
* @brief Contrutor vazio de "Empresa".
*/
	Empresa();
/**
* @brief Contrutor parametizado de "Empresa".
* @param Recebe nomeEmpresa, cnpj e faturamentoMensal.
*/
	Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal);
/**
* @brief Função que retorna o Faturamento Mensal.
* @return Retorna o Faturamento Mensal.
*/
	float getFaturamentoMensal();
/**
* @brief Função para definir o Faturamento Mensal.
* @param Recebe o Faturamento Mensal como float.
*/
	void setFaturamentoMensal(float faturamentoMensal);
/**
* @brief Função que retorna o Nome da Empresa.
* @return Retorna o Nome da Empresa.
*/
	std::string getNomeEmpresa();
/**
* @brief Função para definir o Nome da Empresa.
* @param Recebe o Nome da Empresa como string.
*/
	void setNomeEmpresa(std::string nomeEmpresa);
/**
* @brief Função que retorna o cnpj.
* @return Retorna o cnpj.
*/
	std::string getCnpj();
/**
* @brief Função para definir o cnpj.
* @param Recebe o cnpj como string.
*/
	void setCnpj(std::string cnpj);
/**
* @brief Função que retorna o dono da empresa.
* @return Retorna o dono da empresa.
*/
	Pessoa getDono();
/**
* @brief Função que retorna os Gerentes.
* @return Retorna os Gerentes.
*/
	std::vector<Gerente>& getGerentes();
/**
* @brief Função que retorna os Asgs.
* @return Retorna os Asgs.
*/
	std::vector<Asg>& getAsgs();
/**
* @brief Função que retorna os Vendedores.
* @return Retorna os Vendedores.
*/
	std::vector<Vendedor>& getVendedores();
/**
* @brief Função utilizada para iniciar as outras funções, ela lê o arquivo funçoes.txt e caso a função exista no codigo ira executa-la.
*/
	void carregaFuncoes();
/**
* @brief Função utilizada para inicializar a empresa, ela lê o arquivo empresa.txt e passa suas informações para a empresa.
*/
	void carregarEmpresa();
/**
* @brief Função utilizada para inicializar os Asgs, ela lê o arquivo asg.txt e passa suas informações para os Asgs.
*/
	void carregarAsg();
/**
* @brief Função utilizada para inicializar os Vendedores, ela lê o arquivo vendedores.txt e passa suas informações para os Vendedores.
*/
	void carregarVendedor();
/**
* @brief Função utilizada para inicializar os Gerentes, ela lê o arquivo gerente.txt e passa suas informações para os Gerentes.
*/
	void carregarGerente();
/**
* @brief Função utilizada para inicializar o Dono, ela lê o arquivo dono.txt e passa suas informações para o Dono.
*/
	void carregaDono();
/**
* @brief Função utilizada para pecorrer todos os Asgs e imprime-los.
*/
	void imprimeAsgs();
/**
* @brief Função utilizada para pecorrer todos os Vendedores e imprime-los.
*/
	void imprimeVendedores();
/**
* @brief Função utilizada para pecorrer todos os Gerentes e imprime-los.
*/
	void imprimeGerentes();
/**
* @brief Função utilizada para imprimir o Dono.
*/
	void imprimeDono();
/**
* @brief Função para procurar o funcionario pela matricula recebida por todos os vetores de funcionarios. (Asgs,Vendedores e Gerentes).
* @param Recebe a matricula que sera procurada.
* @return Retorna true, caso o funcionario seja achado.
*/
	bool buscaFuncionario(std::string matricula);
/**
* @brief Função para calcular o salario do funcionario que corresponde a matricula recebida.
* @param Recebe a matricula que sera procurada.
*/
	void calculaSalarioFuncionario(std::string matricula);
/**
* @brief Função para calcular o salario individualmente de cada classe de funcionario depois soma-los para dar o total de gastos da empresa com seus funcionarios e imprimindo-a, além disso a função cria o relatorioFinanceiro.txt.
*/
	void calculaTodoOsSalarios();
/**
* @brief Função para calcular a recisão, realiza a busca do funcionario e depois calcula a recisao desse funcionario encontrado.
* @param Recebe a matricula e a data de desligamento do funcionario.
*/
	void calcularRecisao(std::string matricula, Data desligamento);
/**
* @brief Função para demitir o funcionario, ele acha o funcionario pela matricula escreve seu relatorio de demissão no arquivo relatorioDemissional.txt, depois remove esse funcionario do vetor e re-escreve o arquivo asg.txt com as informações atualizadas.
* @param Recebe a matricula e a data de desligamento do funcionario.
*/
  void demitirFuncionario(std::string matricula,Data desligamento);
/**
* @brief Lê o arquivo novoFuncionario.txt, olha sua primeira linha para saber o tipo de funcionario que sera contratado assim entrando no IF correto e lendo as linhas do arquivo passado, apos isso, adiciona o novo funcionario ao final do arquivo correspondente ao tipo de funcionario que é.
*/
	void contratarFuncionario();
};

#endif
