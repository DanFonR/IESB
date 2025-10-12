#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[250];
    int idade;
} Pessoa;

typedef struct no {
    int chave;
    Pessoa valor;
    struct no *prox;
} NoChaveValor;

/* Lista encadeada */
typedef struct lista {
  NoChaveValor *inicio;
  int size;
} ListaEnc;

/* Implementar a lista enc. */

/* hash(25) -> 5 */
int hash10(int idade) { return idade % 10; }

/* <K, V> */
typedef struct {
    ListaEnc *listas;
    int (*hash)(int valor);
} HashTable;

HashTable *criarTabelaHash(int size, int (*h)(int)) {
    HashTable *ht = calloc(sizeof(HashTable), 1);
    if (!ht) return NULL;

    ht->hash = h;
    ht->listas = calloc(sizeof(ListaEnc), size);
    if (!ht->listas) {
        free(ht);
        return NULL;
    }

    return ht;
}

NoChaveValor *criarNo(int chave, Pessoa valor) {
    NoChaveValor *novo = calloc(sizeof(NoChaveValor), 1);

    if (novo) {
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

/* Chave é a idade */
void inserir(Pessoa p, HashTable *ht) {
    if (!ht) return;
    /* obter o valor de Hash */
    int h = ht->hash(p.idade);

    /*
     * inserir pessoa p na posição ht->listas[h] (ListaEnc)
     * se lista vazia, insere no inicio
     * se não, substitui se chave igual ou insere ordenado
    */
    if ((ht->listas[h]).size == 0) { /* lista vazia */
        (ht->listas[h]).inicio = criarNo(p.idade, p);

        if (!(ht->listas[h]).inicio)
            return;
    }
    else {
        NoChaveValor *novo;
        NoChaveValor *temp = (ht->listas[h]).inicio;

        if (temp->chave == p.idade) {
            temp->valor = p;
            return;
        }
        else if (temp->chave > p.idade) {
            novo = criarNo(p.idade, p);
            if (!novo) return;

            novo->prox = temp;
            (ht->listas[h]).inicio = novo;
        }
        else {
            while (temp->prox) {
                if (temp->chave == p.idade) {
                    temp->valor = p;
                    return;
                }
                else if (temp->chave < p.idade
                        && p.idade < temp->prox->chave) {
                    novo = criarNo(p.idade, p);
                    if (!novo) return;

                    novo->prox = temp->prox;
                    temp->prox = novo;
                    break;
                }

                temp = temp->prox;
            }

            if (!temp->prox) {
                temp->prox = criarNo(p.idade, p);
                if (!temp->prox) return;
            }
        }
    }

    (ht->listas[h]).size++;
}

NoChaveValor *getValue(HashTable *ht, int key) {
    if (!ht) return NULL;

    NoChaveValor *no = (ht->listas[ht->hash(key)]).inicio;

    while (no && no->chave != key) /* ja cuida de no NULL */
        no = no->prox;

    return no;
}

void delKey(HashTable *ht, int key) {
    if (!ht) return;

    int hash = ht->hash(key);
    if (!ht->listas[hash].inicio) return;

    NoChaveValor *no = ht->listas[hash].inicio;
    NoChaveValor *aux;
    NoChaveValor nulo = {0};

    if (no->chave == key) {
        ht->listas[hash].inicio = no->prox;
        *no = nulo;

        free(no);
    }
    else {
        while (no->prox) {
            if (no->prox->chave == key) {
                aux = no->prox;
                no->prox = aux->prox;
                *aux = nulo;

                free(aux);
                break;
            }
            no = no->prox;
        }

        if (no->chave == key) {
            *no = nulo;
            free(no);
        }
    }

    (ht->listas[hash]).size--;
}
