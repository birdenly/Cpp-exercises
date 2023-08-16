#include <iostream>
#include <vector>

using namespace std;

class Aluno{
string nomeCompleto;
string cpf;
string idade;
long int matricula;
string serie;

public:
    Aluno()
    {
    }

    Aluno(string nome, string cpf, string idade,long int matricula, string serie)
    {
        this->nomeCompleto = nome;
        this->cpf = cpf;
        this->idade = idade;
        this->matricula = matricula;
        this->serie = serie;
    }

    string getNomeC()
    {
        return this->nomeCompleto;
    }
    void setNomeC(string nome)
    {
        this->nomeCompleto = nome;
    }
    string getCpf()
    {
        return this->cpf;
    }
    void setCpf(string cpf)
    {
        this->cpf = cpf;
    }

  string getIdade()
    {
        return this->idade;
    }
    void setIdade(string idade)
    {
        this->idade = idade;
    }

    long int getMatricula()
    {
        return this->matricula;
    }
    void setMatricula(long int matricula)
    {
        this->matricula = matricula;
    }

    string getSerie()
    {
        return this->serie;
    }
    void setSerie(string serie)
    {
        this->serie = serie;
    }
};



class Funcionario{
string nomeCompleto;
string cpf;
string idade;
long int matricula;
string cargo;
float salario;

public:
    Funcionario()
    {
    }

    Funcionario(string nome, string cpf, string idade,long int matricula, string cargo,float salario)
    {
        this->nomeCompleto = nome;
        this->cpf = cpf;
        this->idade = idade;
        this->matricula = matricula;
        this->cargo = cargo;
        this->salario = salario;
    }

    string getNomeC()
    {
        return this->nomeCompleto;
    }
    void setNomeC(string nome)
    {
        this->nomeCompleto = nome;
    }
    string getCpf()
    {
        return this->cpf;
    }
    void setCpf(string cpf)
    {
        this->cpf = cpf;
    }
  string getIdade()
    {
        return this->idade;
    }
    void setIdade(string idade)
    {
        this->idade = idade;
    }

    long int getMatricula()
    {
        return this->matricula;
    }
    void setMatricula(long int matricula)
    {
        this->matricula = matricula;
    }

    string getCargo()
    {
        return this->cargo;
    }
    void setCargo(string cargo)
    {
        this->cargo = cargo;
    }
    float getSalario()
    {
        return this->salario;
    }
    void setSalario(float salario)
    {
        this->salario = salario;
    }
};

class Escola{
    string nomeEscola;
    string cnpj;
    Funcionario *FUNCIO = new Funcionario[5];
    Aluno *ALUNO = new Aluno[10];
    vector<Funcionario> FUNCIONARIO;
    vector<Aluno> ALUNOS;
    int contA = 0;
    int contF = 0;

public:
    Escola(string nomeEscola, string cnpj)
    {
        this->nomeEscola = nomeEscola;
        this->cnpj = cnpj;
    }

    string getNomeEscola()
    {
        return this-> nomeEscola;
    }
    void setNomeEscola(string  nomeEscola)
    {
        this->nomeEscola =  nomeEscola;
    }

    string getcnpj()
    {
        return this->cnpj;
    }
    void setcnpj(string cnpj)
    {
        this->cnpj = cnpj;
    }
    void inserirFuncionario(string nome, string cpf, string idade,long int matricula,string cargo, float salario){
        Funcionario temp(nome, cpf, idade ,matricula,cargo, salario);
        FUNCIONARIO.push_back(temp);
    }
    void inserirAluno(string nome, string cpf,string idade, long int matricula, string serie){
        Aluno temp(nome, cpf,idade, matricula, serie);
        ALUNOS.push_back(temp);
    }

    void criarAluno(string nome, string cpf,string idade, long int matricula, string serie){
       // if (contA < 10)
       // {
            ALUNO[contA].setNomeC(nome);
            ALUNO[contA].setCpf(cpf);
            ALUNO[contA].setIdade(idade);
            ALUNO[contA].setMatricula(matricula);
            ALUNO[contA].setSerie(serie);
            contA++;
       // }
       // else
       // {
           // cout << "Não pode mais adicionar alunos" << endl;
       // }
    }

