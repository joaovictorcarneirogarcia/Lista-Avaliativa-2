#include <stdio.h>

int main() {
    int valores[10];

    // Leitura dos 10 valores iniciais
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    int tamanhoAtual = 10;

    // Imprime os valores iniciais
    for (int i = 0; i < tamanhoAtual; i++) {
        printf("%d", valores[i]);
        if (i < tamanhoAtual - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    // Processo de somas e geração de novas sequências
    while (tamanhoAtual > 1) {
        int novoTamanho = tamanhoAtual - 1;
        int novosValores[novoTamanho];

        for (int i = 0; i < novoTamanho; i++) {
            novosValores[i] = valores[i] + valores[i + 1];
        }

        // Imprime os novos valores gerados
        for (int i = 0; i < novoTamanho; i++) {
            printf("%d", novosValores[i]);
            if (i < novoTamanho - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }

        // Atualiza o array de valores com os novos valores
        for (int i = 0; i < novoTamanho; i++) {
            valores[i] = novosValores[i];
        }

        tamanhoAtual = novoTamanho;
    }

    return 0;
}
