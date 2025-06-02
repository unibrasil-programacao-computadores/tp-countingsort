#include "sort.h"
#include "input.h"

int main()
{

    int arr[10] = {4, 7, 1, 9, 3, 2, 8, 5, 6, 1};
    int tamanho = 10;

    countingsort(arr, tamanho);

    printf("array ordenado:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");


    double arr2[5] = {3.251, 2.718, 1.445, 2.286, 1.635};

    int tamanho2 = 5;
    countingsort2(arr2, tamanho2);

    printf("array ordenado:\n");
    for(int i = 0; i < tamanho2; i++)
    {
        printf("%.3f ", arr2[i]);
    }
    printf("\n");



    //sort_base_array(countingsort2, "Countingsort");
    //sort_ordered_arrays(countingsort2, "Countingsort");
    //sort_reverse_ordered_arrays(quicksort, "Quicksort");
     //sort_uniform_arrays(countingsort2, "Countingsort");




    return 0;
}
