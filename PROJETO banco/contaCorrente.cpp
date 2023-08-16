
#include "contaCorrente.hpp"

using namespace std;


  void contaCorrente::depositar(float deposito){
    
  this->setSaldo(deposito);
cout << "Sucesso.\n";
  }
void contaCorrente::sacar(float saca){
    
    if(this->saldoC >= saca*(1+TaxaS)){
    this->setSaldo(((saca*(1+TaxaS))*-1));
      cout << "Saque realizado\n";
    }
    else{
      cout << "Valor insuficiente na conta\n";
        }
  }

float contaCorrente::getTaxaSaque(){
  return TaxaS;
}

void contaCorrente::setTaxaSaque(float taxa ){
  this->TaxaS = taxa ;
}
