#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "empresa.hpp"
using namespace std;
//construtor vazio
Empresa::Empresa(){}
//construtor parametizado
Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal){
	Empresa::setNomeEmpresa(nomeEmpresa);
	Empresa::setCnpj(cnpj);
	Empresa::setFaturamentoMensal(faturamentoMensal);
}
//metodos gets e sets
float Empresa::getFaturamentoMensal(){
	return this->faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float faturamentoMensal){
	this->faturamentoMensal = faturamentoMensal;
}

string Empresa::getNomeEmpresa(){
	return this->nomeEmpresa;
}

void Empresa::setNomeEmpresa(string nomeEmpresa){
	this->nomeEmpresa = nomeEmpresa;
}

string Empresa::getCnpj(){
	return this->cnpj;
}

void Empresa::setCnpj(string cnpj){
	this->cnpj = cnpj;
}

Pessoa Empresa::getDono(){
	return this->dono;
}

vector<Gerente>& Empresa::getGerentes(){
	return this->gerentes;
}

vector<Asg>& Empresa::getAsgs(){
	return this->asgs;
}

vector<Vendedor>& Empresa::getVendedores(){
	return this->vendedores;
}
//funçao que carrega as funções
void Empresa::carregaFuncoes(){
    //cria e lê as funçoes do arquivo
    fstream arquivo;
    arquivo.open("funcoes.txt", ios::in);
    string linha;
    while(getline(arquivo, linha))
    {
        if(linha == "carregarEmpresa()") {
          this->carregarEmpresa();
        }
        else if(linha == "carregarAsg()") {
          this->carregarAsg();
        }      
        else if(linha == "carregarVendedor()"){
         this->carregarVendedor();
        } 
        else if(linha == "carregarGerente()") {
          this->carregarGerente();
        } 
        else if(linha == "carregaDono()") {
          this->carregaDono();
        }   
        else if(linha == "imprimeAsgs()"){
          this->imprimeAsgs();
        }
        else if(linha == "imprimeVendedores()"){
          this->imprimeVendedores();
        } 
        else if(linha == "imprimeGerentes()") {
          this->imprimeGerentes();
        }
        else if(linha == "imprimeDono()") {
          this->imprimeDono();
        } 
        else if(linha == "buscaFuncionario()")
        {
            getline(arquivo, linha);
            this->buscaFuncionario(linha);
        }
        else if(linha == "calculaSalarioFuncionario()") 
        {
            getline(arquivo, linha);
            this->calculaSalarioFuncionario(linha);
        }
        else if(linha == "calculaTodoOsSalarios()"){
          this->calculaTodoOsSalarios();
        } 
        else if(linha == "calcularRecisao()")
        {
            getline(arquivo, linha);

            if(buscaFuncionario(linha))
            {
                string matricula = linha;
                getline(arquivo, linha);
                Data desligamento;
                desligamento.ano = stoi(linha); 
                getline(arquivo, linha);
                desligamento.mes = stoi(linha); 
                getline(arquivo, linha);
                desligamento.dia = stoi(linha); 
                this->calcularRecisao(matricula,desligamento);
            }
            else cout << "Funcionario nao encontrado no sistema.\n";

        }
      else if(linha == "demitirFuncionario()")
        {
            getline(arquivo, linha);
            string matricula = linha;
            getline(arquivo, linha);
            Data desligamento;
            desligamento.ano = stoi(linha); 
            getline(arquivo, linha);
            desligamento.mes = stoi(linha); 
            getline(arquivo, linha);
            desligamento.dia = stoi(linha); 
            this->demitirFuncionario(matricula,desligamento);

        }
      else if(linha == "contratarFuncionario()"){
        this->contratarFuncionario();
      }
    }
    arquivo.close();
  
}
//carrega a empresa
void Empresa::carregarEmpresa(){
    //cria o arquivo
    fstream arquivo;
    arquivo.open("empresa.txt", ios::in);

    string linha;
    Empresa* empresa = new Empresa;
    //passa os dados do arquivo para a empresa
    while (getline(arquivo, linha)) {
     if (linha.find("DADOS DA EMPRESA") != string::npos) {
        getline(arquivo, linha); //nome
        empresa->setNomeEmpresa(linha);
        getline(arquivo, linha); //cnpj
        empresa->setCnpj(linha);
        getline(arquivo, linha); //faturamento
        empresa->setFaturamentoMensal(stoi(linha));
        
    arquivo.close();
}
}
}
//carrega os Asgs
void Empresa::carregarAsg(){
	  
    fstream arquivo;
    arquivo.open("asg.txt", ios::in);

    string linha;
    Asg asg;
    //lê o arquivo e passa para o vetor
    while (getline(arquivo, linha)) {
    if (linha.find("ASG Nº") != string::npos) {
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //nome
        asg.setNome(linha);
        getline(arquivo, linha); //CPF
        asg.setCpf(linha);
        getline(arquivo, linha); //número de filhos
        asg.setFilhos(stoi(linha));
        getline(arquivo, linha); //estado civil
        asg.setEstadoCivil(linha);
        getline(arquivo, linha); //Ignora a linha 
        getline(arquivo, linha); //cidade
        string cidade = linha;
        getline(arquivo, linha); //CEP
        string cep = linha;
        getline(arquivo, linha); //bairro
        string bairro = linha;
        getline(arquivo, linha); //rua
        string rua = linha;
        getline(arquivo, linha); //número da casa
        int numero = stoi(linha);
        Endereco endereco{cidade, bairro, rua, cep, numero};
        asg.setEndereco(endereco);
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //ano de nascimento
        int anoNascimento = stoi(linha);
        getline(arquivo, linha); //mês de nascimento
        int mesNascimento = stoi(linha);
        getline(arquivo, linha); //dia de nascimento
        int diaNascimento = stoi(linha);
        Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
        asg.setData(dataNascimento);
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //matrícula
        asg.setMatricula(linha);
        getline(arquivo, linha); //salário
        asg.setSalario(linha);
        getline(arquivo, linha); //taxa de insalubridade
        asg.setAdicional(stof(linha));
        getline(arquivo, linha); //dias de falta
		    asg.setdiasFalta(stoi(linha));
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //ano de ingresso
        int anoIngresso = stoi(linha);
        getline(arquivo, linha); //mês de ingresso
        int mesIngresso = stoi(linha);
        getline(arquivo, linha); //dia de ingresso
        int diaIngresso = stoi(linha);
        Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};
        asg.setIngresso(dataIngresso);
        this->asgs.push_back(asg);
        }
    }
    arquivo.close();
}
//carrega os vendedores
void Empresa::carregarVendedor(){
    
    fstream arquivo;
    arquivo.open("vendedor.txt", ios::in);
    string linha;
    Vendedor vendedor;
    //lê e passa do arquivo pro vetor
    while (getline(arquivo, linha)) {
    if (linha.find("VENDEDOR Nº") != string::npos) {
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //nome
        vendedor.setNome(linha);
        getline(arquivo, linha); //CPF
        vendedor.setCpf(linha);
        getline(arquivo, linha); //número de filhos
        vendedor.setFilhos(stoi(linha));
        getline(arquivo, linha); //estado civil
        vendedor.setEstadoCivil(linha);
        getline(arquivo, linha); //Ignora a linha 
        getline(arquivo, linha); //cidade
        string cidade = linha;
        getline(arquivo, linha); //CEP
        string cep = linha;
        getline(arquivo, linha); //bairro
        string bairro = linha;
        getline(arquivo, linha); //rua
        string rua = linha;
        getline(arquivo, linha); //número da casa
        int numero = stoi(linha);
        Endereco endereco{cidade, bairro, rua, cep, numero};
        vendedor.setEndereco(endereco);
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //ano de nascimento
        int anoNascimento = stoi(linha);
        getline(arquivo, linha); //mês de nascimento
        int mesNascimento = stoi(linha);
        getline(arquivo, linha); //dia de nascimento
        int diaNascimento = stoi(linha);
        Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
        vendedor.setData(dataNascimento);
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //matricula
        vendedor.setMatricula(linha);
        getline(arquivo, linha); //salário
        vendedor.setSalario(linha);
        getline(arquivo, linha); //tipo do vendedor
		    char tipo = linha.front();
        vendedor.setTipo(tipo);
        getline(arquivo, linha); //dias de falta
		    vendedor.setdiasFalta(stoi(linha));
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //ano de ingresso
        int anoIngresso = stoi(linha);
        getline(arquivo, linha); //mes de ingresso
        int mesIngresso = stoi(linha);
        getline(arquivo, linha); //dia de ingresso
        int diaIngresso = stoi(linha);
        Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};
        vendedor.setIngresso(dataIngresso);
        this->vendedores.push_back(vendedor);
        }
    }
    arquivo.close();
  
}
//carrega os gerentes
void Empresa::carregarGerente(){
  
    fstream arquivo;
    arquivo.open("gerente.txt", ios::in);
    string linha;
    Gerente gerente;
    //lê e passa os dados para o vetor
    while (getline(arquivo, linha)) {
    if (linha.find("GERENTE Nº") != string::npos) {
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //nome
        gerente.setNome(linha);
        getline(arquivo, linha); //CPF
        gerente.setCpf(linha);
        getline(arquivo, linha); //número de filhos
        gerente.setFilhos(stoi(linha));
        getline(arquivo, linha); //estado civil
        gerente.setEstadoCivil(linha);
        getline(arquivo, linha); //Ignora a linha 
        getline(arquivo, linha); //cidade
        string cidade = linha;
        getline(arquivo, linha); //CEP
        string cep = linha;
        getline(arquivo, linha); //bairro
        string bairro = linha;
        getline(arquivo, linha); //rua
        string rua = linha;
        getline(arquivo, linha); //número da casa
        int numero = stoi(linha);
        Endereco endereco{cidade, bairro, rua, cep , numero};
        gerente.setEndereco(endereco);
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //ano de nascimento
        int anoNascimento = stoi(linha);
        getline(arquivo, linha); //mes de nascimento
        int mesNascimento = stoi(linha);
        getline(arquivo, linha); //dia de nascimento
        int diaNascimento = stoi(linha);
        Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
        gerente.setData(dataNascimento);
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //matricula
        gerente.setMatricula(linha);
        getline(arquivo, linha); //salario
        gerente.setSalario(linha);
        getline(arquivo, linha); //valor da participação nos lucros da empresa
        gerente.setLucros(stof(linha));
        getline(arquivo, linha); //qtd de dias que faltou
        gerente.setdiasFalta(stoi(linha));
        getline(arquivo, linha); //Ignora a linha
        getline(arquivo, linha); //ano de ingresso
        int anoIngresso = stoi(linha);
        getline(arquivo, linha); //mes de ingresso
        int mesIngresso = stoi(linha);
        getline(arquivo, linha); //dia de ingresso
        int diaIngresso = stoi(linha);
        Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};
        gerente.setIngresso(dataIngresso);
        this->gerentes.push_back(gerente);
        }
    }
    arquivo.close();
}
//carrega as informações do dono
void Empresa::carregaDono() {
  
    fstream arquivo;
    arquivo.open("dono.txt", ios::in);
    string linha;
    //lê o arquivo e passa para o vetor
    while (getline(arquivo, linha)) {
        if (linha.find("DADOS PESSOAIS DO DONO") != string::npos) {
            getline(arquivo, linha); //nome
            dono.setNome(linha);
            getline(arquivo, linha); //CPF
            dono.setCpf(linha);
            getline(arquivo, linha); //número de filhos
            dono.setFilhos(stoi(linha));
            getline(arquivo, linha); //estado civil
            dono.setEstadoCivil(linha);
            getline(arquivo, linha); //cidade
            string cidade = linha;
            getline(arquivo, linha); //CEP
            string cep = linha;
            getline(arquivo, linha); //bairro
            string bairro = linha;
            getline(arquivo, linha); //rua
            string rua = linha;
            getline(arquivo, linha); //número
            int numero = stoi(linha);
            Endereco endereco{cidade, bairro, rua, cep, numero};
            dono.setEndereco(endereco);
            getline(arquivo, linha); //ano de nascimento
            int anoNascimento = stoi(linha);
            getline(arquivo, linha); //mês de nascimento
            int mesNascimento = stoi(linha);
            getline(arquivo, linha); //dia de nascimento
            int diaNascimento = stoi(linha);
            Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
            dono.setData(dataNascimento);
        }
    }
    arquivo.close();
}

