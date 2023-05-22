#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TABLE_SIZE 1300000 //tamanho do table_size sendo 1.3 * n

// metodo da divisao
int hash_divisao(int chave, int tamanho_tabela) {
    return chave % tamanho_tabela;
}

// metodo da dobra
int hash_dobra(int chave, int tamanho_tabela) {
    int num_digitos = log10(tamanho_tabela) + 1;
    int soma = 0;
    while (chave > 0) {
        soma += chave % (int)pow(10, num_digitos);
        chave /= pow(10, num_digitos);
    }
    return soma % tamanho_tabela;
}

// metodo da multiplicacao
int hash_multiplicacao(int chave, int tamanho_tabela) {
    double A = (sqrt(5) - 1) / 2;
    return (int)(tamanho_tabela * (chave * A - (int)(chave * A)));
}

// metodo da analise de digitos (incompleto)
int hash_analise_digitos(int chave, int num_digitos_escolhidos, int *chaves, int tamanho_vetor_chaves, int tamanho_tabela) {
    int i;
    int distribuicao[tamanho_tabela];
    for (i = 0; i < tamanho_tabela; i++) distribuicao[i] = 0;
    for (i = 0; i < tamanho_vetor_chaves; i++) {
        distribuicao[chaves[i] % (int)pow(10, num_digitos_escolhidos)]++;
    }
    
    int desvio[tamanho_tabela];
    double soma_quadrados = 0;
    double soma_absolutos = 0;
    for (i = 0; i < tamanho_tabela; i++) {
        desvio[i] = distribuicao[i] - tamanho_vetor_chaves / tamanho_tabela;
        soma_quadrados += pow(desvio[i], 2);
        soma_absolutos += abs(desvio[i]);
    }
    return (chave + desvio[0]) % tamanho_tabela;
}

int main() {
    int n = 1000000;
    int *keys = malloc(n * sizeof(int));

    srand(time(NULL)); 

    // Gera as chaves aleatoriamente
    for (int i = 0; i < n; i++) {
        keys[i] = rand() % 2000000001;
    }

    int *table_division = malloc(TABLE_SIZE * sizeof(int));
    int num_colisoes_divisao = 0;
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index_division = hash_divisao(key, TABLE_SIZE);
        if (table_division[index_division] != 0) {
            num_colisoes_divisao++;
        }
        table_division[index_division] = key;
    }
    printf("Numero de colisoes (metodo da divisao): %d\n", num_colisoes_divisao);
    free(table_division);

    for (int i = 0; i < n; i++) {
        keys[i] = rand() % 2000000001;
    }

    int *table_fold = malloc(TABLE_SIZE * sizeof(int));
    int num_colisoes_dobra = 0;
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index_fold = hash_dobra(key, TABLE_SIZE);
        if (table_fold[index_fold] != 0) {
            num_colisoes_dobra++;
        }
        table_fold[index_fold] = key;

    }
    printf("Numero de colisoes (metodo da dobra): %d\n", num_colisoes_dobra);
    free(table_fold);

    for (int i = 0; i < n; i++) {
        keys[i] = rand() % 2000000001;
    }

    int *table_multiplication = malloc(TABLE_SIZE * sizeof(int));
    int num_colisoes_multiplicacao = 0;
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index_multiplication = hash_multiplicacao(key, TABLE_SIZE);
        if (table_multiplication[index_multiplication] != 0) {
            num_colisoes_multiplicacao++;
        }
        table_multiplication[index_multiplication] = key;
    }
    printf("Numero de colisoes (metodo da multiplicacao): %d\n", num_colisoes_multiplicacao);
    free(table_multiplication);

    return 0;
}
