#include <stdio.h>

void merge(int vec[], int start, int mid, int size) {
    int i = start, j = mid, k = 0;
    int w[size - start];
    
    while (i < mid && j < size)
        w[k++] = (vec[i] < vec[j])? vec[i++] : vec[j++];
        
    while (i < mid) w[k++] = vec[i++];
    while (j < size) w[k++] = vec[j++];
    
    for (k = 0, i = start; k < size - start; k++, i++)
        vec[i] = w[k];
}

void merge_sort(int vec[], int start, int size) {
    if (size - start == 1) return;

    int mid = (size + start) / 2;

    merge_sort(vec, start, mid);
    merge_sort(vec, mid, size);
    merge(vec, start, mid, size);
}

void exibir(int vec[], int size) {for (int i = 0; i < size; i++) printf("%d ", vec[i]); puts("");}

int main() {
    int v[] = {9, 5, 3, 1, 2, 0, 7};
    int size = sizeof(v)/sizeof(v[0]);

    exibir(v, size);
    merge(v, 0, 3, size);
    exibir(v, size);

    return 0;
}