void Empresa::imprimeAsgs(){
  cout << "####### Lista de Asg #######" << endl;
    for (Asg& asg : asgs) {
        cout << "Nome: " << asg.getNome() << endl;
        cout << "CPF: " << asg.getCpf() << endl;
        cout << "Número de filhos: " << asg.getFilhos() << endl;
        cout << "Estado civil: " << asg.getEstadoCivil() << endl;
        cout << "Cidade: " << asg.getEndereco().cidade << endl;
        cout << "Cep: " << asg.getEndereco().cep << endl;
        cout << "Bairro: " << asg.getEndereco().bairro << endl;
        cout << "Rua: " << asg.getEndereco().rua << endl;
        cout << "Número: " << asg.getEndereco().numero << endl;
        cout << "Data de nascimento: " << asg.getData().dia <<"/"<< asg.getData().mes <<"/"<< asg.getData().ano <<endl; 
        cout << "Matrícula: " << asg.getMatricula() << endl;
        cout << "Salário: " << asg.getSalario() << endl;
       	cout << "Porcentagem de insalubridade: " << asg.getAdicional() << endl;
        cout << "Data de ingresso: " << asg.getIngresso().dia <<"/"<< asg.getIngresso().mes << "/"<< asg.getIngresso().ano << endl;
        cout << "-----------------------------" << endl;

}
}

