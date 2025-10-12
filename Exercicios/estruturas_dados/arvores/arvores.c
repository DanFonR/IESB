#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct {
    int h;
    int qtd;
} dados_arvore;

struct no {
    No *esq;
    No *dir;
    int dado;
};

void exibir(No *no, int pos) {
    if (no) {
        switch (pos) {
            case 0: /* pre-ordem */
                printf("(%d)", no->dado);
                exibir(no->esq, 0);
                exibir(no->dir, 0);
                break;
            case 1: /* em-ordem */
                exibir(no->esq, 1);
                printf("(%d)", no->dado);
                exibir(no->dir, 1);
                break;
            case 2: /* pos-ordem */
                exibir(no->esq, 2);
                exibir(no->dir, 2);
                printf("(%d)", no->dado);
                break;
            default:
                puts("valor invalido; exibindo as 3 ordens:\n\n");
                puts("pre-ordem");
                exibir(no, 0);
                puts("\n\nem-ordem");
                exibir(no, 1);
                puts("\n\npos-ordem");
                exibir(no, 2);
                break;
        }
    }
}

void liberar(No *no) {
    if (no) {
        if (!(no->esq || no->dir)) {
            free(no);
            return;
        }
        else {
            if (!no->dir) liberar(no->esq);
            if (!no->esq) liberar(no->dir);
        }
    }
}

No *criar_no(int dado) {
    No *novo = calloc(1, sizeof(No));
    if (novo) novo->dado = dado;

    return novo;
}

void altura(No *no, dados_arvore *res) {
    if (no) {
        (res->qtd)++;
        altura(no->esq, res);
        altura(no->dir, res);
    }

    int h = 0, q = res->qtd;
    while (q) {
        h++;
        q /= 2;
    }
    
    res->h = h;
}

int main() {
    No *raiz = criar_no(1);
    raiz->esq = criar_no(2);
    raiz->dir = criar_no(3);
    (raiz->esq)->esq = criar_no(4);
    (raiz->esq)->dir = criar_no(5);
    (raiz->dir)->esq = criar_no(6);
    (raiz->dir)->dir = criar_no(7);
    /* 1->(2->(4, 5), 3->(6, 7)) */
    exibir(raiz, -1);

    puts("\n");
    dados_arvore a;
    altura(raiz, &a);
    printf("altura: %d;"
           "\nqtd. de nos: %d\n",
           a.h, a.qtd);

    liberar(raiz);
    return 0;
}

