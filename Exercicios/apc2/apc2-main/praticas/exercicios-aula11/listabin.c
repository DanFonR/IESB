#include <stdio.h>
#include <stdlib.h>

typedef struct produto Produto;
struct produto {
  char nome[50];
  float preco;
  char categoria[20];
};

void arq_bin() {
  // Arquivos binários
  Produto produtos[] = {
    {"Caneta Bic", 4.50, "Escolar"},
    {"Lapiseira Pentel", 19.50, "Escolar"},
    {"Caderno", 19.99, "Escolar"},
    {"Iphone 15", 10000, "Eletrônico"},
    {"Notebook Lenovo", 5.599, "Eletrônico"},
    {"Borracha", 0.50, "Escolar"},
  };
  int n = sizeof(produtos)/sizeof(Produto); // número de produtos
  FILE *outbin = fopen("saida.bin", "wb");
  
  if(!outbin) { // output == NULL
    fprintf(stderr, "Erro ao abrir o arquivo!\n");
    return;
  }
  
  fwrite(produtos, sizeof(Produto), 6, outbin);
  fclose(outbin);

  FILE *inpbin = fopen("saida.bin", "rb");
  
  if(!inpbin) { // output == NULL
    fprintf(stderr, "Erro ao abrir o arquivo!\n");
    return;
  }
  
  Produto leituraProdutos[6];
  
  if (!fread(leituraProdutos, sizeof(Produto), 6, inpbin)) {
    fprintf(stderr, "erro na leitura do arquivo\n");
    fclose(inpbin);
    return;
  }
  fclose(inpbin);
  
  for(int i = 0; i < 6; i++) {
    printf("produto[%d]: nome: %s, preço: %.2f\n", i,
        leituraProdutos[i].nome, leituraProdutos[i].preco);
  }
}

void lerProdutosBin(char *nomeArquivo) {
  FILE *input_bin = fopen("saida.bin", "rb");
  
  if(!input_bin) { // input_bin == NULL
    fprintf(stderr, "Erro ao abrir o arquivo!\n");
    return;
  }
  
  Produto p;
  // leitura produto por produto
  while(fread(&p, sizeof(struct produto), 1, input_bin) == 1) {
    printf("produto: nome: %s, preço: %.2f\n", p.nome, p.preco);
  }

  fclose(input_bin);
}

Produto *lerProdutosBin2(char *nomeArquivo) {
  FILE *input_bin = fopen("saida.bin", "rb");
  
  if(!input_bin) { // input_bin == NULL
    fprintf(stderr, "Erro ao abrir o arquivo!\n");
    return NULL;
  }

  Produto p;
  // leitura produto por produto
  Produto *produtos = malloc(sizeof(Produto));
  int i = 1;
  
  while(fread(&p, sizeof(struct produto), 1, input_bin) == 1) {
    if (!produtos) {
      fprintf(stderr, "erro de alocacao dinamica\n");
      return NULL;
    }

    printf("produto: nome: %s, preço: %.2f\n", p.nome, p.preco);
    sprintf(produtos[i].nome, "%s",p.nome);
    produtos[i].preco = p.preco;
    sprintf(produtos[i].categoria, "%s",p.categoria);
    produtos = realloc(produtos, sizeof(Produto) * (++i));
  }

  fclose(input_bin);
  return produtos;
}

int main(void) {
  int n;
  arq_bin();


  /*FILE *input = fopen("entrada.txt", "r");
  if(!input) { // output == NULL
    fprintf(stderr, "Erro ao abrir o arquivo entrada.txt!\n");
    return 1;
  }


  FILE *output = fopen("saida.txt", "w");
  if (!output) { // output == NULL
    fprintf(stderr, "Erro ao abrir o arquivo saida.txt!\n");
    return 1;
  }

  while(fscanf(input, "%d", &n) != EOF) {
    fprintf(stdout, "inteiro: %d\n", n);
    fprintf(output, "inteiro: %d\n", n);
  }
  
  fclose(input);
  fclose(output);*/

  Produto *produtos = lerProdutosBin2("saida.bin");
  while (*produtos->nome) {
    printf("%s; R$%.2f; %s\n", *produtos.nome, *produtos.preco,
      *produtos->categoria);
    produtos++;
  }
  free(produtos);

  // scanf("%d", &n); // stdin
  // printf("Valor de n: %d\n", n); // stdout
  // // file scan/print formated
  // fscanf(stdin, "%d", &n); // stdin
  // fprintf(stdout, "Valor de n: %d\n", n); // stdout

  // char buffer_in[100] = "85 7 5";
  // char buffer_out[100] = {'\0'};
  // // string scan/print formated
  // int pos = 0;

  // sscanf(&buffer_in[0], "%d", &n);
  // pos = pos + sprintf(buffer_out+pos, "inteiro: %d\n", n);
  // sscanf(&buffer_in[3], "%d", &n);
  // pos = pos + sprintf(buffer_out+pos, "inteiro: %d\n", n);
  // sscanf(&buffer_in[5], "%d", &n);
  // pos = pos + sprintf(buffer_out+pos, "inteiro: %d\n", n);

  // printf("%s", buffer_out);

  return 0;
}