void Empresa::imprimeVendedores(){
	cout << "####### Lista de Vendedores #######" << endl;
    for (Vendedor& vendedor : vendedores) {
        cout << "Nome: " << vendedor.getNome() << endl;
       	cout << "CPF: " << vendedor.getCpf() << endl;
        cout << "Número de filhos: " << vendedor.getFilhos() << endl;
        cout << "Estado civil: " << vendedor.getEstadoCivil() << endl;
        cout << "Cidade: " << vendedor.getEndereco().cidade << endl;
        cout << "Cep: " << vendedor.getEndereco().cep << endl;
        cout << "Bairro: " << vendedor.getEndereco().bairro << endl;
        cout << "Rua: " << vendedor.getEndereco().rua << endl;
        cout << "Número: " << vendedor.getEndereco().numero << endl;
        cout << "Data de nascimento: " << vendedor.getData().dia <<"/"<< vendedor.getData().mes <<"/"<< vendedor.getData().ano <<endl; 
        cout << "Matrícula: " << vendedor.getMatricula() << endl;
        cout << "Salário: " << vendedor.getSalario() << endl;
       	cout << "Tipo de vendedor: " << vendedor.getTipo() << endl;
        cout << "Data de ingresso: " << vendedor.getIngresso().dia <<"/"<< vendedor.getIngresso().mes << "/"<< vendedor.getIngresso().ano << endl;
        cout << "-----------------------------" << endl;
  
	
}
}

void Empresa::imprimeGerentes(){
	cout << "####### Lista de Gerentes #######" << endl;
    for (Gerente& gerente : gerentes) {
        cout << "Nome: " << gerente.getNome() << endl;
        cout << "CPF: " << gerente.getCpf() << endl;
        cout << "Número de filhos: " << gerente.getFilhos() << endl;
        cout << "Estado civil: " << gerente.getEstadoCivil() << endl;
        cout << "Cidade: " << gerente.getEndereco().cidade << endl;
        cout << "Cep: " << gerente.getEndereco().cep << endl;
        cout << "Bairro: " << gerente.getEndereco().bairro << endl;
        cout << "Rua: " << gerente.getEndereco().rua << endl;
        cout << "Número: " << gerente.getEndereco().numero << endl;
        cout << "Data de nascimento: " << gerente.getData().dia <<"/"<< gerente.getData().mes <<"/"<< gerente.getData().ano <<endl; 
        cout << "Matrícula: " << gerente.getMatricula() << endl;
        cout << "Salário: " << gerente.getSalario() << endl;
        cout << "Participação nos lucros: " << gerente.getLucros() << endl;
        cout << "Data de ingresso: " << gerente.getIngresso().dia <<"/"<< gerente.getIngresso().mes << "/"<< gerente.getIngresso().ano << endl;
        cout << "-----------------------------" << endl;
    }
} 

void Empresa::imprimeDono(){
	
	cout << "####### Dono #######" << endl;
	cout << "Nome: " << dono.getNome() << endl;
	cout << "CPF: " << dono.getCpf() << endl;
	cout << "Número de filhos: " << dono.getFilhos() << endl;
	cout << "Estado civil: " << dono.getEstadoCivil() << endl;
	cout << "Cidade: " << dono.getEndereco().cidade << endl;
	cout << "Cep: " << dono.getEndereco().cep << endl;
  	cout << "Bairro: " << dono.getEndereco().bairro << endl;
  	cout << "Rua: " << dono.getEndereco().rua << endl;
	cout << "Número: " << dono.getEndereco().numero << endl;
	cout << "Data de nascimento: " << dono.getData().dia <<"/"<< dono.getData().mes <<"/"<< dono.getData().ano <<endl; 
  	cout << "-----------------------------" << endl;
}

