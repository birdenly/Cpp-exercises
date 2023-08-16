//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Elemento*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
}

bool TabelaHash::inserir(const std::string& chave, const std::string* valor)
{
	//primeiro calcula o hash
    auto indice = this->hash(chave);
    Par<const std::string, const std::string*>* par = tabela[indice];

    if (par == nullptr) {
        //cria um novo par, incrementa a quantidade e retorna true
        tabela[indice] = new Par<const std::string, const std::string*>(chave, valor);
        ++quantidade;
		// if (fatorDeCarga() > CARGA_LIMITE_SUPERIOR){
		// 	aumentar();
		// }
        return true;
    } else {
        //percorre a lista e procura se algum índice possui a mesma chave, se tiver, atualiza o valor
        while (par != nullptr) {
            if (par->getChave() == chave) {
                par->setValor(valor);
                return true;
            } else {
                //itera
                par = par->getProximo();
            }
        }

        // Chegou ao final da lista sem encontrar a chave, cria um novo Par e o adiciona ao final da lista
        Par<const std::string, const std::string*>* novoPar = new Par<const std::string, const std::string*>(chave, valor);
        novoPar->setProximo(tabela[indice]);
		tabela[indice] = novoPar;
        ++quantidade;
		// if (fatorDeCarga() > CARGA_LIMITE_SUPERIOR){
		//  	aumentar();
		// }
        return true;
    }
    return chave == "" || *valor == "";
}

const std::string* TabelaHash::buscar(const std::string& chave)
{
	auto idx = hash(chave);

	Par<const std::string, const std::string*>* par = tabela[idx];

	if (par == nullptr){
		return nullptr;
	}
	else{
		while (par != nullptr){
			if (par->getChave() == chave){
				return par->getValor();
			}
			par = par->getProximo();
		}
	}
	
    return nullptr;
}

bool TabelaHash::remover(const std::string& chave)
{
	auto indice = hash(chave);
    Par<const std::string, const std::string*>* par = tabela[indice];
    Par<const std::string, const std::string*>* parAnterior = nullptr;

	if (par == nullptr){
		return false;
	}
	else{
		while (par != nullptr){
			if (par->getChave() == chave) {
            	if (parAnterior != nullptr) {
                	parAnterior->setProximo(par->getProximo());
            	}
				else{
                	tabela[indice] = par->getProximo();
            	}
				delete par;
	            --quantidade;
				// if (fatorDeCarga() < CARGA_LIMITE_INFERIOR) {
	   //          	diminuir(); // Redimensiona a tabela para um tamanho maior
	   //      	}
	            return true;
			}
			else {
	            parAnterior = par;
	            par = par->getProximo();
        	}
		}
	}
  	return false;
	
}

float TabelaHash::fatorDeCarga()
{
    return (float)this->getQuantidade() / (float)this->getTamanho();
}

void TabelaHash::aumentar()
{
    std::size_t tamanhoNovo = 2*this->getTamanho() + 1;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::diminuir()
{
    std::size_t metadeTamanho = this->getTamanho()/2;
    std::size_t tamanhoNovo = metadeTamanho % 2 == 0 ? metadeTamanho + 1 : metadeTamanho;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::redimensionar(const std::size_t& tamanhoNovo)
{
 /* Elemento** novo = new Par<const std::string, const std::string*>*[tamanhoNovo];
  auto tamanhoVelho = this->getTamanho();
  this->setTamanho(tamanhoNovo);
  Elemento** Velha = this->tabela;

  for(long unsigned int i=0;i< tamanhoVelho;i++){
	if(Velha[i] != nullptr){
	  auto pAux = Velha[i];
	  while( pAux != nullptr){
		auto aux2= pAux;
		pAux=pAux->getProximo();
		auto ind=this->hash(aux2->getChave());
		if(novo[ind]==nullptr){
		  novo[ind]=aux2;
		  novo[ind]->setProximo(nullptr);
		}
		else{
		  aux2->setProximo(novo[ind]);
		  novo[ind]=aux2;
		}
	  }
	}
  }
  this->tabela = novo;
  delete [] Velha;
  */

	Elemento** novo =  new Elemento*[ tamanhoNovo ]; //tabela com o novo tamanho
	std::size_t tamanhoVelho = this->getTamanho();
	this->setTamanho(tamanhoNovo);
	Elemento** velho = this->tabela; // tabela com o tamanho atual

	for (auto i = 0; i < tamanhoVelho; i++){
		if (velho[i] != nullptr){
			//se encontrar algum indice diferente de nulo percorre o array
			Elemento* pAux = velho[i];
			while (pAux != nullptr){
				Elemento* pAux2 = pAux;
				pAux = pAux->getProximo();
				auto indice = this->hash(pAux2->getChave());
				if (novo[indice] == nullptr){
					novo[indice] = pAux2;
					novo[indice]->setProximo(nullptr);
				}
				else{
					pAux2->setProximo(novo[indice]);
					 novo[indice] = pAux2;
				}
			}
		}
	}
	this->tabela = novo;
	delete[] velho;
	return;
}


std::size_t TabelaHash::preHash(const std::string& chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(const std::string& chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(const std::size_t& tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}

bool TabelaHash::verificarDuplicatas()
{
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t i = 0; i < this->getTamanho(); ++i)
    {
        if(this->tabela[i] == nullptr)
        {
            std::cout << "[" << i << "] = null" << std::endl;
        }
        else
        {
            std::cout << "[" << i << "] = " ;
            auto aux = this->tabela[i];
            while(aux!=nullptr)
            {
                std::cout << "{ " << aux->getChave() << "," << *aux->getValor() << " } -> ";
                
                aux = aux->getProximo();
            }
            std::cout << "null" << std::endl;
            
        }
    }
}
// 	bool twoSum(int array[], int arraySize, int k) {
//    Set<int> s; // Criando um conjunto vazio

//    for (int i = 0; i < arraySize; i++) {
//        int complement = k - array[i];
//        if (s.Contains(complement)) {
//            return true; // Encontrou dois elementos cuja soma é igual a K
//        }
//        s.Insert(array[i]); // Inserindo o elemento no conjunto
//    }

//    return false; // Não foram encontrados dois elementos cuja soma é igual a K
// }

// bool threeSum(int array[], int arraySize, int K) {
//     Set<int> s;
    
//     for (int i = 0; i < arraySize; i++) {
//         s.Insert(array[i]);
//     }
    
//     for (int i = 0; i < arraySize; i++) {
//         int target = K - array[i];
        
//         for (int j = 0; j < arraySize; j++) {
//             int complement = target - array[j];
//             if (s.Contains(complement)) {
//                 return true; // Encontrou três elementos cuja soma é igual a K
//             }
//         }
//     }
    
//     return false; // Não foram encontrados três elementos cuja soma é igual a K
// }