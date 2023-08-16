
#ifndef farmacia_HPP
#define farmacia_HPP

  void criarArquivo();
  void criarArquivoC();
  void comprarRemedio(std::string remedio_procurado);
  void listaRemedios(int x);
  void buscaRemedio(std::string nome_remedio);
  void tirarRemedio(std::string remedio);
  void atualizarArquivoGeral();
  void cadastrarRemedio(int registro,std::string nome,float preco);
  int jaexiste(int reg, std::string nome );
  void trocaPreco(std::string nome,float preco_remedio);
  void valorTotal();
  void apagar();
#endif