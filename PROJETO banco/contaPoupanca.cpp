
#include "contaPoupanca.hpp"

using namespace std;

  void contaPoupanca::depositar(float deposito){
    
  this->setSaldo(deposito*(1+TaxaR));
cout << "Sucesso.\n";
  }
void contaPoupanca::sacar(float saca){
    
    if(this->saldoC >= saca){
      
    this->setSaldo(saca*(-1));
      cout << "Saque realizado\n";
    }
    else{
      cout << "Valor insuficiente na conta\n";
        }
  }

float contaPoupanca::getTaxaRendimento(){
  return TaxaR;
}

void contaPoupanca::setTaxaRendimento(float taxa ){
  this->TaxaR = taxa ;
}