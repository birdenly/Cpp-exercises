#include "header.hpp"
#include <iostream>

using namespace std;

int main() {
  int forma;
  float area;
  cout << "---Área que quer calcular---" << endl;
  cout << " " << endl;
  cout << "triangulo: digite 1" << endl;
  cout << "circulo: digite 2" << endl;
  cout << "quadrado: digite 3" << endl;
  cout << "retangulo: digite 4" << endl;
  cout << " " << endl;
  cout << "------------------------------" << endl;
  cin >> forma;

  if (forma == 1) {
    float base;
    float altura;

    cout << "Valor da base" << endl;
    cin >> base;
    cout << "Valor da altura" << endl;
    cin >> altura;

    area = triangulo(base, altura);
    cout << "Área do triangulo é: " << area << endl;
  }
  if (forma == 2) {
    float raio;

    cout << "Valor do raio" << endl;
    cin >> raio;

    area = circulo(raio);
    cout << "Área do circulo é: " << area << endl;
  }
  if (forma == 3) {
    float lado;

    cout << "Valor do lado" << endl;
    cin >> lado;

    area = quadrado(lado);
    cout << "Área do quadrado é: " << area << endl;
  }
  if (forma == 4) {
    float base;
    float altura;

    cout << "Valor da base" << endl;
    cin >> base;
    cout << "Valor da altura" << endl;
    cin >> altura;

    area = retangulo(base, altura);
    cout << "Área do retangulo é: " << area << endl;
  }
  if(forma > 4 or forma <= 0){
    cout << "Número Invalido." << endl;
  }

  return 0;
}