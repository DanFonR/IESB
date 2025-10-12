#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int arr[], int n) {
    printf("{");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b}\n");
}

void ajusta_heap(int arr[], int n, int i) {
    int maior = i, esq, dir;

    while (maior < n) {
        esq = 2*i + 1;
        dir = esq + 1;

        /* trata array como arvore, propriedade max heap (maximo no topo) */
        if (esq < n && arr[esq] > arr[maior])
            maior = esq;
        if (dir < n && arr[dir] > arr[maior])
            maior = dir;

        if (maior != i) {
            swap(&arr[maior], &arr[i]);
            i = maior; /* parte pro proximo no (o que era o maior) */
        }
        else break;
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) /* esq != null || dir != null */
        ajusta_heap(arr, n, i); /* ultimo no que nao folha (no folha: esq = dir = null) */

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        ajusta_heap(arr, i, 0); /* houve troca na raiz, entao ajusta a partir dela */
    }
}

int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    print_arr(arr, size);
    heap_sort(arr, size);
    print_arr(arr, size);

    return 0;
}