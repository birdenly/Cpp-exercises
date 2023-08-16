//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
  this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
  this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");

  this->cabeca->setProximo(this->cauda);
  this->cabeca->setAnterior(nullptr);

  this->cauda->setProximo(nullptr);
  this->cauda->setAnterior(this->cabeca);

  this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
}

No<std::string> *ListaDuplamenteEncadeada::getCabeca(void) {
  return this->cabeca;
}

No<std::string> *ListaDuplamenteEncadeada::getCauda(void) {
  return this->cauda;
}

int ListaDuplamenteEncadeada::tamanho(void) { 
  return this->quantidade; }

bool ListaDuplamenteEncadeada::vazia(void) { 
  return this->tamanho() == 0; }

std::string ListaDuplamenteEncadeada::recuperar(int i) {
  No<std::string> *aux = getCabeca()->getProximo();
  int contador = 1;
  while (contador != i) {
    aux = aux->getProximo();
    ++contador;
  }
  return aux->getValor();
}

int ListaDuplamenteEncadeada::buscar(std::string s) {
  No<std::string> *aux = getCabeca()->getProximo();
  int contador = 1;
  int indice = -1;

  while (aux != getCauda() && aux->getValor() != s) {
    
      aux = aux->getProximo();
      ++contador;
  }
  if(aux->getValor()==s){
    indice=contador;
  }

   return indice;
}

int ListaDuplamenteEncadeada::buscarMF(std::string s) {
    No<std::string> *aux = getCabeca()->getProximo();
    int contador = 1;
    int indice = -1;

  while (aux != getCauda() && aux->getValor() != s) {
    
      aux = aux->getProximo();
      ++contador;
  }
    if(aux->getValor()==s){
    indice=contador;
  }
  
    //desencadeando o nó da posição
   aux->getAnterior()->setProximo(aux->getProximo());
   aux->getProximo()->setAnterior(aux->getAnterior());
  //encadeando o nó na cabeça
  aux->setProximo(getCabeca()->getProximo());
  aux->setAnterior(getCabeca());
  aux->getAnterior()->setProximo(aux);
  aux->getProximo()->setAnterior(aux);
  //aqui ele busca o indice de onde o aux foi alocado e retorna-o
  indice = buscar(aux->getValor());
  
  return indice; 
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s) {
  No<std::string> *novo = new No<std::string>(s);

  novo->setAnterior(this->getCabeca());
  novo->setProximo(this->getCabeca()->getProximo());

  // COMO NÃO FAZER
  // this->getCabeca()->getProximo()->setAnterior(novo);
  // this->getCabeca()->setProximo( novo );

  // COMO RECOMENDO FAZER
  novo->getAnterior()->setProximo(novo);
  novo->getProximo()->setAnterior(novo);

  ++this->quantidade;

  return true;
}

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s) {
  No<std::string> *novo = new No<std::string>(s);

  novo->setProximo(this->getCauda());
  novo->setAnterior(this->getCauda()->getAnterior());

  novo->getProximo()->setAnterior(novo);
  novo->getAnterior()->setProximo(novo);

  ++this->quantidade;

  return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s) {
  No<std::string> *novo = new No<std::string>(s);
  No<std::string> *aux = getCabeca()->getProximo();
  int contador = 1;
  while (contador != i) {
    aux = aux->getProximo();
    ++contador;
  }
  novo->setProximo(aux);
  novo->setAnterior(aux->getAnterior());

  novo->getProximo()->setAnterior(novo);
  novo->getAnterior()->setProximo(novo);

  ++this->quantidade;
  return true;
}

bool ListaDuplamenteEncadeada::inserirOrdenado(std::string s) {
  
  inserirNaCabeca(s);
  return true;
}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void) {
  No<std::string> *aux = getCabeca()->getProximo();

  aux->getAnterior()->setProximo(aux->getProximo());
  aux->getProximo()->setAnterior(aux->getAnterior());

  std::string nome;
  nome = aux->getValor();
  delete(aux);
  --this->quantidade;

  return nome;
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void) {
  No<std::string> *aux = getCauda()->getAnterior();

  aux->getAnterior()->setProximo(aux->getProximo());
  aux->getProximo()->setAnterior(aux->getAnterior());

  std::string nome;
  nome = aux->getValor();
  delete(aux);
  --this->quantidade;

  return nome;
}

std::string ListaDuplamenteEncadeada::remover(int i) {
  // criamos um ponteiro para apontar para nosso nó
  No<std::string> *aux = getCabeca()->getProximo();
  int contador = 1;
  // avança até apontar para o nó da posição i
  while (contador != i) {
    aux = aux->getProximo();
    ++contador;
  }
  // aqui ele desencadeia nosso nó da lista
  aux->getAnterior()->setProximo(aux->getProximo());
  aux->getProximo()->setAnterior(aux->getAnterior());
  // copiamos seu valor e liberamos o nó
  std::string nome;
  nome = aux->getValor();
  delete(aux);
  --this->quantidade;
  // retorna o valor do nó liberado
  return nome;
}

void ListaDuplamenteEncadeada::imprimir(void) {
  for (auto n = this->cabeca->getProximo(); n != this->cauda;
       n = n->getProximo()) {
    std::cout << n->getValor() << " ";
  }
  std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia() {
  if (this->cabeca == nullptr) {
    return CABECA_NULA;
  } else if (this->cabeca->getProximo() == nullptr) {
    return CABECA_PROXIMO_NULO;
  } else if (this->cabeca->getProximo()->getAnterior() != this->cabeca) {
    return ENCADEAMENTO_INCORRETO;
  } else if (this->cabeca->getAnterior() != nullptr) {
    return CABECA_ANTERIOR;
  }

  if (this->cauda == nullptr) {
    return CAUDA_NULA;
  } else if (this->cauda->getAnterior() == nullptr) {
    return CAUDA_ANTERIOR_NULO;
  } else if (this->cauda->getAnterior()->getProximo() != this->cauda) {
    return ENCADEAMENTO_INCORRETO;
  } else if (this->cauda->getProximo() != nullptr) {
    return CAUDA_PROXIMO;
  }

  if (this->vazia()) {
    if (this->cabeca->getProximo() != this->cauda) {
      return CABECA_CAUDA;
    }

    if (this->cabeca != this->cauda->getAnterior()) {
      return CABECA_CAUDA;
    }
  } else {
    // Verifica encadeamento dos elementos
    for (No<std::string> *i = this->cabeca->getProximo(); i != this->cauda;
         i = i->getProximo()) {
      if (i->getProximo()->getAnterior() != i) {
        return ENCADEAMENTO_INCORRETO;
      }
      if (i->getAnterior()->getProximo() != i) {
        return ENCADEAMENTO_INCORRETO;
      }
    }
  }

  return OK;
}
