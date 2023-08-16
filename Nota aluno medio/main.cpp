#include <iostream>
#include <map>
#include "aluno.hpp"


using namespace std;

int main(){
  double nota1;
  double nota2;
  double nota3;
  double media;
    while(true){
      
        cout << "Digite um nome: ";
        string nome;
        cin >> nome;
        if(nome == "parar"){
           break;
        }
        cout << "Digite a nota 01: ";
        cin >> nota1;
        cout << "Digite a nota 02: ";
        cin >> nota2;
        cout << "Digite a nota 03: ";
        cin >> nota3;
      media = (nota1+nota2+nota3)/3;
      
        criarMAP(nome, nota1, nota2, nota3,media);
    }
    imprimirAlunos();
}