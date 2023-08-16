#ifndef UTIL_HPP
#define UTIL_HPP
/**
* @file util.hpp
* @brief Structs "Data" e "Endereco" serão utilizadas no projeto para guardar os dados dos funcionarios.
*/
typedef struct Data{
	int ano;
	int mes;
	int dia;
};
typedef struct Endereco{
	std::string cidade;
	std::string bairro;
	std::string rua;
	std::string cep;
	int numero;
};

#endif