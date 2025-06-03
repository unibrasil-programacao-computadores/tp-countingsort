#include "sort.h"
#include "input.h"

int main()
{

    int arr1[50] =
    {
        45, 12, 87, 34, 23, 65, 78, 90, 56, 11,
        67, 32, 49, 80, 73, 29, 14, 55, 68, 25,
        37, 19, 92, 41, 76, 61, 84, 16, 38, 99,
        50, 24, 43, 70, 85, 33, 62, 47, 77, 59,
        95, 30, 66, 21, 83, 60, 35, 48, 20, 88
    };
    double arr2[50] =
    {
        12.543, 3.789, 98.123, 45.678, 7.456,
        0.987, 56.321, 13.999, 27.456, 4.321,
        65.432, 8.765, 23.456, 72.111, 1.234,
        87.654, 9.876, 34.567, 51.234, 6.543,
        78.912, 2.345, 44.444, 17.890, 5.678,
        33.333, 11.111, 59.999, 25.678, 3.210,
        80.123, 14.789, 29.456, 60.987, 7.890,
        22.345, 19.876, 42.111, 53.222, 12.345,
        75.678, 5.432, 30.123, 61.234, 8.654,
        49.999, 16.789, 26.543, 71.111, 4.987
    };

    int tamanho = 50;

    countingsort(arr1, tamanho);
    countingsort2(arr2, tamanho);

    printf("array ordenado:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");


    printf("\n=======================Numeros com ponto flutuante====================================\n");

    printf("array ordenado:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%.3f ", arr2[i]);
    }
    printf("\n");

    printf("\n=======================Teste de arquivos do professor====================================\n");

    sort_base_array(countingsort3, "countingsort");
    //sort_ordered_arrays(countingsort3, "Countingsort");
    //sort_reverse_ordered_arrays(countingsort3, "Countingsort");
    //sort_uniform_arrays(countingsort3, "Countingsort");

    return 0;
}
