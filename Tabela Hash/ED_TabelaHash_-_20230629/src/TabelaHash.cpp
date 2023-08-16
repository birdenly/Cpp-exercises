//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//
// bool twoSum(int array[], int arraySize, int k) {
//     Set<int> s; // Criando um conjunto vazio
//     for(auto i = 0; i < arraySize;i++){
//     s.insert(array[i]);
//}
//     for (int i = 0; i < arraySize; i++) {
//         int complement = k - array[i];
//         if (s.Contains(complement)) {
//             return true; // Encontrou dois elementos cuja soma é igual a K
//         }
//     }

//     return false; // Não foram encontrados dois elementos cuja soma é igual a K
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

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

using namespace std;

Par<std::string, std::string> *REMOVIDO = (Par<std::string,std::string>*)(-1);

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
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        Par<string, string>* entry = this->tabela[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] tabela;
}
bool TabelaHash::inserir(const string chave, const string valor)
{
	auto base = hash(chave);
	auto removido = -1;
	auto deleted = base;

    for (auto delta = 0; delta < tamanho; delta++){
        auto idx = (base + delta) % tamanho; // calcula o indice
		if ( (tabela[idx] != nullptr && tabela[idx] != REMOVIDO) && delta == tamanho-1 && chave != tabela[idx]->getChave() ){
			// verifica se o elemento não está na lista
			return false;
		}
        else if (tabela[idx] == nullptr){
			// caso seja nulo primeiro é verificado se a variavel removido foi alterada anteriormente, ou seja, se passou por uma posição marcada como removido
		   if (removido != -1){
               tabela[deleted] = new Par<std::string, std::string>(chave, valor);
               quantidade++;
			   if (fatorDeCarga() > CARGA_LIMITE_SUPERIOR){
				   aumentar();
			   }
			   return true;
		    }
		    else{
                tabela[idx] = new Par<std::string, std::string>(chave, valor);
                quantidade++;
			   	if (fatorDeCarga() > CARGA_LIMITE_SUPERIOR){
				   aumentar();
			   	}
		        return true;
		   }
		}
        else if (tabela[idx] == REMOVIDO && removido == -1 ) {
			deleted = idx;  // Encontramos uma posição DELETED e guardamos e continuamos procurando se temos uma chave igual
			removido = 1;
			if (delta == tamanho-1){
				// trata o caso em que o removido está na última posição
				tabela[deleted] = new Par<std::string, std::string>(chave, valor);
               	quantidade++;
				if (fatorDeCarga() > CARGA_LIMITE_SUPERIOR){
				   aumentar();
			   	}
			   	return true;
			}
		}
        else if (tabela[idx] != REMOVIDO && tabela[idx]->getChave() == chave){
			// caso a chave seja igual atualiza o valor
        	tabela[idx]->setValor(valor);
            return true;
		}
	}

}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
	auto base = hash(chave); // calcula o hash
	
	for (auto delta = 0; delta < tamanho; delta++){
        auto idx = (base + delta) % tamanho;
		if (tabela[idx] != nullptr && tabela[idx] != REMOVIDO && tabela[idx]->getChave() == chave){
			// sempre verificar primeiro se a posição é nula, pq caso seja da erro de segmentação
			//verifica se o par possui a mesma chave, caso sim retorna o valor
			return tabela[idx]->getValor();
		}
	}

	return "NÃO ACHOU";
}

/**
 Este método deve remover da tabela o Par cujo atributo 'chave' == parâmetro 'chave'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um Par com atributo 'chave' == parâmetro 'chave',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool TabelaHash::remover(const string chave)
{
	auto base = hash(chave);
	
	for (auto delta = 0; delta < tamanho; delta++){
        auto idx = (base + delta) % tamanho;
		if (tabela[idx] != nullptr && tabela[idx] != REMOVIDO && tabela[idx]->getChave() == chave){
			// sempre verificar primeiro se a posição é nula, pq caso seja da erro de segmentação
			delete tabela[idx];
			tabela[idx] = REMOVIDO;
			quantidade--;
			if (fatorDeCarga() < CARGA_LIMITE_INFERIOR) {
            	diminuir(); // Redimensiona a tabela para um tamanho maior
        	}
			return true;
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

void TabelaHash::redimensionar(std::size_t tamanhoNovo)
{
	Par<std::string, std::string>** novaTabela = new Par<std::string, std::string>*[tamanhoNovo];
    std::size_t tamanhoAntigo = tamanho;

    // Inicializa a nova tabela com valores nulos
    for (std::size_t i = 0; i < tamanhoNovo; i++) {
        novaTabela[i] = nullptr;
    }

    // Insere os elementos da tabela original na nova tabela
    for (std::size_t i = 0; i < tamanhoAntigo; i++) {
        Par<std::string, std::string>* par = tabela[i];
        if (par != nullptr && par != REMOVIDO) {
            std::size_t novoIndice = hash(par->getChave()) % tamanhoNovo;
            std::size_t incremento = 1;
            while (novaTabela[novoIndice] != nullptr) {
                novoIndice = (novoIndice + incremento) % tamanhoNovo;
                incremento++;
            }
            novaTabela[novoIndice] = par;
        }
    }

    delete[] tabela;

    // Atualiza os membros da tabela atual com os valores da nova tabela
    tabela = novaTabela;
    tamanho = tamanhoNovo;
    quantidade = getQuantidade();

    // Redimensiona novamente se necessário
    float fatorCarga = fatorDeCarga();
    if (fatorCarga < CARGA_LIMITE_INFERIOR && tamanhoNovo > TAMANHO_PADRAO) {
        diminuir();
    }
}

std::size_t TabelaHash::preHash(const string chave)
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

std::size_t TabelaHash::hash(const string chave)
{
    std::size_t hashvalor = this->preHash(chave);
    return hashvalor % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(std::size_t tamanhoNovo)
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
    
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->tabela[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        Par<string, string> * entry = tabela[i];
        if( entry == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getChave() << ":" << entry->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
