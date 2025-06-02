#include <stdio.h>
 //https://www.youtube.com/shorts/YCJu7lIJj3o video usado como base para o código//
void countingSort(int vetor[], int tamanho) {
    int i;
    int maior = vetor[0];

    // Encontra o maior valor do vetor
    for (i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    int contagem[maior + 1];

    // Inicializa o vetor de contagem com 0
    for (i = 0; i <= maior; i++) {
        contagem[i] = 0;
    }

    // Conta as ocorrências de cada número
    for (i = 0; i < tamanho; i++) {
        contagem[vetor[i]]++;
    }

    // Reorganiza os valores no vetor original
    int j = 0;
    for (i = 0; i <= maior; i++) {
        while (contagem[i] > 0) {
            vetor[j] = i;
            j++;
            contagem[i]--;
        }
    }
}

int main() {
    int numeros[] = {4, 2, 2, 8, 3, 3, 1};
   int n = 7;

    printf("Antes:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    countingSort(numeros, n);

    printf("\nDepois:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}

