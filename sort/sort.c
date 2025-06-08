#include "sort.h"
#include <time.h>

extern long long memoria_total_counting;


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


//================================COUNTING SORT=======================================================


void countingsort(double* arr, long arr_size) {


    double menor = arr[0];
    double maior = arr[0];


    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > maior){
           maior = arr[i];
        }
        if (arr[i] < menor){
            menor = arr[i];
        }
    }

    long k = (long)(maior - menor) + 1;

    // caloc para evitar estouro de pilha
    long* arrC = (long*)calloc(k, sizeof(long));
    if (!arrC) {
        printf("memoria insuficiente\n");
        return;
    }

     memoria_total_counting += k * sizeof(long); //so para contar memoria


    // prreenche arrC com a frequencia que aparecem
    for (int i = 0; i < arr_size; i++) {
        arrC[(long)(arr[i] - menor)]++;
    }


    // Ordenar os valores
    int index = 0;
    for (long i = 0; i < k; i++) {
        while (arrC[i] > 0) {
            arr[index] = menor + i;
            index++;
            arrC[i]--;
        }
    }

    free(arrC); // Liberar memória alocada
}


void countingsort2(int* arr, long arr_size)
{
    int maior = arr[0];
    int menor = arr[0];
    int arrB[arr_size];

    for(int i =0; i< arr_size; i++)
    {

        if(arr[i] > maior)
        {
            maior = arr[i];
        }
        else if(arr[i] < menor)
        {
            menor = arr[i];
        }

    }
    int k = maior - menor + 1;

    int arrC[k];

    for(int i = 0; i < k; i++){
        arrC[i] = 0;
    }

    //vetor contagem
    for(int i = 0; i < arr_size; i++)
    {
        arrC[arr[i]-menor] += 1;
    }
    //loop para a cumulativA
    for(int i = 1; i <k ; i++)
    {
        arrC[i] = arrC[i] + arrC[i-1];
    }
    //ordenando
    for(int i = arr_size-1; i>=0; i--)
    {
        arrB[arrC[arr[i]-menor]-1] = arr[i];
        arrC[arr[i]-menor]-= 1;
    }

    // Copia de volta
    for(int i = 0; i < arr_size; i++) {
        arr[i] = arrB[i];
    }
}









