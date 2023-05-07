`insertionSort` é a função principal do algoritmo de Insertion Sort. Recebe como parâmetros um array `arr` e seu tamanho `n`. A função percorre o array a partir da segunda posição, comparando cada elemento com os anteriores e, caso o elemento seja menor, o insere na posição correta no subarray já ordenado. O resultado é um array ordenado em ordem crescente.


    void insertionSort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
     
            /* Move os elementos arr[0..i-1] maiores que key para uma posição à frente de sua posição atual */
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

 
<br>

`printArray`:  recebe um array `arr` e seu tamanho `n` como parâmetros e imprime o array na tela.

`void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}` 

<br>

  `main` :  Cria um array de exemplo e chama a função `insertionSort` para ordená-lo. Em seguida, imprime o array ordenado com a função `printArray`.

    int main() {
        int arr[] = { 12, 11, 13, 5, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);
     
        insertionSort(arr, n);
        printArray(arr, n);
     
        return 0;
    }
