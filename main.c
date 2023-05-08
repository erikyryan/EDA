#include "heap_maxima/max_heap.h"
#include "insertion_sort/insertion_sort.h"
#include "heap_sort/heap_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

int main() {

    int vetor[MAX_SIZE];
    printf("\nGerando numeros...\n");
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        int r = rand() % MAX_SIZE * 2;
        printf("%d\n",r);
        int repetido = 0;
        for (int j = 0; j < i; j++) {
            if (vetor[j] == r) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            i--;
        } else {
            vetor[i] = r;
        }
    }
    printf("Numeros gerados!\n");
    
    clock_t start, end;
    double cpu_time_used;

    // printf("HeapMax - ");
    // start = clock();
    // construir_max_heap(vetor, MAX_SIZE);
    // end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Tamanho: %d, Tempo de execução: %f segundos\n",MAX_SIZE ,cpu_time_used);
    
    printf("HeapSort - ");
    start = clock();
    heapsort(vetor, MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tamanho: %d, Tempo de execução: %f segundos\n",MAX_SIZE ,cpu_time_used);

    printf("InsertionSort - ");
    int n = sizeof(vetor) / sizeof(vetor[0]);
    start = clock();
    insertionSort(vetor, MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tamanho: %d, Tempo de execução: %f segundos\n",MAX_SIZE ,cpu_time_used);
    printf("\n");
    return 0;
}