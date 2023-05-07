<br>

 `void swap(int *x, int *y)`: função que recebe dois ponteiros para inteiros e realiza a troca dos valores apontados por eles. É uma função auxiliar usada para trocar elementos de posição no vetor.

```c
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
```
<br>

`heapify`:  função responsável por "corrigir" o heap, garantindo que o elemento pai seja sempre maior que seus filhos. Recebe um vetor `arr`, o número de elementos `n` e o índice `i` do elemento pai a ser comparado com seus filhos.

```c
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
```
<br>

 `heapsort`: função que executa o algoritmo Heap Sort em um vetor `arr` com `n` elementos. A função itera sobre todos os elementos do vetor, criando um heap máximo e removendo os elementos do heap para inseri-los na posição correta no vetor ordenado.

```c
void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
```
<br>

Na função `main()`, um vetor de inteiros `arr` é inicializado com valores e a quantidade de elementos `n` é definida. Em seguida, a função `heapsort()` é chamada para ordenar o vetor e, por fim, os elementos ordenados são impressos na tela.

```c
int main() {
    int arr[MAX_SIZE] = { 10, 5, 3, 2, 4 };
    int n = 5;

    heapsort(arr, n);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```
