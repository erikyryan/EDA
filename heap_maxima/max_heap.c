#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap_max(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void subir(int heap[], int i) {
    int pai = (i - 1) / 2;
    if (heap[pai] < heap[i]) {
        swap_max(&heap[pai], &heap[i]);
        subir(heap, pai);
    }
}

void descer(int heap[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && heap[esquerda] > heap[maior])
        maior = esquerda;

    if (direita < n && heap[direita] > heap[maior])
        maior = direita;

    if (maior != i) {
        swap_max(&heap[i], &heap[maior]);
        descer(heap, n, maior);
    }
}

void inserir(int heap[], int *n, int chave) {
    if (*n == MAX_SIZE) {
        printf("\nOverflow: Não é possível inserir mais elementos\n");
        return;
    }

    *n = *n + 1;
    int i = *n - 1;
    heap[i] = chave;

    subir(heap, i);
}

void remover(int heap[], int *n) {
    if (*n <= 0) {
        printf("\nUnderflow: Não há elementos para remover\n");
        return;
    }
    if (*n == 1) {
        *n = *n - 1;
        return;
    }

    heap[0] = heap[*n - 1];
    *n = *n - 1;
    descer(heap, *n, 0);
}

void construir_max_heap(int arr[], int n) {
    int ultimoPai = (n / 2) - 1;
    for (int i = ultimoPai; i >= 0; i--)
        descer(arr, n, i);
}