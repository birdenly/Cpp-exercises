#include <iostream>
#include "empresa.hpp"

using namespace std;

/**
* @file main.cpp
* @author João Marinho Caldas Neto, Pedro Arthur Magalhaes Alecrim
* @details Projeto com o objetivo de simulação de uma empresa real, onde todos os funcionarios estão em seus respectivos vetores com seus dados detalhados, tendo como principal arquivo o empresa.cpp onde há grande parte das grandes funções para o funcionamento da empresa.
* @date 23/06/2023
*
*/

/**
* @brief O objeto "atacadoDosCalcado" do tipo empresa é criado e a utilização de carregaFuncoes() para da inicio ao programa.
*/
int main() {

	Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calcados", "40.101.588/0001-98", 156289.56 );
	
	atacadoDosCalcado->carregaFuncoes();
}