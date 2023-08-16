#include "Conta.hpp"

using namespace std;


float Conta::getSaldo(){
  return saldoC;
}

void Conta::setSaldo(float saldo){
  this->saldoC += saldo;
}

