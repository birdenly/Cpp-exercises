#include <iostream>
using namespace std;

float triangulo(float base, float altura) { return base * altura / 2; }

float circulo(float raio) { return 3.14 * (raio * raio); }

float quadrado(float lado) {
  float area = lado * lado;
  return area;
}

float retangulo(float base, float altura) { return base * altura; }
