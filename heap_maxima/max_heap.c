#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void subir(int heap[], int i) {
    int pai = (i - 1) / 2;
    if (heap[pai] < heap[i]) {
        swap(&heap[pai], &heap[i]);
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
        swap(&heap[i], &heap[maior]);
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

void construir(int arr[], int n) {
    int ultimoPai = (n / 2) - 1;
    for (int i = ultimoPai; i >= 0; i--)
        descer(arr, n, i);
}

int main() {
    int heap[MAX_SIZE] = {10, 5, 3, 2, 4};
    int n = 5;

    construir(heap, n);

    printf("Heap construído: ");
    for (int i=0; i<n; ++i)
        printf("%d ", heap[i]);
    
    printf("\n");

    inserir(heap, &n, 15);
    
    printf("Heap após inserção de 15: ");
    for (int i=0; i<n; ++i)
        printf("%d ", heap[i]);
    
    printf("\n");

    remover(heap,&n);

    printf("Heap após remoção: ");
    
     for (int i=0; i<n; ++i)
        printf("%d ", heap[i]);
    
     printf("\n");
}
