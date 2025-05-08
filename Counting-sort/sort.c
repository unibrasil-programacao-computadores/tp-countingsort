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
    for(i = 1;i< arr_size;i++){//come�a na posi��o 2 porque a 0 ja ser� testada
        x =arr[i];
        j = i -1;

        while((j >= 0) && (x < arr[j])){
            arr[j + 1]= arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}
//=================Solu��es feitas por IA para achar um insertion sem sentinela==================
//implementa��o de insertionsort e que n�o use sentinela

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


//Solu��o vi�vel: Insertion Sort com busca bin�ria + deslocamento
//Essa � a vers�o mais eficiente poss�vel do Insertion Sort sem sentinelas,
//porque reduz o n�mero de compara��es de O(n�) para O(n log n)
//(embora o n�mero de movimenta��es continue O(n�)).

// Busca bin�ria para encontrar o �ndice onde inserir o valor x
long busca_binaria(double* arr, long start, long end, double x) {
    long meio;
    while (start < end) {//while (start < end): executa enquanto houver uma sublista v�lida para busca.
        meio = start + (end - start) / 2;//calcula o meio da sublista de forma segura (evita overflow).
        if (x < arr[meio])// se x for menor que o valor do meio, ent�o ele deve estar � esquerda, ent�o ajustamos o end.
            end = meio;
        else//se x for maior ou igual ao valor do meio, ent�o ele vai para a direita.
            start = meio + 1;
    }
    return start; // Posi��o correta de inser��o
}

void insertionsort_binario(double* arr, long arr_size) {
    long i, j, pos;
    double x;

    for (i = 1; i < arr_size; i++) {
        x = arr[i];// armazena o valor atual que queremos ordenar.

        // Encontra a posi��o correta de inser��o usando busca bin�ria
        pos = busca_binaria(arr, 0, i, x);//usa a busca bin�ria para encontrar a posi��o correta de inser��o de x na parte ordenada arr[0..i-1].

        // Desloca os elementos para a direita
        for (j = i; j > pos; j--) {// desloca todos os elementos maiores que x uma posi��o � direita para abrir espa�o na posi��o correta.
            arr[j] = arr[j - 1];
        }

        arr[pos] = x;//insere x na posi��o apropriada.
    }
}

//Insertion Sort Cl�ssico:
//Melhor caso (vetor j� ordenado):
//Compara��es: O(n)
//Deslocamentos: O(1) por itera��o (nenhum deslocamento).
//
//Pior caso (vetor invertido):
//Compara��es: O(n�)
//Deslocamentos: O(n�)
//
// Insertion Sort com Busca Bin�ria:
//Melhor caso:
//Compara��es: O(n log n)
//Deslocamentos: O(1) por itera��o, se j� estiver ordenado.
//
//Pior caso:
//Compara��es: O(n log n) � melhoria real sobre o cl�ssico
//Deslocamentos: O(n�) � igual ao cl�ssico, pois ainda precisamos mover os elementos