bool Empresa::buscaFuncionario(string matricula){
//realiza a busca da matricula pelos vetores de funcionarios
        cout << "\nBusca Funcionario:" << endl;
        for(auto i : asgs)
        {
            if(i.getMatricula() == matricula)
            {
                cout << "Funcionario Asg encontrado" << endl;
                return true;
            }
        }
    

        for(auto i : vendedores)
        {
            if(i.getMatricula() == matricula)
            {
                cout << "Funcionario Vendendor encontrado" << endl;
                return true;
            }
        }

        for(auto i : gerentes)
        {
            if(i.getMatricula() == matricula)
            {
                cout << "Funcionario Gerente encontrado" << endl;
                return true;
            }
        }
      //se for encontrado retorna true, caso contrario nao retorna nada
    cout << "Funcionário não encontrado no sistema" << endl;
}

void Empresa::calculaSalarioFuncionario(string matricula){
  //realiza uma busca nos vetores para achar o funcionario
          cout << "\nCalculo Salario Funcionario:" << endl;
          for(auto asg : asgs)
        {
            if(asg.getMatricula() == matricula)
            {
              float salasg = asg.calcularSalario(asg.getdiasFaltas());
                cout << "Salario do Asg: " << salasg << endl;
              //calcula o salario do funcionario atraves da matricula
                return;
            }
        }
    

        for(auto vendedor : vendedores)
        {
            if(vendedor.getMatricula() == matricula)
            {
              float salVendedor = vendedor.calcularSalario(vendedor.getdiasFaltas());
              cout << "Salario do Vendedor: " << ": " << salVendedor << endl;
              //calcula o salario do funcionario atraves da matricula
              return;
            }
        }
    

        for(auto gerente : gerentes)
        {
            if(gerente.getMatricula() == matricula)
            {
              float salgerente = gerente.calcularSalario(gerente.getdiasFaltas());
              cout << "Salario do Gerente: " << ": " << salgerente << endl;
              //calcula o salario do funcionario atraves da matricula
               return;
            }
        }
    
    cout << "Funcionário não encontrado no sistema." << endl;
	
}

void Empresa::calculaTodoOsSalarios(){
    //sai somando todos os salarios e depois imprime
    float total_salario_asg = 0.0;
    float total_salario_vendedor = 0.0;
    float total_salario_gerente = 0.0;
    float total=0.0;
cout << "\nCalculo de todos os Salarios:" << endl;

    // criação do arquivo
    fstream arquivo;
    arquivo.open("relatórioFinanceiro.txt", ios::out);
    arquivo << "######### Relatório Financeiro ########" << endl << endl;
    arquivo << "Cargo: ASG" << endl;
    
	for(auto i : this->asgs)
    {
        arquivo << i.getMatricula() << " - " << i.getNome() << " - " << i.getSalario() << endl;
        total_salario_asg += stof(i.getSalario());
        //soma todos os asgs em uma variavel para o total
	}
	arquivo << "Total ASG: " << total_salario_asg << endl;
    

    arquivo << "Cargo: VENDEDOR" << endl;
  
	for(auto i : this->vendedores){
		arquivo << i.getMatricula() << " - " << i.getNome() << " - " << i.getSalario() << endl;

		total_salario_vendedor += stof(i.getSalario());
    //soma todos os vendedores em uma variavel para o total
	}
	arquivo << "Total VENDEDOR: " << total_salario_vendedor << endl;
  
	arquivo << "Cargo: GERENTE" <<endl;
	for(auto i : this->gerentes){ 
    	arquivo << i.getMatricula() << " - " << i.getNome() << " - " << i.getSalario() << endl;
		  total_salario_gerente += stof(i.getSalario());
      //soma todos os gerentes em uma variavel para o total
      
    }
	
	total = total_salario_asg + total_salario_vendedor + total_salario_gerente;
  //calculo do total usando as 3 variaveis anteriores
  cout << "Salario total dos ASGs: " << total_salario_asg << endl;
  cout << "Salario total dos vendedores: " << total_salario_vendedor << endl;
  cout << "Salario total dos gerentes: " << total_salario_gerente << endl;
  cout << "Salario total de todos os funcionarios: " << total << endl;
		
	arquivo << "Total GERENTE: " << total_salario_gerente << endl << endl;

  	arquivo << "CUSTO TOTAL: " << total << endl << endl;

  	arquivo << "FATURAMENTO MENSAL: " << getFaturamentoMensal() << endl << endl;

  
	arquivo << "Custo ASG(%): " << round((total_salario_asg / total * 100)*100) /100<< endl;
	
	arquivo << "Custo VENDEDOR(%): " << round((total_salario_vendedor / total * 100)*100)/100 << endl;
	
	arquivo << "Custo GERENTE(%): " << round((total_salario_gerente / total * 100)*100)/100 << endl << endl;

	float lucro = getFaturamentoMensal() - total;
  //faturamento do mes - o total dos salarios dos funcionarios
  	
	arquivo << "LUCRO DA EMPRESA: " << lucro << endl << endl;

	if (lucro < 0){
		arquivo << "SITUAÇÃO: prejuízo";
	}
	else if(lucro > 0){
		arquivo << "SITUAÇÃO: lucro";
	}
	else{
		arquivo << "SITUAÇÃO: equilíbrio";
	}
	arquivo.close();
}

void Empresa::calcularRecisao(string matricula, Data desligamento){
    //realiza a busca do funcionario pela matricula
    // depois calcula a recisao desse funcionario
	cout << "\nCalculo da Recisão:" << endl;

	for(auto i : asgs)
	{
		if(i.getMatricula() == matricula)
		{
			cout << "Valor da recisao do ASG: " << i.calcularRescisao(desligamento) << endl;
			return;
		}
	}


	for(auto i : vendedores)
	{
		if(i.getMatricula() == matricula)
		{
			cout << "Valor da recisao do VENDEDOR: " << i.calcularRescisao(desligamento) << endl;
			return;
		}
	}


	for(auto i : gerentes)
	{
		if(i.getMatricula() == matricula)
		{
			 cout << "Valor da recisao do GERENTE: " << i.calcularRescisao(desligamento) << endl;
			return;
		}
	}

    cout << "Funcionário não encontrado no sistema." << endl;
}

