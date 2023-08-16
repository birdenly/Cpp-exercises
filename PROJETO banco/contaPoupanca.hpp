#ifndef CONTAP_HPP
#define CONTAP_HPP


#include <iostream>
#include "Conta.hpp"


class contaPoupanca : public Conta
{
    private:
float TaxaR = 0.05;
    public:

      void depositar(float deposito);
      void sacar(float saca);

 float getTaxaRendimento();
  void setTaxaRendimento(float rendimento);


};

#endif