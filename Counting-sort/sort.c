#include "sort.h"

int compare(const void* a, const void* b)
{
    double diff =  *(double*)a - *(double*)b;
    return diff > 0 ? 1 : diff < 0 ? -1 : 0;
}

void quicksort(double* arr, long arr_size)
{
    qsort(arr, arr_size, sizeof(double), compare);
}

void selectionsort(double* arr, long arr_size)
{
    int i, j, min;
    double x;//temporario

    for(i = 0; i <= arr_size - 1; i++)
    {

        min = i;

        for(j = i + 1; j < arr_size; j++)
        {

            if(arr[j] < arr[min])
            {
                min = j;
            }

        }
        x = arr[min];
        arr[min] = arr[i];
        arr[i] = x;

    }

}
void insertionsort(double* arr, long arr_size){
    int i,j;
    double x;
    for(i = 1;i< arr_size;i++){//começa na posição 2 porque a 0 ja será testada
        x =arr[i];
        j = i -1;

        while((j >= 0) && (x < arr[j])){
            arr[j + 1]= arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}
//=================Soluções feitas por IA para achar um insertion sem sentinela==================
//implementação de insertionsort e que não use sentinela

void insertionsort_sem_qualquer_sentinela(double* arr, long arr_size) {
    long i, j;
    double x;

    for (i = 1; i < arr_size; i++) {
        x = arr[i];

        // Percorre os elementos anteriores de forma reversa, mas usando for com controle claro
        for (j = i; j > 0 && arr[j - 1] > x; j--) {
            arr[j] = arr[j - 1];
        }

        arr[j] = x;
    }
}


//Solução viável: Insertion Sort com busca binária + deslocamento
//Essa é a versão mais eficiente possível do Insertion Sort sem sentinelas,
//porque reduz o número de comparações de O(n²) para O(n log n)
//(embora o número de movimentações continue O(n²)).

// Busca binária para encontrar o índice onde inserir o valor x
long busca_binaria(double* arr, long start, long end, double x) {
    long meio;
    while (start < end) {//while (start < end): executa enquanto houver uma sublista válida para busca.
        meio = start + (end - start) / 2;//calcula o meio da sublista de forma segura (evita overflow).
        if (x < arr[meio])// se x for menor que o valor do meio, então ele deve estar à esquerda, então ajustamos o end.
            end = meio;
        else//se x for maior ou igual ao valor do meio, então ele vai para a direita.
            start = meio + 1;
    }
    return start; // Posição correta de inserção
}

void insertionsort_binario(double* arr, long arr_size) {
    long i, j, pos;
    double x;

    for (i = 1; i < arr_size; i++) {
        x = arr[i];// armazena o valor atual que queremos ordenar.

        // Encontra a posição correta de inserção usando busca binária
        pos = busca_binaria(arr, 0, i, x);//usa a busca binária para encontrar a posição correta de inserção de x na parte ordenada arr[0..i-1].

        // Desloca os elementos para a direita
        for (j = i; j > pos; j--) {// desloca todos os elementos maiores que x uma posição à direita para abrir espaço na posição correta.
            arr[j] = arr[j - 1];
        }

        arr[pos] = x;//insere x na posição apropriada.
    }
}

//Insertion Sort Clássico:
//Melhor caso (vetor já ordenado):
//Comparações: O(n)
//Deslocamentos: O(1) por iteração (nenhum deslocamento).
//
//Pior caso (vetor invertido):
//Comparações: O(n²)
//Deslocamentos: O(n²)
//
// Insertion Sort com Busca Binária:
//Melhor caso:
//Comparações: O(n log n)
//Deslocamentos: O(1) por iteração, se já estiver ordenado.
//
//Pior caso:
//Comparações: O(n log n) — melhoria real sobre o clássico
//Deslocamentos: O(n²) — igual ao clássico, pois ainda precisamos mover os elementos
