#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"


class client
{
    private:
std::string nome;
std::string cpf;
contaCorrente *corrente;
contaPoupanca *poupanca;

    public:

client();
  std::string getNome();
  void setNome(std::string nome);
  std::string getCpf();
  void setCpf(std::string cpf);

    client(std::string nome, std::string cpf, float saldoPoupanca,float saldoConta);

contaCorrente* getCC();
contaPoupanca* getCP();

};

#endif