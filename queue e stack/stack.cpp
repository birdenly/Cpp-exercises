#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> lista1{1, 2, 3, 4, 5};
  int escolha;
  cout << "------Escolha uma comando-----" << endl;
  cout << "" << endl;
  cout << "lista de teste: 1 2 3 4 5" << endl;
  cout << "adicionar item: digite 1" << endl;
  cout << "remover item: digite 2" << endl;
  cout << "encerrar programa: digite 0" << endl;
  cout << "---------------------------" << endl;
  cin >> escolha;
  
  while(escolha!=0){
      if(escolha < 0 or escolha > 2){
      cout << "comando invalido"<< endl;
      break;
    }

    cout << " "<< endl;
    if(escolha == 1){
      cout << "Número a ser adicionado" << endl;
      int num;
      cin >> num;
      lista1.push_back(num);
      cout << " "<< endl;
      cout << "lista atualizada:" << endl;
      for (auto x = lista1.begin(); x !=lista1.end(); ++x){
        cout << *x << " ";
      }
        cout << " "<< endl;
    }
    if(escolha == 2){
    lista1.pop_back();
      cout << " "<< endl;
      cout << "lista atualizada:" << endl;
      for (auto x = lista1.begin(); x !=lista1.end(); ++x){
        cout << *x << " ";
      }
        cout << " "<< endl;
      
    }
    cout << "Proximo comando?" << endl;
    cin >> escolha;

  }

  cout << " "<< endl;
  cout << "---programa encerrado---" << endl;
  return 0;
}