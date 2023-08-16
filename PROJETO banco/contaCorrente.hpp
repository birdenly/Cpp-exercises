#ifndef CONTAC_HPP
#define CONTAC_HPP


#include <iostream>
#include "Conta.hpp"


class contaCorrente : public Conta
{
    private:
float TaxaS = 0.05;
    public:

      void depositar(float deposito);
      void sacar(float saca);

 float getTaxaSaque();
  void setTaxaSaque(float taxa);


};

#endif