void Empresa::demitirFuncionario(std::string matricula,Data desligamento){

    //cria e lê os arquivos
    fstream arquivo;
    arquivo.open("relatórioDemissional.txt", ios::out | ios::trunc );
  
    //percorre o vetor
    for(auto it = asgs.begin(); it != asgs.end(); ++it)
        {   //ao achar o funcionario, imprime seu relatorio demissional
            if(it->getMatricula() == matricula)
            {
              cout << "Fazendo relatorio de demissão do ASG" << endl;
              arquivo << "##############################" << endl;
              arquivo << "Relatorio Demissional" << endl;
              arquivo << "##############################" << endl;
              arquivo << "Cargo: ASG" << endl;
              arquivo << "Nome: " << it->getNome() << endl;              
              arquivo << "CPF: " << it->getCpf() <<endl;
              arquivo << "Matrícula: " << it->getMatricula()<< endl;
              arquivo << "Data de ingresso: " << it->getIngresso().dia <<"/"<< it->getIngresso().mes << "/"<< it->getIngresso().ano << endl;
              arquivo << "Data de demissão: " << desligamento.dia <<"/"<< desligamento.mes << "/"<< desligamento.ano << endl;
              arquivo << "******************************" << endl;
              arquivo << "Valor de rescisão: " << it->calcularRescisao(desligamento)  << endl;
              arquivo << "******************************" << endl;
              int anosTrabalhados = desligamento.ano - it->getIngresso().ano;
              int mesesTrabalhados = desligamento.mes - it->getIngresso().mes;
              int diasTrabalhados = desligamento.dia - it->getIngresso().dia;           
              arquivo << "Tempo de Trabalho: " << anosTrabalhados <<" anos, "<< mesesTrabalhados << " meses e "<< diasTrabalhados << " dias"<<endl; 
              arquivo.close();

	
              asgs.erase(it);
              //remove o funcionario

				int i = 0;
		arquivo.open("asg.txt", ios::out);
              //re escreve o arquivo asg sem o funcionario

			  
			  for (Asg& asg : asgs) {
          		arquivo << "#########################################################" << endl;
			    arquivo << "ASG Nº: " << i << endl;
			    arquivo << "##### DADOS PESSOAIS #####" << endl;
			    arquivo << asg.getNome() << endl;
			    arquivo << asg.getCpf() << endl;
         		arquivo << asg.getFilhos() << endl;
			    arquivo << asg.getEstadoCivil() << endl;
          		arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
			    arquivo << asg.getEndereco().cidade << endl;
			    arquivo << asg.getEndereco().cep << endl;
			    arquivo << asg.getEndereco().bairro << endl;
			    arquivo << asg.getEndereco().rua << endl;
			    arquivo << asg.getEndereco().numero << endl;
			    arquivo << "##### Data de nascimento (ano, mes, dia) #####" << endl;
			    arquivo << asg.getData().ano << endl;
			    arquivo << asg.getData().mes << endl;
			    arquivo << asg.getData().dia << endl;
			    arquivo << "##### DADOS FUNCIONAIS #####" << endl;
			    arquivo << asg.getMatricula() << endl;
			    arquivo << asg.getSalario() << endl;
			    arquivo << asg.getAdicional() << endl;
			    arquivo << asg.getdiasFaltas() << endl;
			    arquivo << "##### Data de ingresso (ano, mes, dia) #####" << endl;
			    arquivo << asg.getIngresso().ano << endl;
			    arquivo << asg.getIngresso().mes << endl;
			    arquivo << asg.getIngresso().dia << endl;
			    
				i++;
			}

	arquivo.close();


              
           	  return;

              
    	}
	}
      for(auto it = vendedores.begin(); it != vendedores.end(); ++it)
        {   //ao achar o funcionario, imprime seu relatorio demissional
            if(it->getMatricula() == matricula)
            {
              cout << "Fazendo relatorio de demissão do VENDEDOR" << endl;
              arquivo << "##############################" << endl;
              arquivo << "Relatorio Demissional" << endl;
              arquivo << "##############################" << endl;
              arquivo << "Cargo: VENDEDOR" << endl;
              arquivo << "Nome: " << it->getNome() << endl;              
              arquivo << "CPF: " << it->getCpf() <<endl;
              arquivo << "Matrícula: " << it->getMatricula()<< endl;
              arquivo << "Data de ingresso: " << it->getIngresso().dia <<"/"<< it->getIngresso().mes << "/"<< it->getIngresso().ano << endl;
              arquivo << "Data de demissão: " << desligamento.dia <<"/"<< desligamento.mes << "/"<< desligamento.ano << endl;
              arquivo << "******************************" << endl;
              arquivo << "Valor de rescisão: " << it->calcularRescisao(desligamento)  << endl;
              arquivo << "******************************" << endl;
              int anosTrabalhados = desligamento.ano - it->getIngresso().ano;
              int mesesTrabalhados = desligamento.mes - it->getIngresso().mes;
              int diasTrabalhados = desligamento.dia - it->getIngresso().dia;           
              arquivo << "Tempo de Trabalho: " << anosTrabalhados <<" anos, "<< mesesTrabalhados << " meses e "<< diasTrabalhados << " dias"<<endl; 
             arquivo.close();

	
            vendedores.erase(it);
              //remove o funcionario
			int i = 0;
			arquivo.open("vendedor.txt", ios::out);
              //re escreve o arquivo asg sem o funcionario

			  
			  for (Vendedor& vendedor : vendedores) {
          		arquivo << "#########################################################" << endl;
			    arquivo << "VENDEDOR Nº: " << i << endl;
			    arquivo << "##### DADOS PESSOAIS #####" << endl;
			    arquivo << vendedor.getNome() << endl;
			    arquivo << vendedor.getCpf() << endl;
          		arquivo << vendedor.getFilhos() << endl;
			    arquivo << vendedor.getEstadoCivil() << endl;
          		arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
			    arquivo << vendedor.getEndereco().cidade << endl;
			    arquivo << vendedor.getEndereco().cep << endl;
			    arquivo << vendedor.getEndereco().bairro << endl;
			    arquivo << vendedor.getEndereco().rua << endl;
			    arquivo << vendedor.getEndereco().numero << endl;
			    arquivo << "##### Data de nascimento (ano, mes, dia) #####" << endl;
			    arquivo << vendedor.getData().ano << endl;
			    arquivo << vendedor.getData().mes << endl;
			    arquivo << vendedor.getData().dia << endl;
			    arquivo << "##### DADOS FUNCIONAIS #####" << endl;
			    arquivo << vendedor.getMatricula() << endl;
			    arquivo << vendedor.getSalario() << endl;
			    arquivo << vendedor.getTipo() << endl;
			    arquivo << vendedor.getdiasFaltas() << endl;
			    arquivo << "##### Data de ingresso (ano, mes, dia) #####" << endl;
			    arquivo << vendedor.getIngresso().ano << endl;
			    arquivo << vendedor.getIngresso().mes << endl;
			    arquivo << vendedor.getIngresso().dia << endl;
			    
				i++;
			}

arquivo.close();


              
           	  return;

              
    	}
	}
  
for(auto it = gerentes.begin(); it != gerentes.end(); ++it)
        {   //ao achar o funcionario, imprime seu relatorio demissional
            if(it->getMatricula() == matricula)
            {
              cout << "Fazendo relatorio de demissão do GERENTE" << endl;
              arquivo << "##############################" << endl;
              arquivo << "Relatorio Demissional" << endl;
              arquivo << "##############################" << endl;
              arquivo << "Cargo: GERENTE" << endl;
              arquivo << "Nome: " << it->getNome() << endl;              
              arquivo << "CPF: " << it->getCpf() <<endl;
              arquivo << "Matrícula: " << it->getMatricula()<< endl;
              arquivo << "Data de ingresso: " << it->getIngresso().dia <<"/"<< it->getIngresso().mes << "/"<< it->getIngresso().ano << endl;
              arquivo << "Data de demissão: " << desligamento.dia <<"/"<< desligamento.mes << "/"<< desligamento.ano << endl;
              arquivo << "******************************" << endl;
              arquivo << "Valor de rescisão: " << it->calcularRescisao(desligamento)  << endl;
              arquivo << "******************************" << endl;
              int anosTrabalhados = desligamento.ano - it->getIngresso().ano;
              int mesesTrabalhados = desligamento.mes - it->getIngresso().mes;
              int diasTrabalhados = desligamento.dia - it->getIngresso().dia;           
              arquivo << "Tempo de Trabalho: " << anosTrabalhados <<" anos, "<< mesesTrabalhados << " meses e "<< diasTrabalhados << " dias"<<endl; 
              arquivo.close();

	
              gerentes.erase(it);
              //remove o funcionario

				int i = 0;
		    arquivo.open("gerente.txt", ios::out);
              //re escreve o arquivo gerente sem o funcionario

			  
			  for (Gerente& gerente : gerentes) {
          arquivo << "#########################################################" << endl;
			    arquivo << "VENDEDOR Nº: " << i << endl;
			    arquivo << "##### DADOS PESSOAIS #####" << endl;
			    arquivo << gerente.getNome() << endl;
			    arquivo << gerente.getCpf() << endl;
          arquivo << gerente.getFilhos() << endl;
			    arquivo << gerente.getEstadoCivil() << endl;
          arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
			    arquivo << gerente.getEndereco().cidade << endl;
			    arquivo << gerente.getEndereco().cep << endl;
			    arquivo << gerente.getEndereco().bairro << endl;
			    arquivo << gerente.getEndereco().rua << endl;
			    arquivo << gerente.getEndereco().numero << endl;
			    arquivo << "##### Data de nascimento (ano, mes, dia) #####" << endl;
			    arquivo << gerente.getData().ano << endl;
			    arquivo << gerente.getData().mes << endl;
			    arquivo << gerente.getData().dia << endl;
			    arquivo << "##### DADOS FUNCIONAIS #####" << endl;
			    arquivo << gerente.getMatricula() << endl;
			    arquivo << gerente.getSalario() << endl;
			    arquivo << gerente.getLucros() << endl;
			    arquivo << gerente.getdiasFaltas() << endl;
			    arquivo << "##### Data de ingresso (ano, mes, dia) #####" << endl;
			    arquivo << gerente.getIngresso().ano << endl;
			    arquivo << gerente.getIngresso().mes << endl;
			    arquivo << gerente.getIngresso().dia << endl;
			    
				i++;
			}

arquivo.close();


              
           	  return;

              
    	}
	} 
    arquivo.close();
  
};

