#include <iostream>
#include <map>

using namespace std;

struct Notas {
  float nota01;
  float nota02;
  float nota03;
  float media;
};

int main() {

  map<string, Notas> aluno; // nome é a chave
  float nota1;
  float nota2;
  float nota3;
  
  cout << "Nome do aluno: ";
  string nome;
  cin >> nome;
  cout << "Nota 1: ";
  cin >> nota1;
  cout << "Nota 2: ";
  cin >> nota2;
  cout << "Nota 3: ";
  cin >> nota3;

  aluno[nome].nota01 = nota1;
  aluno[nome].nota02 = nota2;
  aluno[nome].nota03 = nota3;
  aluno[nome].media = (nota1 + nota2 + nota3) / 3;

  for (auto i : aluno) {
    cout << "Nome: " << i.first << endl;
    cout << "Nota 1: " << i.second.nota01 << endl;
    cout << "Nota 2: " << i.second.nota02 << endl;
    cout << "Nota 3: " << i.second.nota03 << endl;
    cout << "Media: " << i.second.media;
  }
}