#include <iostream>
#include "Hremedios.hpp" //importa o arquivo de cabeçalho remedios

using namespace std;

int main(int argc, char *argv[]){
  
  cout << "-----Farmacia-----\n";
  
  // Escolhendo o perfil
  
  cout << "Escolha seu perfil:\n";
  cout << "1 - cliente\n";
  cout << "2 - Gerente\n";
  int perfil; 
  cin >> perfil;
  
  // Le o arquivo Remedios.txt
  criarArquivo();
  
  // Menu para o cliente
  if(perfil == 1){
    while(true){
      cout << "\n--------Área cliente--------\n\n";
      cout << "1 - Listar remédios\n";
      cout << "2 - Buscar remédios\n";
      cout << "3 - Adicionar ao carrinho de compras\n"; 
      cout << "4 - Remover do carinho de compras\n"; 
      cout << "5 - Valor total do carrinho\n";
      cout << "6 - Esvaziar carrinho de compras\n";
      cout << "7 - Sair\n"; 
      int opt;
      cin >> opt;
      
      //listar todos os remedios
      if(opt == 1){
        listaRemedios(0);//Chama a função em remedios.cpp
      }

      //Buscar um remedio
      else if(opt == 2){
        cout << "Nome do remédio: ";
        string remedio_procurado;
        cin >> remedio_procurado;
        buscaRemedio(remedio_procurado); //Chama a função em remedios.cpp
      }

      //Adicionar um remedio que existe ao carrinho de compras
      else if(opt==3){
        cout << "Nome do remédio: ";
        string remedio_procurado;
        cin >> remedio_procurado;
       comprarRemedio(remedio_procurado);//Chama a função em remedios.cpp
      }

      //Remover 1 remedio no carrinho de compras
      else if(opt==4){
      }
      //calcular valor total das compras, tem um bug que nao consegui resolver
      else if(opt==5){
       //valorTotal(); //Chama a função em remedios.cpp
      }
      //Esvaziar a lista de compras como alternativa de remover apenas 1
      else if(opt==6){
        apagar();//Chama a função em remedios.cpp
      }
      
      //Acaba a área do cliente
      else{
        break;
      }
    } 
  }

  // Menu de opções para o perfil admin
  else if(perfil == 2){
    string senha;
    cout << "\nSenha:\n";
    cin >> senha;
    			if (senha != "9595"){ //verificar se é admin
				cout << "Senha incorreta!\n";
			}
			else{
        // Menu para o admin
    while(true){
      cout << "\n--------Área gerente---------\n\n";
      cout << "1 - Listar remédios\n";
      cout << "2 - Buscar remédios\n";
      cout << "3 - Adicionar novo medicamento\n"; 
      cout << "4 - Atualizar preço\n"; 
      cout << "5 - excluir remédio\n"; 
      cout << "6 - Sair\n";

      int opt;
      cin >> opt;

      //listar todos os remedios
      if(opt == 1){
        listaRemedios(1);//Chama a função em remedios.cpp
      }
      

      //Buscar um remedio
      else if(opt == 2){
        cout << "Nome do remédio: ";
        string nome_remedio;
        cin >> nome_remedio;
        buscaRemedio(nome_remedio); //Chama a função em remedios.cpp
      }
        
        //Cadastras um novo remedio em Remedios.txt, utilizando seu registro(chave),nome e preço
        else if(opt==3){
        cout << "Resgistro: ";
        int registro_remedio;
        cin >> registro_remedio;
        cout << "Nome do remédio: ";
        string nome_remedio;
        cin >> nome_remedio;
        cout << "Preço do remédio: ";
        float preco_remedio;
        cin >> preco_remedio;
        cadastrarRemedio(registro_remedio, nome_remedio, preco_remedio);//Chama a função em remedios.cpp
          
        }
        //Trocar o preco de um remedio já existente
        else if(opt==4){
        cout << "Nome do remédio: ";
        string nome_remedio;
        cin >> nome_remedio;
        cout << "Preço do remédio: ";
        float preco_remedio;
        cin >> preco_remedio;
        trocaPreco(nome_remedio,preco_remedio); //Chama a função em remedios.cpp
          
        }

        //Remover 1 remedio do Remedios.txt
        else if ( opt == 5){
        cout << "Nome do remédio: ";
        string remedio_procurado;
        cin >> remedio_procurado;
        tirarRemedio(remedio_procurado);//Chama a função em remedios.cpp
        }
      else{
        break;
      }
    }
  }
}

  //Perfil diferente dos listados
  else{
      cout << "Perfil não existe\n"<< endl;
    }
  atualizarArquivoGeral();//Chama a função em remedios.cpp
  return 0; 
}