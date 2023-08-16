
#include "client.hpp"
#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"
#include "Conta.hpp"

using namespace std;



string client::getNome(){
    return this->nome;
  }
  void client::setNome(string nome){
    this->nome = nome;
  }
  string client::getCpf(){
    return this->cpf;
  }
  void client::setCpf(string cpf){
    this->cpf = cpf;
  }
client::client(){
}

    
    
  client::client(string nome, string cpf, float saldoPoupanca,float saldoConta)
    {
        this->nome = nome;
        this->cpf = cpf;
        corrente = new contaCorrente();
        poupanca = new contaPoupanca();
        corrente->setSaldo(saldoConta);
        poupanca->setSaldo(saldoPoupanca);
    }

contaCorrente* client::getCC(){
  return this->corrente;
}

contaPoupanca* client::getCP(){
  return this->poupanca;
}