void Empresa::contratarFuncionario(){
    fstream arquivo;
    arquivo.open("novoFuncionario.txt", ios::in);
  //criação do arquivo

    string linha;
	  string cargo;

	getline(arquivo, linha); //cargo do funcionário
	cargo = linha;

	if (cargo == "ASG"){
    cout << "####### Contratando ASG ########" << endl;
		Asg asg;
	    while (getline(arquivo, linha)) {
	        getline(arquivo, linha); //nome
	        asg.setNome(linha);
	        getline(arquivo, linha); //CPF
	        asg.setCpf(linha);
	        getline(arquivo, linha); //número de filhos
	        asg.setFilhos(stoi(linha));
	        getline(arquivo, linha); //estado civil
	        asg.setEstadoCivil(linha);
	        getline(arquivo, linha); //Ignora a linha 
	        getline(arquivo, linha); //cidade
	        string cidade = linha;
	        getline(arquivo, linha); //CEP
	        string cep = linha;
	        getline(arquivo, linha); //bairro
	        string bairro = linha;
	        getline(arquivo, linha); //rua
	        string rua = linha;
	        getline(arquivo, linha); //número da casa
	        int numero = stoi(linha);
	        Endereco endereco{cidade, bairro, rua, cep, numero};
	        asg.setEndereco(endereco);
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //ano de nascimento
	        int anoNascimento = stoi(linha);
	        getline(arquivo, linha); //mês de nascimento
	        int mesNascimento = stoi(linha);
	        getline(arquivo, linha); //dia de nascimento
	        int diaNascimento = stoi(linha);
	        Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
	        asg.setData(dataNascimento);
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //matrícula
	        asg.setMatricula(linha);
	        getline(arquivo, linha); //salário
	        asg.setSalario(linha);
	        getline(arquivo, linha); //taxa de insalubridade
	        asg.setAdicional(stof(linha));
	        getline(arquivo, linha); //dias de falta
			    asg.setdiasFalta(stoi(linha));
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //ano de ingresso
	        int anoIngresso = stoi(linha);
	        getline(arquivo, linha); //mês de ingresso
	        int mesIngresso = stoi(linha);
	        getline(arquivo, linha); //dia de ingresso
	        int diaIngresso = stoi(linha);
	        Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};
	        asg.setIngresso(dataIngresso);
	        asgs.push_back(asg);
	        }
			arquivo.close();

			fstream arquivoEscrita;
			arquivoEscrita.open("asg.txt", ios::app);

			//adiciona informações do novo funcionário
    		arquivoEscrita << "#########################################################" <<endl;
		  	arquivoEscrita << "ASG Nº: " << asgs.size()-1 << endl;
		    arquivoEscrita << "##### DADOS PESSOAIS #####" << endl;
		    arquivoEscrita << asg.getNome() << endl;
		    arquivoEscrita << asg.getCpf() << endl;
		    arquivoEscrita << asg.getFilhos() << endl;
		    arquivoEscrita << asg.getEstadoCivil() << endl;
		    arquivoEscrita << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
		    arquivoEscrita << asg.getEndereco().cidade << endl;
		    arquivoEscrita << asg.getEndereco().cep << endl;
		    arquivoEscrita << asg.getEndereco().bairro << endl;
		    arquivoEscrita << asg.getEndereco().rua << endl;
		    arquivoEscrita << asg.getEndereco().numero << endl;
		    arquivoEscrita << "***** Data de nascimento (ano, mes, dia) ****" << endl;
		    arquivoEscrita << asg.getData().ano << endl;
		    arquivoEscrita << asg.getData().mes << endl;
		    arquivoEscrita << asg.getData().dia << endl;
		    arquivoEscrita << "##### DADOS FUNCIONAIS #####" << endl;
		    arquivoEscrita << asg.getMatricula() << endl;
		    arquivoEscrita << asg.getSalario() << endl;
		    arquivoEscrita << asg.getAdicional() << endl;
		    arquivoEscrita << asg.getdiasFaltas() << endl;
		    arquivoEscrita << "***** Data de ingresso (ano, mes, dia) ****" << endl;
		    arquivoEscrita << asg.getIngresso().ano << endl;
		    arquivoEscrita << asg.getIngresso().mes << endl;
		    arquivoEscrita << asg.getIngresso().dia << endl;
		    arquivoEscrita.close();
    }
	else if(cargo == "VENDEDOR"){
    cout << "####### Contratando VENDEDOR ########" << endl;
		Vendedor vendedor;
		while (getline(arquivo, linha)) {
	        getline(arquivo, linha); //nome
	        vendedor.setNome(linha);
	        getline(arquivo, linha); //CPF
	        vendedor.setCpf(linha);
	        getline(arquivo, linha); //número de filhos
	        vendedor.setFilhos(stoi(linha));
	        getline(arquivo, linha); //estado civil
	        vendedor.setEstadoCivil(linha);
	        getline(arquivo, linha); // Ignora a linha 
	        getline(arquivo, linha); //cidade
	        string cidade = linha;
	        getline(arquivo, linha); //CEP
	        string cep = linha;
	        getline(arquivo, linha); //bairro
	        string bairro = linha;
	        getline(arquivo, linha); //rua
	        string rua = linha;
	        getline(arquivo, linha); //número da casa
	        int numero = stoi(linha);
	        Endereco endereco{cidade, bairro, rua, cep, numero};
	        vendedor.setEndereco(endereco);
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //ano de nascimento
	        int anoNascimento = stoi(linha);
	        getline(arquivo, linha); //mês de nascimento
	        int mesNascimento = stoi(linha);
	        getline(arquivo, linha); //dia de nascimento
	        int diaNascimento = stoi(linha);
	        Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
	        vendedor.setData(dataNascimento);
	        getline(arquivo, linha); //Ignora a linha
	        getline(arquivo, linha); //matrícula
	        vendedor.setMatricula(linha);
	        getline(arquivo, linha); //salário
	        vendedor.setSalario(linha);
	        getline(arquivo, linha); //tipo do vendedor
			    char tipo = linha.front();
	        vendedor.setTipo(tipo);
	        getline(arquivo, linha); //dias de falta
			    vendedor.setdiasFalta(stoi(linha));
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //ano de ingresso
	        int anoIngresso = stoi(linha);
	        getline(arquivo, linha); //mês de ingresso
	        int mesIngresso = stoi(linha);
	        getline(arquivo, linha); //dia de ingresso
	        int diaIngresso = stoi(linha);
	        Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};
	        vendedor.setIngresso(dataIngresso);
	        vendedores.push_back(vendedor);
	        }
			arquivo.close();

			fstream arquivoEscrita;
			arquivoEscrita.open("vendedor.txt", ios::app);
		
		    // Acrescenta as informações do novo funcionário
    		arquivoEscrita << "#########################################################" <<endl;
		    arquivoEscrita << "VENDEDOR Nº: " << vendedores.size()-1 << endl;
		    arquivoEscrita << "##### DADOS PESSOAIS #####" << endl;
		    arquivoEscrita << vendedor.getNome() << endl;
		    arquivoEscrita << vendedor.getCpf() << endl;
		    arquivoEscrita << vendedor.getFilhos() << endl;
		    arquivoEscrita << vendedor.getEstadoCivil() << endl;
		    arquivoEscrita << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
		    arquivoEscrita << vendedor.getEndereco().cidade << endl;
		    arquivoEscrita << vendedor.getEndereco().cep << endl;
		    arquivoEscrita << vendedor.getEndereco().bairro << endl;
		    arquivoEscrita << vendedor.getEndereco().rua << endl;
		    arquivoEscrita << vendedor.getEndereco().numero << endl;
		    arquivoEscrita << "***** Data de nascimento (ano, mes, dia) ****" << endl;
		    arquivoEscrita << vendedor.getData().ano << endl;
		    arquivoEscrita << vendedor.getData().mes << endl;
		    arquivoEscrita << vendedor.getData().dia << endl;
		    arquivoEscrita << "##### DADOS FUNCIONAIS #####" << endl;
		    arquivoEscrita << vendedor.getMatricula() << endl;
		    arquivoEscrita << vendedor.getSalario() << endl;
		    arquivoEscrita << vendedor.getTipo() << endl;
		    arquivoEscrita << vendedor.getdiasFaltas() << endl;
		    arquivoEscrita << "***** Data de ingresso (ano, mes, dia) ****" << endl;
		    arquivoEscrita << vendedor.getIngresso().ano << endl;
		    arquivoEscrita << vendedor.getIngresso().mes << endl;
		    arquivoEscrita << vendedor.getIngresso().dia << endl;
		    arquivoEscrita.close();
	}
	else if(cargo == "GERENTE"){
    cout << "####### Contratando GERENTE ########" << endl;
    Gerente gerente;
		while (getline(arquivo, linha)) {
	        getline(arquivo, linha); //nome
	        gerente.setNome(linha);
	        getline(arquivo, linha); //CPF
	        gerente.setCpf(linha);
	        getline(arquivo, linha); //número de filhos
	        gerente.setFilhos(stoi(linha));
	        getline(arquivo, linha); //estado civil
	        gerente.setEstadoCivil(linha);
	        getline(arquivo, linha); // Ignora a linha 
	        getline(arquivo, linha); //cidade
	        string cidade = linha;
	        getline(arquivo, linha); //CEP
	        string cep = linha;
	        getline(arquivo, linha); //bairro
	        string bairro = linha;
	        getline(arquivo, linha); //rua
	        string rua = linha;
	        getline(arquivo, linha); //número da casa
	        int numero = stoi(linha);
	        Endereco endereco{cidade, bairro, rua, cep, numero};
	        gerente.setEndereco(endereco);
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //ano de nascimento
	        int anoNascimento = stoi(linha);
	        getline(arquivo, linha); //mês de nascimento
	        int mesNascimento = stoi(linha);
	        getline(arquivo, linha); //dia de nascimento
	        int diaNascimento = stoi(linha);
	        Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};
	        gerente.setData(dataNascimento);
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //matrícula
	        gerente.setMatricula(linha);
	        getline(arquivo, linha); //salário
	        gerente.setSalario(linha);
	        getline(arquivo, linha); //valor da participação nos lucros da empresa
	        gerente.setLucros(stof(linha));
	        getline(arquivo, linha); //dias de falta
			    gerente.setdiasFalta(stoi(linha));
	        getline(arquivo, linha); // Ignora a linha
	        getline(arquivo, linha); //ano de ingresso
	        int anoIngresso = stoi(linha);
	        getline(arquivo, linha); //mês de ingresso
	        int mesIngresso = stoi(linha);
	        getline(arquivo, linha); //dia de ingresso
	        int diaIngresso = stoi(linha);
	        Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};
	        gerente.setIngresso(dataIngresso);
	        gerentes.push_back(gerente);
	        }
			arquivo.close();

			fstream arquivoEscrita;
			arquivoEscrita.open("gerente.txt", ios::app);
		
		    // Acrescenta as informações do novo funcionário
        arquivoEscrita << "#########################################################" <<endl;
		    arquivoEscrita << "GERENTE Nº: " << gerentes.size()-1 << endl;
		    arquivoEscrita << "##### DADOS PESSOAIS #####" << endl;
		    arquivoEscrita << gerente.getNome() << endl;
		    arquivoEscrita << gerente.getCpf() << endl;
		    arquivoEscrita << gerente.getFilhos() << endl;
		    arquivoEscrita << gerente.getEstadoCivil() << endl;
		    arquivoEscrita << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
		    arquivoEscrita << gerente.getEndereco().cidade << endl;
		    arquivoEscrita << gerente.getEndereco().cep << endl;
		    arquivoEscrita << gerente.getEndereco().bairro << endl;
		    arquivoEscrita << gerente.getEndereco().rua << endl;
		    arquivoEscrita << gerente.getEndereco().numero << endl;
		    arquivoEscrita << "***** Data de nascimento (ano, mes, dia) ****" << endl;
		    arquivoEscrita << gerente.getData().ano << endl;
		    arquivoEscrita << gerente.getData().mes << endl;
		    arquivoEscrita << gerente.getData().dia << endl;
		    arquivoEscrita << "##### DADOS FUNCIONAIS #####" << endl;
		    arquivoEscrita << gerente.getMatricula() << endl;
		    arquivoEscrita << gerente.getSalario() << endl;
		    arquivoEscrita << gerente.getLucros() << endl;
		    arquivoEscrita << gerente.getdiasFaltas() << endl;
		    arquivoEscrita << "***** Data de ingresso (ano, mes, dia) ****" << endl;
		    arquivoEscrita << gerente.getIngresso().ano << endl;
		    arquivoEscrita << gerente.getIngresso().mes << endl;
		    arquivoEscrita << gerente.getIngresso().dia << endl;
		    arquivoEscrita.close();
	}
}
          