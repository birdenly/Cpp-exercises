#include <iostream>
#include <map>
#include <vector>
#include <fstream>


using namespace std;

//Scruct para armazenar um remedio
struct remedio{
  string nome;
  float preco;
};
//Scruct para armazenar um remedio da lista de compras, mas não utilizei
struct compra{
string nomeC;
float precoC;
};

//Map para os Remedios e um para a lista de compras
map<long long int, remedio> remedios;
//Map para a lista de compras, mas não utilizei
map<long long int, compra> compras;


//Ler o arquivo ou criar um arquivo e salva-lo no map
void criarArquivo(){
  fstream arquivoCriar;

  //cria o arquivo Remedios.txt se não existir
  arquivoCriar.open("Remedios.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  //Abre o arquivo alunos.txt
  fstream arquivoler;
  arquivoler.open("Remedios.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  //Ler todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  //fecha
  arquivoler.close(); 
  

  //Transfere as linhas do vector para dentro do map
  for(int i = 0; i< vetor.size(); i+=3){
    long long int num_remedio = stoll(vetor[i]);
    remedios[num_remedio].nome = vetor[i+1];
    remedios[num_remedio].preco = stoll(vetor[i+2]);
  }
}

//Ler o arquivo ou criar um arquivo e salva-lo no map, iria ser utilizado para apagar 1 remedio da lista de compra e mostrar o preço total mas não consegui
void criarArquivoC(){
  fstream arquivoCriar;

  //cria o arquivo Compras.txt se não existir
  arquivoCriar.open("Compras.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  //Abre o arquivo Compras.txt
  fstream arquivoler;
  arquivoler.open("Compras.txt", ios::in);
  string linha;
  vector<string> vetor;
  
 //Ler todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  //fecha
  arquivoler.close(); 
  

  //Transfere as linhas do vector para dentro do map
  for(int i = 0; i< vetor.size(); i+=3){
    long long int num_remedio = stoll(vetor[i]);
    compras[num_remedio].nomeC = vetor[i+1];
    compras[num_remedio].precoC = stoll(vetor[i+2]);
  }
}

//Lista todos os remedios da loja
void listaRemedios(int x){
  cout << "\n-----Remedios diponiveis-----\n";
  if(x==0){ // caso seja cliente apenas imprime nome e preço
  for(auto i : remedios){
    cout << "Nome: "<< i.second.nome << endl;
    cout << "preço: "<< i.second.preco << endl;
    cout << "------------------------------\n";
}
}
  else{ //caso seja o admin imprime registro,nome e preço
    for(auto i : remedios){
    cout << "Registro: "<< i.first << endl;
    cout << "Nome: "<< i.second.nome << endl;
    cout << "preço: "<< i.second.preco << endl;
    cout << "------------------------------\n";
}
}
  
}

//Busca um remedio
void buscaRemedio(string remedio_procurado){
  int x = 0;
  for(auto i : remedios){ // procurar o nome no map remedios até achar 1 igual
    if(i.second.nome == remedio_procurado){
      cout << "\nProduto encontrado!\n";
      x=1;
    }
  }
  if(x==0){ //caso não ache x = 0
    cout << "\nProduto não encontrado!\n";
  }
}

//Adicionar a lista de compras
void comprarRemedio(string remedio){
  fstream arquivoCriar;
  //abre ou cria o arquivo Compras.txt
  arquivoCriar.open("Compras.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  fstream arquivoler;
  arquivoler.open("Compras.txt", ios::in);

    string linha;
  vector<string> vetor;
  
  //ler todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  //fechar
  arquivoler.close();
  
  fstream arquivo;
  arquivo.open("Compras.txt", ios::out | ios::app); //Abre o arquivo
for(auto i : remedios){ //procurar o nome no map remedios até achar e adicionar a lista de compras
    if(i.second.nome == remedio){
  arquivo << i.first << endl;
  arquivo << i.second.nome << endl;
  arquivo << i.second.preco << endl;
  cout << "\nItem adicionado a lista de compras\n";
    }   
  } 
  arquivo.close(); 
}

//apenas atualizar o Arquivo Remedios.txt
void atualizarArquivoGeral(){
  fstream arquivo;
  arquivo.open("Remedios.txt", ios::out); //Apagar o conteudo de Remedios.txt
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(auto i : remedios){
    arquivo << i.first << endl;
    arquivo << i.second.nome << endl;
    arquivo << i.second.preco << endl;
  }
}

//Apagar 1 remedio do Remedio.txt
void tirarRemedio(string remedio){
  for(auto i : remedios){//procurar o nome no map remedios até achar e remover-lo
    if(i.second.nome == remedio){
      remedios.erase(i.first);
      atualizarArquivoGeral(); //atualizar o arquivo depois da remoção
      cout << "\nProduto Removido\n" << endl;
      return;
    }   
  }
  cout << "Produto não encontrado" << endl;
}

//Verificar se o produto ja existe
int jaexiste(int reg, string nome ){
  for(auto i : remedios){//procurar o nome no map remedios
    if((i.first == reg) or (i.second.nome == nome)){//se achar um registro ou nome igual o remedio já existe
      return 1;
    }   
  }
  return 0; //caso nao ache
}

//Adicionar um remedio ao arquivo Remedios.txt
void cadastrarRemedio(int registro,string nome,float preco){
  fstream arquivo;
  //abrir o arquivo
  arquivo.open("Remedios.txt", ios::out | ios::app);
 
  int x = jaexiste(registro,nome); //Verificar se existe
  
  if(x==0){//Se não existir pode adicionar ao arquivo
  arquivo << registro << endl;
  remedios[registro].nome = nome;
  arquivo << nome << endl;
  remedios[registro].preco = preco;
  arquivo << preco << endl;
    cout << "\nProduto cadastrado\n";
  }
  else{
    cout << "\nRegistro ou nome já existente\n";
  }
  arquivo.close(); // Fecha o arquivo
}

//Trocar preço de um remédio que já existe
void trocaPreco(string nome, float preco_remedio){
    for(auto i : remedios){ //procurar o nome no map remedios
    if(i.second.nome == nome){//se o produto existir, remove seu preço e adiciona um novo
      remedios.erase(i.second.preco);
      remedios[i.first].preco = preco_remedio;
      atualizarArquivoGeral(); // Chama a função para atualizar o arquivo
      cout << "\nProduto atualizado\n" << endl;
      return;
    }   
  } 
}

//Deletar o conteudo de Compras.txt
void apagar(){
  fstream arquivo;
  arquivo.open("Compras.txt", ios::out);
}

//imprimir o valor total das Compras.txt
void valorTotal(){ //FUNCIONAVA APENAS SE COMPRAS TIVER ALGUM VALOR DENTRO E REINICIAR O PROGRAMA
 float total;
	for(auto it = compras.begin(); it != compras.end(); it++){
 	total += it->second.precoC;
	}
	cout << "Valor R$ " << total << endl; 
	}
