#include <iostream>

#include "client.hpp"
#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"
#include "Conta.hpp"

using namespace std;

int main() {
  client *joao= new client("joao","900.000.666-10",250,250);
  cout << "----Saldo----\n";
  cout << "Saldo Joao Conta Corrente: " << joao->getCC()->getSaldo()<< endl;
  cout << "Saldo Joao Poupança: " << joao->getCP()->getSaldo() << endl;
  cout << "----Depositar----\n";
  joao->getCC()->depositar(1000);
  joao->getCP()->depositar(1000);
  cout << "----SALDO----\n";
  cout << "Saldo Joao Conta Corrente: " << joao->getCC()->getSaldo() << endl;
  cout << "Saldo Joao Poupança: " << joao->getCP()->getSaldo() << endl;
  cout << "----Sacar----\n";
  joao->getCC()->sacar(155);
  joao->getCP()->sacar(280);
  cout << "----Saldo----\n";
  cout << "Saldo Joao Conta Corrente: " << joao->getCC()->getSaldo() << endl;
  cout << "Saldo Joao Poupança:" << joao->getCP()->getSaldo() << endl;
  
  
  






  
}