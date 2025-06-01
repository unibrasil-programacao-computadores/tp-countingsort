#include "sort.h"
#include "input.h"

int main()
{

    int arr[10] = {4, 7, 1, 9, 3, 2, 8, 5, 6, 1};
    int tamanho = 10;

    countingsort(arr, tamanho);

    printf("array ordenado:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


//    sort_base_array(quicksort, "Quicksort");
//    sort_ordered_arrays(quicksort, "Quicksort");
//    sort_reverse_ordered_arrays(quicksort, "Quicksort");
//    sort_uniform_arrays(quicksort, "Quicksort");


//    sort_base_array(insertionsort_binario, "insertionsort_Binario");
//    sort_ordered_arrays(insertionsort_binario, "insertionsort_Binario");
//    sort_reverse_ordered_arrays(insertionsort_binario, "insertionsort_Binario");
//    sort_uniform_arrays(insertionsort_binario, "insertionsort_Binario");


    return 0;
}
