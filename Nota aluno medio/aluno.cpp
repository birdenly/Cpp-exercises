#include <iostream>
#include <map>
#include <fstream>

using namespace std;


struct Notas{
    double nota01;
    double nota02;
    double nota03;
    double media;
};

map<string, Notas> alunos;

void escreverARQ(string nome, double nota1, double nota2, double nota3, double media){
  
  fstream arquivo;
  arquivo.open("ALUNOS.txt", ios::out | ios::app);
    arquivo << nome << endl;
    arquivo << nota1 << endl;
    arquivo << nota2 << endl;
    arquivo << nota3 << endl;
    arquivo << media << endl;
}

void criarMAP(string nome, double nota1, double nota2, double nota3, double media){
    alunos[nome].nota01 = nota1;
    alunos[nome].nota02 = nota2;
    alunos[nome].nota03 = nota3;
    alunos[nome].media = media;
escreverARQ(nome,nota1,nota2,nota3,media);
}

void imprimirAlunos(){
    for(auto i : alunos){
    cout << "Nome: " << i.first << endl;
    cout << "Nota 1: " << i.second.nota01 << endl;
    cout << "Nota 2: " << i.second.nota02 << endl;
    cout << "Nota 3: " << i.second.nota03 << endl;
    cout << "Media: " << i.second.media << endl;
    }
}
    