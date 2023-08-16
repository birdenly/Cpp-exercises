#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>

class Conta{

protected:
float saldoC;

public:

void virtual depositar(float valor) = 0;
void virtual sacar(float valor) = 0;
float getSaldo();
void setSaldo(float saldo);







};
#endif