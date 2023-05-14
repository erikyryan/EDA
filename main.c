#include "heap_maxima/max_heap.h"
#include "insertion_sort/insertion_sort.h"
#include "heap_sort/heap_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50000000

int main() {

    int *vetor = malloc(MAX_SIZE * sizeof(int));
    FILE *file = fopen("random_numbers.txt", "r");

    if (vetor == NULL) {
        printf("Failed to allocate memory for array\n");
        return 1;
    }

    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("entrou");
        fscanf(file, "%d", &vetor[i]);
    }
    fclose(file);
    
    clock_t start, end;
    double cpu_time_used;

    printf("HeapSort - ");
    start = clock();
    heapsort(vetor, MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tamanho: %d, Tempo de execucao: %f segundos\n",MAX_SIZE ,cpu_time_used);

    printf("InsertionSort - ");
    int n = sizeof(vetor) / sizeof(vetor[0]);
    start = clock();
    insertionSort(vetor, MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tamanho: %d, Tempo de execucao: %f segundos\n",MAX_SIZE ,cpu_time_used);
    printf("\n");
    free(vetor);
    return 0;
}