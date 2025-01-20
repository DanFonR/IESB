#include <stdio.h>
#include <stdlib.h>
#define badalloc_check(obj) \
if (!obj) { \
  fprintf(stderr, "\aerro de alocacao de memoria\n"); \
  fclose(obj); \
  exit(EXIT_FAILURE); \
}

typedef struct {
  char *nome;
  float preco;
  char *categoria;
} Produto;

char *tabelamento(Produto* restrict produtos, size_t size) {
  char static tabela[BUFSIZ];
  int offset = sprintf(tabela, "|%-16s|%-8s|%-10s|\n",
                      "Nome", "Preco", "Categoria");

  for (int i = 0; i < 38; i++)
    offset += sprintf(tabela + offset, "_");

  offset += sprintf(tabela + offset, "\n");

  for (int i = 0; i < size; i++) {
    offset += sprintf(tabela + offset, "|%-16s|%-8.2f|%-10s|\n",
      produtos[i].nome, produtos[i].preco, produtos[i].categoria);
  }
  
  return tabela;
}

int escrever_tabela(Produto* restrict produtos, size_t size) {
  FILE *prods = fopen("prods.bin", "wb");

  badalloc_check(prods);

  if (fwrite(produtos, sizeof(Produto), size, prods))
    fprintf(stderr, "tabela estruturada escrita com sucesso\n");
  else {
    fprintf(stderr, "\aerro de escrita de tabela estruturada\n");
    return 1;
  }
  
  fclose(prods);

  return 0;
}

void ler_tabela(FILE* restrict prods, Produto *produtos, size_t size) {
  if (fread(produtos, sizeof(Produto), size, prods))
    fprintf(stderr, "arquivo lido com sucesso\n");
  else fprintf(stderr, "\aerro de leitura do arquivo\n");
}

int main() {
  Produto produtos[] = {
    {"Caneta Bic", 4.50, "Escolar"},
    {"Lapiseira Pintel", 19.50, "Escolar"},
    {"Caderno", 19.99, "Escolar"},
    {"iPhone 15", 10000, "Eletronico"},
    {"Notebook Lenovo", 5599, "Eletronico"},
    {"Borracha", 0.50, "Escolar"},
  };
  size_t len = sizeof(produtos)/sizeof(Produto);
  char *tabela = tabelamento(produtos, len);
  
  puts(tabela);
  escrever_tabela(produtos, len);
  
  return 0;
}
