#include <iostream>

using namespace std;

int soma_numeros(int a, int b) {
  if (a >= b) {
    return 0;
  }

  else {
    return a + soma_numeros(a + 1, b);
  }
}

int main() {
  int a, b;
  cout << "Digite o valor de A: ";
  cin >> a;
  cout << "Digite o valor de B: ";
  cin >> b;

  int resultado = soma_numeros(a, b);
  cout << "A soma dos números entre " << a << " e " << b << " é " << resultado;

  return 0;
}