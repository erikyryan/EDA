-   `swap`: Essa função troca os valores de duas variáveis. Ela é usada pelas funções  `subir`  e  `descer`  para trocar elementos de lugar na heap.

```c
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

```

<br>

-   `subir`: Essa função é usada para restaurar a propriedade da heap máxima após a inserção de um novo elemento. Ela compara o elemento recém-inserido com seu pai e, se for maior, troca os dois elementos de lugar. Esse processo é repetido até que a propriedade da heap máxima seja restaurada.

```c
void subir(int heap[], int i) {
    int pai = (i - 1) / 2;
    if (heap[pai] < heap[i]) {
        swap(&heap[pai], &heap[i]);
        subir(heap, pai);
    }
}

```

<br>

-   `descer`: Essa função é usada para restaurar a propriedade da heap máxima após a remoção do elemento máximo. Ela compara o elemento na raiz da árvore (que foi substituído pelo último elemento da heap) com seus filhos e troca-o com o maior dos dois filhos se for menor que eles. Esse processo também é repetido até que a propriedade da heap máxima seja restaurada.

```c
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

```
<br>


-   `inserir`: Essa função insere um novo elemento na heap. Primeiro, ela verifica se há espaço disponível na heap. Em seguida, ela adiciona o novo elemento no final da heap e chama a função  `subir`  para restaurar a propriedade da heap máxima.
```c
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

```

<br>

-   `remover`: Essa função remove o elemento máximo da heap (que está sempre na raiz da árvore). Primeiro, ela verifica se há elementos na heap. Em seguida, ela substitui o elemento máximo pelo último elemento da heap e chama a função  `descer`  para restaurar a propriedade da heap máxima.

```c
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

```

<br>

-   `construir`: Essa função constrói uma heap máxima a partir de um array de elementos. Ela chama a função  `descer`  para cada elemento do array começando pelo último pai e indo até a raiz da árvore.

```c
void construir(int arr[], int n) {
    int ultimoPai = (n / 2) - 1;
    for (int i = ultimoPai; i >= 0; i--)
        descer(arr, n, i);
}

```
