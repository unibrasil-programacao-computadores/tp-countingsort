#include "sort.h"
#include "input.h"

long long memoria_total_counting = 0;

int main()
{


    sort_base_array(countingsort, "countingsort");
    sort_ordered_arrays(countingsort, "countingsort");
    sort_reverse_ordered_arrays(countingsort, "countingsort");
    sort_uniform_arrays(countingsort, "countingsort");



    printf("\nMemória total usada pelo Counting Sort: %.2f MB\n",
           memoria_total_counting / (1024.0 * 1024.0));


//   sort_base_array(quicksort, "quicksort");
//    sort_ordered_arrays(quicksort, "quicksort");
//   sort_reverse_ordered_arrays(quicksort, "quicksort");
//   sort_uniform_arrays(quicksort, "quicksort");


//   sort_base_array(selectionsort, "selectionsort");
//   sort_ordered_arrays(selectionsort, "selectionsort");
//    sort_reverse_ordered_arrays(selectionsort, "selectionsort");
//    sort_uniform_arrays(selectionsort, "selectionsort");





    return 0;
}
