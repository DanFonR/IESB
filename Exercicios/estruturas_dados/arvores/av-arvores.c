/*


*/

/* 3 */
#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
    int dado;
    No *esq;
    No *dir;
};

void exibir(No *arvore) {
    if (arvore) {
        printf("(%d)", arvore->dado);
        exibir(arvore->esq);
        exibir(arvore->dir);
    }
}

No *criar_no(int dado) {
    No *novo = calloc(1, sizeof(No));
    if (novo) novo->dado = dado;
    return novo;
}

/* a */
void inserir_ordenado(No *arvore, int dado) {
    if (!arvore || dado == arvore->dado) return;

    if (dado < arvore->dado) {
        inserir_ordenado(arvore->esq, dado);
        if (!(arvore->esq)) arvore->esq = criar_no(dado);
    }
    if (dado > arvore->dado) {
        inserir_ordenado(arvore->dir, dado);
        if (!(arvore->dir)) arvore->dir = criar_no(dado);
    }
}

/* b */
int altura(No *arvore) {
    if (!arvore) return -1;
    
    int h_dir = altura(arvore->dir), h_esq = altura(arvore->esq);

    return ((h_dir > h_esq)? h_dir : h_esq) + 1;
}

/* c */
int caminho(No *arvore, int dado) {
    if (!arvore) return 0;

    if (arvore->dado == dado) {
        printf("(%d)", dado);
        return 1;
    }
    else {
        int caminho_esq = caminho(arvore->esq, dado);
        int caminho_dir = caminho(arvore->dir, dado);

        if (caminho_esq || caminho_dir) printf("<-(%d)", arvore->dado);

        return caminho_esq || caminho_dir;
    }
}

/* d */
int total_nos(No *arvore) {
    if (!arvore) return 0;

    int qtd_e = total_nos(arvore->esq), qtd_d = total_nos(arvore->dir);
    return qtd_d + qtd_e + 1;
}

int main() {
    No *arvore = criar_no(2);
    arvore->esq = criar_no(7);
    arvore->esq->esq = criar_no(3);
    arvore->esq->dir = criar_no(1);
    arvore->esq->dir->esq = criar_no(0);
    arvore->esq->dir->esq->esq = criar_no(5);
    arvore->dir = criar_no(9);
    arvore->dir->dir = criar_no(8);
    arvore->dir->dir->dir = criar_no(6);

    printf("%d\n",caminho(arvore, 0));
    
    return 0;
}