    void criarFuncionario(string nome, string cpf,string idade, long int matricula, string cargo,float salario){
       // if (contF < 10)
       // {
            FUNCIO[contF].setNomeC(nome);
            FUNCIO[contF].setCpf(cpf);
            FUNCIO[contF].setIdade(idade);
            FUNCIO[contF].setMatricula(matricula);
            FUNCIO[contF].setCargo(cargo);
            FUNCIO[contF].setSalario(salario);
            contF++;
      //  }
       // else
       // {
         //   cout << "Não pode mais adicionar alunos" << endl;
        //}
    }


    void listarAlunos()
    {
        cout << "------ALUNOS DA ESCOLA------" << endl;
        for (int i = 0; i < contA; i++)
        {
            cout << "Nome: " << ALUNO[i].getNomeC() << endl;
            cout << "Cpf: " << ALUNO[i].getCpf() << endl;
            cout << "Idade " << ALUNO[i].getIdade() << endl;
            cout << "Matricula: " << ALUNO[i].getMatricula() << endl;
            cout << "Serie: " << ALUNO[i].getSerie() << endl;
            cout << "-------------------------------" << endl;
        }
    }
    void listarFuncionarios()
    {
        cout << "------FUNCIONARIOS DA ESCOLA------" << endl;
        for (int i = 0; i < contF; i++)
        {
            cout << "Nome: " << FUNCIO[i].getNomeC() << endl;
            cout << "Cpf: " << FUNCIO[i].getCpf() << endl;
            cout << "Idade " << FUNCIO[i].getIdade() << endl;
            cout << "Matricula: " << FUNCIO[i].getMatricula() << endl;
            cout << "Cargo: " << FUNCIO[i].getCargo() << endl;
            cout << "Salario: " << FUNCIO[i].getSalario() << endl;
            cout << "-------------------------------" << endl;
        }
    }

    float salarioT(){
        float soma = 0;
        for (int i = 0; i < contF; i++){
            soma += FUNCIO[i].getSalario();
        }
        return soma;
    }
};

int main()
{
  int totalA = 0;
  int totalF = 0;
        cout << "Nome da escola: ";
        string nomeE;
        cin >> nomeE;
        cout << "cnpj: ";
        string cnpj;
        cin >> cnpj;
    Escola *ESCOLA = new Escola(nomeE, cnpj);

        cout << "1- ALUNO" << endl;
        cout << "2- FUNCIONARIO" << endl;
        cout << "3- SALARIO" << endl;
        int opc;
        cin >> opc;
if(opc == 1){
  while(totalA <10){
        cout << "Nome do aluno: ";
        string nome;
        cin >> nome;
         cout << "Cpf: ";
        string cpf;
        cin >> cpf;
         cout << "Idade: ";
        string idade;
        cin >> idade;
        cout << "Matricula: ";
        long int matricula;
        cin >> matricula;
        cout << "serie: ";
        string serie;
        cin >> serie;
totalA++;
    ESCOLA->criarAluno(nome, cpf, idade, matricula,serie);
  }
    ESCOLA->listarAlunos();
}
if(opc==2){
    while(totalF <5){
        cout << "Nome do funcionario: ";
        string nome;
        cin >> nome;
         cout << "Cpf: ";
        string cpf;
        cin >> cpf;
         cout << "Idade: ";
        string idade;
        cin >> idade;
        cout << "Matricula: ";
        long int matricula;
        cin >> matricula;
        cout << "Cargo: ";
        string cargo;
        cin >> cargo;
        cout << "Salario: ";
        float salario;
        cin >> salario;
totalF++;
    ESCOLA->criarFuncionario(nome, cpf, idade, matricula,cargo,salario);
  }
    ESCOLA->listarFuncionarios();
    float salario = ESCOLA->salarioT();
    cout << "Salarios Total: "<< salario << endl;
}



  
    return 0;
}