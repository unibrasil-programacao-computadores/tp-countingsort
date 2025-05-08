#include "sort.h"
#include "input.h"

int main()
{
//    sort_base_array(quicksort, "Quicksort");
//    sort_ordered_arrays(quicksort, "Quicksort");
//    sort_reverse_ordered_arrays(quicksort, "Quicksort");
//    sort_uniform_arrays(quicksort, "Quicksort");

//    sort_base_array(selectionsort, "selectionsort");
//    sort_ordered_arrays(selectionsort, "selectionsort");
//    sort_reverse_ordered_arrays(selectionsort, "selectionsort");
//    sort_uniform_arrays(selectionsort, "selectionsort");

//    sort_base_array(insertionsort, "insertionsort");
//    sort_ordered_arrays(insertionsort, "insertionsort");
//    sort_reverse_ordered_arrays(insertionsort, "insertionsort");
//    sort_uniform_arrays(insertionsort, "insertionsort");

    sort_base_array(insertionsort_binario, "insertionsort_Binario");
    sort_ordered_arrays(insertionsort_binario, "insertionsort_Binario");
    sort_reverse_ordered_arrays(insertionsort_binario, "insertionsort_Binario");
    sort_uniform_arrays(insertionsort_binario, "insertionsort_Binario");


    return 0;
}
