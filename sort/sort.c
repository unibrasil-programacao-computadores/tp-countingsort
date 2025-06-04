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


//================================COUNTING SORT=======================================================
//bom dia
void countingsort(int* arr, long arr_size)
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


//counting para valores double primeiro multiplica por mil pra virar inteiro e depois divide para voltar a ser double
void countingsort2(double* arr, long arr_size) {

    int conversor = 1000;

    // Converte para inteiro
    for (int i = 0; i < arr_size; i++) {
        arr[i] = (arr[i] * conversor);
    }

    int maior = arr[0];
    int menor = arr[0];

    for(int i = 0; i < arr_size; i++) {
        if(arr[i] > maior) {
            maior = arr[i];
        } else if(arr[i] < menor) {
            menor = arr[i];
        }
    }

    int k = maior - menor + 1;
    int arrC[k];

    for(int i = 0; i < k; i++) {
        arrC[i] = 0;
    }

    //vetor contagems
    for(int i = 0; i < arr_size; i++) {
        arrC[(int)arr[i] - menor] += 1;
    }

    //loop para a cumulativA
    for(int i = 1; i < k; i++) {
        arrC[i] += arrC[i - 1];
    }

    // ordenando
    double arrB[arr_size];
    for(int i = arr_size - 1; i >= 0; i--) {
        arrB[arrC[(int)arr[i] - menor] - 1] = arr[i];//aqui ta trucnando
        arrC[(int)arr[i] - menor] -= 1;
    }

    // convertendo de volta em double
    for(int i = 0; i < arr_size; i++) {
        arr[i] = arrB[i] / conversor;
    }
}

void countingsort3(double* arr, long arr_size) {
    int conversor = 100;


    int i;
    
    for ( i = 0; i <= k; i++){
        arrC[i] = 0;
    int arr_int[arr_size];// para inteiros

    for (int i = 0; i < arr_size; i++) {
        arr_int[i] = (int)(arr[i]) / conversor;
    }

    for ( i = 1; i <= arr_size; i++){    
        arrC[arrA[i ].Chave] = arrC[arrA[i ].Chave] + 1;
    }

    for ( i = 1; i <= k; i++){
        arrC[i] = arrC[i] + arrC[i - 1];
    }

    for ( i = arr_size; i > 0; i--){
         arrB[arrC[arrA[ i ].Chave]] = arrA[ i ];
        arrC[arrA[ i ].Chave] = arrC[arrA[ i ].Chave] - 1;

    }

    for ( i = 1; i <= arr_size; i++){
        arrA[ i ] = arrB[i ];

    }

    int maior = arr_int[0];
    int menor = arr_int[0];

    for (int i = 0; i < arr_size; i++) {
        if (arr_int[i] > maior) maior = arr_int[i];
        if (arr_int[i] < menor) menor = arr_int[i];
    }

    int k = maior - menor + 1;
    int arrC[k];

    // coloca 0 em todo o  arrC
    for (int i = 0; i < k; i++) {
        arrC[i] = 0;
    }

    // contagem
    for (int i = 0; i < arr_size; i++) {
        arrC[arr_int[i] - menor]++;
    }

    // Cumulativa
    for (int i = 1; i < k; i++) {
        arrC[i] += arrC[i - 1];
    }


    int arrB[arr_size];
    for (int i = arr_size - 1; i >= 0; i--) {
        arrB[arrC[arr_int[i] - menor] - 1] = arr_int[i];
        arrC[arr_int[i] - menor]--;
    }

    // aatualiza o arr original
    for (int i = 0; i < arr_size; i++) {
        arr[i] = arrB[i] * conversor;
    }
}



}