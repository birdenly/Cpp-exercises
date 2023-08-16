#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include "pessoa.hpp"
#include "util.hpp"
/**
* @file funcionario.hpp
* @brief Criação da classe "Funcionario", possui as funções virtuais calcularSalario e calcularRecisao que serão utilizadas por asg,vendedor e gerente.
*/
class Funcionario{
	std::string salario;
	std::string matricula;
	Data ingressoEmpresa;
  

	public:
  int diasFalta;
// declaração de gets e sets e das funções
	  std::string getSalario();
    void setSalario(std::string salario);
    std::string getMatricula();
    void setMatricula(std::string matricula);
	  Data getIngresso();
	  void setIngresso(Data ingressoEmpresa);

    int getdiasFaltas();
    void setdiasFalta(int diasFalta);

    virtual float calcularSalario(int diasFalta) = 0;
    virtual float calcularRescisao(Data desligamento) = 0;

};

#endif