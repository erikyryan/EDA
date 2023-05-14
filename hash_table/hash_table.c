#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Método da divisão
int hash_divisao(int chave, int tamanho_tabela) {
    return chave % tamanho_tabela;
}

// Método da dobra
int hash_dobra(int chave, int tamanho_tabela) {
    int num_digitos = log10(tamanho_tabela) + 1;
    int soma = 0;
    while (chave > 0) {
        soma += chave % (int)pow(10, num_digitos);
        chave /= pow(10, num_digitos);
    }
    return soma % tamanho_tabela;
}

// Método da multiplicação
int hash_multiplicacao(int chave, int tamanho_tabela) {
    double A = (sqrt(5) - 1) / 2;
    return (int)(tamanho_tabela * (chave * A - (int)(chave * A)));
}

// Método da análise de dígitos
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
    // Escolha o desvio de distribuição que deseja usar aqui
    // Neste exemplo, estamos usando o primeiro desvio de distribuição
    return (chave + desvio[0]) % tamanho_tabela;
}

int main() {
    // Teste das funções de dispersão
    int chaves[] = {1234, 5678, 9101};
    int tamanho_vetor_chaves = sizeof(chaves)/sizeof(chaves[0]);
    int tamanho_tabela = 10;

    printf("Metodo da divisao: %d\n", hash_divisao(chaves[0], tamanho_tabela));
    printf("Metodo da dobra: %d\n", hash_dobra(chaves[0], tamanho_tabela));
    printf("Metodo da multiplicacao: %d\n", hash_multiplicacao(chaves[0], tamanho_tabela));
    printf("Metodo da analise de digitos: %d\n", hash_analise_digitos(chaves[0], 2, chaves, tamanho_vetor_chaves, tamanho_tabela));

    return 0;
}
